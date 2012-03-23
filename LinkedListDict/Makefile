all: testDict

testDict: testDict.o single_ll.o
	gcc -Wall testDict.o single_ll.o -o testDict

single_ll.o: single_ll.c single_ll.h
	gcc -g -Wall -c single_ll.c -o single_ll.o

testDict.o: test.c
	gcc -g -Wall -c test.c -o testDict.o

clean:
	rm -rf *.o testDict
