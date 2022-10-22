#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Print the end pointer on the screen. What does this value express? Compare with the
memory addresses of the local and global variables from the previous point. Initialize
the varGlobal variable in the line of its declaration and recheck it against the value of the
end pointer.
*/

extern char end;

int32_t varGlobalNoInit; // no initialize value

int32_t varGlobal = 1;

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
    printf("end adress\t%10p\n", &end);
    printf("var adress\t%10p\n", &var);
    printf("varGlobal adress\t%10p\n", &varGlobal);
    printf("varGlobalNoInit adress\t%10p\n", &varGlobalNoInit);
    
    exit(EXIT_SUCCESS);
}