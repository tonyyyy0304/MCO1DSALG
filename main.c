#include<stdio.h>
#include "getters.h"
#include<conio.h>
#include "infixToPostfix.c"

#define MAX_INPUT 255

int main()
{
    Stack operandStack;
    Stack operatorStack;

    Queue equation;
    Queue postfixEquation;
    String256 input;

    initQueue(&equation);
    initQueue(&postfixEquation);
    initStack(&operandStack);
    initStack(&operatorStack);

    int n;
    String256 temp;

    printf("Select how many expressions: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
   {
        scanf(" %s", input);
        

        tokenExtractor(input, &equation);
        infixToPostfix(&postfixEquation, &equation, &operatorStack, equation.tailIndex);
         while(dequeue(&equation, temp)){
            printf("%s ", temp);
        }
        printf("\n");
        while(dequeue(&postfixEquation, temp)){
            printf("%s ", temp);
        }

        printf("\n");
        resetQueue(&postfixEquation);
        resetQueue(&equation);
        resetStack(&operatorStack);
   }

    getch();
}