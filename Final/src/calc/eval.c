#ifndef _MAINGUARD
#define _DISABLECALC // Prevent Redefinitions
#include "../main.h"

#endif // _MAINGUARD


int postFixcalc(char inputString[MAX_INPUT_LENGTH])
{
    stack stack = {-1, {0}}; 
    int i; 
    
  
    // Scan all characters 
    for (i = 0; i<inputString[i]; ++i) 
    { 
      
        // If number push
        if (isdigit(inputString[i])) 
            stack_push(&stack, inputString[i] - '0'); 
  
        // If operator pop
        else
        { 
            int a, b;
            switch (inputString[i]) 
            { 
                case '+': 
                    a = stack_top(&stack); stack_pop(&stack);
                    b = stack_top(&stack); stack_pop(&stack);
                    stack_push(&stack, add(a,b)); break;

                case '-': 
                    a = stack_top(&stack); stack_pop(&stack);
                    b = stack_top(&stack); stack_pop(&stack);
                    stack_push(&stack, subtract(a,b)); break;

                case '*': 
                    a = stack_top(&stack); stack_pop(&stack);
                    b = stack_top(&stack); stack_pop(&stack);
                    stack_push(&stack, multiply(a,b)); break;

                case '/': 
                    a = stack_top(&stack); stack_pop(&stack);
                    b = stack_top(&stack); stack_pop(&stack);
                    stack_push(&stack, divide(a,b)); break; 

                case '^': 
                    a = stack_top(&stack); stack_pop(&stack);
                    b = stack_top(&stack); stack_pop(&stack);
                    stack_push(&stack, powr(a,b)); break;

                case 's': 
                    b = stack_top(&stack); stack_pop(&stack);
                    stack_push(&stack, squarert(b)); break;
                
                case '!': 
                    b = stack_top(&stack); stack_pop(&stack);
                    stack_push(&stack, factorial(b)); break;
            } 
        } 
    } 
    return stack_top(&stack); 
    
}


//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(void)
{
   
    char inputString[10];
    scanf("%s", inputString);
  

    printf ("postfix evaluation: %d", postFixcalc(inputString)); 
} 
#endif // _DEFMAIN