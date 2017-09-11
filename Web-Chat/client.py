#!/usr/bin/python

import sys, select, string, socket

def prompt():
	sys.stdout.write(sys.argv[1]+': ')
	sys.stdout.flush()

def main():

	host = socket.gethostname()
	port = 3102

	c_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	c_sock.settimeout(5)
	try:
		c_sock.connect((host,port))
	except:
		print 'Unable to connect, try again.'
		sys.exit()
	
	print 'Connected to Server. '
	prompt()

	while True:
	
		socket_list = [sys.stdin, c_sock]
		read_sockets, write_sockets, error_sockets = select.select(socket_list , [], [])
	
		for sock in read_sockets:
			if sock == c_sock:
				try:
		                	r = c_sock.recv(1024)
		        	except:
		               		print 'Disconnected'
		                	break
				if not r:
					print '\nConnection lost'
					sys.exit()
				else:
					sys.stdout.write('\n'+r)
					prompt()
			else:
		        	message = sys.stdin.readline()
				if message == 'exit':
					print 'Connection terminated\n'
					c_sock.send(message)
					c_sock.close()
					sys.exit()
				else:
					c_sock.send(message)
					prompt()
	
if __name__ == "__main__":
    main()
