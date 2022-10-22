#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Make a program to calculate the size of a pointer to an 8-bit integer,
16-bit, 32-bit, float and double pointers. Display each of the sizes on the screen.
*/


int main(int argc, const char argv[]) 
{
    printf("Sizeof 8-bit integer pointer: \t%d bytes\n", sizeof(int8_t ));
    printf("Sizeof 16-bit integer pointer: \t%d bytes\n", sizeof(int16_t));
    printf("Sizeof 32-bit integer pointer: \t%d bytes\n", sizeof(int16_t ));
    printf("Sizeof float pointer: \t\t%d bytes\n", sizeof(float));
    printf("Sizeof double integer pointer: \t%d bytes\n", sizeof(double *));
    exit(EXIT_SUCCESS);
}