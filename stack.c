#include <stdlib.h>
#include <string.h>

/**
 * @brief Initialize the stack.
 *
 * This function sets the top index of the stack to -1 and clears all token entries in the stack.
 *
 * @param stack Pointer to the Stack to initialize.
 */
void initStack(Stack* stack)
{
    stack->topIndex = -1;
     for(int i = 0; i<256; i++)
        strcpy(stack->token[i], "\0");
}

/**
 * @brief Reset the stack.
 *
 * This function resets the top index of the stack to -1 and clears all token entries in the stack.
 *
 * @param stack Pointer to the Stack to reset.
 */
void resetStack(Stack* stack)
{
    stack->topIndex = -1;
     for(int i = 0; i<256; i++)
        strcpy(stack->token[i], "\0");
}

/**
 * @brief Push an element onto the stack.
 *
 * This function pushes a string onto the stack. If the stack is full, it returns 0; otherwise, it returns 1.
 *
 * @param stack Pointer to the Stack where the string will be pushed.
 * @param src The string to push.
 * @return 1 if the string was pushed successfully, 0 if the stack is full.
 */
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

/**
 * @brief Pop an element from the stack.
 *
 * This function pops a string from the stack and stores it in the provided destination.
 * If the stack is empty, it returns 0; otherwise, it returns 1.
 *
 * @param stack Pointer to the Stack from which the string will be popped.
 * @param dest The destination where the popped string will be stored.
 * @return 1 if the string was popped successfully, 0 if the stack is empty.
 */
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

/**
 * @brief Initialize the integer stack.
 *
 * This function sets the top index of the integer stack to -1 and clears all token entries in the stack.
 *
 * @param stack Pointer to the StackInt to initialize.
 */
void initStackInt(StackInt* stack)
{
    stack->topIndex = -1;
     for(int i = 0; i<256; i++)
       stack->token[i] = 0;
}

/**
 * @brief Reset the integer stack.
 *
 * This function resets the top index of the integer stack to -1 and clears all token entries in the stack.
 *
 * @param stack Pointer to the StackInt to reset.
 */
void resetStackInt(StackInt* stack)
{
   stack->topIndex = -1;
        for(int i = 0; i<256; i++)
            stack->token[i] = 0;
}

/**
 * @brief Push an integer onto the stack.
 *
 * This function pushes an integer onto the stack. If the stack is full, it returns 0; otherwise, it returns 1.
 *
 * @param stack Pointer to the StackInt where the integer will be pushed.
 * @param src The integer to push.
 * @return 1 if the integer was pushed successfully, 0 if the stack is full.
 */
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

/**
 * @brief Pop an integer from the stack.
 *
 * This function pops an integer from the stack and stores it in the provided destination.
 * If the stack is empty, it returns 0; otherwise, it returns 1.
 *
 * @param stack Pointer to the StackInt from which the integer will be popped.
 * @param dest The destination where the popped integer will be stored.
 * @return 1 if the integer was popped successfully, 0 if the stack is empty.
 */
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
