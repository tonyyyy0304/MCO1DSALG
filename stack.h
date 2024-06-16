#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef char String100[100];
typedef char String256[256];
typedef char token10[100];

typedef struct Stack{
    token10 token[256];
    int topIndex;
}Stack;


#endif