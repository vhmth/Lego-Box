all: testDsets

testDsets: testDsets.o dsjsets.o
	gcc -Wall testDsets.o dsjsets.o -o testDsets

dsjsets.o: dsjsets.c dsjsets.h
	gcc -g -Wall -c dsjsets.c -o dsjsets.o

testDsets.o: test.c
	gcc -g -Wall -c test.c -o testDsets.o

clean:
	rm -rf *.o testDsets
