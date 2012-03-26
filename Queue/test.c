/*
 * Tests the queue data structure implemented in queue_t.h
 * and queue_t.c.
 */


#include <stdio.h>
#include <stdlib.h>

#include "queue_t.h"

int main() {

    // initialize
    queue_t testQ;
    queue_init(&testQ);

    // add some items
    queue_enqueue(&testQ, "item 1");
    queue_enqueue(&testQ, "item 2");
    queue_enqueue(&testQ, "item 3");

    // print the queue
    queue_print(&testQ);

    // dequeue
    queue_dequeue(&testQ);

    // print the queue
    printf("After dequeueing once:\n");
    queue_print(&testQ);

    printf("The size of the queue: %d\n", queue_size(&testQ));

    // the front of the queue
    printf("The front of the queue: %s\n", (char *)queue_front(&testQ));

    // the back of the queue
    printf("The back of the queue: %s\n", (char *)queue_back(&testQ));

    // add some more items
    queue_enqueue(&testQ, "item4");
    queue_enqueue(&testQ, "item5");

    printf("After queueing twice more:\n");
    queue_print(&testQ);

    // free up the queue's memory
    queue_destroy(&testQ);

    return 0;
}
