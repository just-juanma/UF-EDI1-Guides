#include "math.h"

/*
Add a function that returns a 16-bit unsigned integer that allows me to count the number of times it was called. Check the memory
location that each of the created variables occupy in the general map. The prototype is following:
uint16_t Access_Count (void);
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

    int (*mainPtr) (int, char**);
    int32_t (*sumArrayPtr) (int16_t*, int16_t);
    uint16_t (*accessCountPtr) (void);
    int32_t (*sumPtr) (int32_t, int32_t);

    mainPtr = &main;
    sumArrayPtr = &sumArray;
    accessCountPtr = &accessCount;
    sumPtr = &sum;

    printf("Main adress: \t%10p\n", mainPtr);
	printf("sumArray adress: \t%10p\n", sumArrayPtr);
    printf("accessCount adress\t%10p\n", accessCountPtr);
    printf("sum adress\t%10p\n", sum);
    printf("x adress\t%10p\n", x);
    printf("xn adress\t%10p\n", &xn);
    printf("i adress\t%10p\n", &i);
    printf("count adres\t%10p\n", &count);


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

uint16_t accessCount(void)
{
    return ++count;
}
