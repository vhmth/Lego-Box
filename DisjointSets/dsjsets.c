/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Implementation of a disjoint-sets data structure.
 */

#include <stdio.h>
#include <stdlib.h>

#include "dsjsets.h"



/*  O(1) OPERATION
 *  --------------
 *  Initializes the disjoint-sets data structure with a size of
 *  0 and its dsets array as a NULL pointer. ASSUMES MEMORY HAS
 *  ALREADY BEEN ALLOCATED FOR PARAMETER D.
 */

void dsjsets_init(dsjsets *d){

    //NULL-check the parameter
    if (!d)
        return;

    // NULL the dsets array
    d->dsets = NULL;

    // this is empty right now
    d->size = 0;
}



/*  O(N) OPERATION
 *  --------------
 *  Adds n unconnected sets to the dsets array of parameter d.
 *  If d is NULL or n is less than or equal to 0 this function
 *  does nothing.
 */

void dsjsets_addelems(dsjsets *d, int n){

    // NULL-check d and make sure n makes sense
    if (!d || (n <= 0))
        return;

    // if this is the first time adding elements
    if (!(d->dsets)){

        // allocate the memory
        d->dsets = (int *)malloc(n*sizeof(int));

        // initialize these sets to -1 (disjoint)
        int i;
        for (i = 0; i < n; i++)
            d->dsets[i] = -1;

        // update size
        d->size = n;

        return;
    }

    // we need to realloc
    d->dsets = (int *)realloc(d->dsets, (n+d->size)*sizeof(int));

    // initialize new sets to -1
    int i;
    for (i = n; i < (d->size + n); i++)
        d->dsets[i] = -1;

    // update size
    d->size += n;
}
