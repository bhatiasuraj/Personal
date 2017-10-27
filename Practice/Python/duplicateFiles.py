#!/usr/bin/python

from os import listdir
from os.path import isfile, join
import collections

mypath="/home/sbhatia/git/Personal/Practice"

files = [f for f in listdir(mypath) if isfile(join(mypath, f))]

print files

checkedFiles = set()

uniqFiles = []

for f in files:
	if f not in checkedFiles:
		uniqFiles.append(f)
		checkedFiles.add(f)

print uniqFiles
