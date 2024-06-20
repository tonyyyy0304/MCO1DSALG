#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "queue.c"
#include "stack.c"
#include <conio.h>
#include <math.h>
#include "infixToPostfix.c"
#include "evaluatePostfix.c"

#define MAX_INPUT 255

int main()
{
    StackInt operandStack; // this stack is used for evaluating postfix expressions 
    Stack operatorStack; // this stack is used for converting infix to postfix 

    Queue equation; // this queue keeps the tokenized infix expresion
    Queue postfixEquation; // this queue stores postfix expression
    
    String256 input;

    initQueue(&equation); 
    initQueue(&postfixEquation);
    initStackInt(&operandStack);
    initStack(&operatorStack);
    
    String256 temp;
    token10 tempArray[256];

    int stop = 0;
    int error = 0;

    FILE *fp_input;
    FILE *fp_output;

    fp_input = fopen("infix.txt", "r");
    fp_output = fopen("output.txt", "w");

    if (fp_input == NULL){
        printf("Error accessing file");
        return 0;
    }

    if (fp_output == NULL){
        printf("Error accessing file");
        return 0;
    }

    while(fgets(input, sizeof(input), fp_input) != NULL && !(stop)){
        
        printf("Infix: %s\n", input);
        if (strcmp(input, "QUIT") != 0){
            tokenExtractor(input, &equation);
            infixToPostfix(&postfixEquation, &equation, &operatorStack, equation.tailIndex);
        
            int i = 0;
            printf("Postfix: ");
            while(dequeue(&postfixEquation, temp)){
                printf("%s ", temp);
                strcpy(tempArray[i], temp);
                fprintf(fp_output, "%s ", temp);
                i++;
            }
            fprintf(fp_output, "\n");

            printf("\n");

            for(int j = 0; j<i; j++)
                enqueue(&postfixEquation, tempArray[j]);

            int result = evaluatePostfix(&postfixEquation, &operandStack, &error);
            if (!error){
                printf("Answer: %d\n", result);
                fprintf(fp_output, "%d\n", result);
                fprintf(fp_output, "\n");
            }else{
                printf("Error! Division by zero");
                fprintf(fp_output, "Error! Division by zero\n\n");
                error = 0;
            }

            printf("\n");
            
            resetQueue(&postfixEquation);
            resetQueue(&equation);
            resetStack(&operatorStack);
            resetStackInt(&operandStack);
            printf("\n");
        }else if (strcmp(input, "QUIT") == 0){
            stop = 1;
        }
    }

    fclose(fp_input);
    fclose(fp_output);

    return 0;
}
