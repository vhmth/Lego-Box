/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Implementation of a single linked list.
 */


#include <stdio.h>
#include <stdlib.h>

#include "single_ll.h"


/*  O(1) OPERATION
 *  --------------
 *  Initializes the single linked list with a size of 0.
 *  The initializer ASSUMES MEMORY HAS ALREADY BEEN ALLOCATED
 *  FOR THE PARAMETER L.
 */

void single_ll_init(single_ll *l){
    l->size = 0;

    // setting the head to NULL will serve to indicate whether
    // the linked list is empty or not
    head = NULL;
}



/*  O(N) OPERATION
 *  --------------
 *  Add an item to the linked list. This function returns 1
 *  if the item was added successfully and 0 if the item already
 *  exists or any of the paramters are NULL.
 */

int single_ll_add(single_ll *l, const void *key, const void *data){
    // NULL-check the parameters
    if (!l || !key || !data)
        return 0;

    // if this is the first item being added
    if (!(l->head)){
        l->head = (node_t*)malloc(sizeof(node_t));
        l->head->key = key;
        l->head->data = data;
        l->head->next = NULL;
        (l->size)++;
        return 1;
    }

    // otherwise we step through until the end
    node_t *stepper = l->head;
    while (stepper){

        // this key already exists
        if (stepper->key == key)
            return 0;

        // if we're at the end, let's add the son'bitch
        if (!(stepper->next)){
            stepper->next = (node_t*)malloc(sizeof(node_t));
            stepper->next->key = key;
            stepper->next->data = data;
            (l->size)++;
            return 1;
        }

        // traverse
        stepper = stepper->next;
    }

    // for some reason we reached the end?
    // let's put a stop to the compiler's whining
    return 0;
}



/*  O(N) OPERATION
 *  --------------
 *  Retrieves the specified value paired to the key passed in.
 *  If no key exists or either of the parameters are NULL, NULL is
 *  returned.
 */

const void *single_ll_get(single_ll *l, const void *key){

    // NULL-check the parameters
    if (!l || !key)
        return NULL;

    // let's step through the list
    node_t *stepper = l->head;
    while (stepper){

        // we found the son'bitch
        if (stepper->key == key)
            return stepper->value;

        // just keep swimming
        stepper = stepper->next;
    }

    // we couldn't find the key, return NULL
    return NULL;
}
