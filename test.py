import sys
import path


def increase_rightest(a,n):
    for i in range(len(a)-1,0,-1):
        if a[i]!=0:
            break
    a[i]+=n;
    return a
def modify_rightest(a,n):
    for i in range(len(a)-1,0,-1):
        if a[i]!=0:
            break
    a[i]=n;
    return a


a=[0]*12
ans=0;
while a[0]<20:
    if sum(a)==20:
        print(" ".join(map(str,a)))
        #a[-1]+=15
        #a=increase_rightest(a, 1)
        a=modify_rightest(a, 21)
        ans+=1
    elif sum(a)>20:
        a=increase_rightest(a, 1)
    else:
        a[-1]+=1
    for i in range(11,0,-1):
        a[i-1]+=a[i]//21
        a[i]=a[i]%21
    #if ans>200:
    #    break 
print(ans)