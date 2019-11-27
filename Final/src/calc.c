    // TODO REWRITE

#include "main.h"

//Int to track the mode of the calcualor. 0 is DEC, 1 is BIN, 2 is HEX, 3 is ASTRO
int mode = 0;

int main(int argc, char *argv[])
{
    //checks that the correct number of comand line arguments were parsed
    if (argc > 2)
    {
        fprintf(stderr, "Usage: ./calc MODE or leave empty for decimal\n");
        return 1;
    }
    
    //looks at that the mode the user wants to boot into and set mode to that
    else if (argc == 2)
    {
        if (strcmp(argv[1], "DEC") == 0)
        {
            mode = 0;
        }
        else if (strcmp(argv[1], "BIN") == 0)
        {
            mode = 1;
        }
        else if (strcmp(argv[1], "HEX") == 0)
        {
            mode = 2;
        }
        else if (strcmp(argv[1], "AST") == 0)
        {
            mode = 3;
        }
        else if (strcmp(argv[1], "HELP") == 0)
        {
            fprintf(stderr, "Usage: ./calc MODE. Modes are DEC(decimal) BIN(binary) HEX(hexadecimal) and AST(astronomical) leave empty for decimal\n");
            return 1;
        }
    }
    //the default case is that mode is decimal so 0
    else
        {
            mode = 0;
        }
    
    
    
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

       /*
       *
       * BASIC COMMANDS
       * 
       */

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

        else if(strcmp(op, "^") == 0){
            result = powr(a,b);
            printf("%.9lf\n", result);
            a = result;
        }

        else if(strcmp(op, "%") == 0){
            result = dmod(a,b);
            printf("%.9lf\n", result);
            a = result;
        }

        /*
        *
        * ADVANCED COMMANDS
        * 
        */
        
        else if(strcmp(op, "sqrt") == 0){
            result = squarert(b);
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
        
        else if(strcmp(op, "off") == 0 || strcmp(op, "exit") == 0 || strcmp(op, "quit") == 0 || strcmp(op, "q") == 0)
        {
            on = false;
        }

        else
        {
            printf("Unknown Command\n");
        }

        
  
    //system("clear");
    }while(on == true);
    return 0;
}
