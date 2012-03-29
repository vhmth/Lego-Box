/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Header file for a hash table.
 */

#ifndef HASH_TABLE_H__
#define HASH_TABLE_H__

typedef struct _hashtable_t {

    // the maximum load factor
    // defaults to 0.7 with init
    float alpha;

    // the capacity of this table (number
    // of buckets)
    int capacity;

    // the number of items in the table
    int numItems;

    // the table of linked lists
    node_t *table;
} hashtable_t;

// Functionals.
void hashtable_insert(hashtable_t *h, char *key, void *value);
void *hashtable_find(hashtable_t *h, char *key);
void hashtable_remove(hashtable_t *h, char *key);
void hashtable_clear(hashtable_t *h);
int hashtable_size(hashtable_t *h);
int hashtable_numelems(hashtable_t *h);
float hashtable_loadfactor(hashtable_t *h);

// Utility functions.
void hashtable_init(hashtable_t *h);
void hashtable_destroy(hashtable_t *h);

#endif
