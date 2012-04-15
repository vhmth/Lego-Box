all: testTrie

testTrie: testTrie.o trie.o
	gcc -Wall testTrie.o trie.o -o testTrie

trie.o: trie.c trie.h
	gcc -g -Wall -c trie.c -o trie.o

testTrie.o: test.c
	gcc -g -Wall -c test.c -o testTrie.o

clean:
	rm -rf *.o testTrie
