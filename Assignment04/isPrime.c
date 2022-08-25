#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    int i;//O(1)
    for (i = 2; i<=sqrt(n); i++)//O(sqrt(n))+O(1)+O(1)
        if (n % i == 0)//O(1)
            return 0;//O(1)
    return 1;//O(1)
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", isPrime(n));
    return 0;
}
//O(sqrt(n))