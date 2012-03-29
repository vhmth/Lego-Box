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

    printf("\nBuilding a series of min-heaps...\n\n");
    // build an array of ints that we will
    // use to test the heap
    int numbers[] = {20, 15, 12, 22, 30, 10, 8, 42, 50 , 19, 1, 0, 45};
    void** items = malloc(13*sizeof(int*));
    
    int j;
    for(j=1; j<14; j++){
        printf(">>> Building heap of size %d\n\n", j);
        int i;
        for(i=0; i < j; i++){
            items[i] = malloc(sizeof(int));
            *(int*)items[i] = numbers[i];
        }
        
        heap h;
        heap_init_with_items(&h, compare, items, j);
        
        heap_print(&h);

    }

	return 0;
}
