#!/usr/bin/python

import os

print os.path.getmtime('fileTimes.py')
print os.path.getctime('fileTimes.py')

stat = os.stat('fileTimes.py')
try:
	print stat.st_birthtime
except AttributeError:
	print stat.st_mtime
