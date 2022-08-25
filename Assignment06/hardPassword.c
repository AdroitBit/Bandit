#include <stdio.h>
#include <stdlib.h>
//1q2w3e4rxr4e3w2q1y : valid
//1q2w3e4rx1q2w3e4ry : invalid
//1q2w3e4rx1q2w3ey : invalid


int is_valid(char *str){
    unsigned long long ix=0;
    while(str[ix]!='x'){
        ++ix;
    }

    for(unsigned long long i=1;1;i++){
        //if(ix+i>l-1){
        //    return 0;
        //}
        if(str[ix+i]=='y'){
            return 1;
        }
        else if(str[ix-i]!=str[ix+i]){
            return 0;
        }
    }

    return 0;
}

int main(){
    char password[1000000];
    scanf("%s", password);

    printf("%d\n", is_valid(password));


    //FILE *out=fopen("name_of_file.txt","w");
	//fputs("Hello File",out);
	//fclose(out);

    return 0;
}