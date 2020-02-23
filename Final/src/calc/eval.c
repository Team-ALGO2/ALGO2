#ifndef _MAINGUARD
#define _DISABLECALC // Prevent Redefinitions
#include "../main.h"

#endif // _MAINGUARD


int postFixcalc(char inputString[MAX_INPUT_LENGTH])
{
    stack stack = {-1, {0}}; 
    int i; 
    scanf("%c", inputString);
  
    // Scan all characters 
    for (i = 0; i<inputString[i]; ++i) 
    { 
      
        // If number push
        if (isdigit(inputString[i])) 
            stack_push(&stack, inputString[i] - '0'); 
  
        // If operator pop
        else
        { 
          
            int a = stack_top(&stack); stack_pop(&stack);

            int b = stack_top(&stack); stack_pop(&stack);
            
            switch (inputString[i]) 
            { 
            case '+': stack_push(&stack, add(a,b)); break;
            case '-': stack_push(&stack, subtract(a,b)); break;
            case '*': stack_push(&stack, multiply(a,b)); break;
            case '/': stack_push(&stack, divide(a,b)); break; 
            //case '^': stack_push(&stack, powr(val1,val2)); break;
            //case 's': stack_push(&stack, sqrt(val1)); break;

            } 
        } 
    } 
    return stack_top(&stack); 
    printf ("postfix evaluation: %d", inputString); 
}


//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(void)
{
    
 
} 
#endif // _DEFMAIN