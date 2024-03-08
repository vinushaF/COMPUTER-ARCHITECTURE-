#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 256
#define MAIN_MEMORY_SIZE 1024

typedef struct { int valid, tag, data; } CacheBlock;

void accessCache(int address, CacheBlock *cache) {
    int i = address % CACHE_SIZE, t = address / CACHE_SIZE;
    if (cache[i].valid && cache[i].tag == t)
        printf("Cache hit! Data found at address %d\n", address);
    else {
        printf("Cache miss! Data not found at address %d\n", address);
        cache[i].valid = 1; cache[i].tag = t; cache[i].data = address;
    }
}

int main() {
    CacheBlock cache[CACHE_SIZE];
    int memory[MAIN_MEMORY_SIZE];
    for (int i = 0; i < CACHE_SIZE; i++) cache[i].valid = 0;
    for (int i = 0; i < MAIN_MEMORY_SIZE; i++) memory[i] = i;

    int address;
    printf("Enter memory address to access (0-%d): ", MAIN_MEMORY_SIZE - 1);
    scanf("%d", &address);
    accessCache(address, cache);
    return 0;
}
