/*
 * Tests the queue data structure implemented in queue_t.h
 * and queue_t.c.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bintree.h"

// use strcmp for the comparison function
int comparer(const void *a, const void *b){
    return strcmp((char *)a, (char *)b);
}

int main() {

    // initialize
    bintree_t testBT;
    bintree_init(&testBT, &comparer);

    // free up the dictionary's memory
    bintree_destroy(&testBT);

    return 0;
}
