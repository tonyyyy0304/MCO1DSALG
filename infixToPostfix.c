#include<string.h>
#include<stdio.h>


typedef char String100[100];
typedef char String256[256];
typedef char token10[11];

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

void push(token10 stack[], char* src, int* top)
{
    strcpy(stack[*top], src);
    (*top)++;
}

int enqueue(token10 queue[], char* src, int* tail, int* head)
{

    if(*tail == 254)
        return 0;
    else
    {
        if (*head == -1)
            *head = 0;
        *tail += 1;
        strcpy(queue[*tail], src);
        return 1;
    } 
}



void tokenExtractor(char* stringInput, token10 queue[], int* headIndex, int* tailIndex)
{
    int i;

    *headIndex = -1, *tailIndex = -1;

    char temp[100] = "\0";

    for (i=0; i<strlen(stringInput); i++)
    {

        if(isDigit(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);

            if(!isDigit(stringInput[i+1]))
            {
                enqueue(queue, temp, tailIndex, headIndex);
                strcpy(temp, "\0");
            }
        }
        else if(isOperator(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);

            if(!isOperator(stringInput[i+1]))
            {
                enqueue(queue, temp, tailIndex, headIndex);
                strcpy(temp, "\0");
            }
        }
        else if(isParenthesis(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);
            enqueue(queue, temp, tailIndex, headIndex);
            strcpy(temp, "\0");
        }
    }
}

