#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef char String100[100];
typedef char String256[256];
typedef char token10[100];


typedef struct Queue{
    token10 token[256];
    int headIndex;
    int tailIndex;
}Queue;


#endif