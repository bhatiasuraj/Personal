#!/usr/bin/python

import os
import sys


a = [5, 3, 4, 5, 7, 5, 3, 2, 1]

d = {}


for i in a:
	
	if not d.has_key(i):
		d[i] = 1
	else:
		d[i] += 1


print d



