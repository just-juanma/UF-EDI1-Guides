#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/*
Implement a set of functions for handling a FIFO queue queue of byte-sized variables.
variables of byte size. Manage all the variables in the queue queue from a
data_queue_t structure. Create a test program that allows to enter and display queue through the implemented functions.
*/

typedef struct {
    int8_t beg; // beginning value of queue
    int8_t end; // end value of queue
    int8_t* queue; 

} dataQueue_t;

void generateQueue(dataQueue_t** FIFO, size_t* n);
void queue(int8_t node, dataQueue_t* FIFO, size_t* n);
void dequeue(dataQueue_t* FIFO, size_t* n);
int8_t getBeg(dataQueue_t* FIFO);
int8_t getEnd(dataQueue_t* FIFO);
void resize(dataQueue_t** FIFO, size_t n);
 
int main(int argc, char* argv[]) 
{
   srand(time(NULL));
   dataQueue_t* FIFO = NULL;
   int8_t data1 = rand() % INT8_MAX, data2 = rand() % INT8_MAX, data3 = rand() % INT8_MAX;
   size_t n = 0;
   generateQueue(&FIFO, &n);
   
   queue(data1, FIFO, &n);

   queue(data2, FIFO, &n);

   queue(data3, FIFO, &n);

   dequeue(FIFO, &n);
    
    printf("Beginning node:\t%d\n", getBeg(FIFO));
    printf("End node:\t%d\n", getEnd(FIFO));

    exit(EXIT_SUCCESS);
}

/// @brief queue generation
/// @param n size of FIFO
/// @return FIFO pointer with dinamic array allocation
void generateQueue(dataQueue_t** FIFO, size_t* n)
{
    *FIFO = calloc(1, sizeof(dataQueue_t));
    (*(*FIFO)).queue = calloc(++(*n), sizeof(int8_t));
}

/// @brief add a node at the end of queue
/// @param node node to add
/// @param FIFO queue
/// @param n size of FIFO
void queue(int8_t node, dataQueue_t* FIFO, size_t* n)
{
   (*FIFO).queue[*n - 1] = node;
   if(*n == 1)
       (*FIFO).beg = node;
   (*FIFO).end = node;
   resize(&FIFO, ++*n);
}

/// @brief erase the first value of the queue
/// @param FIFO queue
/// @param n size of FIFO
void dequeue(dataQueue_t* FIFO, size_t* n) 
{
    uint32_t i;
    for(i = 0; i < *n; i++) {
        (*FIFO).queue[i] = (*FIFO).queue[i + 1];
    }
    (*FIFO).beg = *((*FIFO).queue);
    if(*n == 1)
         (*FIFO).end = *((*FIFO).queue);
    resize(&FIFO, --*n);
}

/// @brief modifies array length by n
/// @param FIFO queue
/// @param n new size
void resize(dataQueue_t** FIFO, size_t n)
{
    (*(*FIFO)).queue = realloc((*(*FIFO)).queue, n);
}

/// @return beginning of queue
int8_t getBeg(dataQueue_t* FIFO)
{
    return (*FIFO).beg;
}

/// @return end of queue
int8_t getEnd(dataQueue_t* FIFO)
{
    return (*FIFO).end;
}