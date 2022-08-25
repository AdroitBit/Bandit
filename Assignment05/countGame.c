#include <stdio.h>
#include <stdlib.h>

int is_contain(int n, int digit) {
    while(n>0){
        if(n % 10 == digit){
            return 1;
        }
        n /= 10;
    }
    return 0;
}

int main(){
    int n, k, count=0,n_out=0;
    scanf("%d %d", &n, &k);

    int *limit = (int *)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) {
        scanf("%d", limit+i);
    }

    for(int i=0;n_out<n-1;++i){
        if(i>=n){
            i=0;
        }
        if(limit[i]>-1){
            ++count;
            if(count%k==0||is_contain(count,k)){
                --limit[i];
            }
            if(limit[i]==-1){
                ++n_out;
            }
        }
    }

    for (int i=0;i<n;i++) {
        if (limit[i]>-1){
            printf("%d\n", i+1);
            break;
        }
    }

    return 0;
}