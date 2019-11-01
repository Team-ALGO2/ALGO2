#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);



int main()
{
    double a = 0;
    double b = 0;
    char op;
    int on = 1;

    printf("Choose a number: ");
    scanf("%lf", &a);

    

    


    //printf("%f %c %f = ", a,op, b);
  do{
        printf("Choose an operator: ");
        scanf(" %c", &op);
        printf("Choose a number: ");
        
        scanf("%lf", &b);
        
        if(op == '+'){
            printf("%.1lf + %.1lf = %.1lf",a, b, add(a,b));
            a = (add(a,b));
            
            }
        else if(op == '-'){
            printf("%.1lf - %.1lf = %.1lf",a, b, subtract(a,b));
            a = subtract(a,b);
            }
        else if(op == '*'){
            printf("%.1lf * %.1lf = %.1lf",a, b, multiply(a,b));
            a = multiply(a,b);
        }
        else if(op == '/'){
            printf("%.1lf / %.1lf = %.1lf",a, b, divide(a,b));
            a= divide(a,b);
            }
      
        
      printf("\nType 0 to leave, 1 to stay");
      scanf("%d", &on);
    
    }while(on == 1);
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
