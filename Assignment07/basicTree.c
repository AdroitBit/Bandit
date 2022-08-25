#include <stdio.h>
#include <stdlib.h>

// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
typedef struct node {
    int value;
    tree_t* first_child;
    tree_t* next_sibling;
} node_t;
typedef node_t tree_t;

// Write your code here
// ...
tree_t* attach(tree_t* t,int parent,int child);//parent node,and child node
tree_t* detach(tree_t* t,int node);
tree_t* search(tree_t* t,int node);
tree_t* degree(tree_t* t,int node);//amount of children nodes
int is_root(tree_t* t,int node);//node เป้นตัวรากมั๊ย
int is_leaf(tree_t* t,int node);//node เป็นตัวล่างสุดมั๊ย
void siblings(tree_t* t,int node);//แฝด : parent แล้ว children เลย
int depth(tree_t* t,int node);//
void print_path(tree_t* t,int start,int end);
int path_length(tree_t* t,int start,int end);
void ancestor(tree_t* t,int node);
void descendant(tree_t* t,int node);
void bfs(tree_t* t);
void dfs(tree_t* t);
void print_tree(tree_t* t);

tree_t* create_node(int value){
    tree_t* new_t=(tree_t*)malloc(sizeof(tree_t));
    new_t->value=value;
    new_t->first_child=NULL;
    new_t->next_sibling=NULL;
    return new_t;
}

tree_t* attach(tree_t* t,int p,int c){
    tree_t* c_t = create_node(c);
    tree_t* p_t=search(t,p);
    if(p_t->first_child==NULL){
        p_t->first_child = c_t;
    }else{
        p_t=p_t->first_child;
        while (p_t->next_sibling!=NULL){
            p_t=p_t->next_sibling;
        }
        p_t->next_sibling=c_t;
    }
    return t;
}
tree_t* detach(tree_t* t,int node){

}
tree_t* search(tree_t* t,int node){
    tree_t* r=NULL;

    if(t->value==node){
        r=t;
    }
    //not found in current node,search in child
    if(r==NULL && t->first_child!=NULL){
        r=search(t->first_child,node);
    }
    //no children search in siblings
    if(r==NULL){
        r=search(t->next_sibling,node);
    }
    return r;
};
tree_t* degree(tree_t* t,int node){
    t=t->first_child;
    if (t==NULL)return 0;
    int n=1;
    while (t->next_sibling!=NULL) {
        t=t->next_sibling;
        n++;
    }
    return n;
}
int is_root(tree_t* t,int node);//node เป้นตัวรากมั๊ย
int is_leaf(tree_t* t,int node);//node เป็นตัวล่างสุดมั๊ย
void siblings(tree_t* t,int node);//แฝด : parent แล้ว children เลย
int depth(tree_t* t,int node);//
void print_path(tree_t* t,int start,int end);
int path_length(tree_t* t,int start,int end);
void ancestor(tree_t* t,int node);
void descendant(tree_t* t,int node);
void bfs(tree_t* t);
void dfs(tree_t* t);
void print_tree(tree_t* t);
















int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;
    }
  }
  return 0;
}