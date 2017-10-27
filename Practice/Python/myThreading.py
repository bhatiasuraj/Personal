#!/usr/bin/python

import threading
import time


class myThread (threading.Thread):
	def __init__(self, threadID, threadName, counter):
		threading.Thread.__init__(self)
		self.threadID = threadID
		self.threadName = threadName
		self.counter = counter

	def run(self):
		print ("Starting thread " + self.threadName)
		threadLock.acquire()
		printTime(self.threadName, self.counter, 3)
		threadLock.release()

def printTime(threadName, delay, counter):
	while counter:
		time.sleep(delay)
		print ("%s: %s" % (threadName, time.ctime(time.time())))
		counter -= 1


threadLock = threading.Lock()

threads = []

# Create new threads

thread1 = myThread(1, "Thread-1", 1)
thread2 = myThread(2, "Thread-2", 2)

# Start new threads
thread1.start()
thread2.start()

threads.append(thread1)
threads.append(thread2)

for t in threads:
	t.join()

print ("Exiting all threads!")
