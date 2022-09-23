#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;
} heap_t;


heap_t *init_heap(int size) {
    heap_t *heap = (heap_t *) malloc(sizeof(heap_t));
    heap->data = (int *) malloc(sizeof(int) * size);
    heap->last_index = 0;
    return heap;
}



heap_t* insert(heap_t *heap, int data){
    heap->last_index++;
    heap->data[heap->last_index] = data;
    int i = heap->last_index;
    while (i > 1 && heap->data[i] > heap->data[i / 2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[i / 2];
        heap->data[i / 2] = temp;
        i /= 2;
    }
    return heap;
}
int delete_max(heap_t *heap){
    int max = heap->data[1];
    heap->data[1] = heap->data[heap->last_index];
    heap->last_index--;
    int i = 1;
    while (i * 2 <= heap->last_index) {
        int max_index = i;
        if (heap->data[i] < heap->data[i * 2]) {
            max_index = i * 2;
        }
        if (i * 2 + 1 <= heap->last_index && heap->data[max_index] < heap->data[i * 2 + 1]) {
            max_index = i * 2 + 1;
        }
        if (max_index == i) break;
        int temp = heap->data[i];
        heap->data[i] = heap->data[max_index];
        heap->data[max_index] = temp;
        i = max_index;
    }
    return max;

}
int find_max(heap_t *heap){
    int n;
    if(heap->last_index == -1 || heap->last_index == 0){
        return -1;
    }
    n = heap->data[1];
    for (int i = 1; i <= heap->last_index; i++) {
        if (heap->data[i] > n) {
            n = heap->data[i];
        }
    }
    return n;
}

int update_key(heap_t *heap, int old_value, int new_value){
    int index;
    for (int i = 1; i <= heap->last_index; i++) {
        //printf("%d ",heap->data[i]);
        if (heap->data[i] == old_value) {
            index=i;
            //heap->data[i] = new_value;
            break;
        }
    }
    if(index > heap->last_index){
        return -1;
    }
    heap->data[index] = new_value;
    int i = index;
    while (i > 1 && heap->data[i] > heap->data[i / 2]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[i / 2];
        heap->data[i / 2] = temp;
        i /= 2;
    }
    return 0;
}


int bfs(heap_t *heap){
    for (int i = 1; i <= heap->last_index; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main(void){
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;

    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i=0; i<n; i++){
        scanf("%d", &command);
        switch(command){
            case 1:
                scanf("%d", &data);
                insert(max_heap, data);
                break;
            case 2:
                delete_max(max_heap);
                break;
            case 3:
                printf("%d\n", find_max(max_heap));
                break;
            case 4:
                scanf("%d %d", &old_key, &new_key);
                update_key(max_heap, old_key, new_key);
                break;
            case 5:
                bfs(max_heap);
                break;
        }
    }
    return 0;
}