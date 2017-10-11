import re
import sys

for i in range(int(raw_input())):
    number = raw_input()

    if len(number) != 10:
        print ("NO")

    else:
        if bool(re.match(r'^[7-9]{1,10}[0-9]{1,9}$', number)):
            print ("YES")
        else:
            print ("NO")
