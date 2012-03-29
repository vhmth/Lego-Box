/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Implementation file for a hash table.
 */

#include <stdlib.h>

#include "hash_function.c"
#include "hash_table.h"



/*  O(1) OPERATION
 *  --------------
 *  Initializes the hash table with a capacity of 32. The
 *  initializer ASSUMES MEMORY HAS ALREADY BEEN ALLOCATED
 *  FOR PARAMETER H.
 */

void hashtable_init(hashtable_t *h){

    // NULL-check the parameter
    if (!h)
        return;

    // the load factor is defaulted to 0.7
    h->alpha = .7;

    // the capacity is defaulted to 32
    h->capacity = 32;
    h->table = (node_t *)malloc(32*sizeof(node_t));
    h->numItems = 0;
}
