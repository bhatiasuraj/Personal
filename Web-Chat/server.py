#!/usr/bin/python

import socket
import sys
from thread import *
import select

def create_socket(TCP_PORT):

	global s_sock
	s_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	s_sock.bind(('0.0.0.0',TCP_PORT))
	s_sock.listen(10)

	return s_sock

def main():

	global host, connection_list, TCP_PORT, addr, recv_buffer
	host = 'localhost'
	TCP_PORT = 3102
	recv_buffer = 4096
	connection_list = []
		
	connection_list.append(create_socket(TCP_PORT))
	print 'Chat server started on port '+str(TCP_PORT)
	
	while True:

	        read_sockets,write_sockets,error_sockets = select.select(connection_list,[],[])

		for sock in read_sockets:
        	    if sock == s_sock:
			c, addr = s_sock.accept()
			connection_list.append(c)
			print 'Connected with '+ addr[0] + ':' +str(addr[1])+'\n'
        	         
                	broadcast_data(c, "[%s:%s] entered room\n" % addr)
             
            	    else:
 		        start_new_thread(clientthread ,(sock,))
				
def broadcast_data (c, message):

    for socket in connection_list:
        if socket != s_sock and socket != c :
            try :
                socket.send(message)
            except :
                socket.close()
                connecton_list.remove(socket)

def clientthread(c):

	while True:

		try:
			m = c.recv(1024)
			if not m:
                        	break
                	
			elif m == 'exit':
                        	print '\nClosed client '+str(addr[1])+'\n'
                        	break

                	elif m:
                        	broadcast_data(c, "\r" + '<' + str(c.getpeername()) + '> ' + m)

		except socket.error as m:
			broadcast_data(sock, "Client (%s, %s) is offline" % addr)
                        print "Client (%s, %s) is offline" % addr
                        c.close()
                        connection_list.remove(c)
                        continue

	c.close()
if __name__ == "__main__":
    main()
