/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Header file for a single linked list.
 */

#ifndef SINGLE_LL_H__
#define SINGLE_LL_H__


// The nodes of the linked list.
typedef struct _node_t {
    // the key at the node, defined by the user
    // so left as a void pointer
    void *key;

    // the data at the node, defined by the user
    // so left as a void pointer
    void *data;

    // the next node
    struct _node_t *next;
} node_t;



// The linked list header.
typedef struct _single_ll {
    // the size of this linked list
    int size;

    // the head of the linked list
    node_t *head;
} single_ll;


// Functionals.
int single_ll_add(single_ll *l, void *key, void *data);
const void *single_ll_get(single_ll *l, const void *key);
const void *single_ll_get_at(single_ll *l, int index);
int single_ll_remove(single_ll *l, const void *key);
int single_ll_remove_at(single_ll *l, int index);
int single_ll_size(single_ll *l);
int single_ll_empty(single_ll *l);

// Utility functions.
void single_ll_init(single_ll *l);
void single_ll_print(single_ll *l);
void single_ll_destroy(single_ll *l);


#endif
