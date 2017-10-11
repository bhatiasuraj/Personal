#!/usr/bin/python


import sys
import re

testCases = raw_input()

numList = []

for i in range(0, int(testCases)):
	numList.append(raw_input())


for i in numList:

	print bool(re.match(r'^[-+]?[0-9]*\.[0-9]+$' , i))
