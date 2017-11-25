#!/usr/bin/python

import os
import sys
from itertools import permutations


def checkPalindrome(string1):
	perms = [''.join(p) for p in permutations(string1)]

	for item in perms:
		if item == item[::-1]:
			# print "Given String "+string1+" can be used to create a palindrome"
			return True
	return False

string1 = raw_input("Enter string: ")

print checkPalindrome(string1)



