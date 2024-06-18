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
    
    String256 temp;

    do{
        printf("Input infix expression (enter QUIT to end program): ");
        scanf(" %s", input);
        
        if (strcmp(input, "QUIT") != 0){
            tokenExtractor(input, &equation);
            infixToPostfix(&postfixEquation, &equation, &operatorStack, equation.tailIndex);

            printf("\n");
            printf("Postfix: ");
            while(dequeue(&postfixEquation, temp)){
                printf("%s ", temp);
            }

            printf("\n");
            resetQueue(&postfixEquation);
            resetQueue(&equation);
            resetStack(&operatorStack);

            printf("\n");
        }
    }while(strcmp(input, "QUIT") != 0);

    return 0;
}
