#!/usr/bin/python

import sys
import os
import time
from random import randint
from datetime import timedelta
import re
from datetime import datetime
import ipaddress

def error_handling(ip_addr, cpu_id, start_date, start_time, end_date, end_time):

	# Saving path of the log file to be queried
	data_path = sys.argv[1]

	# Error-handling for incorrect file path
	if (os.path.exists(data_path)) == False:
	        print 'Path does not exist\n'
	        sys.exit()

	ip_addr = unicode(ip_addr)

	# Validating a IPv4 address
        try:
		ipaddress.ip_address(ip_addr)
	except:
		print 'Invalid IP address, try again\n'
		sys.exit()

	# Validating the CPU ID number
	if cpu_id == '1' or cpu_id == '0':
		pass
	else:
                print 'Invalid CPU ID, try again\n'
                sys.exit()

	# Validating the date format
	try:
                datetime.strptime(start_date, '%Y-%m-%d')
                datetime.strptime(end_date, '%Y-%m-%d')
        except ValueError:
                print 'Incorrect date format, should be YYYY-MM-DD\n'
		sys.exit()

	# Validating the time format
        try:
                datetime.strptime(start_time, '%H:%M')
                datetime.strptime(end_time, '%H:%M')
        except ValueError:
                print 'Incorrect time format, should be HH:MM\n'
		sys.exit()

	return data_path

def main():

	# Interactive tool begins to take input from user
	while True:

		command = raw_input('>').split(' ')

		# To quit the interactive tool
		if command[0] == 'EXIT' or command[0] == 'exit':
			sys.exit()

		# Error-handling for incorrect user command
		if command[0] != 'QUERY':
			print 'Unrecognizable command, please try again'
			sys.exit()

		# Parsing the user command to get the attributes for the log entries to be checked
	        action = command[0]
	        ip_addr = command[1]
	        cpu_id = command[2]
	        start_date = command[3]
	        start_time = command[4]
	        end_date = command[5]
	        end_time = command[6]

		# Handle all possible errors and return the file path
		data_path = error_handling(ip_addr, cpu_id, start_date, start_time, end_date, end_time)

		# Start time when the server starts creating logs
		server_time = '00:00'

		# Calculate difference between log creation time and requested log time
		server_diff = datetime.strptime(start_time, '%H:%M') - datetime.strptime(server_time, '%H:%M')
		server_minutes = int(server_diff.total_seconds()/60)

		date = '2014-10-31'
		time_stamp = int(time.mktime(datetime.strptime(date, "%Y-%m-%d").timetuple()))
		time_stamp += server_minutes*60

		# Calculate time difference between start and end time
		time_diff = datetime.strptime(end_time, '%H:%M') - datetime.strptime(start_time, '%H:%M')
		minutes = int(time_diff.total_seconds()/60)

		# Increment start time by 1 minute to generate next log entry
		start_time = datetime.strptime(command[4], '%H:%M')
		increment = timedelta(minutes=1)
		count = 0

		# Since command is QUERY, start printing log entries according to user requests
		print 'CPU'+cpu_id+' usage on '+ip_addr+':'

		# Opening log file to read the entries
		file = open(data_path, 'r')

		# Reading through every line to get the requested entries
		for line in file:

			# Searching on basis of timestamp, ip address and CPU ID and printing it to the user in requested format
			if re.search(str(time_stamp)+'\t'+str(ip_addr)+'\t'+cpu_id, line):
				cpu_usage = line.split('\t')[3]
				cpu_usage = cpu_usage.rstrip()
				print '('+start_date+' '+datetime.strftime(start_time, '%H:%M')+', '+str(cpu_usage)+')',
				if count != (minutes-1):
					print ',',
				else:
					print ''

				# Updating timestamp by one minute and start time for the next entry
				time_stamp += 60
				start_time += increment

				# Updating count to print the requested number of log entries
				count += 1
				if count == minutes:
					break


if __name__ == "__main__":
	main()


