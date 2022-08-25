#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000


int max(int num1, int num2){
    return (num1 > num2 ) ? num1 : num2;
}

char *strrev(char *str){
    char *p1, *p2;
    if (! str || ! *str)return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}


typedef struct big_int {
    int digits_len;
    unsigned char digits[MAX_SIZE];
} big_int_t;
big_int_t create_null(){
    big_int_t r;
    r.digits_len = 0;
    for(int i=0;i<MAX_SIZE;i++){
        r.digits[i]=0;
    }
    return r;
}

big_int_t create(char* n){
    big_int_t r=create_null();
    char rn[MAX_SIZE];
    strcpy(rn,n);
    strrev(rn);
    r.digits_len=strlen(rn);
    for(int i=0;i<r.digits_len;++i){
        r.digits[i]=rn[i]-'0';
    }
    return r;
}



big_int_t add(big_int_t a, big_int_t b){
    big_int_t r=create_null();
    for(int i=0;i<max(a.digits_len,b.digits_len);++i){
        r.digits[i]+=a.digits[i]+b.digits[i];
        r.digits_len=i+1;
        if(r.digits[i]>=10){
            r.digits[i+1]=r.digits[i]/10;
            r.digits[i]=r.digits[i]%10;
            r.digits_len=i+2;
        }

        
    }
    return r;
}

big_int_t print(big_int_t a){
    for(int i=a.digits_len-1;i>=0;--i){
        printf("%d",a.digits[i]);
    }
    return a;
}

big_int_t just_print(big_int_t a){
    for(int i=0;i<a.digits_len;++i){
        printf("%d ",a.digits[i]);
    }
    return a;
}

int main(){
    char sa[MAX_SIZE],sb[MAX_SIZE];
    scanf("%s",sa);
    scanf("%s",sb);

    big_int_t a=create(sa);
    big_int_t b=create(sb);
    print(add(a,b));
    return 0;
}