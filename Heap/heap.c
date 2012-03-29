#include "heap.h"
#include <stdlib.h>
#include <stdio.h>


void swap_positions(int pos1, int pos2){
    
}

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
    
    // If there are 2 children, swap the parent with one of the children
    if(has_left && has_right){
        
        // if the left child should be placed above the right child
        // swap the left child with the parent
        if(h->compare(left, right)){
            swap_positions(index, left_index);
            heapify_down(h, left_index);
        }
        
        // otherwise, swap the parent with the right child
        else{
            swap_positions(index, right_index);
            heapify_down(h, right_index);
        }
    }
    
    else if(has_left){
        
        // If the left child should be placed above
        // the parent, swap them
        if(h->compare(left, parent)){
            swap_positions(index, left_index);
            heapify_down(h, left_index);
        }
    }
    
}

// Build a heap using the items array
void build_heap(heap* h){
    int i;
    for(i=0; i < h->size; i++){
        heapify_down(h, i);
    }
}

void heap_init(heap* h, int(*comparer)(const void *, const void *), void** items, int item_count){
    
    // Set the compare function
    h->compare = comparer;
    
    // Give size and capacity valid values
    h->size = 0;
    h->capacity = 16;
    
    if(items != NULL) {
        // create a heap using the items array 
        h->size = item_count;
        h->items = items;
        build_heap(h);
    }
    
    else {
        
        // Allocate memory for the items array
        h->items = malloc(h->capacity * sizeof(void*));
        
        // Our heap is empty, so make each entry in the items array
        // equal to NULL, rather than garbage data
        int i;
        for(i=0; i < h->capacity; i++){
            h->items[i] = NULL;
        }
    }
}


void* heap_peek(heap* h){
    return h->items[0];
}

int heap_size(heap* h){
    return h->size;
}

void heap_destroy(heap* h){
    free(h->items);
}

void heap_print(heap* h){
    int i;
    for(i=0; i < h->size; i++){
        printf("%d   ", *(int*)h->items[i]);
        if(i == 0 || i == 2 || i == 6 || i == 14) printf("\n");
    }
    printf("\n");
}
