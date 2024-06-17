#include <stdlib.h>
#include <string.h>
#include "stack.h"

void initStack(Stack* stack)
{
    stack->topIndex = -1;
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