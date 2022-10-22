#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/*
Implement a set of functions for handling a FIFO data queue of byte-sized variables.
variables of byte size. Manage all the variables in the data queue from a
data_queue_t structure. Create a test program that allows to enter and display data through the implemented functions.
*/

typedef struct {
    int8_t beg;
    int8_t end;
    int8_t* data;

} dataQueue_t;

dataQueue_t* generateQueue(size_t* n);
void addNode(int8_t node, dataQueue_t* FIFO, size_t* n);
void eraseNode(dataQueue_t* FIFO, size_t* n);
int8_t getBeg(dataQueue_t* FIFO);
int8_t getEnd(dataQueue_t* FIFO);

int main(int argc, char* argv[]) 
{
   srand(time(NULL));
   dataQueue_t* FIFO = NULL;
   int8_t data1 = rand() % 0x7E, data2 = rand() % 0x7E, data3 = rand() % 0x7E;
   size_t n = 0;
   FIFO = generateQueue(&n);
   
   addNode(data1, FIFO, &n);

   addNode(data2, FIFO, &n);

   addNode(data3, FIFO, &n);

   eraseNode(FIFO, &n);
    
    printf("Beginning node:\t%d\n", getBeg(FIFO));
    printf("End node:\t%d\n", getEnd(FIFO));

    exit(EXIT_SUCCESS);
}

dataQueue_t* generateQueue(size_t* n)
{
    dataQueue_t* FIFO = calloc((*n + 1), sizeof(dataQueue_t));
    (*FIFO).data = calloc(++(*n), sizeof(int8_t));
    return FIFO;
}

void addNode(int8_t node, dataQueue_t* FIFO, size_t* n)
{
   (*FIFO).data[*n - 1] = node;
   if(*n == 1)
       (*FIFO).beg = node;
   (*FIFO).end = node;
   (*FIFO).data = realloc((*FIFO).data, ++(*n));
}

void eraseNode(dataQueue_t* FIFO, size_t* n) 
{
    int i = 0;
    for(i = 0; i < *n; i++) {
        (*FIFO).data[i] = (*FIFO).data[i + 1];
    }
    (*FIFO).beg = *((*FIFO).data);
    if(*n == 1)
         (*FIFO).end = *((*FIFO).data);
    *n--;
}

int8_t getBeg(dataQueue_t* FIFO)
{
    return (*FIFO).beg;
}

int8_t getEnd(dataQueue_t* FIFO)
{
    return (*FIFO).end;
}