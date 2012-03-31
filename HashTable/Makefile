all: testFunction testHashTable

testFunction: testFunction.o
	gcc -g -Wall testFunction.o -o testFunction

testFunction.o: testFunction.c
	gcc -g -Wall -c testFunction.c -o testFunction.o

testHashTable: testHashTable.o hashTable.o
	gcc -g -Wall testHashTable.o hashTable.o -o testHashTable

testHashTable.o: test.c
	gcc -g -Wall -c test.c -o testHashTable.o

hashTable.o: hash_table.c hash_table.h
	gcc -g -Wall -c hash_table.c -o hashTable.o

clean:
	rm -rf *.o testFunction testHashTable
