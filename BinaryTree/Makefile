all: testBinTree

testBinTree: testBinTree.o queue_t.o stack.o bintree.o
	gcc -g -Wall testBinTree.o queue_t.o stack.o bintree.o -o testBinTree

queue_t.o: queue_t.c queue_t.h
	gcc -g -Wall -c queue_t.c -o queue_t.o

stack.o: stack.c stack.h
	gcc -g -Wall -c stack.c -o stack.o

bintree.o: bintree.c bintree.h
	gcc -g -Wall -c bintree.c -o bintree.o

testBinTree.o: test.c
	gcc -g -Wall -c test.c -o testBinTree.o

clean:
	rm -rf *.o testBinTree
