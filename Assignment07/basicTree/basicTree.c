#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

#ifdef DEBUG
#define debug(...) printf("[DEBUG] ");printf(__VA_ARGS__);printf("\n")
#else
#define debug(...)
#endif

// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
typedef struct node {
    int value;
    struct node* parent;
    struct node* first_child;
    struct node* prev_sibling;
    struct node* next_sibling;
} node_t;
typedef node_t tree_t;
tree_t* all_nodes[100];
int i_all_nodes=-1;

// Write your code here
// ...
tree_t* attach(tree_t* t,int parent,int child);//parent node,and child node
tree_t* detach(tree_t* t,int node);
int search(tree_t* t,int node);//is node n in structure tree
tree_t* search_t(tree_t* t,int node);//search that node
int degree(tree_t* t,int node);//amount of children nodes
int is_root(tree_t* t,int node);//node
int is_leaf(tree_t* t,int node);//node
void siblings(tree_t* t,int node);
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
    new_t->parent=NULL;
    new_t->first_child=NULL;
    new_t->prev_sibling=NULL;
    new_t->next_sibling=NULL;
    all_nodes[++i_all_nodes]=new_t;
    debug("create node %d",value);
    return new_t;
}

tree_t* attach(tree_t* t,int p,int c){
    if(p==-1 || t==NULL){
        tree_t* c_t=create_node(c);
        return c_t;
    }
    if(t==NULL){
        debug("tree is null");
        tree_t* c_t=create_node(c);
        tree_t* p_t=create_node(p);
        c_t->parent=p_t;
        p_t->first_child=c_t;
        debug("%d parent of %d",p,c);

        return p_t;
    }

    tree_t* c_t = create_node(c);
    tree_t* p_t=search_t(t,p);
    c_t->parent=p_t;
    debug("%d parent of %d",p,c);
    if(p_t->first_child==NULL){
        p_t->first_child=c_t;
        debug("%d first child of %d",c,p);
    }
    else{
        debug("attaching %d as next sibling",c);
        tree_t* temp=p_t->first_child;
        while(temp->next_sibling!=NULL){
            temp=temp->next_sibling;
        }
        temp->next_sibling=c_t;
        c_t->prev_sibling=temp;
        debug("%d next sibling of %d",c_t->value,c_t->prev_sibling->value);
    }
    return t;
}
tree_t* detach(tree_t* t,int node){
    tree_t* n_t=search_t(t,node);
    if(n_t->parent==NULL){
        debug("node %d is root",node);
        return t;
    }
    if(n_t->prev_sibling==NULL){
        debug("node %d is first child",node);
        n_t->parent->first_child=n_t->next_sibling;
        if(n_t->next_sibling!=NULL){
            n_t->next_sibling->prev_sibling=NULL;
        }
    }
    else{
        debug("node %d is not first child",node);
        n_t->prev_sibling->next_sibling=n_t->next_sibling;
        if(n_t->next_sibling!=NULL){
            n_t->next_sibling->prev_sibling=n_t->prev_sibling;
        }
    }
    n_t->parent=NULL;
    n_t->prev_sibling=NULL;
    n_t->next_sibling=NULL;
    return t;
}
tree_t* search_t(tree_t* t,int node){
    tree_t* r=NULL;
    debug("searching %d",t->value);
    if(t->value==node){
        debug("found");
        r=t;
    }
    //not found in current node,search in child
    if(r==NULL && t->first_child!=NULL){
        debug("searching in child %d",t->first_child->value);
        r=search_t(t->first_child,node);
    }
    //no children search in siblings
    if(r==NULL && t->next_sibling!=NULL){
        debug("searching in child %d",t->next_sibling->value);
        r=search_t(t->next_sibling,node);
    }
    return r;
}
int search(tree_t* t,int node){
    return search_t(t,node)!=NULL;
}
int degree(tree_t* t,int node){
    tree_t* n_t=search_t(t,node);
    int count=0;
    tree_t* temp=n_t->first_child;
    while(temp!=NULL){
        count++;
        temp=temp->next_sibling;
    }
    return count;
}
int is_root(tree_t* t,int node){
    return search_t(t,node)->parent == NULL;
}
int is_leaf(tree_t* t,int node){
    return degree(t,node)==0;
}
int is_descendant(tree_t* t,int p,int c){
    tree_t* p_t=search_t(t,p);
    tree_t* c_t=search_t(t,c);
    while(c_t!=NULL){
        if(c_t==p_t){
            return 1;
        }
        c_t=c_t->parent;
    }
    return 0;
}
void siblings(tree_t* t,int node){
    tree_t* n_t=search_t(t,node);
    if(n_t->parent==NULL){
        debug("node %d is root",node);
        printf("\n");
        return;
    }
    tree_t* temp=n_t->parent->first_child;
    while(temp!=NULL){
        //debug("%d",e->value);
        if(temp!=n_t){
            printf("%d ",temp->value);
        }
        temp=temp->next_sibling;
    }
    printf("\n");
    
}
int depth(tree_t* t,int node){
    tree_t* n_t=search_t(t,node);
    int count=0;
    while(n_t->parent!=NULL){
        count++;
        n_t=n_t->parent;
    }
    return count;
}
void print_path(tree_t* t,int start,int end){
    tree_t* s=search_t(t,start);
    tree_t* e=search_t(t,end);
    if(s==e){
        printf("%d ",s->value);
        return;
    }


    tree_t* stack[100];
    int i=0;
    do{
        stack[i]=e;
        debug("%d\n",e->value);
        e=e->parent;
        ++i;
    }while(e!=s);
    stack[i]=s;
    for(int j=i;j>=0;j--){
        printf("%d ",stack[j]->value);
    }
    printf("\n");
    
}
int path_length(tree_t* t,int start,int end){
    int d=1;
    tree_t* s=search_t(t,start);
    tree_t* e=search_t(t,end);
    while (s!=e){
        e=e->parent;
        d++;
    }
    return d;
}
void ancestor(tree_t* t,int node){
    tree_t* i_t=search_t(t,node);
    tree_t* nodes[100];
    int i=0;
    while(1){
        nodes[i]=i_t;
        debug("node %d",i_t->value);
        if(i_t->parent==NULL){
            break;
        }else{
            i_t=i_t->parent;
        }
        ++i;
    }
    for(int j=i;j>=0;--j){
        printf("%d ",nodes[j]->value);
    }
    printf("\n");
}
void descendant(tree_t* t,int node){
    tree_t* node_t=search_t(t,node);
    bfs(node_t);
};
void bfs(tree_t* t){//breadth first search
    /*
    my plan:
    1. create a queue
    2. enqueue root
    3. while queue is not empty
        3.1 dequeue
        3.2 print
        3.3 enqueue children
    */
    tree_t* queue[100];
    int front=0;
    int rear=0;
    queue[rear]=t;
    rear++;
    while(front!=rear){
        tree_t* temp=queue[front];
        front++;
        printf("%d ",temp->value);
        tree_t* current_node=temp->first_child;
        while(current_node!=NULL){
            queue[rear]=current_node;
            rear++;
            current_node=current_node->next_sibling;
        }
    }
    printf("\n");
};
void dfs(tree_t* t){//depth first search
    /*
    my plan:
    1. create a stack
    2. push root
    3. while stack is not empty
        3.1 pop
        3.2 print
        3.3 push children in reverse order
    */
    tree_t* stack[100];
    int top=0;
    stack[top]=t;
    top++;
    while(top!=0){
        tree_t* temp=stack[top-1];
        top--;
        printf("%d ",temp->value);
        tree_t* current_node=temp->first_child;
        //reverse order need to use prev_sibling
        while(current_node!=NULL && current_node->next_sibling!=NULL){
            current_node=current_node->next_sibling;
        }
        while(current_node!=NULL){
            stack[top]=current_node;
            top++;
            current_node=current_node->prev_sibling;
        }
    }
    printf("\n");

};
void _print_tree(tree_t* t,int tab){
    for(int i=0;i<tab;i++){
        printf("    ");
    }
    printf("%d\n",t->value);
    if(t->first_child!=NULL){
        _print_tree(t->first_child,tab+1);
    }
    if(t->next_sibling!=NULL){
        _print_tree(t->next_sibling,tab);
    }
}
void print_tree(tree_t* t){
    _print_tree(t,0);
}
















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