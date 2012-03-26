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
#include "../Queue/queue_t.h"



/*  O(1) OPERATION
 *  --------------
 *  Initializes the given node with the given parameters.
 *  If key or value are NULL, this function does nothing.
 *  This function should only be used by this class!
 */

void bintree_makenode(tree_node_t *n, void *key, void *value){

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



/*  O(N) OPERATION
 *  --------------
 *  Finds the in-order predecessor of a node. Note that the
 *  left child of the desired node must be passed into this
 *  function! If the parameter is NULL, it is returned. This
 *  function should only be used by this class!
 */

tree_node_t *bintree_inorderpred(tree_node_t *n){

    // if there is no right child, this is the IOP
    if (!n || !(n->right))
        return n;

    // traverse
    return bintree_inorderpred(n->right);
}



/*  O(N) OPERATION
 *  --------------
 *  Gets the parent of the child node passed in. If either
 *  parameter is NULL or the child is the root, a NULL pointer
 *  is returned. If no node matching child is found in the tree
 *  b, a NULL pointer is returned. This function should only be
 *  used by this class!
 */

tree_node_t *bintree_getparent(bintree_t *b, tree_node_t *child){

    // NULL-check the parameters
    if (!b || !child || (child == b->root))
        return NULL;

    // find that thang's pa/ma
    tree_node_t *stepper = b->root;
    while (stepper){

        // compare the child value with this node's children's
        // values

        // the left child is child?
        int comp = b->compare(child->value, stepper->value);
        if (comp < 0 && !(stepper->left)){
            comp = b->compare(child->value, stepper->left);
            if (comp == 0)
                return stepper;
            stepper = stepper->left;
        } else if (comp < 0)
            return NULL;

        // the right child is child?
        if (comp > 0 && !(stepper->right)){
            comp = b->compare(child->value, stepper->right);
            if (comp == 0)
                return stepper;
            stepper = stepper->right;
        } else if (comp > 0)
            return NULL;
    }

    // shouldn't have been able to reach here partner
    return NULL;
}



/*  O(1) OPERATION
 *  --------------
 *  Initializes the binary tree with a NULL root and a
 *  height of -1. ASSUMES MEMORY HAS ALREADY BEEN
 *  ALLOCATED FOR PARAMETER B. The comparer function
 *  object is for comparisons between the keys of the
 *  nodes in this binary tree.
 */

void bintree_init(bintree_t *b, int(*comparer)(const void *, const void *)){

    // NULL-check the parameters
    if (!b || !comparer)
        return;

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

int bintree_insert(bintree_t *b, void *key, void *value){

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

int bintree_remove(bintree_t *b, const void *key){

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



/*  O(N) OPERATION
 *  --------------
 *  Finds the node in bintree b with a key of the key parameter
 *  passed in. If either parameter is NULL or there is no node
 *  in b that has a key matching the parameter, this function returns
 *  NULL. Otherwise, this function returns the value of the node with
 *  a key matching the parameter.
 */

void *bintree_find(bintree_t *b, const void *key){

    // NULL-check the parameters
    if (!b || !key)
        return NULL;

    // let's find this son'bitch
    tree_node_t *stepper = b->root;
    while (stepper){

        // first compare
        int comp = b->compare(key, stepper->key);

        // is this him?
        if (comp == 0)
            return stepper->value;

        // traverse
        if (comp < 0)
            stepper = stepper->left;
        else
            stepper = stepper->right;
    }

    return NULL;
}



/*  O(1) OPERATION
 *  --------------
 *  Returns the height of the given binary tree b. If the parameter
 *  is NULL -1 is returned (a tree with no nodes).
 */

int bintree_height(bintree_t *b){

    // NULL-check the parameter
    if (!b)
        return -1;

    return b->height;
}



/*  O(N) OPERATION
 *  --------------
 *  Prints out the tree in its entirety, level-by-level using
 *  Breadth-First-Search. Each node is printed in the format
 *  '(key, value)'. If the parameter is NULL or the tree is empty,
 *  nothing is printed out. THIS FUNCTION WILL ONLY WORK IF THE
 *  KEYS AND VALUES ARE CHAR * STRINGS!
 */

void bintree_print(bintree_t *b){

    //NULL-check the parameter
    if (!b || !(b->root))
        return;

    // two queues to switch off levels
    queue_t q1, q2;
    queue_init(&q1);
    queue_init(&q2);

    int level = 0;
    queue_enqueue(&q1, b->root);
    while (!queue_empty(&q1) || !queue_empty(&q2)){

        if (!queue_empty(&q1))
            printf("Level %d: ", level);
        // the first queue needs to be emptied
        while (!queue_empty(&q1)){

            // get a node
            tree_node_t *tmp = queue_dequeue(&q1);

            // add its children to the other queue
            if (tmp->left)
                queue_enqueue(&q2, tmp->left);
            if (tmp->right)
                queue_enqueue(&q2, tmp->right);

            // print this node's contents
            if (queue_empty(&q1)){
                level++;
                printf("(%s, %s)\n", (char *)tmp->key, (char *)tmp->value);
            } else
                printf("(%s, %s) ", (char *)tmp->key, (char *)tmp->value);
        }

        if (!queue_empty(&q2))
            printf("Level %d: ", level);
        // the second queue needs to be emptied
        while (!queue_empty(&q2)){

            // get a node
            tree_node_t *tmp = queue_dequeue(&q2);

            // add its children to the other queue
            if (tmp->left)
                queue_enqueue(&q1, tmp->left);
            if (tmp->right)
                queue_enqueue(&q1, tmp->right);

            // print this node's contents
            if (queue_empty(&q2)){
                level++;
                printf("(%s, %s)\n", (char *)tmp->key, (char *)tmp->value);
            } else
                printf("(%s, %s) ", (char *)tmp->key, (char *)tmp->value);
        }
    }
}



/*  O(N) OPERATION
 *  --------------
 *  Destroys the memory associated with the nodes of this binary
 *  tree. This function does not destroy the actual key-value pointers
 *  inserted into the tree! THIS FUNCTION SHOULD BE CALLED BEFORE
 *  ANY BINARY TREE OBJECT LEAVES SCOPE TO AVOID MEMORY LEAKS.
 */

void bintree_destroy_helper(tree_node_t *curr){

    //NULL-check the parameters
    if (!curr)
        return;

    // search n' destroy!!!!
    if (curr->left)
        bintree_destroy_helper(curr->left);
    if (curr->right)
        bintree_destroy_helper(curr->right);

    // destroy the current node
    free(curr);
}
void bintree_destroy(bintree_t *b){

    // NULL-check the parameter
    if (!b || !(b->root))
        return;

    // call the helper
    bintree_destroy_helper(b->root);
}
