/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Header file for a queue data structure.
 */

#ifndef QUEUE_T_H__
#define QUEUE_T_H__

#include "../Stack/stack.h"

// the queue data struct
typedef struct _queue_t {
    // the stacks that will hold the items of this queue
    stack in, out;

    // number of items in the queue
    int size;
} queue_t;

// Functionals.
int queue_empty(queue_t *q);
int queue_size(queue_t *q);
void *queue_front(queue_t *q);
void *queue_back(queue_t *q);
void *queue_enqueue(queue_t *q, void *item);
void *queue_dequeue(queue_t *q);

// Utility functions.
void queue_init(queue_t *q);
void queue_print(queue_t *q);
void queue_destroy(queue_t *q);

#endif
