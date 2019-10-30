#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);


int main(void)
{
    double a = 0;
    double b = 0;
    char op;



    printf("Choose an operator: ");
    scanf("%c", &op);

    // get numbers
    printf("Choose a number: ");
    scanf("%lf", &a);



    printf("Choose a number: ");
    scanf("%lf", &b);


    printf("%f %c %f = ", a,op, b);

     switch(op)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf",a, b, add(a,b));
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf",a, b, subtract(a,b));
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf",a, b, multiply(a,b));
            break;
        case '/':
            printf("%.1lf / %.1lf = %.1lf",a, b, divide(a,b));
            break;
        // operator doesn't match any case constant (+, -, *, /)
        default:
            printf("Error! Operator is not correct");
    }
    
    return 0;
}
    

double add(double a, double b)
{
    return a+b;
}

double subtract(double a, double b)
{
    return a-b;
}

double multiply(double a, double b)
{
    return a*b;
}

double divide(double a, double b)
{
    return a/b;
}
