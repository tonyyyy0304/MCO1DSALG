#include <string.h>
#include <stdio.h>
#include <math.h>
#include "queue.c"
#include "stack.c"
#include "infixToPostfix.c"



int postfixAnswer(int operand1, int operand2, char* operator) {
    
    
    if (strcmp(operator, "^") == 0){
        return pow(operand1, operand2);
    }else if (strcmp(operator, "*") == 0){
        return operand1 * operand2;   
    }else if (strcmp(operator, "/") == 0){
        if (operand2 == 0){
            printf("Division by zero error!");
        }
        else return operand1 / operand2;

    }else if (strcmp(operator, "+") == 0){
        return operand1 + operand2;
    }else if (strcmp(operator, "-") == 0){
        return operand1 - operand2;
    }else if (strcmp(operator, "<=") == 0){
        return operand1 <= operand2;
    }else if(strcmp(operator, ">=") == 0 ){
        return operand1 >= operand2;
    }else if(strcmp(operator, ">") == 0 ){
        return operand1 > operand2;
    }else if (strcmp(operator, "<") == 0){
        return operand1 < operand2;
    }else if (strcmp(operator, "==") == 0){
        return operand1 == operand2;
    }else if ( strcmp(operator, "!=") == 0){
        return operand1 != operand2;
    }else if (strcmp(operator, "&&") == 0){
        return operand1 && operand2;
    }else if (strcmp(operator, "||") == 0){
        return operand1 || operand2; 
    }

    return 0;

}



int evaluatePostfix(Queue *queue, Stack *stack){

    int operand1, operand2, result;
    char *operator;

    while (queue->headIndex != -1 && queue->tailIndex != -1){
        dequeue(queue, &operator);

         if (isDigit(operator[0]) && isDigit(operator[1])){
                push(stack, atoi(operator));
     }else{
        pop(stack, operand2);
        pop(stack, operand1);
        result = postfixAnswer(operand1, operand2, operator);
        push(stack, result);
     }

     free(operator);

}

return pop(stack, result);
}