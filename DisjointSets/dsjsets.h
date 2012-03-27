/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Header file for a disjoint-sets data structure.
 */

#ifndef DSJSETS_H__
#define DSJSETS_H__

// the disjoint-sets struct
typedef struct _dsjsets {

    // the array that will contain all the sets
    int *dsets;

    // the number of sets
    int size;
} dsjsets;

// Functionals.
void dsjsets_addelems(dsjsets *d, int n);
int dsjsets_find(dsjsets *d, int x);
void dsjsets_union(dsjsets *d, int a, int b);
int dsjsets_size(dsjsets *d);

// Utility functions.
void dsjsets_init(dsjsets *d);
void dsjsets_print(dsjsets *d);
void dsjsets_destroy(dsjsets *d);

#endif
