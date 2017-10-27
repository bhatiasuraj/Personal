#!/usr/bin/python

def is_sub(s, i, i_len, s_len):

	x = 0

	y = 0

	while x < i_len and y < s_len:

		if s[x] == i[y]:

			x += 1
		y += 1

	return (x == i_len)


for i in range(int(raw_input())):

	no_of_items = raw_input()

	items = raw_input().split(' ')

	match_string = raw_input()

	string_len = len(match_string)

	maxi = 0

	for i in items:

		m = len(i)

		if is_sub(match_string, i, m, string_len) and m > maxi:
			maxi = m
			answer = i

print answer


