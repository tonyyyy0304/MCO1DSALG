#include<string.h>
#include<stdio.h>
#include "queue.h"
#include "stack.h"

typedef char String100[100];
typedef char String256[256];
typedef char token10[100];

int isDigit(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int isOperator(char c)
{
     if(c == '+' || c == '*' ||c == '/' ||c == '-' || c == '!' ||
        c == '^' ||c == '<' ||c == '>' || c == '=' || c == '|' || c == '&')
        return 1;
    else
        return 0;
}

int isParenthesis(char c)
{
    return (c == '(' || c == ')');
}

void pusher(token10 stack[], char* src, int* top)
{
    strcpy(stack[*top], src);
    (*top)++;
}

void tokenExtractor(char* stringInput, token10 stack[])
{
    int i, topIndex = 0;
    char temp[100] = "\0";

    for (i=0; i<strlen(stringInput); i++)
    {
        if(isDigit(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);

            if(!isDigit(stringInput[i+1]))
            {
                pusher(stack, temp, &topIndex);
                strcpy(temp, "\0");
            }
        }
        else if(isOperator(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);

            if(!isOperator(stringInput[i+1]))
            {
                pusher(stack, temp, &topIndex);
                strcpy(temp, "\0");
            }
        }
        else if(isParenthesis(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);
            pusher(stack, temp, &topIndex);
            strcpy(temp, "\0");
        }
    }
}

int InComingPrecedence(char operator){
    switch(operator){
        case '^':
            return 4;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
        default:
            return 0;
    }
}

int InStackPrecedence(char operator){
    switch(operator){
        case '^':
            return 3;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
        default:
            return 0;
    }
}

void infixToPostfix(Queue *converter, token10 stack[], int length){
    int i;
    
    Stack *convert = createStack(length);

    for (i = 0; i < length; i++){
        if (isDigit(stack[i][0])){
            Enqueue(converter, stack[i][0]);
        }else if (isOperator(stack[i][0])){
            if (isStackEmpty(convert))
            {
                push(convert, stack[i][0]);
            }else{
                while(!isStackEmpty(convert) && InComingPrecedence(stack[i][0]) <= InStackPrecedence(peekStack(convert)))
                    Enqueue(converter, pop(convert));
                    
                push(convert, stack[i][0]);
            }
        }else if (stack[i][0] == '('){
            push(convert, stack[i][0]);
        }else if (stack[i][0] == ')'){
            int stop = 0;
            while (!isStackEmpty(convert) && !(stop)) {
                Enqueue(converter, pop(convert));

                if(peekStack(convert) != '('){
                    stop = 1;
                    pop(convert);
                }
            }
        }
    }    

    while (!isStackEmpty(convert)){
        Enqueue(converter, pop(convert));
    }

    clearStack(convert);
}

