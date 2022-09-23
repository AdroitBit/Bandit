import getch
import os
import time
s=""
s+="Assignment Folder : "
print(s)
time.sleep(1)
while True:
    os.system("clear")
    time.sleep(0.1)
    print(s,end="")
    char = getch.getche()
    if ord(char)==127: # Backspace
        s=s[:-1]
    elif ord(char)==10: # Enter
        #print()
        break
    else:
        s+=char
# ...
#char = getch.getch() # User input, but not displayed on the screen
# or
#char = getch.getche() # also displayed on the screen


#print(ord(char))
print("Actual result : ",s)