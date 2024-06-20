#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "queue.h"
#include "queue.c"
#include "stack.c"
#include <conio.h>
#include<math.h>
#include "infixToPostfix.c"
#include "evaluatePostfix.c"

#define MAX_INPUT 255

int main()
{
    StackInt operandStack;
    Stack operatorStack;

    Queue equation;
    Queue postfixEquation;
    
    String256 input;

    initQueue(&equation);
    initQueue(&postfixEquation);
    initStackInt(&operandStack);
    initStack(&operatorStack);
    
    String256 temp;
    String100 tempArray[256];

    do{
        printf("Input infix expression (enter QUIT to end program): ");
        scanf(" %s", input);
        
        if (strcmp(input, "QUIT") != 0){
            tokenExtractor(input, &equation);
            infixToPostfix(&postfixEquation, &equation, &operatorStack, equation.tailIndex);
            
            printf("\n");
            printf("Postfix: ");

            int i = 0;
            while(dequeue(&postfixEquation, temp)){
                printf("%s ", temp);
                strcpy(tempArray[i], temp);
                i++;
            }
            printf("\n");

            for(int j = 0; j<i; j++)
                enqueue(&postfixEquation, tempArray[j]);

            int result = evaluatePostfix(&postfixEquation, &operandStack);
            printf("%d", result);

            printf("\n");
            
            resetQueue(&postfixEquation);
            resetQueue(&equation);
            resetStack(&operatorStack);
            resetStackInt(&operandStack);
            printf("\n");
        }
    }while(strcmp(input, "QUIT") != 0);

    return 0;
}
