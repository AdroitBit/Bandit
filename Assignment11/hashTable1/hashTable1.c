#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item {
    char *text;
    struct item *next;
} item_t;

typedef struct hash {
    item_t **table;
    int size;
    int hash_key;
} hash_t;

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
hash_t* init_hashtable(int size, int hash_key) {
    hash_t *hash = malloc(sizeof(hash_t));
    hash->table = malloc(sizeof(item_t*) * size);
    hash->size = size;
    hash->hash_key = hash_key;
    for (int i = 0; i < size; i++) {
        hash->table[i] = NULL;
    }
    return hash;
}

int key(char *text, hash_t *hash) {//key of text
    unsigned int key = 0;
    unsigned int mul=1;
    unsigned int len = strlen(text);
    for (int i = len-1; i>=0; i--) {
        key += text[i]*mul;
        mul *= hash->hash_key;
    }
    return key % hash->size;
}

hash_t* insert(hash_t *hash, char *text) {
    unsigned int index= key(text, hash);
    item_t *item = malloc(sizeof(item_t));
    item->text = malloc(sizeof(char) * TEXTSIZE);
    strcpy(item->text, text);
    if(hash->table[index] == NULL) {
        hash->table[index] = item;
        item->next = NULL;
    } else {
        item_t* latest_item = hash->table[index];
        while (latest_item->next != NULL) {
            latest_item = latest_item->next;
        }
        latest_item->next = item;
        item->next=NULL;
    }
    return hash;
}

int search(hash_t *hash, char *text) {//return index
    int index = key(text, hash);
    item_t *item = hash->table[index];
    while (item != NULL) {
        if (strcmp(item->text, text) == 0) {
            return index;
        }
        item = item->next;
    }
    return -1;
}

void print_hash(hash_t *hash,char *text) {
    int index = search(hash, text);
    printf("index: %d\n", index);
    for (int i = 0; i < hash->size; i++) {
        item_t *item = hash->table[i];
        if (i == index) {
            printf(YEL);
        }
        printf("%d: ", i);
        while (item != NULL) {
            printf("%s ", item->text);
            item = item->next;
        }
        printf("  ");
        printf(RESET);
    }
    printf("\n");
}


int main(void) {
  hash_t *hashtable = NULL;
  char *text = NULL;
  int m, n, i, hash_key;
  int command;

  scanf("%d %d %d",  &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char) * TEXTSIZE);

  for (i=0; i<n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
      case 1:
        insert(hashtable, text);
        //print_hash(hashtable,text);
        break;
      case 2:
        printf("%d\n", search(hashtable, text));
      break;
    }
  }
  return 0;
}