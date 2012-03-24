/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Implementation of a binary tree.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

void bintree_makenode(tree_node_t *n, const void *key, const void *value){

    // NULL-check the parameters
    if (!key || !value)
        return;

    // if necessary
    if (!n)
        n = (tree_node_t *)malloc(sizeof(tree_node_t));

    // modify contents
    n->key = key;
    n->value = value;
    n->right = NULL;
    n->left = NULL;
}

int bintree_init(bintree *b, int(*comparer)(const void *, const void *)){

    // if the root is null, this tree is empty brah
    b->root = NULL;

    // height of a tree with no nodes is
    // -1, not 0 brah
    b->height = -1;

    b->compare = comparer;
}

int bintree_insert(bintree_t *b, const void *key, const void *value){

    // NULL-check the paramters
    if (!b || !key, !value)
        return 0;

    // this is the first node being added
    if (!(b->root)){
        bintree_makenode(b->root, key, value); 
        b->height = 0;
        return 1;
    }

    // let's add this son'bitch
    int currHeight = 0;
    tree_node_t *stepper = b->root;
    while (stepper){

        // compare for insertion and traversal conditions
        int comp = b->compare(key, stepper->key);

        // if this key compares equally to another
        if (comp == 0)
            return 0;

        // add to the left child
        if (!(stepper->left) && (comp < 0)){
            bintree_makenode(stepper->left, key, value);
            if (currHeight == b->height)
                (b->height)++;
            return 1;
        }

        // add to the right child
        if (!(stepper->right) && (comp > 0)){
            bintree_makenode(stepper->right, key, value);
            if (currHeight == b->height)
                (b->height)++;
            return 1;
        }

        // traverse
        if (comp < 0)
            stepper = stepper->left;
        else
            stepper = stepper->right;
        currHeight++;
    }

    // shouldn't be able to reach this point
    // but let's shut up the compiler warnings
    return 0;
}
