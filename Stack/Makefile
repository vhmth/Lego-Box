all: testStack

testStack: testStack.o stack.o
	gcc -Wall testStack.o stack.o -o testStack

stack.o: stack.c stack.h
	gcc -g -Wall -c stack.c -o stack.o

testStack.o: test.c
	gcc -g -Wall -c test.c -o testStack.o

clean:
	rm -rf *.o testStack
