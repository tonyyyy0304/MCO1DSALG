
int postfixAnswer(int operand1, int operand2, char* operator, int error) {
    
    if (strcmp(operator, "^") == 0){
        return pow(operand1, operand2);
    }else if (strcmp(operator, "*") == 0){
        return operand1 * operand2;   
    }else if (strcmp(operator, "/") == 0){
        if (operand2 == 0){
            
            return error = 1;
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
    }

    return 0;

}

int evaluatePostfix(Queue *queue, StackInt *stack){

    int operand1, operand2, resultInt = 0, error = 0;
    char operator[100];
    int temp;
    
    while (dequeue(queue, operator) && error = 0){
        
        if(isDigit(operator[0])){
            temp = atoi(operator);
            pushInt(stack, temp);
        }
        else{
            popInt(stack, &operand2);
            popInt(stack, &operand1);
            resultInt = postfixAnswer(operand1, operand2, operator);
            pushInt(stack, resultInt);
        }
    }
    popInt(stack, &resultInt);
    return resultInt;
}
