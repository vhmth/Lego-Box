all: testHeap

testHeap: testHeap.o heap.o
	gcc -Wall testHeap.o heap.o -o testHeap

heap.o: heap.c heap.h
	gcc -g -Wall -c heap.c -o heap.o

testHeap.o: test.c
	gcc -g -Wall -c test.c -o testHeap.o

clean:
	rm -rf *.o testHeap
