#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/*
Make a routine in the main program that allows me to test its operation by saving the values in a global variable.
Check the address where this variable is stored.
*/

int32_t valueSaver;

int main(int argc, char* argv[])
{
    valueSaver = sum(4, 5);

    printf("valueSaver adress: \t%10p\n", valueSaver);

    exit(EXIT_SUCCESS);
}

inline int32_t sum(int32_t a, int32_t b) {
	return a + b;
}

