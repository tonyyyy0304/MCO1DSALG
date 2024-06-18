#include<string.h>
#include<stdio.h>
#include "queue.c"
#include "stack.c"

typedef char output[10];

int isDigit(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int isOperator(char c)
{
     if(c == '+' || c == '*' ||c == '/' ||c == '-' || c == '!' || c == '%' ||
        c == '^' ||c == '<' ||c == '>' || c == '=' || c == '|' || c == '&')
        return 1;
    else
        return 0;
}

int isParenthesis(char c)
{
    return (c == '(' || c == ')');
}

/*
*   This function groups digits and operators that must be treated as one token in the translation algorithm
*
*/
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

int InComingPrecedence(char* operator){
    
    if (strcmp(operator, "^") == 0){
        return 7;
    }else if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0){
        return 6;
    }else if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0){
        return 5;
    }else if (strcmp(operator, "<=") == 0 || strcmp(operator, ">=") == 0 || 
                strcmp(operator, ">") == 0 || strcmp(operator, "<") == 0){
        return 4;
    }else if (strcmp(operator, "==") == 0 || strcmp(operator, "!=") == 0){
        return 3;
    }else if (strcmp(operator, "&&") == 0){
        return 2;
    }else if (strcmp(operator, "||") == 0){
        return 1;
    }

    return 0;
}

int InStackPrecedence(char* operator){

    if (strcmp(operator, "^") == 0){
        return 7;
    }else if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0){
        return 6;
    }else if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0){
        return 5;
    }else if (strcmp(operator, "<=") == 0 || strcmp(operator, ">=") == 0 || 
                strcmp(operator, ">") == 0 || strcmp(operator, "<") == 0){
        return 4;
    }else if (strcmp(operator, "==") == 0 || strcmp(operator, "!=") == 0){
        return 3;
    }else if (strcmp(operator, "&&") == 0){
        return 2;
    }else if (strcmp(operator, "||") == 0){
        return 1;
    }
    return 0;
}


/*
    This function translates the tokenized infix expression to postfix

    param:
    Queue* queue : this is the address of queue that will hold the translated postfix expression
    Queue* keep : this is the address pf queue that holds the tokenized infix expression
    Stack* stack : this is the address of operator stack
    int length : this is the length of the infix notation to be translated

*/
void infixToPostfix(Queue* queue, Queue* keep, Stack *stack, int length){
    int i;
    char temp[100];

    for (i = 0; i <= length; i++){
        if (isDigit(keep->token[i][0])){
            enqueue(queue, keep->token[i]); //if token is a number, immediately enqueue it to the postfix queue
        }else if (isOperator(keep->token[i][0])){
           while(stack->topIndex != -1 && InComingPrecedence(keep->token[i]) <= InStackPrecedence(stack->token[stack->topIndex])){ //this loop compares the precedence on the stack and the incoming operator
                pop(stack, temp);//in the postfix algo, we pop if the stack precedence has higher or equal precedence
                enqueue(queue, temp);//this delivers the operator to the postfix expression queue
            }

            push(stack, keep->token[i]);//after checking precedence, we push to the operator stack
            //it is important to note that the while loop may not happen, thus directly pushing the operator to the stack
        }else if (strcmp(keep->token[i], "(") == 0){
             push(stack, keep->token[i]);//we always push open parenthesis
        }else if (strcmp(keep->token[i], ")") == 0){
            while (stack->topIndex != -1 && strcmp(stack->token[stack->topIndex], "(") != 0) {
                pop(stack, temp);//we always pop everything inside the parentheses
                enqueue(queue, temp);
            }

            pop(stack, temp);// this is to remove the open parenthesis
        }
    }

    while (stack->topIndex != -1){
        pop(stack, temp);//if there are remaining operators in stack after scanning all tokens, we pop everything inside it
        enqueue(queue, temp);
    }

}

