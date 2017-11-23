#!/usr/bin/python

import os
import sys
import collections


a = [5, 3, 4, 5, 7, 5, 3, 2, 1, 5, 3, 4, 5, 7, 5, 3, 2, 1, 6, 23, 56, 67, 88, 23, 4, 5, 3, 4, 5, 7, 5, 3, 2, 1]

d = {}


for i in a:
	
	if not d.has_key(i):
		d[i] = 1
	else:
		d[i] += 1
count = 0

print d

print "Duplicate numbers: "
for num, inst in d.iteritems():
	if inst > 1:
		print num
		count += 1

print "Number of Duplicate numbers: "+str(count)
