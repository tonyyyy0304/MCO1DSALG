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

    int stop = 0;

    FILE *fp_input;
    FILE *fp_output;

    fp_input = fopen("infix.txt", "r");
    fp_output = fopen("output.txt", "a");

    if (fp_input == NULL){
        printf("Error accessing file");
        return 0;
    }

    if (fp_output == NULL){
        printf("Error accessing file");
        return 0;
    }

    while(fgets(input, sizeof(input), fp_input) != NULL && !(stop)){
        
        printf("Input: %s", input);
        if (strcmp(input, "QUIT") != 0){
            tokenExtractor(input, &equation);
            infixToPostfix(&postfixEquation, &equation, &operatorStack, equation.tailIndex);
            
            printf("\n");
            printf("Postfix: ");

            int i = 0;
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

            int result = evaluatePostfix(&postfixEquation, &operandStack);
            if (result != -1){
                printf("Answer: %d", result);
                fprintf(fp_output, "%d\n", result);
                fprintf(fp_output, "\n");
            }else{
                printf("Error! Division by zero");
                fprintf(fp_output, "Error! Division by zero\n\n");
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
