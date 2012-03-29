/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Implementation file for a hash table.
 */

#include <stdlib.h>
#include <string.h>

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
    h->MAX_ALPHA = .7;
    h->alpha = 0;

    // the capacity is defaulted to 32
    h->capacity = 32;
    h->table = (node_t **)malloc(32*sizeof(node_t *));

    // NULL all the table pointers
    int i;
    for (i = 0; i < 32; i++)
        h->table[i] = NULL;
    h->numItems = 0;
}



/*  O(1) OPERATION
 *  --------------
 *  Inserts an item into the hash table. If any of the parameters
 *  are NULL or h has not been initialized, this function does
 *  nothing.
 */

void hashtable_insert(hashtable_t *h, char *key, void *value){

    // NULL-check the parameters
    if (!h || !(h->table) || !key || !value)
        return;

    // if the load factor has reached its max
    // resize
    if (h->alpha >= h->MAX_ALPHA){
        //get all the items
        int size = h->numItems;
        char *keys[size];
        void *values[size];
        int i;
        int j;
        j = 0;
        for (i = 0; i < h->capacity; i++){
            // an item was found
            if (h->table[i]){
                // traverse this list, adding items
                node_t *stepper = h->table[i];
                while (stepper){
                    node_t *tmp = stepper->next;

                    keys[j] = stepper->key;
                    values[j] = stepper->value;
                    j++;

                    // delete node
                    free(stepper);

                    // traverse
                    stepper = tmp;
                }

                // NULL this node
                h->table[i] = NULL;
            }
        }

        // clean up the memory and resize
        h->capacity *= 2;
        h->table = realloc(h->table, h->capacity);
        h->numItems = 0;
        h->alpha = 0;

        // rehash the items
        for (i = 0; i < size; i++)
            hashtable_insert(h, keys[i], values[i]);
    }

    // otherwise get the index of this key
    unsigned int index = SuperFastHash(key, h->capacity) % h->capacity;

    // now insert
    if (!h->table[index]){
        // there was no collision

        // make a node
        h->table[index] = (node_t *)malloc(sizeof(node_t));
        (h->table[index])->key = key;
        (h->table[index])->value = value;
        (h->table[index])->next = NULL;
    } else {
        // collision occurred, so append to the chain

        // traverse to end
        node_t *stepper = h->table[index];
        while (stepper->next)
            stepper = stepper->next;

        // append
        stepper->next = (node_t *)malloc(sizeof(node_t));
        stepper->next->key = key;
        stepper->next->value = value;
        stepper->next->next = NULL;
    }

    // update the number of elements and
    // load factor
    (h->numItems)++;
    h->alpha = (float)h->numItems/(h->capacity);
}



/*  O(N) OPERATION/O(1) AVERAGE OPERATION
 *  -------------------------------------
 *  Finds the void pointer value associated with the key
 *  parameter and returns it. If either of the parameters
 *  are NULL, this function returns a NULL-pointer. If the
 *  key is not in h, this function again returns a NULL-pointer.
 */

void *hashtable_find(hashtable_t *h, char *key){

    // NULL-check the parameters
    if(!h || !(h->table) | !key)
        return NULL;

    // get the index from the hash function
    unsigned int index = SuperFastHash(key, h->capacity) % h->capacity;

    // find the value
    node_t *stepper = h->table[index];
    while (stepper){
        // if this is the node associated with the
        // key, return its value
        if (!strcmp(key, stepper->key))
            return stepper->value;

        // traverse
        stepper = stepper->next;
    }

    // couldn't find the key in this table
    return NULL;
}



/*  O(N) OPERATION/O(1 + N/k) AVERAGE OPERATION
 *  -------------------------------------------
 *  Removes the node that contains the same key as that of the
 *  key parameter. If either parameter is NULL or no nodes in
 *  the table have the same key, this funciton does nothing.
 */

void hashtable_remove(hashtable_t *h, char *key){

    // NULL-check the parameters
    if (!h || !(h->table) || !key)
        return;

    // get the index from the hash function
    unsigned int index = SuperFastHash(key, h->capacity) % h->capacity;

    // find the value
    node_t *stepper = h->table[index];

    // if it's the first item
    if (!strcmp(stepper->key, key)){
        h->table[index] = stepper->next;

        // free this node
        free(stepper);

        // update the number of items
        (h->numItems)--;
    } else {
        // if it's an item further in the list
        while(stepper->next){
            // if this is the node, remove a node
            if (!strcmp(stepper->next->key, key)){
                node_t *tmp = stepper->next;

                stepper->next = stepper->next->next;

                // free the next node
                free(stepper->next);

                // update the number of items
                (h->numItems)--;

                break;
            }

            // traverse
            stepper = stepper->next;
        }
    }

    // update the load factor
    h->alpha = (float)h->numItems/(h->capacity);
}
