#include<string.h>
#include<stdio.h>
#include "queue.c"
#include "stack.c"

typedef char output[10];

int isDigit(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int isOperator(char c)
{
     if(c == '+' || c == '*' ||c == '/' ||c == '-' || c == '!' || c == '%' ||
        c == '^' ||c == '<' ||c == '>' || c == '=' || c == '|' || c == '&')
        return 1;
    else
        return 0;
}

int isParenthesis(char c)
{
    return (c == '(' || c == ')');
}

void tokenExtractor(char* stringInput, Queue* queue)
{
    int i;

    char temp[100] = "\0";

    for (i=0; i<strlen(stringInput); i++)
    {

        if(isDigit(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);

            if(!isDigit(stringInput[i+1]))
            {
                enqueue(queue, temp);
                strcpy(temp, "\0");
            }
        }
        else if(isOperator(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);

            if(!isOperator(stringInput[i+1]))
            {
                enqueue(queue, temp);
                strcpy(temp, "\0");
            }
        }
        else if(isParenthesis(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);
            enqueue(queue, temp);
            strcpy(temp, "\0");
        }
    }
}

int InComingPrecedence(char* operator){
    
    if (strcmp(operator, "^") == 0){
        return 7;
    }else if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0){
        return 6;
    }else if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0){
        return 5;
    }else if (strcmp(operator, "<=") == 0 || strcmp(operator, ">=") == 0 || 
                strcmp(operator, ">") == 0 || strcmp(operator, "<") == 0){
        return 4;
    }else if (strcmp(operator, "==") == 0 || strcmp(operator, "!=") == 0){
        return 3;
    }else if (strcmp(operator, "&&") == 0){
        return 2;
    }else if (strcmp(operator, "||") == 0){
        return 1;
    }

    return 0;
}

int InStackPrecedence(char* operator){

    if (strcmp(operator, "^") == 0){
        return 7;
    }else if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0){
        return 6;
    }else if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0){
        return 5;
    }else if (strcmp(operator, "<=") == 0 || strcmp(operator, ">=") == 0 || 
                strcmp(operator, ">") == 0 || strcmp(operator, "<") == 0){
        return 4;
    }else if (strcmp(operator, "==") == 0 || strcmp(operator, "!=") == 0){
        return 3;
    }else if (strcmp(operator, "&&") == 0){
        return 2;
    }else if (strcmp(operator, "||") == 0){
        return 1;
    }
    return 0;
}

void infixToPostfix(Queue* queue, Queue* keep, Stack *stack, int length){
    int i;
    char temp[100];

    for (i = 0; i < length && strcmp(queue->token[i], "\0") != 0 ; i++){
        if (isDigit(keep->token[i][0])){
            enqueue(queue, keep->token[i]);
        }else if (isOperator(keep->token[i][0])){
           while(stack->topIndex != 0 && InComingPrecedence(keep->token[i]) <= InStackPrecedence(stack->token[stack->topIndex - 1])){
                pop(stack, temp);
                enqueue(queue, temp);
            }

            push(stack, keep->token[i]);
            
        }else if (strcmp(keep->token[i], "(") == 0){
             push(stack, keep->token[i]);
        }else if (strcmp(keep->token[i], ")") == 0){
            while (stack->topIndex != 0 && strcmp(stack->token[stack->topIndex - 1], "(") != 0) {
                pop(stack, temp);
                enqueue(queue, temp);
            }

            pop(stack, temp);
        }
    }

    while (stack->topIndex != 0){
        pop(stack, temp);
        enqueue(queue, temp);
    }

}

