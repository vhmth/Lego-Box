#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

/*  O(1) OPERATION
 *  --------------
 *  Swaps the values at the given indices
 */
void swap_positions(heap* h, int pos1, int pos2){
    //printf("swapping %d with %d\n", *(int*)h->items[pos1], *(int*)h->items[pos2]);
    void* temp = h->items[pos1];
    h->items[pos1] = h->items[pos2];
    h->items[pos2] = temp;
}

/*  O(LOG(N)) OPERATION
 *  --------------
 *  Sifts the value at 'index' upward to position
 *  such that the heap property is maintained
 */
void heapify_up(heap* h, int index){
    
    // find index of the parent
    unsigned int parent_index = (index-1)/2;
    
    // get pointers to parent and child
    void* parent = h->items[parent_index];
    void* child = h->items[index];
    
    // if the child is out of place,
    // swap it with the parent
    if(h->compare(child, parent)){
        swap_positions(h, parent_index, index);
        heapify_up(h, parent_index);
    }
    
    // otherwise, everything is right in the world
    
}

/*  O(LOG(N)) OPERATION
 *  --------------
 *  Sifts the value at 'index' downward to position
 *  such that the heap property is maintained
 */
void heapify_down(heap* h, int index){

    // find the indices of the current node's children
    unsigned int left_index = 2*index + 1;
    unsigned int right_index = 2*index + 2;
    
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
            swap_positions(h, index, left_index);
            heapify_down(h, left_index);
        }
        
        // otherwise, swap the parent with the right child
        else{
            swap_positions(h, index, right_index);
            heapify_down(h, right_index);
        }
    }
    
    else if(has_left){
        
        // If the left child should be placed above
        // the parent, swap them
        if(h->compare(left, parent)){
            swap_positions(h, index, left_index);
            heapify_down(h, left_index);
        }
    }
    
}

/*  O(N) OPERATION
 *  --------------
 *  Builds a heap using the items array
 */
void build_heap(heap* h){
    
    // going from the bottom up, sift
    // down nodes to their proper positions
    int i;
    for(i=h->size/2; i >= 0; i--){
        heapify_down(h, i);
    }
}

/*  O(1) OPERATION
 *  --------------
 *  Initializes a heap of size 0, capacity 16
 */
void heap_init(heap* h, int(*comparer)(const void *, const void *)){
    
    // Set the compare function
    h->compare = comparer;
    
    // Give size and capacity valid values
    h->size = 0;
    h->capacity = 16;
    
    // Allocate memory for the items array
    h->items = malloc(h->capacity * sizeof(void*));
    
    // Our heap is empty, so make each entry in the items array
    // equal to NULL, rather than garbage data
    int i;
    for(i=0; i < h->capacity; i++){
        h->items[i] = NULL;
    }
}

/*  O(N) OPERATION
 *  --------------
 *  Initializes a heap, and builds it using the items array
 */
void heap_init_with_items(heap* h, int(*compare)(const void *, const void *), void** items, int item_count){
    
    // Set the compare function
    h->compare = compare;
    
    // Give size and capacity valid values
    h->size = item_count;
    h->capacity = 16;
    
    // make sure we have enough space for all the items
    while(h->capacity < item_count) h->capacity*=2;
    
    // verify that a non-NULL array was passed in
    if(items != NULL) {
        
        // Copy the values from items parameter.
        // We want our own dynamic array to tinker with
        // so we can leave the users' original array intact
        h->items = malloc( h->capacity * sizeof(void*));
        int i;
        for(i=0; i < item_count; i++){
            h->items[i] = items[i];
        }
        
        build_heap(h);
    }
}

/*  O(N) OPERATION
 *  --------------
 *  Doubles the size of the items array,
 *  preserving the values it already holds
 */
void heap_resize(heap* h){
    
    // double the capacity
    h->capacity *= 2;
    
    // allocate more memory for the items array
    h->items = realloc(h->items, h->capacity * sizeof(void*));
}

/*  O(LOG(N)) OPERATION
 *  --------------
 *  Inserts 'item' into the heap
 */
void heap_insert(heap* h, void* item){
    
    // if we've ran out of space in our items array
    // double the size of it
    if(h->size == h->capacity) heap_resize(h);
    
    // increment size
    h->size++;
    
    // place item in the last slot of the array,
    // then sift it upward into its proper position
    h->items[h->size-1] = item;
    heapify_up(h, h->size-1);
        
}

/*  O(1) OPERATION
 *  --------------
 *  Returns the topmost item in the heap
 */
void* heap_peek(heap* h){
    return h->items[0];
}

/*  O(1) OPERATION
 *  --------------
 *  Returns and removes the topmost item in the heap
 */
void* heap_remove(heap* h){
    
    // if there's nothing in the heap, return NULL
    if(h->size == 0) return NULL;
    
    // get a pointer to the top item and decrement size
    void* top = h->items[0];
    h->size--;
    
    // if there's more stuff in our heap, place the last
    // item in the root, and sift it down to preserve
    // the heap properties
    if(h->size > 0){
        h->items[0] = h->items[h->size];
        heapify_down(h, 0);
    }
    
    return top;
}

/*  O(1) OPERATION
 *  --------------
 *  Returns the size of the heap
 */
int heap_size(heap* h){
    return h->size;
}

/*  O(1) OPERATION
 *  --------------
 *  Deallocates all the memory the heap allocated
 */
void heap_destroy(heap* h){
    free(h->items);
}

/*  O(N) OPERATION
 *  --------------
 *  Prints the values in the heap, ASSUMING THEY ARE INTEGERS
 */
void heap_print(heap* h){
    int i;
    int nodes_for_level = 1;
    int node_at = 0;
    
    for(i=0; i < h->size; i++){
        printf("%d  ", *(int*)h->items[i]);
        
        node_at++;
        if(node_at == nodes_for_level){
            printf("\n");
            
            nodes_for_level *= 2;
            node_at = 0;
        }
    }
    if(node_at != 0) printf("\n");
    printf("\n");
}
