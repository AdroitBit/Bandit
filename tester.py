import os
import sys
import subprocess
import time
os.chdir(os.path.dirname(os.path.abspath(__file__)))

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
print(bcolors.BOLD,bcolors.FAIL,"GHIASDASD")


#os.chdir("Assignment07")
#c_file="basicTree.c"
#os.system(f"gcc {c_file}"+test_file)
#c_program="./a.out"
#c_inputs=["input1.txt"]
#c_inputs=[open(i).read() for i in c_input]
#for c_input in c_inputs:
#    for line in c_input.split('\n'):
#        os.popen("")