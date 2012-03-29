#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

// this compare function is written as to
// create a min-heap
int compare(const void* a, const void* b){
    int* A = (int*)a;
    int* B = (int*)b;
    return *A < *B;
}

int main(){

    // build an array of ints that we will
    // use to test the heap
    int numbers[] = {20, 15, 12, 22, 30, 10, 8, 42, 50 , 19, 1, 0, 45};
    void** items = malloc(13*sizeof(int*));
    
    printf("Building heap of size 13 \n\n");
    int i;
    for(i=0; i < 13; i++){
        items[i] = malloc(sizeof(int));
        *(int*)items[i] = numbers[i];
    }
    
    // build a heap from the items array
    heap h;
    heap_init_with_items(&h, compare, items, 13);
    heap_print(&h);
    
    // remove 4 items and check the structure again
    int* top;
    for(i=0; i<4; i++){
        top = heap_remove(&h);
        printf("Removed %d\n", *top);
    }
    printf("\n");
    heap_print(&h);
    
    // removing the rest of the items
    while(heap_size(&h) > 0){
        top = heap_remove(&h);
        printf("Removed %d\n", *top);
    }
    heap_print(&h);
    
    heap_destroy(&h);

	return 0;
}
