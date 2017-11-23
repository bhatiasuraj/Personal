#!/usr/bin/python

import os
import math


def factorial(num):

	if num == 0:
		return 1

	else:
		
		#return math.factorial(num)
		#return factorial(num-1) * num


num = int(raw_input("Enter number: "))

print factorial(num)

