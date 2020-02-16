#ifndef _MAINGUARD
#include "../main.h"
#endif

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
          
            int val1 = stack_top(&stack); stack_pop(&stack);

            int val2 = stack_top(&stack); stack_pop(&stack);
            
            switch (inputString[i]) 
            { 
            case '+': stack_push(&stack, val2 + val1); break;
            case '-': stack_push(&stack, val2 - val1); break;
            case '*': stack_push(&stack, val2 * val1); break;
            case '/': stack_push(&stack, val2/val1); break; 
            //case '^': stack_push(&stack, powr(val1,val2)); break;
            //case 's': stack_push(&stack, sqrt(val1)); break;

            } 
        } 
    } 
    return stack_top(&stack); 
}