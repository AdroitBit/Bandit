#include <stdio.h>
#include <stdlib.h>

int main(){
    int *data=(int *)malloc(sizeof(int)*100);
    data[0]=1;
    data[1]=5;
    data[2]=3;
    data[3]=4;

    for(int i=0;i<100;i++){
        printf("%d ",data[i]);
    }
    return 0;
}