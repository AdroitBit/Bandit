import os
import sys
import subprocess
import time
from glob import glob
import difflib
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
assignment_folder=input("Input Your assignment folder : ")
#assignment_folder="Assignment07"
problem_name=input("Input Your problem name : ")
#problem_name="basicTree"

os.system(f"gcc -o {assignment_folder}/{problem_name}/a.out {assignment_folder}/{problem_name}/{problem_name}.c")


test_case_files=glob(f"{assignment_folder}/{problem_name}/test_cases/test_case*.txt")
#test_case_files=[
#    #f"{assignment_folder}/{problem_name}/test_cases/input11.txt",
#    #f"{assignment_folder}/{problem_name}/test_cases/input12.txt",
#    f"{assignment_folder}/{problem_name}/test_cases/input15.txt"
#]
for test_case_file in test_case_files:
    print(f"{bcolors.OKCYAN}Testing {test_case_file}{bcolors.ENDC}")
    result_test_case_file=f"{assignment_folder}/{problem_name}/test_cases/result_{os.path.basename(test_case_file)}"
    lines=open(test_case_file,"r").read().split("\n")
    all_inputs=[line[3:] for line in lines if line[0:3]=="i| "]
    all_outputs=[line[3:] for line in lines if line[0:3]=="O= "]
    with open("_temp.txt","w") as f:
        f.write("\n".join(all_inputs))
    #program_output=subprocess.Popen(f"cat _temp.txt | ./{assignment_folder}/{problem_name}/a.out",stdout=subprocess.DEVNULL).read()
    program_output=os.popen(f"cat _temp.txt | ./{assignment_folder}/{problem_name}/a.out").read()
    os.remove("_temp.txt")

    
    to_write=[]
    with open(result_test_case_file,"w") as f:
        if len(program_output)==0:
            f.write("The program can't be finished. As it can cause by Segmentation fault or other error")
        else:
            program_output_ln=program_output.split("\n")
            for line in lines:
                if line[0:3]=="i| ":
                    to_write.append(line.rstrip())
                if line[0:3]=="O= ":
                    output=program_output_ln.pop(0).rstrip()
                    to_write.append(f"O= {output}")
                    if output=="Segmentation fault":
                        break
            f.write("\n".join(to_write))


    file1=result_test_case_file
    file2=test_case_file
    compare_test_case_file=f"{assignment_folder}/{problem_name}/test_cases/compare_{os.path.basename(test_case_file)}"
    if len(program_output)!=0:
        with open(compare_test_case_file,"w") as f:
            for line in difflib.unified_diff(
                open(file1).readlines(), open(file2).readlines(), fromfile=file1,
                tofile=file2, lineterm=''):
                #print(line)
                f.write(line)
    else:
        with open(compare_test_case_file,"w") as f:
            f.write("The program can't be finished. As it can cause by Segmentation fault or other error")
    if open(compare_test_case_file,"r").read().strip()=="":
        print(f"  {bcolors.OKGREEN}Test case {test_case_file} passed{bcolors.ENDC}")
    else:
        print(f"  {bcolors.FAIL}Test case {test_case_file} failed{bcolors.ENDC}")
        os.system(f"cat {compare_test_case_file}")
        print()
    time.sleep(0.1)

#print(bcolors.BOLD,bcolors.FAIL,"GHIASDASD")


#os.chdir("Assignment07")
#c_file="basicTree.c"
#os.system(f"gcc {c_file}"+test_file)
#c_program="./a.out"
#c_inputs=["input1.txt"]
#c_inputs=[open(i).read() for i in c_input]
#for c_input in c_inputs:
#    for line in c_input.split('\n'):
#        os.popen("")