/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Implementation of the queue data structure.
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue_t.h"



/*  O(1) OPERATION
 *  --------------
 *  Initializes the queue with a size of 0. The initializer
 *  ASSUMES MEMORY HAS ALREADY BEEN ALLOCATED FOR THE PARAMETER
 *  Q.
 */

void queue_init(queue_t *q){

    // NULL-check the parameter
    if (!q)
        return;

    q->size = 0;

    // initialize the stacks
    stack_init(&(q->in));
    stack_init(&(q->out));
}



/*  O(1) OPERATION
 *  --------------
 *  Returns 1 if the queue has a size of 0 or the parameter is
 *  NULL. Returns 0 otherwise.
 */

int queue_empty(queue_t *q){

    // NULL-check the parameter
    if (!q)
        return 1;

    return (q->size == 0);
}



/*  O(1) OPERATION
 *  --------------
 *  Returns the size of this queue. If the parameter is NULL, returns
 *  0.
 */

int queue_size(queue_t *q){

    // NULL-check the parameter
    if (!q)
        return 0;

    return q->size;
}



/*  O(N) OPERATION/O(1) OPERATION AMORTIZED
 *  ---------------------------------------
 *  Returns the item at the front of the queue. If the parameter is NULL
 *  or the queue is empty, a NULL pointer is returned.
 */

void *queue_front(queue_t *q){

    // NULL-check the parameter and check the size
    if (!q || (q->size == 0))
        return NULL;

    // if the out stack has items in it, we simply peek
    if (stack_size(&(q->out)) > 0)
        return stack_peek(&(q->out));

    // otherwise we must dequeue everything from the in
    // stack to the out stack and then peek
    int inSize = stack_size(&(q->in));
    int i;
    for (i = 0; i < inSize; i++)
        stack_push(&(q->out), stack_pop(&(q->in)));
    return queue_front(q);
}
