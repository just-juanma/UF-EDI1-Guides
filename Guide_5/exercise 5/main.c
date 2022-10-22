#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Modify the function int32_t Sum(int32_t a, int32_t b) to print the address of arguments a and b.
Make a call from the main to the Sum function, using
variables v1 and v2 to pass the value of the arguments. Compare the addresses
of v1 and v2 with those of a and b. What conclusions can be drawn from this?
*/

int32_t sum(int32_t a, int32_t b) {
    printf("a adress:\t%10p\n", &a);
    printf("b adress:\t%10p\n", &b);
	return a + b;
}

int main(int argc, char* argv[]) 
{
   int32_t v1, v2, foo;

   printf("v1 adress:\t%10p\n", &v1);
   printf("v2 adress:\t%10p\n", &v2);

   foo = sum(v1, v2);

    
    exit(EXIT_SUCCESS);
}