#!/usr/bin/python

import os
import sys

arr = [1, 2, 3, 4, 5, 6, 5, 4, 3, 4, 5, 6, 7]

num = int(raw_input("enter number: "))

index = arr[-1] - num

if index > 0:
	if arr[index] == num:
		print "Number found at position "+str(index)

	else:
		while index <= len(arr):

			diff = num - arr[index]
			index += diff

			if arr[index] == num:

				print "Number found at position "+str(index)

				sys.exit()

			else:
				continue


elif index == 0:
	if arr[-1] == num:
		print "Number found at position "+str(len(arr) +1)


else:
	print "Number not in array"


