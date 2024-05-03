#include <stdio.h>
#include <stdlib.h>

typedef struct Heap_t Heap;

#define toss() (rand() % 2)


// O(1)

Heap * makeHeap(void);

// O(1)

int compareHeap(void *a, void *b);

// O(log(n))

int insertHeap(Heap *heap, void *data);

// O(log(n))

void * deleteMax(Heap *heap);

// O(n)

void destroy(Heap *heap);

