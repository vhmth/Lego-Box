all: testFunction

testFunction: testFunction.o
	gcc -g -Wall testFunction.o -o testFunction

testFunction.o: testFunction.c
	gcc -g -Wall -c testFunction.c -o testFunction.o

clean:
	rm -rf *.o testFunction
