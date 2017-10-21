#!/usr/bin/python

import sys, os

row = []
column = []

file = open("file.txt", "r")
for line in file:

	row.append(line.split(' ')[0])
	column.append(line.split()[1])

for item in row:
	sys.stdout.write(item+' ')
	sys.stdout.flush()

print " "

for item2 in column:
	sys.stdout.write(item2+' ')
	sys.stdout.flush()
print " "
