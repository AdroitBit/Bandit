#include <stdio.h>
#include <stdlib.h>
#include <week8.h>
/*
#if __has_include("week8.h")
#include "week8.h"
#endif
#if __has_include(<week8.h>)
#include <week8.h>
#endif
*/


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
int have_l(tree_t *t) {
    if (t->left != NULL)
        return 1;
    else return 0;
}
int have_r(tree_t *t) {
    if (t->right != NULL)
        return 1;
    else return 0;
}
int is_full(tree_t* t){//left and right is not None
    if(t==NULL)
        return 0;
    if(!have_l(t) && !have_r(t))
        return 1;
    if(have_l(t) && have_r(t))
        return is_full(t->left) && is_full(t->right);
    return 0;
}

int depth(tree_t *t) {
  int d = 0;
  while (t != NULL) {
    d++;
    t = t->left;
  }
  return d;
}
// Check if the tree is perfect
int is_Perfect(tree_t *t, int d, int level) {
    // Check if the tree is empty
  if (t == NULL)
    return 1;

  // Check the presence of children
  if (t->left == NULL && t->right == NULL)
    return (d == level + 1);

  if (t->left == NULL || t->right == NULL)
    return 0;

  return is_Perfect(t->left, d, level + 1) &&
       is_Perfect(t->right, d, level + 1);
}
// Wrapper function
int is_perfect(tree_t *t) {
  int d = depth(t);
  return is_Perfect(t, d, 0);
}


int countNumNodes(tree_t* t){
    if(t == NULL)
        return 0;
    return 1 + countNumNodes(t->left) + countNumNodes(t->right);
}

// Check if the tree is a complete binary tree
int checkComplete(tree_t *t, int index, int numberNodes) {
  // Check if the tree is complete
  if (t == NULL)
    return 1;

  if (index >= numberNodes)
    return 0;

  return (checkComplete(t->left, 2 * index + 1, numberNodes) && checkComplete(t->right, 2 * index + 2, numberNodes));
}
int is_complete(tree_t* t){
    return checkComplete(t, 0, countNumNodes(t));
}
int is_degenerate(tree_t* t){
    if(t==NULL)
        return 0;
    if(t->left==NULL && t->right==NULL)
        return 1;
    if(t->left!=NULL && t->right==NULL)
        return is_degenerate(t->left);
    if(t->left==NULL && t->right!=NULL)
        return is_degenerate(t->right);
    if(t->left!=NULL && t->right!=NULL)
        return 0;
    return 0;
}
int _is_skewed(tree_t* t, int side){//side=0 left , side=1 right
    if(t==NULL)
        return 0;
    if(t->left==NULL && t->right==NULL)
        return 1;
    if(side==0 && have_l(t) && !have_r(t)){
        return _is_skewed(t->left, 0);
    }
    if(side==1 && !have_l(t) && have_r(t)){
        return _is_skewed(t->right, 1);
    }
    return 0;
}
int is_skewed(tree_t* t){
    return _is_skewed(t,0) || _is_skewed(t,1);
}

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
  //print_tree(t);

  printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

  return 0;
}