#include <stdio.h>
#include <stdlib.h>

typedef struct cell//cell for cache
{
    int data;
    int mem_addr;
} cell_t;

typedef struct hash
{
    cell_t *table;//point to cell, and cell is part of memory???
    int cache_size;
} hash_t;

typedef hash_t cache_t;
typedef int memory_t;

memory_t *init_memory(int size)
{
    memory_t *memory = (memory_t *)malloc(sizeof(memory_t) * size);
    int i = 0;
    for (i = 0; i < size; i++)
    {
        memory[i] = rand();
    }
    return memory;
}
cache_t *init_cache(int size)
{
    //printf("cache size is %d\n", size);
    cache_t *cache = (cache_t *)malloc(sizeof(cache_t));
    cache->table = (cell_t *)malloc(sizeof(cell_t) * size);
    cache->cache_size = size;
    int i = 0;
    for (i = 0; i < size; i++)
    {
        cache->table[i].data = -1;
        cache->table[i].mem_addr = -1;
    }
    return cache;
}
void get_data(int mem_addr,memory_t *memory, cache_t *cache){//not just get data but it can stored to cache too. Why name like this? This is hello of confusion
    //collision event=override
    //printf("Load address: %d\n", mem_addr);
    
    int cache_index;
    cache_index = mem_addr % cache->cache_size;
    //printf("Cache index: %d %d %d\n", cache_index,mem_addr,cache->cache_size);
    /*
        print logic is confusing
        if cache_index is not empty and same value , print Address is loaded
        if cache_index is not empty,print("Index is used") print("Load from memory")
        if cache_index is empty, print("Load from memory")
    */

    if(cache->table[cache_index].mem_addr!=-1 && cache->table[cache_index].mem_addr==mem_addr){
        printf("Address %d is loaded\n",mem_addr);
    }
    else if(cache->table[cache_index].mem_addr!=-1){
        printf("Index: %d is used\n",cache_index);
        printf("Load from memory\n");
    }
    else if(cache->table[cache_index].mem_addr==-1){
        printf("Load from memory\n");
    }
    cache->table[cache_index].data = memory[mem_addr];
    cache->table[cache_index].mem_addr = mem_addr;
    printf("Data: %d\n", cache->table[cache_index].data);
}

int main(void)
{
    memory_t *memory = NULL;
    cache_t *cache = NULL;
    int memory_size, cache_size;
    int i, n, addr;

    scanf("%d %d %d", &memory_size, &cache_size, &n);
    memory = init_memory(memory_size);
    cache = init_cache(cache_size);

    for (i = 0; i < n; i++)
    {
        printf("Load address: ");
        scanf("%d", &addr);
        get_data(addr, memory, cache);
    }
    return 0;
}