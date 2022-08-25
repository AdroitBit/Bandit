#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef node_t queue_t;

queue_t* last_node(queue_t* q) {
  while (q->next != NULL) {
    q = q->next;
  }
  return q;
}

queue_t* enqueue(queue_t *q, int value){
  node_t *new_node = (queue_t*)malloc(sizeof(node_t));
  new_node->data = value;
  new_node->next = NULL;

  if (q == NULL) {
    q = new_node;
  } else {
    last_node(q)->next = new_node;
  }
  return q;
}

queue_t* dequeue(queue_t *q) {
  if (q == NULL) {
    printf("Queue is empty.\n");
    return q;
  }

  printf("%d\n", q->data);
  queue_t *temp = q;
  q = q->next;
  free(temp);
  return q;
}

int show(queue_t *q) {
  if (q == NULL) {
    printf("Queue is empty.\n");
    return -1;
  }
  while (q != NULL) {
    printf("%d ", q->data);
    q = q->next;
  }
  printf("\n");
  return 0;
}

int empty(queue_t *q) {
  if (_size(q)==0) {
    printf("Queue is empty.\n");
    return 1;
  }else{
    printf("Queue is not empty.\n");
    return 0;
  }
}

int _size(queue_t *q) {
  int size = 0;
  while (q != NULL) {
    size++;
    q = q->next;
  }
  return size;
}

int size(queue_t *q) {
  printf("%d\n", _size(q));
}


int main(){
  queue_t *q = NULL;
  int n, i, command, value;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &command);
    switch (command)
    {
    case 1:
      scanf("%d", &value);
      q = enqueue(q, value);
      break;
    case 2:
      q = dequeue(q);
      break;
    case 3:
      show(q);
      break;
    case 4:
      empty(q);
      break;
    case 5:
      size(q);
      break;
    }
  }
  return 0;
}