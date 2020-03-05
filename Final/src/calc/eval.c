#include "../main.h"

int computeMath(int opp1, int opp2, char opp);
int postFixcalc(queue input, queue inputBits);

int postFixcalc(queue input, queue inputBits)
{
    stack opperands = {-1, {0}};
    int length = queue_length(&input);
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
            int opp2 = stack_pop(&opperands);
            int opp1 = stack_pop(&opperands);
            stack_push(&opperands, computeMath(opp1, opp2, queue_getFront(&input)));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
    }
    return stack_pop(&opperands);
}

//a function that will compute the operation given the 2 opperands under int form and the opperator under char form
int computeMath(int opp1, int opp2, char opp)
{
    switch (opp) 
        { 
            case '+': 
                return add(opp1,opp2);

            case '-': 
                return subtract(opp1,opp2);

            case '*': 
                return multiply(opp1,opp2);

            case '/': 
                return divide(opp1,opp2); 

            case '%': 
                return mod(opp1,opp2);
                
            case '^': 
                return powr(opp1,opp2);
        }
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