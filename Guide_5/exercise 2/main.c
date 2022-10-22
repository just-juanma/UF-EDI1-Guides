#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Print the etext pointer on the screen. What does this value express? Perform a function
int32_t Sum(int32_t a, int32_t b) and generate a pointer pointing to it. Print that
address and the address of the main, compare with the content of etext.
*/

extern char etext; 

int32_t sum(int32_t a, int32_t b) {
	return a + b;
}

int main(int argc, char* argv[])
{
	int32_t (*functionPointer) (int32_t, int32_t);
	int (*mainPointer) (int, char**);

	functionPointer = &sum;

	mainPointer = &main;

	printf("Main adress: \t%10p\n", mainPointer);
	printf("Function adress: \t%10p\n", functionPointer);
	printf("etext adress: \t%10p\n", &etext);

	exit(EXIT_SUCCESS);
}