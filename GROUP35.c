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
    Queue postfixEquation; // this queue stores postfix expression
    
    initQueue(&postfixEquation);
    initStackInt(&operandStack);
    initStack(&operatorStack);
    
    String256 input;
    String256 temp;
    token10 tokenInfix[256];
    token10 tempArray[256];
    
    int counter = 0;
    int stop = 0;
    int error = 0;

    FILE *fp_input;
    FILE *fp_output;

    fp_input = fopen("TESTCASE.txt", "r");
    fp_output = fopen("RESULT.txt", "w");

    if (fp_input == NULL){
        printf("Error accessing file");
        return 0;
    }

    if (fp_output == NULL){
        printf("Error accessing file");
        return 0;
    }

    while(fgets(input, sizeof(input), fp_input) != NULL && !(stop)){
        
        printf("%s", input);
        fprintf(fp_output, "%s", input);
        if (strcmp(input, "QUIT\n") != 0 && strcmp(input, "QUIT") != 0){
            tokenExtractor(input, tokenInfix, &counter);
            infixToPostfix(&postfixEquation, tokenInfix, &operatorStack, counter);
        
            int i = 0;
            while(dequeue(&postfixEquation, temp)){
                printf("%s ", temp);
                strcpy(tempArray[i], temp);
                fprintf(fp_output, "%s ", temp);
                i++;
            }
            fprintf(fp_output, "\n");
            
            for(int j = 0; j<i; j++)
                enqueue(&postfixEquation, tempArray[j]);
            printf("\n");
            int result = evaluatePostfix(&postfixEquation, &operandStack, &error);
            if (!error){
                printf("%d\n", result);
                fprintf(fp_output, "%d\n", result);
                fprintf(fp_output, "\n");
            }else{
                printf("Error! Division by zero\n");
                fprintf(fp_output, "Error! Division by zero\n\n");
                error = 0;
            }

            printf("\n");
            
            resetQueue(&postfixEquation);
            resetStack(&operatorStack);
            resetStackInt(&operandStack);

            for(int k=0; k<256; k++)
                strcpy(tokenInfix[k],"\0");

        }else if (strcmp(input, "QUIT\n") == 0 || strcmp(input, "QUIT") == 0){
            stop = 1;
        }
    }

    fclose(fp_input);
    fclose(fp_output);

    return 0;
}
