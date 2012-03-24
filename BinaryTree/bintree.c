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



/*  O(1) OPERATION
 *  --------------
 *  Initializes the given node with the given parameters.
 *  If key or value are NULL, this function does nothing.
 *  This function should only be used by this class!
 */

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



/*  O(N) OPERATION
 *  --------------
 *  Gets the height of the given tree rooted at the parameter
 *  n. If n is NULL, returns -1 (a tree with no nodes). This
 *  function should only be used by this class!
 */
int bintree_getrealheight(tree_node_t *n){

    // NULL-check the parameter
    if (!n)
        return -1;

    // get the heights of the left and right subtrees
    int left = bintree_getrealheight(n->left);
    int right = bintree_getrealheight(n->right);

    // return the max of the left and right subtree heights
    // plus one
    if (left > right)
        return left + 1;
    return right + 1;
}



/*  O(1) OPERATION
 *  --------------
 *  Initializes the binary tree with a NULL root and a
 *  height of -1. ASSUMES MEMORY HAS ALREADY BEEN
 *  ALLOCATED FOR PARAMETER B. The comparer function
 *  object is for comparisons between the keys of the
 *  nodes in this binary tree.
 */

int bintree_init(bintree *b, int(*comparer)(const void *, const void *)){

    // if the root is null, this tree is empty brah
    b->root = NULL;

    // height of a tree with no nodes is
    // -1, not 0 brah
    b->height = -1;

    b->compare = comparer;
}



/*  O(N) OPERATION
 *  --------------
 *  Inserts a node into this binary tree. The function returns
 *  1 upon successful insertion and 0 otherwise. If any
 *  of the parameters are NULL, this function returns 0.
 */

int bintree_insert(bintree_t *b, const void *key, const void *value){

    // NULL-check the paramters
    if (!b || !key || !value)
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



/*  O(N) OPERATION
 *  --------------
 *  Finds the node with a key matching the key parameter
 *  and removes that node from the tree. If there exists
 *  no key or either of the parameters is NULL, 0 is
 *  returned. Upon successful removal, a 1 is returned.
 */

int bintree_remove(bintree *b, const void *key){

    // NULL-check the parameters
    if (!b || !key)
        return 0;

    // find the son'bitch
    tree_node_t *stepper = b->root;
    while (stepper) {

        // compare this key with the parameter
        int comp = b->compare(key, stepper->key);

        // we got him now!
        if (comp == 0){
            // there's one child
            if ( (!(stepper->left) && stepper->right) ||
                 (stepper->left && !(stepper->right)) ){

                // if it's the left child
                if (stepper->left){
                    tree_node_t *tmp = stepper->left;
                    stepper->key = stepper->left->key;
                    stepper->value = stepper->left->value;
                    stepper->right = stepper->left->right;
                    stepper->left = stepper->left->left;
                    free(tmp);
                } else {
                    // otherwise it's the right
                    tree_node_t *tmp = stepper->right;
                    stepper->key = stepper->right->key;
                    stepper->value = stepper->right->value;
                    stepper->left = stepper->right->left;
                    stepper->right = stepper->right->right;
                    free(tmp);
                }
            } else if (!(stepper->left) && !(stepper->right)) {
                // there's no children

                tree_node_t *parent = bintree_getparent(b, stepper);

                // if there's no parent, the tree's empty
                if (!parent)
                    b->root = NULL;
                else {
                    if (parent->left == stepper)
                        parent->left = NULL;
                    else
                        parent->right = NULL;
                }

                free(stepper);
            } else {
                // there's two children
                tree_node_t *iop = bintree_inorderpred(stepper->left);
                if (iop == stepper->left){
                    stepper->key = iop->key;
                    stepper->value = iop->value;
                    stepper->left = iop->left;
                    free(iop);
                } else {
                    stepper->key = iop->key;
                    stepper->value = iop->value;
                    // the iop has a child
                    if (iop->left){
                        tree_node_t *tmp = iop->left;
                        iop->key = iop->left->key;
                        iop->value = iop->left->value;
                        iop->right = iop->left->right;
                        iop->left = iop->left->left;
                        free(tmp);
                    } else {
                        tree_node_t *iopparent = bintree_getparent(b, iop);
                        iopparent->right = NULL;
                        free(iop);
                    }
                }
            }

            b->height = bintree_getrealheight(b->root);
            return 1;
        }

        // traverse
        if (comp < 0)
            stepper = stepper->left;
        else
            stepper = stepper->right;
    }

    // we weren't able to get'em... but next time...
    return 0;
}
