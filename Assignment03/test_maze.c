#include <stdio.h>
int print_square(int* a,int w,int h){
    for(int i=0;i<w;i++){
        for(int j=0;j<w;j++){
            printf("%4d",a[i*w+j]);
        }
        printf("\n");
    }
}
int main(){
    int h,w;
    scanf("%d",&h);w=h;
    int a[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            a[i][j]=2;
        }
    }
    print_square(a[0],w);
    return 0;
}