#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Stack{
    int top;
    char *store;
    int capacity;

}Stack;

Stack *createStack(int capacity);
int peekTopIndex(Stack *stack);
bool isStackEmpty(Stack *stack);
void push(Stack *stack, char token);
char pop(Stack *stack);
char peekStack(Stack *stack);
void clearStack(Stack *stack);


#endif