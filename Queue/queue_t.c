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
    stack_init(&in);
    stack_init(&out);
}
