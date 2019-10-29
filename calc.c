#include <stdio.h>
#include <stdlib.h>

int add(int, int);
int substract(int, int);
int multiply(int, int);
int divide(int, int);
int mod(int, int);



int main(void)
{

    int a = 0;
    int b = 0;
    char op;

    //need to rewrite this to enable multiple number calculatrions
    // i think that we could use stacks to load all the numbers and do fifo to unpack all the numbers
    // get numbers
    //should also make a stack for the opperators aswell as the partenthases for BEDMAS
    printf("Choose a number: ");
    scanf("%d", &a);

    printf("Choose an operator: ");
    scanf("%1s", &op);

    printf("Choose a number: ");
    scanf("%d", &b);


    printf("%d %c %d = ", a, op, b);


    switch( op )
{
	case '+':
        printf("%d", add(a, b));
	case '-':
        printf("%d", substract(a, b));
	case '*':
        printf("%d", multiply(a, b));
    case '/':
        printf("%d", divide(a, b));
    case '%':
        printf("%d", mod(a, b));

}
}


int add(a, b)
{
    return a+b;
}

int substract(a, b)
{
    return a-b;
}

int multiply(a, b)
{
    return a*b;
}

int divide(a, b)
{
    return a/b;
}

int mod(a, b)
{
    return a%b;
}