#include "../main.h"

long double computeMath(long double opp1, long double opp2, char opp);
long double postfixCalc(queue input, queue inputBits);

//given 2 queues, will compute them when in postfix for, returns the result
long double postfixCalc(queue input, queue inputBits)
{
    stack opperands = {-1, {0}};
    int length = queue_length(&inputBits);
    for(int i = 0; i < length; i++)
    {
        if (queue_getFront(&inputBits) == 0)
        {
            stack_push(&opperands, queue_getFront(&input));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
        else if (queue_getFront(&inputBits) == 1)
        {
            long double opp2 = stack_top(&opperands);
            stack_pop(&opperands);
            long double opp1 = stack_top(&opperands);
            stack_pop(&opperands);
            char opp = queue_getFront(&input);
            fprintf(stderr, YEL"%Lf %c %Lf computed as: %Lf\n"RESET,opp1, opp, opp2, computeMath(opp1, opp2, opp));
            stack_push(&opperands, computeMath(opp1, opp2, opp));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
    }
    fprintf(stderr, BLU"Evaluated as in function: %Lf\n"RESET, stack_top(&opperands));
    return stack_top(&opperands);
}

//a function that will compute the operation given the 2 opperands under int form and the opperator under char form
long double computeMath(long double opp1, long double opp2, char opp)
{
    switch (opp) 
    {
        case '+': 
            return add(opp1, opp2);
            break;

        case '-': 
            return subtract(opp1, opp2);
            break;

        case '*': 
            return multiply(opp1, opp2);
            break;

        case '/': 
            return divide(opp1, opp2); 
            break;

        case '%': 
            return mod(opp1, opp2);
            break;
            
        case '^': 
            return powr(opp1,opp2);
            break;
        
        default:
            fprintf(stderr, RED"An error has occured in the computation of an equasion\n"RESET);
            break;
    }
    return 1;
}
//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
/*
#ifdef _DEFMAIN
int main(void)
{
   
    char inputString[10];
    scanf("%s", inputString);
  

    printf ("postfix evaluation: %d", postFixcalc(inputString)); 
} 
#endif // _DEFMAIN
*/