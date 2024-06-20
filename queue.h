#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef char String100[100];
typedef char String256[256];
typedef char token10[11];


typedef struct Queue{
    token10 token[256];//a limit of 10 characters per token since the limit of C int is within 10 digits
    int headIndex;
    int tailIndex;
}Queue;


#endif