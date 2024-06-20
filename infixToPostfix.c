/**
 * @brief Check if a character is a digit.
 *
 * This function returns 1 if the character is a digit ('0'-'9'),
 * and 0 otherwise.
 *
 * @param c The character to check.
 * @return 1 if c is a digit, 0 otherwise.
 */
int isDigit(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

/**
 * @brief Check if a character is an operator.
 *
 * This function returns 1 if the character is one of the following operators:
 * +, *, /, -, !, %, ^, <, >, =, |, &.
 * It returns 0 otherwise.
 *
 * @param c The character to check.
 * @return 1 if c is an operator, 0 otherwise.
 */
int isOperator(char c)
{
     if(c == '+' || c == '*' ||c == '/' ||c == '-' || c == '!' || c == '%' ||
        c == '^' ||c == '<' ||c == '>' || c == '=' || c == '|' || c == '&')
        return 1;
    else
        return 0;
}

/**
 * @brief Check if a character is a unary operator.
 *
 * This function returns 1 if the character is the unary operator '!'.
 * It returns 0 otherwise.
 *
 * @param c The character to check.
 * @return 1 if c is a unary operator, 0 otherwise.
 */
int isUnaryOperator(char c)
{
    if(c == '!')
        return 1;
    else
        return 0;
}

/**
 * @brief Check if a character is a parenthesis.
 *
 * This function returns 1 if the character is a parenthesis ('(' or ')').
 * It returns 0 otherwise.
 *
 * @param c The character to check.
 * @return 1 if c is a parenthesis, 0 otherwise.
 */
int isParenthesis(char c)
{
    return (c == '(' || c == ')');
}

/**
 * @brief Extract tokens from an input string and enqueue them.
 *
 * This function processes the input string, grouping digits and operators
 * that must be treated as single tokens, and enqueues them into the provided queue.
 *
 * @param stringInput The input string to process.
 * @param queue Pointer to the queue where tokens will be enqueued.
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
            if(isOperator(stringInput[i+1]) && !isUnaryOperator(stringInput[i+1]))
            {
                strncat(temp, &stringInput[i+1], 1);
                i++;
            }
            enqueue(queue, temp);
            strcpy(temp, "\0");
        }
        else if(isParenthesis(stringInput[i]))
        {
            strncat(temp, &stringInput[i], 1);
            enqueue(queue, temp);
            strcpy(temp, "\0");
        }
    }
}

/**
 * @brief Get the incoming precedence of an operator.
 *
 * This function returns the precedence level of an operator when it is encountered in the input.
 * Higher values indicate higher precedence.
 *
 * @param operator The operator as a string.
 * @return The precedence level of the operator.
 */
int InComingPrecedence(char* operator){
    
    if (strcmp(operator, "!") == 0){
        return 9;
    }else if (strcmp(operator, "^") == 0){
        return 8;
    }else if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0 || strcmp(operator, "%") == 0){
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

/**
 * @brief Get the in-stack precedence of an operator.
 *
 * This function returns the precedence level of an operator when it is in the stack.
 * Higher values indicate higher precedence.
 *
 * @param operator The operator as a string.
 * @return The precedence level of the operator.
 */
int InStackPrecedence(char* operator){
    if (strcmp(operator, "!") == 0){
        return 8;
    }else if (strcmp(operator, "^") == 0){
        return 7;
    }else if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0 || strcmp(operator, "%") == 0){
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

/**
 * @brief Convert an infix expression to postfix notation.
 *
 * This function processes the tokens in the 'keep' queue, converting the infix expression
 * to postfix notation and enqueuing the result into the 'queue'. It uses a stack to manage operators.
 *
 * @param queue Pointer to the queue where the postfix expression will be enqueued.
 * @param keep Pointer to the queue containing the infix expression tokens.
 * @param stack Pointer to the stack used for operator management.
 * @param length The length of the token queue.
 */
void infixToPostfix(Queue* queue, Queue* keep, Stack *stack, int length){
    int i;
    char temp[100];

    for (i = 0; i <= length; i++){
        if (isDigit(keep->token[i][0])){
            enqueue(queue, keep->token[i]); 
        }else if (isOperator(keep->token[i][0])){
           while(stack->topIndex != -1 && InComingPrecedence(keep->token[i]) <= InStackPrecedence(stack->token[stack->topIndex])){ 
                pop(stack, temp);
                enqueue(queue, temp);
            }

            push(stack, keep->token[i]);
        }else if (strcmp(keep->token[i], "(") == 0){
             push(stack, keep->token[i]);
        }else if (strcmp(keep->token[i], ")") == 0){
            while (stack->topIndex != -1 && strcmp(stack->token[stack->topIndex], "(") != 0) {
                pop(stack, temp);
                enqueue(queue, temp);
            }

            pop(stack, temp);
        }
    }

    while (stack->topIndex != -1){
        pop(stack, temp);
        enqueue(queue, temp);
    }

}

