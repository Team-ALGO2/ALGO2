#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int substract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);


int main(void)
{
    int a = 0;
    int b = 0;
    char op = '+';




    // get numbers
    printf("Choose a number: ");
    scanf("%d", &a);

    printf("Choose an operator: ");
    scanf("%1s", &op);

    printf("Choose a number: ");
    scanf("%d", &b);


    printf("%d %c %d = ", a, op, b);


    // Do operations
    if (op == '+')
    {
        printf("%d", add(a, b));
    }
    else if (op == '-')
    {
        printf("%d", substract(a, b));
    }
    else if (op == '*')
    {
        printf("%d", multiply(a, b));
    }
    else if (op == '/')
    {
        printf("%d", divide(a, b));
    }

    printf("\n");

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