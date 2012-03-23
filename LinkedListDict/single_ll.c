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
    l->head = NULL;
}



/*  O(N) OPERATION
 *  --------------
 *  Add an item to the linked list. This function returns 1
 *  if the item was added successfully and 0 if the item already
 *  exists or any of the paramters are NULL.
 */

int single_ll_add(single_ll *l, void *key, void *data){
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
            return stepper->data;

        // just keep swimming
        stepper = stepper->next;
    }

    // we couldn't find the key, return NULL
    return NULL;
}




/*  O(N) OPERATION
 *  --------------
 *
 *  Retrieves the specified value paired to the index passed in.
 *  The index is zero-based and, if the pointer param is NULL
 *  or the index is invalid, a NULL pointer is returned.
 */

const void *single_ll_get_at(single_ll *l, int index){

    // NULL-checking param and index-checking index
    if (!l || (index < 0) || (index >= l->size))
        return NULL;

    // let's step through the list
    node_t *stepper = l->head;
    int i = 0;
    while (i < index){
        stepper = stepper->next;
        i++;
    }

    // I told you we gon' find you
    return stepper->data;
}



/*  O(N) OPERATION
 *  --------------
 *  Deletes the specified value paired to the key passed in.
 *  If no key exists or either of the parameters are NULL, 0 is
 *  returned. 1 is returned upon successful removal.
 */

int single_ll_remove(single_ll *l, const void *key){

    // NULL-check the parameters
    if (!l || !(l->head) || !key)
        return 0;

    // if the head is the key
    if (l->head->key == key){
        node_t *tmp = l->head;
        l->head = l->head->next;
        (l->size)--;
        free(tmp);
        return 1;
    }

    // let's step through the list
    node_t *stepper = l->head;
    while (stepper->next){

        // we found the son'bitch
        if (stepper->next->key == key){
            node_t *tmp = stepper->next;
            stepper->next = stepper->next->next;
            free(tmp);
            (l->size)--;
            return 1;
        }

        // just keep swimming
        stepper = stepper->next;
    }

    // we couldn't find the key, return NULL
    return 0;
}




/*  O(N) OPERATION
 *  --------------
 *
 *  Deletes the specified value paired to the index passed in.
 *  The index is zero-based and, if the pointer param is NULL
 *  or the index is invalid, a 0 is returned. 1 is returned
 *  upon successful removal.
 */

int single_ll_remove_at(single_ll *l, int index){

    // NULL-checking param and index-checking index
    if (!l || (index < 0) || (index >= l->size))
        return 0;

    // if the head is the key
    if (index == 0){
        node_t *tmp = l->head;
        l->head = l->head->next;
        free(tmp);
        (l->size)--;
        return 1;
    }

    // let's step through the list
    node_t *stepper = l->head;
    int i = 0;
    while (i < (index-1)){
        stepper = stepper->next;
        i++;
    }

    // I told you we gon' find you
    node_t *tmp = stepper->next;
    stepper->next = stepper->next->next;
    free(tmp);
    (l->size)--;
    return 1;
}



/*  O(1) OPERATION
 *  --------------
 *
 *  Returns the size of the linked list.
 */

int single_ll_size(single_ll *l){

    // NULL-check the parameter
    if (!l)
        return 0;

    return l->size;
}



/*  O(1) OPERATION
 *  --------------
 *
 *  Returns a 1 if the linked list is empty and 0 otherwise.
 */

int single_ll_empty(single_ll *l){

    //NULL-check the parameter
    if (!l)
        return 1;

    return (l->size == 0);
}



/*  O(N) OPERATION
 *  --------------
 *
 *  Prints out the contents of the linked list in the following form:
 *  (key, value)  (key, value)  (key, value)....
 *  and nothing if the list is empty. NOTE THAT THIS ONLY WORKS IF
 *  THE KEYS AND VALUES ARE PROPER CHAR* STRINGS!
 */

void single_ll_print(single_ll *l){

    // NULL-check the parameter
    if (!l)
        return;

    // print out its contents
    int i;
    node_t *stepper = l->head;
    for (i = 0; i < l->size; i++){
        if (i != (l->size -1))
            printf("(%s, %s)  ", (char *)stepper->key, (char *)stepper->data);
        else
            printf("(%s, %s)\n", (char *)stepper->key, (char *)stepper->data);

        stepper = stepper->next;
    }
}



/*  O(N) OPERATION
 *  --------------
 *
 *  Destroys all memory allocated by the linked list dictionary. Note that this
 *  DOES NOT FREE UP MEMORY FROM THE KEY-VALUE PAIRS NOR DOES IT FREE UP THE
 *  ACTUAL DICTIONARY/LINKED LIST ITSELF!
 */

void single_ll_destroy(single_ll *l){

    // NULL-check the parameters
    if (!l)
        return;

    // free up the nodes in the list
    node_t *stepper = l->head;
    while(stepper){
        node_t *tmp = stepper->next;
        free(stepper);
        stepper = tmp;
    }

    // just in case you try to re-use the dictionary after calling destroy
    // without calling init again
    l->head = NULL;
    l->size = 0;
}
