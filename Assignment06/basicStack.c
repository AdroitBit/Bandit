#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t* push(stack_t* s, int value) {
  node_t *new_node = (stack_t*)malloc(sizeof(node_t));
  if (new_node == NULL) {
    return -1;
  }
  new_node->data = value;
  new_node->next = s;
  s = new_node;
  return s;
}

int top(stack_t* s) {
  if(_size(s) == 0) {
    printf("Stack is empty.\n");
  }
  if (s == NULL) {
    return -1;
  }
  printf("%d\n", s->data);
  return s->data;
}

stack_t* pop(stack_t* s) {
  if (s == NULL) {
    return s;
  }
  stack_t *temp = s;
  return temp->next;
}

int empty(stack_t* s) {
  if(_size(s) == 0) {
    printf("Stack is empty.\n");
  }else{
    printf("Stack is not empty.\n");
  }
}

int _size(stack_t* s) {
  int size = 0;
  while (s != NULL) {
    size++;
    s = s->next;
  }
  return size;
}

int size(stack_t* s) {
  printf("%d\n", _size(s));
}



int main(void) {
  stack_t *s = NULL;
  int n, i, command, value;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &value);
        s = push(s, value);
        break;

      case 2:
        top(s);
        break;

      case 3:
        s = pop(s);
        break;

      case 4:
        empty(s);
        break;

      case 5:
        size(s);
        break;

      default:
        break;
    }
  }

  return 0;
}