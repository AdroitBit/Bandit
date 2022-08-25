#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* append(node_t* startNode,int val){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = val;
    newNode->next = NULL;
    if(startNode == NULL){
        return newNode;
    }
    node_t* curr = startNode;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    return startNode;
}
node_t* get(node_t* startNode,int idx){
    node_t* curr = startNode;
    for(int i=0;i<idx;++i){
        curr = curr->next;
    }
    printf("%d\n",curr->data);
    return curr;
}
node_t* show(node_t* startNode){
    node_t* curr = startNode;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}
node_t* reverse(node_t* startNode){
    int temp[100];
    int i=0;
    node_t* curr = startNode;
    while(curr != NULL){
        temp[i++] = curr->data;
        curr = curr->next;
    }

    curr=startNode;
    for(int j=i-1;j>=0;--j){
        curr->data = temp[j];
        curr = curr->next;
    }

    return startNode;
}
node_t* cut(node_t* startNode,int idx1,int idx2){
    node_t* curr = startNode;
    for(int i=0;i<idx1;++i){
        curr = curr->next;
    }
    //curr is now what returned
    node_t* temp = curr;
    for(int i=0;i<idx2-idx1;++i){
        temp = temp->next;
    }
    temp->next = NULL;
    return curr;
}

void print_all_char(char* str){
    for(int i=0;i<5;i++){
        printf("%d\n",str[i]);
    }
}


int main() {
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf(" %c",&command);
        //print_all_char(&command);
        int val;
        int idx;
        int idx1,idx2;
        switch(command) {
            case 'A':
                scanf("%d",&val);
                startNode = append(startNode,val);
                break;
            case 'G':
                scanf("%d",&idx);
                get(startNode,idx);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                scanf("%d %d",&idx1,&idx2);
                startNode = cut(startNode,idx1,idx2);
                break;
            default:
                break;
            }
    }
    return 0;
}