#ifndef _HEAP_H_
#define _HEAP_H_

/*
 * Heap Data Structure
 */

typedef Structure _heap{
    int(*compare)(const void *, const void *);
    void** items;
    int size;
    int capacity;
} heap;

/*
 * Initializers:
 * The heap requires a comparer function to determine
 * how elements are placed in the heap. The comparer function 
 * should return 1 if the first parameter should be placed
 * "below" the second parameter.
 *
 * The first initializer will create an empty heap of default size 16.
 *
 * The second initializer will use the values in the items array
 * to build a heap.
 */
void heap_init(heap* h, int(*comparer)(const void *, const void *));
void heap_init(heap* h, int(*comparer)(const void *, const void *), void** items);


void heap_insert(heap* h);

/* Only allowing access to the "top" item on the heap.
 * In most cases this would correspond to the minimum
 * or maximum value
 *
 * heap_peek will return but NOT remove the top element
 * heap_remove will return AND remove the top element
 */
void* heap_peek(heap* h);
void* heap_remove(heap* h);

/* heap_find returns 1 if there is a node
 * in the heap with the value val
 */
int heap_find(heap* h, void* val);

int heap_size(heap* h);

void heap_destroy(heap* h);