#include "math.h"

/*
Add an inline version of the function of point 3 to the "math" library. Check
with the compiler that the function is indeed inline (use __inline).
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
    printf("Sum array = %d\n", sumArray(x, xn));

    printf("Sum = %d\n", sum(2,4));

    exit(EXIT_SUCCESS);
}

inline int32_t sum(int32_t a, int32_t b) {
	return a + b;
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