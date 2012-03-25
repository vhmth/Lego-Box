#include "stack.h"
#include <stdlib.h>


/*  O(1) OPERATION
 *  --------------
 *  Initializes the stack with size 0, capacity 16
 *  The initializer ASSUMES MEMORY HAS ALREADY BEEN ALLOCATED
 *  FOR THE PARAMETER S.
 */
void stack_init(stack* s){
    
    // just in case memory wasn't allocated for s
    if(s == NULL) return;
    
    // give size and capacity valid values;
    // we'll arbitrarily choose 16 as the initial capacity
    s->size = 0;
    s->capacity = 16;
    
    // allocate memory for the items array
    s->items = malloc(s->capacity * sizeof(void*));
}


/*  O(N) OPERATION
 *  --------------
 *  Doubles the capacity of the stack,
 *  while preserving its contents.
 */
void stack_resize(stack* s){
    
    // double the capacity
    s->capacity *= 2;
    
    // allocate more memory for the items array
    s->items = realloc(s->items, s->capacity * sizeof(void*));
}



/*  O(1) OPERATION
 *  --------------
 *  Push the object pointed to by 'ptr' onto the stack
 */
void stack_push(stack* s, void* ptr){
    
    // if there's no more room on the stack, double
    // the size of our items array
    if(s->size == s->capacity) stack_resize(s);
    
    // push the item onto the stack
    int top_index = s->size;
    s->items[top_index] = ptr;
    
    // increment size
    s->size++;
}


/*  O(1) OPERATION
 *  --------------
 *  Remove and return the top item of the stack
 */
void* stack_pop(stack* s){
    // return NULL if stack is empty
    if(s->size == 0) return NULL;
    
    // get pointer to the top item
    int top_index = s->size - 1;
    void* top_item = s->items[top_index];
    
    // remove top item
    s->items[top_index] = NULL;
    s->size--;
    
    return top_item;
}


/*  O(1) OPERATION
 *  --------------
 *  Return the top item of the stack
 */
void* stack_peek(stack* s){
    // return NULL if stack is empty
    if(s->size == 0) return NULL;
    
    // get pointer to the top item
    int top_index = s->size - 1;
    void* top_item = s->items[top_index];
    
    return top_item;    
}


/*  O(1) OPERATION
 *  --------------
 *  Return the size of the stack
 */
int stack_size(stack* s){
    return s->size;
}


/*  O(N) OPERATION
 *  --------------
 *  Free all memory allocated by s
 */
void stack_destroy(stack* s){
    free(s->items);
}





