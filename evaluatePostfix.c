/**
 * @brief Evaluate a postfix expression given two operands and an operator.
 *
 * This function performs arithmetic or logical operations based on the given operator.
 * It returns the result of the operation between operand1 and operand2.
 * If a division by zero is attempted, it sets the error flag.
 *
 * @param operand1 The first operand.
 * @param operand2 The second operand.
 * @param operator The operator as a string.
 * @param error Pointer to an integer for error handling.
 * @return The result of the operation.
 */
int postfixAnswer(int operand1, int operand2, char* operator, int* error) {
    
    if (strcmp(operator, "^") == 0){
        return pow(operand1, operand2);
    }else if (strcmp(operator, "*") == 0){
        return operand1 * operand2;   
    }else if (strcmp(operator, "/") == 0){
        if (operand2 == 0){
            *error = 1;
        }
        else return operand1 / operand2;
    }else if (strcmp(operator, "%") == 0){
        return operand1 % operand2;
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
    }else if (strcmp(operator, "!") == 0){
        return !operand2;
    }

    return 0;

}

/**
 * @brief Evaluate a postfix expression stored in a queue and return the result.
 *
 * This function processes a queue containing a postfix expression, evaluates it
 * using a stack for operands, and returns the final result. If an error occurs
 * (e.g., division by zero), it sets the error flag and returns a predefined error value.
 *
 * @param queue Pointer to the Queue containing the postfix expression.
 * @param stack Pointer to the StackInt used for evaluation.
 * @param error Pointer to an integer for error handling.
 * @return The result of the postfix expression, or -99999 if an error occurred.
 */
int evaluatePostfix(Queue *queue, StackInt *stack, int* error){

    int operand1, operand2, resultInt = 0;
    char operator[100];
    int temp;
    
    while (dequeue(queue, operator) && !(*error)){
        
        if(isDigit(operator[0])){
            temp = atoi(operator);
            pushInt(stack, temp);
        }
        else if(isUnaryOperator(operator[0]) && !isOperator(operator[1]))
        {
            popInt(stack, &operand2);
            operand1 = 0;
            resultInt = postfixAnswer(operand1, operand2, operator, error);
            pushInt(stack, resultInt);
        }
        else{
            popInt(stack, &operand2);
            popInt(stack, &operand1);
            resultInt = postfixAnswer(operand1, operand2, operator, error);
            pushInt(stack, resultInt);
        }
    }
    popInt(stack, &resultInt);
    if(*error == 0)
        return resultInt;
    else
        return -99999;

}
