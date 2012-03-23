/*
 * Tests the dictionary data structure implemented in single_ll.h
 * and single_ll.c.
 */


#include <stdio.h>
#include <stdlib.h>

#include "single_ll.h"

int main() {
    // initialize
    single_ll testDict;
    single_ll_init(&testDict);

    // add some keys
    single_ll_add(&testDict, "key1", "data1");
    single_ll_add(&testDict, "key2", "data2");
    single_ll_add(&testDict, "key3", "data3");
    single_ll_add(&testDict, "key4", "data4");
    single_ll_print(&testDict);

    // remove key 2
    printf("After removing 'key2':\n");
    single_ll_remove(&testDict, "key2");
    single_ll_print(&testDict);

    // remove key at index 1
    printf("After removing key at index 1:\n");
    single_ll_remove_at(&testDict, 1);
    single_ll_print(&testDict);

    // get the size
    printf("Current size of dict: %d\n", single_ll_size(&testDict));

    // free up the dictionary's memory
    single_ll_destroy(&testDict);

    return 0;
}
