#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Make a function that allows to sum an array of 16-bit signed integers and return a 32-bit integer.
It must receive the address of the array and its length. The prototype is as follows:
int32_t Sum_Array (int16_t* x, int16_t xn);
*/

int32_t sumArray(int16_t* x, int16_t xn)
{
    uint16_t i;
    int32_t sum = 0;
    for(i = 0; i < xn; i++) {
        sum += x[i];
    }
    return sum;
}