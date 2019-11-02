#include "utils.h"

// For Global Defines, Use Utils. For Local, Use Here.

// wonky PI definitions
#define PI 3.141592653589

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main()
{
    double a = 0;
    double b = 0;
    char op[3];
    int on = true;

    printf("Choose a number: ");
    //printf("0");
    
    system("clear");
    scanf("%lf", &a);
    


    //printf("%f %c %f = ", a,op, b);
  do{
      
        
        printf("Choose an operator: ");
        scanf("%s",op);
        printf("Choose another number: ");
        scanf("%lf", &b);
        
        if(strcmp(op, "+") == 0){
            printf("%.9lf",add(a,b));
            a = (add(a,b));
            
            }
        else if(strcmp(op, "-") == 0){
            printf("%.9lf", subtract(a,b));
            a = subtract(a,b);
            }
        else if(strcmp(op, "*") == 0){
            printf("%.9lf", multiply(a,b));
            a = multiply(a,b);
        }
        else if(strcmp(op, "/") == 0){
            printf("%.9lf", divide(a,b));
            a= divide(a,b);
            }
        else if(strcmp(op, "sin") == 0){
        printf("%.9lf", sin(b*PI/180));
        a= sin(b*PI/180);
        }
        else if(strcmp(op, "cos") == 0){
        printf("%.9lf", cos(b*PI/180));
        a= sin(b*PI/180);
        }

        
  
    system("clear");
    }while(on == true);
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
