#!/usr/bin/python


import os, sys


file1 = open('file_1.txt', 'r')

checkString = "I am Suraj Bhatia"

line_count = 0

string_count = 0

for line in file1:

	line = line.strip('\n')

	line_count += 1

	if line == checkString:
		string_count += 1


print "Total number of matching lines: "+str(string_count)+" out of "+str(line_count)+" lines"

print "Percentage of matching line = "+str((float(string_count)/float(line_count)) * 100)
