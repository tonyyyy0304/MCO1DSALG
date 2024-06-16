#include <stdlib.h>
#include "stack.h"

Stack *createStack(int capacity){

    Stack *stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->store = malloc(sizeof(stack->store) * sizeof(char));

    return stack;
}

int peekTopIndex(Stack *stack){
    return stack->top;
}

bool isStackEmpty(Stack *stack){
    return (stack->top == -1);
}

bool isStackFull(Stack *stack){
    return (stack->top == stack->capacity - 1);
}

void push(Stack *stack, char token){
    
    if (isStackFull(stack)){
        return;
    }

    stack->store[stack->top++] = token;

}

char pop(Stack *stack){
    if (isStackEmpty(stack)){
        return '\0';
    }

    stack->top--;
    return stack->store[stack->top];
}

char peekStack(Stack *stack){
    return stack->store[stack->top];
}

void clearStack(Stack *stack){
    stack->top = -1; // resets stack to -1
}