#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node {
  int data;
  int height;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t avl_t;
#endif

// Write your code here
// ** Note that the print_tree() function
// has been implemented already and
// included in the week9.h header
// ...
avl_t* single_rotate_with_left(avl_t* k2){
    avl_t* k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->left),k2->height)+1;
    return k1;
}
avl_t* single_rotate_with_right(avl_t* k2){
    avl_t* k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->right),k2->height)+1;
    return k1;
}
avl_t* double_rotate_with_left(avl_t* k3){
    k3->left=single_rotate_with_right(k3->left);
    return single_rotate_with_left(k3);
}
avl_t* double_rotate_with_right(avl_t* k3){
    k3->right=single_rotate_with_left(k3->right);
    return single_rotate_with_right(k3);
}

avl_t* insert(avl_t *t, int data) {
  if (t == NULL) {
    t = (avl_t*)malloc(sizeof(avl_t));
    t->data = data;
    t->height = 0;
    t->left = NULL;
    t->right = NULL;
  } else if (data < t->data) {
    t->left = insert(t->left, data);
    if (height(t->left) - height(t->right) == 2) {
      if (data < t->left->data) {
        t = single_rotate_with_left(t);
      } else {
        t = double_rotate_with_left(t);
      }
    }
  } else if (data > t->data) {
    t->right = insert(t->right, data);
    if (height(t->right) - height(t->left) == 2) {
      if (data > t->right->data) {
        t = single_rotate_with_right(t);
      } else {
        t = double_rotate_with_right(t);
      }
    }
  }
  t->height = max(height(t->left), height(t->right)) + 1;
  return t;
}

int height(avl_t* t){
    if(t==NULL){
        return -1;
    }else{
        return t->height;
    }
}
int max(int a,int b){
    return a>b?a:b;
}
avl_t* delete(avl_t* t, int data) {
  if (t == NULL) {
    return NULL;
  } else if (data < t->data) {
    t->left = delete(t->left, data);
    if (height(t->right) - height(t->left) == 2) {
      if (height(t->right->left) > height(t->right->right)) {
        t = double_rotate_with_right(t);
      } else {
        t = single_rotate_with_right(t);
      }
    }
  } else if (data > t->data) {
    t->right = delete(t->right, data);
    if (height(t->left) - height(t->right) == 2) {
      if (height(t->left->right) > height(t->left->left)) {
        t = double_rotate_with_left(t);
      } else {
        t = single_rotate_with_left(t);
      }
    }
  } else {
    if (t->left != NULL && t->right != NULL) {
      avl_t* tmp = t->right;
      while (tmp->left != NULL) {
        tmp = tmp->left;
      }
      t->data = tmp->data;
      t->right = delete(t->right, t->data);
    } else {
      avl_t* tmp = t;
      if (t->left == NULL) {
        t = t->right;
      } else if (t->right == NULL) {
        t = t->left;
      }
      free(tmp);
    }
  }
  if (t != NULL) {
    t->height = max(height(t->left), height(t->right)) + 1;
  }
  return t;
}


int main(void) {
  avl_t *t = NULL;
  int n, i;
  int command, data;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &command);
    switch (command) {
    case 1:
      scanf("%d", &data);
      t = insert(t, data);
      break;
    case 2:
      scanf("%d", &data);
      t = delete (t, data);
      break;
    case 3:
      print_tree(t);
      break;
    }
  }
  return 0;
}