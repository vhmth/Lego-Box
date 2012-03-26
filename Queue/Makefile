all: testQueue

testQueue: testQueue.o queue_t.o stack.o
	gcc -g -Wall testQueue.o queue_t.o stack.o -o testQueue

queue_t.o: queue_t.c queue_t.h
	gcc -g -Wall -c queue_t.c -o queue_t.o

stack.o: stack.c stack.h
	gcc -g -Wall -c stack.c -o stack.o

testQueue.o: test.c
	gcc -g -Wall -c test.c -o testQueue.o

clean:
	rm -rf *.o testQueue
