#include "trie.h"
#include <stdlib.h>

void trie_init(trie* t){

	// allocate memory for the root node
	t->root = malloc(sizeof(node));

	// the root is just the starting point for all key lookups,
	// so the letter and value do not matter
	t->root->letter = '.';
	t->root->value = NULL;

	// initially the root has no children, and it
	// will never have any siblings
	t->root->child = NULL;
	t->root->next = NULL;

}


