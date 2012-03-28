/*
 * Tests the disjoint-sets data structure implemented in dsjsets.h
 * and dsjsets.c.
 */


#include <stdio.h>
#include <stdlib.h>

#include "dsjsets.h"

int main() {

    // initialize
    dsjsets d;
    dsjsets_init(&d);

    // add 10 elements
    dsjsets_addelems(&d, 10);

    // print
    dsjsets_print(&d);

    // union some sets
    dsjsets_union(&d, 0, 1);
    dsjsets_union(&d, 2, 3);

    // print again
    printf("\nAfter unioning sets (0 and 1) and (2 and 3):\n");
    dsjsets_print(&d);

    // union some more sets that have alreay been unioned
    dsjsets_union(&d, 4, 2);
    dsjsets_union(&d, 4, 0);

    // print again
    printf("\nAfter unioning sets (4 and 2) and (4 and 0):\n");
    dsjsets_print(&d);

    // add 5 more elements
    dsjsets_addelems(&d, 5);

    // print again
    printf("\nAfter adding 5 more sets:\n");
    dsjsets_print(&d);

    // do some finds
    printf("\nfind(0): %d\n", dsjsets_find(&d, 0));
    printf("\nfind(9): %d\n", dsjsets_find(&d, 9));

    // print the size
    printf("\nNumber of Sets: %d\n", dsjsets_size(&d));

    // free up the disjoint-sets data structure
    dsjsets_destroy(&d);

    return 0;
}
