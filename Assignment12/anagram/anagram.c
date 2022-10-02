#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX_LEN 50


char* sort(char* astr){//insertion sort
    
    char* str=(char*)malloc(WORD_MAX_LEN*sizeof(char));
    strcpy(str,astr);

    for(int i=1;i<strlen(str);i++){
        char temp;
        int j1=i-1;
        int j2=i;
        while(j1>=0 && str[j1]>str[j2]){
            temp=str[j1];
            str[j1]=str[j2];
            str[j2]=temp;
            j1--;
            j2--;
        }
    }

    //for (int i = 0; i < strlen(str); i++){
    //    char temp;
    //    for (int j = i + 1; j < strlen(str); j++){
    //        if (str[i] > str[j]){
    //            temp = str[i];
    //            str[i] = str[j];
    //            str[j] = temp;
    //        }
    //    }
    //}

    return str;
}

int main(){
    char** str_dict;//dictionary
    //char** sorted_dict;

    int m,n;
    scanf("%d %d", &m, &n);
    str_dict=(char**)malloc(m*sizeof(char*));
    for(int i=0;i<m;i++){
        str_dict[i]=(char*)malloc(WORD_MAX_LEN*sizeof(char));
        scanf("%s",str_dict[i]);
    }
    for(int i=0;i<n;i++){
        char str[WORD_MAX_LEN];
        scanf("%s", str);
        for(int j=0;j<m;j++){
            if(strcmp(sort(str),sort(str_dict[j]))==0){
                printf("%s ", str_dict[j]);
            }
        }
        printf("\n");
    }
    return 0;

}