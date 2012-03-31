/*
 * Tests the hash table data structure implemented in
 * hash_table.h and hash_table.c.
 */


#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

int main() {

    // initialize
    hashtable_t h;
    hashtable_init(&h);

    // add some items
    printf("insert key 1\n");
    hashtable_insert(&h, "key 1", "value 1");
    printf("num elems: %d\n", hashtable_numelems(&h));

    printf("insert key 2\n");
    hashtable_insert(&h, "key 2", "value 2");
    printf("num elems: %d\n", hashtable_numelems(&h));

    printf("insert key 3\n");
    hashtable_insert(&h, "key 3", "value 3");
    printf("num elems: %d\n", hashtable_numelems(&h));

    printf("insert key 4\n");
    hashtable_insert(&h, "key 4", "value 4");
    printf("num elems: %d\n", hashtable_numelems(&h));

    printf("insert key 5\n");
    hashtable_insert(&h, "key 5", "value 5");
    printf("num elems: %d\n", hashtable_numelems(&h));

    printf("insert key 6\n");
    hashtable_insert(&h, "key 6", "value 6");
    printf("num elems: %d\n", hashtable_numelems(&h));

    // print the load factor
    printf("\nload factor: %f\n", hashtable_loadfactor(&h));

    // find these items
    printf("\nhashtable_find(key 1): %s\n", (char *)hashtable_find(&h, "key 1"));
    printf("hashtable_find(key 2): %s\n", (char *)hashtable_find(&h, "key 2"));
    printf("hashtable_find(key 3): %s\n", (char *)hashtable_find(&h, "key 3"));
    printf("hashtable_find(key 4): %s\n", (char *)hashtable_find(&h, "key 4"));
    printf("hashtable_find(key 5): %s\n", (char *)hashtable_find(&h, "key 5"));
    printf("hashtable_find(key 6): %s\n", (char *)hashtable_find(&h, "key 6"));

    // remove some items
    printf("\nremoving key 3\n");
    hashtable_remove(&h, "key 3");
    printf("hashtable_find(key 3): %s\n", (char *)hashtable_find(&h, "key 3"));

    printf("removing key 4\n");
    hashtable_remove(&h, "key 4");
    printf("hashtable_find(key 4): %s\n", (char *)hashtable_find(&h, "key 4"));

    // print the number of items
    printf("\nnum elems: %d\n", hashtable_numelems(&h));

    // clear the table
    printf("\nclearing the table\n");
    hashtable_clear(&h);
    printf("hashtable_find(key 1): %s\n", (char *)hashtable_find(&h, "key 1"));
    printf("num elems: %d\n", hashtable_numelems(&h));

    // free up the queue's memory
    hashtable_destroy(&h);

    return 0;
}
