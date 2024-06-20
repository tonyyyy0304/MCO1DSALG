#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef char String100[100];
typedef char String256[256];
typedef char token10[11];

typedef struct Stack{
    token10 token[256];
    int topIndex;
}Stack;

typedef struct StackInt{
    int token[256];
    int topIndex;
}StackInt;


#endif