#include "math.h"

/*
Save the above function in a file named "math.c". Generate its
corresponding header. Perform a test routine with different values in a program.
*/

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int16_t xn = rand() % _I16_MAX;
    uint16_t i;
    int16_t* x = calloc(xn, sizeof(int16_t));
    for(i = 0; i < xn; i++) {
        x[i] = rand() % _I16_MAX;
    }
    printf("Sum array = %d", sumArray(x, xn));
    exit(EXIT_SUCCESS);
}

int32_t sumArray(int16_t* x, int16_t xn)
{
    uint16_t i;
    int32_t sum = 0;
    for(i = 0; i < xn; i++) {
        sum += x[i];
    }
    return sum;
}