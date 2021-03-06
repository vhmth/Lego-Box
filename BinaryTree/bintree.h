/*
 *
 *  Author: Vinay Hiremath
 *          vhiremath4@gmail.com
 *          www.vhmath.com
 *
 *  Description: Header file for a binary tree.
 */

#ifndef BINTREE_H__
#define BINTREE_H__

// the nodes of the binary tree
typedef struct _tree_node_t {
    // the key at this node, defined by the user
    // so left as a void pointer
    void *key;

    // the value at this node, defined by the user
    // so left as a void pointer
    void *value;

    // the children nodes
    struct _tree_node_t *left;
    struct _tree_node_t *right;
} tree_node_t;

typedef struct _bintree_t {
    // the root of this tree
    tree_node_t *root;

    // the height of this tree
    int height;

    // how we will compare nodes in the tree
    int(*compare)(const void *, const void *);
} bintree_t;

// Functionals.
int bintree_insert(bintree_t *b, void *key, void *value);
int bintree_remove(bintree_t *b, const void *key);
void *bintree_find(bintree_t *b, const void *key);
int bintree_height(bintree_t *b);

// Utility functions.
void bintree_init(bintree_t *b, int(*comparer)(const void *, const void *));
void bintree_print(bintree_t *b);
void bintree_destroy(bintree_t *b);

#endif
