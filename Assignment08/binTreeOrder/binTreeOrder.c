#include <stdio.h>
#include <stdlib.h>
#include <week8.h>

#ifndef __bin_tree__
typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif

// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header
// ...
void _print_tree(tree_t* t,int tab){
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
void print_tree(tree_t* t){
    _print_tree(t,0);
}
void _print_preorder(tree_t* t){
    if(t==NULL)
        return;
    printf("%d ",t->data);
    _print_preorder(t->left);
    _print_preorder(t->right);
}   
void print_preorder(tree_t *t) {
    _print_preorder(t);
    printf("\n");
}
void _print_inorder(tree_t* t){
    if(t==NULL)
        return;
    _print_inorder(t->left);
    printf("%d ",t->data);
    _print_inorder(t->right);
}
void print_inorder(tree_t *t) {
    _print_inorder(t);
    printf("\n");
}
void _print_postorder(tree_t* t){
    if(t==NULL)
        return;
    _print_postorder(t->left);
    _print_postorder(t->right);
    printf("%d ",t->data);
}
void print_postorder(tree_t *t) {
    _print_postorder(t);
    printf("\n");
}


int main(void) {
  tree_t *t = NULL;
  int n, i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }
  print_preorder(t);
  print_postorder(t);
  print_inorder(t);
  
  return 0;
}