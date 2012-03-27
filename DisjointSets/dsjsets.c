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
    d->dsets = (int *)realloc(d->dsets, (n + d->size)*sizeof(int));

    // initialize new sets to -1
    int i;
    for (i = n; i < (d->size + n); i++)
        d->dsets[i] = -1;

    // update size
    d->size += n;
}



/*  O(log*N) OPERATION
 *  ------------------
 *  Finds the root of nth element. If n does not make sense, d is
 *  NULL or d has not been initialized, this function returns -1.
 */

int dsjsets_find(dsjsets *d, int n){

    // NULL-check d and make sure n makes sense
    if (!d || !(d->dsets) || n < 0 || n >= d->size)
        return -1;

    // if this is a root set, return
    if (d->dsets[n] < 0)
        return n;

    // otherwise recurse until you hit the root
    int rootSet = dsjsets_find(d, d->dsets[n]);

    // point to the root set (path compression)
    d->dsets[n] = rootSet;

    return rootSet;
}



/*  O(logN) OPERATION
 *  -----------------
 *  Unions sets a and b. Implemented such that the bigger set
 *  points to the smaller set. If the indexes of a and b don't
 *  make sense, this function does nothing. This function also
 *  does nothing if d is NULL or has not been initialized.
 */

void dsjsets_union(dsjsets *d, int a, int b){

    // NULL-check d and make sure a and b make sense
    if (!d || !(d->dsets) || a < 0 || a >= d->size
        || b < 0 || b >= d->size)
        return;

    // get the roots of a and b
    int aRoot = dsjsets_find(d, a);
    int bRoot = dsjsets_find(d, b);

    // and their sizes
    int aSize = d->dsets[aRoot];
    int bSize = d->dsets[bRoot];

    // union
    if (bSize < aSize){
        // point set a to set b
        d->dsets[aRoot] = bRoot;

        // update size of set b
        d->dsets[bRoot] += aSize;

        return;
    }

    // set a's size is less than or equal to b's
    // point set b to set a
    d->dsets[bRoot] = aRoot;

    // update size of set a
    d->dsets[aRoot] += bSize;
}



/*  O(1) OPERATION
 *  --------------
 *  Returns the the number of sets in this data structure. If
 *  d is NULL, this returns 0.
 */

int dsjsets_size(dsjsets *d){

    // NULL-check the parameter
    if (!d)
        return 0;

    return d->size;
}
