#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t bst_t;//binary search tree

//Write you code here
bst_t* insert(bst_t* t,int data){
    if(t==NULL){
        t=(bst_t*)malloc(sizeof(bst_t));
        t->data=data;
        t->left=NULL;
        t->right=NULL;
    }else if(data<t->data){
        t->left=insert(t->left,data);
    }else if(data>t->data){
        t->right=insert(t->right,data);
    }
    return t;
}
bst_t* delete(bst_t* t,int data){
    if(t==NULL){
        return t;
    }else if(data<t->data){
        t->left=delete(t->left,data);
    }else if(data>t->data){
        t->right=delete(t->right,data);
    }else{
        if(t->left==NULL){
            bst_t* temp=t->right;
            free(t);
            return temp;
        }else if(t->right==NULL){
            bst_t* temp=t->left;
            free(t);
            return temp;
        }
        bst_t* temp=t->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        t->data=temp->data;
        t->right=delete(t->right,temp->data);
    }
    return t;
}
int find(bst_t* t,int data){
    if(t==NULL){
        return 0;
    }else if(data<t->data){
        return find(t->left,data);
    }else if(data>t->data){
        return find(t->right,data);
    }else{
        return 1;
    }
}
int find_min(bst_t* t){
    if(t==NULL){
        return -1;
    }else if(t->left==NULL){
        return t->data;
    }else{
        return find_min(t->left);
    }
}
int find_max(bst_t* t){
    if(t==NULL){
        return -1;
    }else if(t->right==NULL){
        return t->data;
    }else{
        return find_max(t->right);
    }
}
void _print_tree(bst_t* t,int tab){
    for(int i=0;i<tab;i++){
        printf("    ");
    }
    printf("%d\n",t->data);
    if(t->left!=NULL){
        _print_tree(t->left,tab+1);
    }else{
        for(int i=0;i<tab;i++){
            printf("    ");
        }
        printf("\n");
    }
    if(t->right!=NULL){
        _print_tree(t->right,tab+1);
    }
}
void print_tree(bst_t* t){
    _print_tree(t,0);
}


int main(void){
    bst_t* t = NULL;
    int n,i;
    int command,data;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&command);
        switch(command){
            case 1:
                scanf("%d",&data);
                t = insert(t,data);
                break;
            case 2:
                scanf("%d",&data);
                t=delete(t,data);
                break;
            case 3:
                scanf("%d",&data);
                printf("%d\n",find(t,data));
                break;
            case 4:
                printf("%d\n",find_min(t));
                break;
            case 5:
                printf("%d\n",find_max(t));
                break;
        }
    }
    //print_tree(t);
    return 0;
}