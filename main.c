#include<stdio.h>
#include "./getters.h"
#include<conio.h>

struct operandStack
{
    int operandNum;
    struct operandStack* next;
};

struct operatorStack
{
    char operatorChar;
    struct operatorStack* next;
};

typedef char String256[257];

void translateInfixToPostfix()
{

}



int main()
{
    String256 input;
    scanf("%s", input);

    //String256 equationQueue;


    printf("%d", getSum(1,2));
    getch();
}