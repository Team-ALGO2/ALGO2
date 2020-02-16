#ifndef _MAINGUARD
#include "../main.h"
#endif

// to convert from an inputed string to postfix notation 
//results are outputed to the dataOut and bitsOut stacks
int infixToPostfix(stack input, stack inputBits, stack * dataOut, stack * bitsOut)
{
    printf("Begin infix to postfix \n");
    //working is only a stack of chars in int form so we do not need to give it a bin stack
    stack working = {-1, {0}};

    // set length to the number of inputs in the stack
    int length = stack_length(&input);
    for(int i = 0; i < length - 1; i++)
    {
        // if it is an opperand then push to the output
        if(stack_top(&inputBits) == 0)
        {
            printf("Pushing number: %d\n", stack_top(&working));
            stack_push(dataOut ,(stack_top(&input)));
            stack_pop(&input); //get rid of the data at the top of the stack
            stack_push(bitsOut, 0); // used to identify if a number or char (0 is number)
            stack_pop(&inputBits);//get rid of the bin just inputed
        }
        // if it is a opperator then figure out if to push or directly to output
        else if (stack_top(&inputBits) == 1)
        {
            printf("Pushing operator: %d\n", stack_top(&working));
            while (!stack_isEmpty(&working) && oppPres(stack_top(&working), stack_top(&input)) == -1)
            {
                stack_push(dataOut, stack_top(&working)); //push the data
                stack_push(bitsOut, 1); //push 1 because it is a char
                stack_pop(&working);
            }
            stack_push(&working, stack_top(&input));
            stack_pop(&input);
            stack_pop(&inputBits);
        }
    }
    //need to push the remaining chars to the end once all of the opperands have been pushed
    while(!stack_isEmpty(&working))
    {
        stack_push(dataOut, stack_top(&working)); //push the data
        stack_push(bitsOut, 1); //push 1 because it is a char
        stack_pop(&working);
    }
    stack_printer(dataOut);
    printf("Done infix to postfix \n");
    return 0; //return 0 if done and not failed
}