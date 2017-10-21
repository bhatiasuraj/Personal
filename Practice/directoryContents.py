#!/usr/bin/python

import os


pathName = "/home/sbhatia/git/Personal/Practice"


def osWalk(pathName):

	for root, dirs, files in os.walk(".", topdown=False):
		for name in files:
			print os.path.join(root, name)
		for name in dirs:
			print os.path.join(root, name)

def noOSWalk(sPath):

	for sChild in os.listdir(sPath):
		sChildPath = os.path.join(sPath, sChild)
		if os.path.isdir(sChildPath):
			noOSWalk(pathName)
		else:
			print sChildPath



#osWalk(pathName)
noOSWalk(pathName)

