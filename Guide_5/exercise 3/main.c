#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Print the edata pointer on the screen. What does this value express? Compare this value with
the function pointers declared in the previous point. Do they belong to the same segment?
Declare a variable local to the main int32_t var and compare its value with the segment
edata. Declare a global variable int32_t varGlobal and compare it with the value of edata.
*/

extern char edata;

int32_t varGlobal;

int32_t sum(int32_t a, int32_t b) {
	return a + b;
}

int main(int argc, char* argv[]) 
{
    int32_t (*functionPointer) (int32_t, int32_t);
	int (*mainPointer) (int, char**);

	functionPointer = &sum;

	mainPointer = &main;

    int32_t var;

	printf("Main adress: \t%10p\n", mainPointer);
	printf("Function adress: \t%10p\n", functionPointer);
    printf("edata adress\t%10p\n", &edata);
    printf("var adress\t%10p\n", &var);
    printf("varGlobal adress\t%10p\n", &varGlobal);
    
    exit(EXIT_SUCCESS);
}