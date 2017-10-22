#!/usr/bin/python


import os, sys


with open('file_1.txt', 'r') as file1:
	with open('file_2.txt', 'r') as file2:
		same = set(file1).intersection(file2)


same.discard("\n")
same.discard(" ")

print same

with open('output.txt', 'w') as fileout:
	for line in same:
		fileout.write(line)


