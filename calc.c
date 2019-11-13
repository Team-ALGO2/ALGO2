// TODO REWRITE

#include "main.h"

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
    
  do
  {
      
        
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
            a = result;
        }

        else if(strcmp(op, "sin") == 0){
            result = sine(b);
            printf("%.9lf\n", result);
            a = result;
        }

        else if(strcmp(op, "cos") == 0){
          
            result = cosine(b);
            printf("%.9lf\n", result);
            a = result;
        }

        else if(strcmp(op, "tan") == 0){
          
            result = tangent(b);
            printf("%.9lf\n", result);
            a = result;
        }

        else if(strcmp(op, "sinh") == 0){
            result = sineh(b);
            printf("%.9lf\n", result);
            a = result;
        }
         
        else if(strcmp(op, "cosh") == 0){
          
            result = cosineh(b);
            printf("%.9lf\n", result);
            a = result;
        }

        else if(strcmp(op, "^") == 0){
          result = powr(a,b);
          printf("%.9lf\n", result);
            a = result;
        }
        
        else if(strcmp(op, "sqrt") == 0){
            result = squarert(b);
            printf("%.9lf\n", result);
            a = result;
        }
        
        else if(strcmp(op, "cos") == 0){
            result = cosine(b*PI/180);
            printf("%.9lf\n", result);
            a= result;
        }

        else if(strcmp(op, "%") == 0){
            if((float)(long)a != a || (float)(long)b != b)
            {
                printf(YEL "WARNING! MOD CANNOT SUPPORT DECIMALS. CONVERTING TO INTEGER.\n" RESET);
                a = (long)a;
                b = (long)b;
            }
            result = mod(a,b);
            printf("%.9f\n", result);
            a = (float)result; // turn Back To Float Lol
        }

        else if(strcmp(op, "!") == 0){
            if((float)(long long)b != b)
            {
                printf(YEL "WARNING! FACTORIAL CANNOT SUPPORT DECIMALS. CONVERTING TO INTEGER.\n" RESET);
                b = (long long)b;
            }
            result = factorial(b);
            printf("%.9f\n", result);
            a = (float)result; // turn Back To Float Lol
        }

        else if(strcmp(op, "|") == 0){
            result = baseConvert(a ,b);
            printf("%.9f\n", result);
        }
        
        else if(strcmp(op, "off") == 0 || strcmp(op, "exit") == 0 || strcmp(op, "quit") == 0 || strcmp(op, "q") == 0)
        {
            on = false;
        }
        
        else if(strcmp(op, "C") == 0){
            if((float)(long)a != a || (float)(long)b != b)
            {
                printf(YEL "WARNING! CHOOSE CANNOT SUPPORT DECIMALS. CONVERTING TO INTEGER.\n" RESET);
                a = (long)a;
                b = (long)b;
            }
            result = aChooseB(a,b);
            printf("%.9f\n", result);
            a = (float)result; // turn Back To Float Lol
        }
        
        else if(strcmp(op, "P") == 0){
            if((float)(long)a != a || (float)(long)b != b)
            {
                printf(YEL "WARNING! PERMUTATION CANNOT SUPPORT DECIMALS. CONVERTING TO INTEGER.\n" RESET);
                a = (long)a;
                b = (long)b;
            }
            result = aPermB(a,b);
            printf("%.9f\n", result);
            a = (float)result; // turn Back To Float Lol
        }

        else
        {
            printf("Unknown Command\n");
        }

        
  
    //system("clear");
    }while(on == true);
    return 0;
}
