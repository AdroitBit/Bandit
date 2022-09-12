#include<sys/utsname.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
struct utsname uts;
uname(&uts);
printf("System is %s on %s hardware\n",uts.sysname, uts.machine);
printf("OS Release is %s\n",uts.release);
printf("OS Version is\n",uts.version);
}