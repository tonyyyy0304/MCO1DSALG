#include<math.h>

int getSum(int operand1, int operand2)
{
    return operand1 + operand2;
}

int getDifference(int operand1, int operand2)
{
    return operand1 - operand2;
}

int getProduct(int operand1, int operand2)
{
    return operand1 * operand2;
}

int getQuotient(int operand1, int operand2)
{
    return operand1 / operand2;
}

int getPower(int operand1, int operand2)
{
    return (int)pow(operand1, operand2);
}