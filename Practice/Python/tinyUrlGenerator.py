#!/usr/bin/python

import os
import sys
import string
import random

charDB = string.ascii_letters + '0123456789'

url2code = {}
code2url = {}

while True:
	longUrl = raw_input("Enter URL: ")

	if longUrl == 'q':
		sys.exit("BYE")

	while longUrl not in url2code:

		code = ''.join(random.choice(charDB) for _ in range(6))

		if code not in code2url:
			code2url[code] = longUrl
			url2code[longUrl] = code
			print "http://tinyurl.com/"+url2code[longUrl]


