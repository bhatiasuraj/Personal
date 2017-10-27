#!/usr/bin/python

import sys


primeList = [2]

for i in range(3,10000):

	divisor = 2

	while divisor <= i:

		if i % divisor == 0:
			break
		divisor += 1

	if i == divisor:
		primeList.append(i)

print primeList

