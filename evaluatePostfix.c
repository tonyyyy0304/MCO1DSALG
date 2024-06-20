
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



int evaluatePostfix(Queue *queue, StackInt *stack){

    int operand1, operand2, result;
    char *operator;
    int temp;

    while (queue->headIndex != -1 && queue->tailIndex != -1){
        dequeue(queue, operator);

         if (isDigit(operator[0])){
                temp = atoi(operator);
                pushInt(stack, temp);
        }
        else{
            popInt(stack, &operand2);
            popInt(stack, &operand1);
            result = postfixAnswer(operand1, operand2, operator);
            pushInt(stack, result);
        }
        free(operator); 
        operator = (char *)malloc(10 * sizeof(char));
    }
    popInt(stack, &result);

    return result;
}