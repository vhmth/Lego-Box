#ifndef TRIE_H__
#define TRIE_H__

typedef struct _node{
	void* letter;
	void* value;
	struct _node* next; // points to the right sibling
	struct _node* child;
}node;

typedef struct _trie{
	node* root;
}trie;

void trie_init(trie* t);
void* trie_get_value(trie* t, char* key); // returns the value for a given key
void trie_set_value(trie* t, char* key, void* value);
void trie_destroy(trie* t);

#endif
