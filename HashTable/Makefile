all: testHashTable

testHashTable: testHashTable.o hashTable.o
	gcc -g -Wall testHashTable.o hashTable.o -o testHashTable

testHashTable.o: test.c
	gcc -g -Wall -c test.c -o testHashTable.o

hashTable.o: hash_table.c hash_table.h
	gcc -g -Wall -c hash_table.c -o hashTable.o

clean:
	rm -rf *.o testHashTable
