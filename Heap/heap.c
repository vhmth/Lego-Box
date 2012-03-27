#include "heap.h"
#include <stdlib.h>


void heapify_up(heap* h){
    
}

void heapify_down(heap* h){
    
}

// Restore the heap properties for h
void build_heap(heap* h){
    
}
void heap_init(heap* h, int(*comparer)(const void *, const void *), void** items){
    
    // Set the compare function
    h->compare = comparer;
    
    // Give size and capacity valid values
    h->size = 0;
    h->capacity = 16;
    
    // Allocate memory for the items array
    if(items != NULL) h->items = items;
    else h->items = malloc(h->capacity * sizeof(void*));
    
    // Restore the heap properties
    build_heap(h);
}


void* heap_peek(heap* h){
}

int heap_size(heap* h){
    return h->size;
}

void heap_destroy(heap* h){
    free(h->items);
}
