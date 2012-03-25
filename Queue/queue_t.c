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
 *  Returns the item at the front of the queue (the item that
 *  was enqueued first). If the parameter is NULL or the queue
 *  is empty, a NULL pointer is returned.
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



/*  O(1) OPERATION
 *  --------------
 *  Returns the item at the back of the queue (the item that was
 *  enqueued last). If the parameter is NULL or the queue is
 *  empty, a NULL pointer is returned.
 */

void *queue_back(queue_t *q){

    // NULL-check the parameter and check the size
    if (!q || (q->size == 0))
        return NULL;

    return stack_peek(&(q->in));
}



/*  O(1) OPERATION
 *  --------------
 *  Queues up an item (adds it to the back of the queue). If the
 *  parameter q is NULL, this function does nothing.
 */

void queue_enqueue(queue_t *q, void *item){

    // NULL-check the queue
    if (!q)
        return;

    // enqueue
    stack_push(q, item);
}



/*  O(N) OPERATION/O(1) OPERATION AMORTIZED
 *  ---------------------------------------
 *  Removes the first item in the queue (the item first enqueued).
 *  If the queue is NULL or empty, a NULL pointer is returned.
 */

void *queue_dequeue(queue_t *q){

    // NULL-check the parameter and check the size
    if (!q || (q->size == 0))
        return NULL;

    // if there are items on the out stack, simply pop
    if (stack_size(&(q->out)) > 0){
        (q->size)--;
        return stack_pop(&(q->out));
    }

    // otherwise we must dequeue from the in stack onto
    // the out stack and then pop
    int inSize = stack_size(&(q->in));
    int i;
    for (i = 0; i < inSize; i++)
        stack_push(&(q->out), stack_pop(&(q->in)));
    return queue_dequeue(q);
}



/*  O(N) OPERATION
 *  --------------
 *  Prints the queue in the following format:
 *      "front--> (value), (value), ..., (value) <--back"
 *  If the queue is empty or NULL, nothing is printed. NOTE THAT
 *  THIS ONLY WORKS IF THE VALUES OF THIS QUEUE ARE CHAR * STRINGS!
 */

void queue_print(queue_t *q){

    // NULL-check the parameter and check the size
    if (!q || (q->size == 0))
        return;

    printf("front--> ");

    // print the values
    int i;
    for (i = 0; i < q->size; i++){

        void *tmp = queue_dequeue(q);

        if (i == (q->size - 1))
            printf("(%s) <--back", tmp);
        else
            printf("(%s), ", tmp);

        queue_enqueue(q, tmp);
    }
}



/*  O(N) OPERATION
 *  --------------
 *  Free up memory associated with the parameter queue. This function
 *  should be called before any queue_t object leaves scope to ensure
 *  no memory leaks occur!
 */

void queue_destroy(queue_t *q){

    // NULL-check the parameter
    if (!q)
        return;

    // free up the stacks
    stack_destroy(!(q->in));
    stack_destroy(!(q->out));
}
