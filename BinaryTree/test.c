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

    // add some nodes
    bintree_insert(&testBT, "key 2", "value 1");
    bintree_insert(&testBT, "key 1", "value 2");
    bintree_insert(&testBT, "key 3", "value 3");
    bintree_insert(&testBT, "key 4", "value 4");
    bintree_insert(&testBT, "key 0", "value 5");
    bintree_insert(&testBT, "key 9", "value 6");

    // print the tree
    bintree_print(&testBT);

    // free up the dictionary's memory
    bintree_destroy(&testBT);

    return 0;
}
