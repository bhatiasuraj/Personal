#!/usr/bin/python

import sys, os

for i in range(0, 100):

	if i % 3 == 0 and i % 5 == 0:
		print "fuzzbuzz"
	elif i % 3 == 0:
		print "fuzz"
	elif i % 5 == 0:
		print "buzz"
	else:
		print i


