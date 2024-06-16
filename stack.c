#include <stdlib.h>
#include <string.h>
#include "stack.h"

void initStack(Stack* stack)
{
    stack->topIndex = 0;
}

int push(Stack* stack, char* src)
{
    if(stack->topIndex == 255)
        return 0;
    else
    {
        strcpy(stack->token[stack->topIndex], src);
        (stack->topIndex)++;
    }
    return 1;
}

int pop(Stack* stack, char* dest)
{

    if(stack->topIndex == 0)
        return 0;
    else
    {
        strcpy(dest, stack->token[stack->topIndex]);
        (stack->topIndex)--;
        return 1;
    }    
    
}