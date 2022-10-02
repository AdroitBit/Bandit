#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int *arr, int arrSize){
    int i;
    for (i = 0; i < arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertion_sort(int *arr, int arrSize){
    for (int i = 1; i < arrSize; i++){
        int temp;
        int j1=i-1;
        int j2=i;
        while (j1 >= 0 && arr[j1] > arr[j2]){
            temp = arr[j1];
            arr[j1] = arr[j2];
            arr[j2] = temp;
            j1--;
            j2--;
        }
        print_array(arr, arrSize);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, n);
    //print_array(arr, n);



    return 0;
}