#ifndef STACK_H
#define STACK_H

typedef char String256[256];
typedef char token10[11];

typedef struct Stack{
    token10 token[256];//a limit of 10 characters per token since the limit of C int is within 10 digits
    int topIndex;
}Stack;

typedef struct StackInt{
    int token[256];//a limit of 10 characters per token since the limit of C int is within 10 digits
    int topIndex;
}StackInt;

//two types of data struct to accommodate the operand and operator stack


#endif