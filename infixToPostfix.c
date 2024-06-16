#include<string.h>
#include<stdio.h>
#include "queue.c"
#include "stack.c"


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



