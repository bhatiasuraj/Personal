#!/usr/bin/python


import sys, os

count = 0
while (os.fork() > 0):
	count += 1
	print count

