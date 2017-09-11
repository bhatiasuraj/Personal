#!/usr/bin/python

import sys
import time
import datetime
from random import randint
import ipaddress
from os import path
import os

def log_generator(ip_range, time_stamp, t_stamp, log_file):

	# Creating log for 1000 server IP addresses
	for ip in ip_range.hosts():

		# Creating log for every minute of the day
		for i in range(24*60):

			# Creating log entry for both CPU 0 and CPU 1 of every server
			log_file.write(str(time_stamp)+'\t'+str(ip)+'\t0\t'+str(randint(0,100))+'%\n')
		 	log_file.write(str(time_stamp)+'\t'+str(ip)+'\t1\t'+str(randint(0,100))+'%\n')

			# Updating timestamp by 60 seconds
		        time_stamp += 60

		# Resetting timestamp for the next server
		time_stamp = t_stamp

def main():

	# Directory path where log files are saved
	data_path = sys.argv[1]

	# Check if data path exists
	if not os.path.exists(data_path):
		print 'Data path does not exist, try again.'
		sys.exit()

	date = '2014-10-31'

	# Creating timestamp on basis of date
	time_stamp = int(time.mktime(datetime.datetime.strptime(date, "%Y-%m-%d").timetuple()))
	t_stamp = time_stamp

	# Creating a log file and writing the headings for the entries to the file
	file_path = path.relpath(data_path+'/'+str(date)+'.log')
	log_file = open(file_path, "w")
	log_file.write('timestamp\tIP\t\tcpu_id\tusage\n')

	# Creating a range of IP addresses to be assigned to the servers
	ip_range = ipaddress.ip_network(u'192.168.0.0/22')

	log_generator(ip_range, time_stamp, t_stamp, log_file)


if __name__ == "__main__":
        main()
