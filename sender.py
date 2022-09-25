import os
from glob import glob
os.chdir(os.path.dirname(os.path.abspath(__file__)))

student_id=input("Input your student id : ")
if student_id[0]!="b":
    student_id="b"+student_id
assignment_folder=input("Input Your assignment folder : ")
print("This run the command to make sure folder exists")
os.system(f"""
    ssh {student_id}@adt.mikelab.net "mkdir -p {assignment_folder}"
""")

for problem_name in sorted(glob(f"{assignment_folder}/*")):
    file=glob(f"{problem_name}/*.c")[0]
    print(problem_name,file)

    os.system(f"""
        scp {file} {student_id}@adt.mikelab.net:/home/b64/{student_id}/{assignment_folder}/
    """)
    print(file)
    #print(problem_name)