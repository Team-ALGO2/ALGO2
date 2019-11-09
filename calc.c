// TODO REWRITE

#include "main.h"
#include "utils/math.c"


//double add(double a, double b);
//double subtract(double a, double b);
//double multiply(double a, double b);
//double divide(double a, double b);
//long mod(long a, long b);

int main()
{
    double a = 0;
    double b = 0; 
    
    char op[30];
    int on = true;
    //system("clear");
    printf("Choose a number: ");
    scanf("%lf", &a);
    
  do{
      
        
        printf("Choose an operator: ");
        scanf("%s", op);
        
        printf("Choose another number: ");
        scanf("%lf", &b);
        
       double result=1;
        if(strcmp(op, "+") == 0){
            result = add(a,b);
            printf("%.9lf\n", result);
            a = result;
        }
        else if(strcmp(op, "-") == 0){
            result = subtract(a,b);
            printf("%.9lf\n", result);
            a = result;
        }
        else if(strcmp(op, "*") == 0){
            result = multiply(a,b);
            printf("%.9lf\n", result);
            a = result;
        }
        else if(strcmp(op, "/") == 0){
            result = divide(a,b);
            printf("%.9lf\n", result);
            a= result;
        }
        else if(strcmp(op, "sin") == 0){
            result = sin(b*PI/180);
            printf("%.9lf", result);
            a= result;
        }
        else if(strcmp(op, "cos") == 0){
          
            result = cos(b*PI/180);
            printf("%.9lf\n", result);
            a= result;
        }
        else if(strcmp(op, "^") == 0){
          result = powr(a,b);
          printf("%.9lf\n", result);
            a= result;
            
        }
        
        else if(strcmp(op, "sqrt") == 0){
          
            result = squarert(b);
            printf("%.9lf\n", result);
            a= result;
        }
        
        else if(strcmp(op, "cos") == 0){
          
            result = cos(b*PI/180);
            printf("%.9lf\n", result);
            a= result;
        }
        


        else if(strcmp(op, "%") == 0){
            if((float)(int)a != a || (float)(int)b != b){
                printf(YEL "WARNING! MOD CANNOT SUPPORT DECIMALS. CONVERTING TO INTEGER.\n" RESET);
                a = (int)a;
                b = (int)b;
            }
            result = mod(a,b);
            printf("%.9lf", result);
            a= result;
        }

        else if(strcmp(op, "off") == 0){
          
            on = false;
        }
  
    //system("clear");
    }while(on == true);
    return 0;
}
