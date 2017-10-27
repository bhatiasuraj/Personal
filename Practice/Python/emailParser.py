#!/usr/bin/python


import email.utils
import re


for i in range(int(raw_input())):

        parseList = email.utils.parseaddr(raw_input())

        if bool(re.match('[a-zA-Z](\w|-|\.)*@[a-zA-Z]*\.[A-Za-z]{0,3}$', parseList[1])):
                print email.utils.formataddr(parseList)
