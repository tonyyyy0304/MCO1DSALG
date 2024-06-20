#include <stdlib.h>
#include <string.h>


void initStack(Stack* stack)
{
    stack->topIndex = -1;
     for(int i = 0; i<256; i++)
        strcpy(stack->token[i], "\0");
}

void resetStack(Stack* stack)
{
    stack->topIndex = -1;
     for(int i = 0; i<256; i++)
        strcpy(stack->token[i], "\0");
}


int push(Stack* stack, char* src)
{
    if(stack->topIndex == 255)
        return 0;
    else
    {
        stack->topIndex += 1;
        strcpy(stack->token[stack->topIndex], src);
       
    }
    return 1;
}

int pop(Stack* stack, char* dest)
{

    if(stack->topIndex == -1)
        return 0;
    else
    {
        strcpy(dest, stack->token[stack->topIndex]);
        stack->topIndex -= 1;
        return 1;
    }       
}

void initStackInt(StackInt* stack)
{
    stack->topIndex = -1;
     for(int i = 0; i<256; i++)
       stack->token[i] = 0;
}

void resetStackInt(StackInt* stack)
{
   stack->topIndex = -1;
        for(int i = 0; i<256; i++)
            stack->token[i] = 0;
}

int pushInt(StackInt* stack, int src)
{
    if(stack->topIndex == 255)
        return 0;
    else
    {
        stack->topIndex += 1;
        stack->token[stack->topIndex] = src;
       
    }
    return 1;
}

int popInt(StackInt* stack, int* dest)
{
    if(stack->topIndex == -1)
        return 0;
    else
    {
        *dest = stack->token[stack->topIndex];
        stack->topIndex -= 1;
        return 1;
    }       
}