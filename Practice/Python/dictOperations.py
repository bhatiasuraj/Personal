#!/usr/bin/python

import operator

d = {0:10, 4:1, 1:2, 4:1}

d2 = {6:10, 7:1, 8:2, 9:1}

d3 = {10:10, 11:1, 12:2, 13:1}

d4 = {}

d.update({2:40})

d[5] = 30

print "Value of biggest key: " + str(d[max(d.keys())])

print "Biggest key: " + str((max(d)))

print "Biggest Value: " + str(max(d.values()))

# sorted_d = sorted(d.items(), key=operator.itemgetter(0))

sorted_d = sorted(d.items())

print 'Dictionary in ascending order of value: ', sorted_d

rsorted_d = sorted(d.items(), reverse=True)

print 'Dictionary in descending order of value: ', rsorted_d

for i in (d, d2, d3): d4.update(i)

i = 4

if i in d4:
	print "exists!"

print d4

print d
