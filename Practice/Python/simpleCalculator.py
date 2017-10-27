#!/usr/bin/python

import sys



def Add(n1, n2):
	try:
		return int(n1)+int(n2)
	except ValueError:
		return "Invalid number"
	except KeyboardInterrupt:
		sys.exit("\nExit program")

def Multiply(n1, n2):
	try:
		return n1*n2
	except ValueError:
		return "Invalid number"
	except KeyboardInterrupt:
		sys.exit("\nExit program")

def main():

	try:
		while True:

			print ("Options: \n1. Addition (1) \n2. Multiply (2) \n3. Exit (q)\n")

			operation = raw_input("Choose operation: ")

			if operation == 'q':
				sys.exit("Exit program")

			try:
				num1 = raw_input("Enter first number: ")
				num2 = raw_input("Enter second number: ")

			except ValueError:
                		return "Invalid number"

			if operation == '1':
				print Add(num1, num2)

			elif operation == '2':
				print Multiply(num1, num2)

			elif operation == 'q':
				sys.exit("\nExit program")

			else:
				print "Invalid operation, try again"

	except KeyboardInterrupt:
		sys.exit("\nExit program")


if __name__ == "__main__":
    main()

