#!/usr/bin/python

import os
import sys

numString = ''

while True:

	num = int(raw_input())

	if num == 1:
		numString += '1'

	elif num == 0:
		numString = '0' + numString

	print str(num)+' '+numString
