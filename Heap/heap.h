#ifndef _HEAP_H_
#define _HEAP_H_

/*
 * Heap Data Structure
 */

typedef struct _heap{
    int(*compare)(const void *, const void *);
    void** items;
    int size;
    int capacity;
} heap;

/*
 * Initializers:
 * The heap requires a comparer function to determine
 * how elements are placed in the heap. The comparer function 
 * should return 1 if the second parameter should be placed
 * "below" the first parameter.
 *
 * i.e. comparer(2, 5) would return 1 if we want a minheap of integers
 *
 * heap_init will create an empty heap of default size 16
 * heap_init_with_items will create a heap from the items array
 */
void heap_init(heap* h, int(*comparer)(const void *, const void *));

void heap_init_with_items(heap* h, int(*comparer)(const void *, const void *), void** items, int item_count);

void heap_resize(heap* h);

void heap_insert(heap* h, void* item);

/* Only allowing access to the "top" item on the heap.
 * In most cases this would correspond to the minimum
 * or maximum value
 *
 * heap_peek will return but NOT remove the top element
 * heap_remove will return AND remove the top element
 */
void* heap_peek(heap* h);
void* heap_remove(heap* h);

int heap_size(heap* h);

void heap_destroy(heap* h);

/* Prints the values of the heap in level order
 * Should only be called for heaps of ints
 */
void heap_print(heap* h);


#endif