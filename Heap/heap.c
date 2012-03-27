#include "heap.h"
#include <stdlib.h>


void heapify_up(heap* h, int index){
    
    
}

void heapify_down(heap* h, int index){
    
    // find the indices of the current node's children
    unsigned int left_index = 2*index + 1;
    unsigned int right_index = 2*index + 1;
    
    /// check if children actually exist
    int has_left = left_index < h->size;
    int has_right  = right_index < h->size;
    
    // if we're at a leaf, we're done :-)
    if(!has_left && !has_right) 
        return;
    
    // get values of the parent, left, and right nodes
    // so we can compare them
    void* parent = h->items[index];
    void* left = h->items[left_index];
    void* right = h->items[right_index];
    
    // if the compare function indicates the parent should be placed
    // above both children, the heap property is already satisfied
    if(has_left && h->compare(parent, left)
       && has_right && h->compare(parent, right)){
        return;
    }
}

// Build a heap using the items array
void build_heap(heap* h){
    
}

void heap_init(heap* h, int(*comparer)(const void *, const void *), void** items){
    
    // Set the compare function
    h->compare = comparer;
    
    // Give size and capacity valid values
    h->size = 0;
    h->capacity = 16;
    
    // Allocate memory for the items array
    if(items != NULL) {
        // find size of items parameter
        //h->capacity = ?
        //h->size = ?        
        h->items = items;
    }
    else {
        // create a heap using the items array
        h->items = malloc(h->capacity * sizeof(void*));
    }
}


void* heap_peek(heap* h){
    return NULL;
}

int heap_size(heap* h){
    return h->size;
}

void heap_destroy(heap* h){
    free(h->items);
}
