#include "hash_function.c"
#include <stdio.h>
#include <stdlib.h>

int main(){

	char *keys[10];
	keys[0] = "hello";
	keys[1] = "world";
	keys[2] = "this";
	keys[3] = "shit";
	keys[4] = "cray";
	keys[5] = "you";
	keys[6] = "know";
	keys[7] = "that";
	keys[8] = "right";
	keys[9] = "bro?";

	int i;
	for (i = 0; i < 10; i++){
		printf("%s\n", keys[i]);
		printf("hash %d: %u\n", i, SuperFastHash(keys[i], 10) % 10);
	}

	return 0;

}
