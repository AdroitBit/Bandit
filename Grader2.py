assignment_folder=input("Input Your assignment folder : ")
problem_name=input("Input Your problem name : ")


import os
import sys
import subprocess
import time
from glob import glob
import difflib
import time
os.system("clear")
os.chdir(os.path.dirname(os.path.abspath(__file__)))

from html.parser import HTMLParser


os.system(f"gcc -o {assignment_folder}/{problem_name}/a.out {assignment_folder}/{problem_name}/{problem_name}.c")


test_case_files=glob(f"{assignment_folder}/{problem_name}/test_cases/test_case*.xml")
test_case_files.sort() 
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

class MyHTMLParser(HTMLParser):
    def __init__(self):
        super().__init__()
        self.state_input=False
        self.mode="feed_test_case"
        
        self.test_case_inputs=[]
        self.test_case_outputs=[]
        self.test_data=None

        self._program_outputs=[]
        self._result_xml=""
    def handle_starttag(self, tag, attrs):
        if self.mode=="feed_test_case":
            if tag=="i":
                self.state_input=True
        if self.mode=="result_xml":
            if tag=="i":
                self._result_xml+="<i>"
                self.state_input=True

    def handle_endtag(self, tag):
        if self.mode=="feed_test_case":
            if tag=="i":
                self.state_input=False
        if self.mode=="result_xml":
            if tag=="i":
                self._result_xml+="</i>\n"
                self.state_input=False

    def handle_data(self, data):
        if self.mode=="feed_test_case":
            if self.state_input:
                self.test_case_inputs.append(data)
            else:
                self.test_case_outputs.append(data)
        if self.mode=="result_xml":
            if self.state_input:
                self._result_xml+=data
            else:
                self._result_xml+=self._program_outputs.pop(0)
            self._result_xml+=data
    def feed_test_case(self,data):
        self.mode="feed_test_case"
        self.test_data=data
        data=data.replace("</i>\n","\n</i>")
        self.feed(data)
    def result_xml(self,program_outputs):
        self.mode="result_xml"
        self._program_outputs=program_outputs.split("\n")
        print(self._program_outputs)
        self._result_xml=""
        self.feed(self.test_data)
        return self._result_xml#.replace("<i></i>",f"<i>{program_output}</i>")


#parser.feed(open("test_case1.xml","r").read())
#parser.inputs



for test_case_file in test_case_files:
    print(f"{bcolors.OKCYAN}Testing {test_case_file}{bcolors.ENDC}")
    parser = MyHTMLParser()
    parser.feed_test_case(open(test_case_file,"r").read())

    with open("_temp.txt","w") as f:
        f.write("".join(parser.test_case_inputs).rstrip())
    program_output=os.popen(f"cat _temp.txt | ./{assignment_folder}/{problem_name}/a.out").read()
    #os.remove("_temp.txt")

    result_test_case_file=f"{assignment_folder}/{problem_name}/test_cases/result_{os.path.basename(test_case_file)}"
    #print(parser.result_xml(program_output))
    with open(result_test_case_file,"w") as f:
        if len(program_output)==0:
            f.write("No output")
        else:
            f.write(parser.result_xml(program_output))
            #print(parser.result_xml(program_output))
#
#
    #print(program_output)

    #print(parser.inputs)
    #parser
    #print(parser.print_outputs)









