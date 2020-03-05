#include "../main.h"

int computeMath(int opp1, int opp2, char opp);
int postfixCalc(queue input, queue inputBits);

int postfixCalc(queue input, queue inputBits)
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
            int opp2 = stack_top(&opperands);
            stack_pop(&opperands);
            int opp1 = stack_top(&opperands);
            stack_pop(&opperands);
            char opp = queue_getFront(&input);
            printf("%d %c %d computed as: %d\n",opp1, opp, opp2, computeMath(opp1, opp2, opp));
            stack_push(&opperands, computeMath(opp1, opp2, opp));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
    }
    return stack_top(&opperands);
}

//a function that will compute the operation given the 2 opperands under int form and the opperator under char form
int computeMath(int opp1, int opp2, char opp)
{
    switch (opp) 
        {
            case '+': 
                return opp1 + opp2;
                break;

            case '-': 
                return opp1 - opp2;
                break;

            case '*': 
                return opp1 * opp2;
                break;

            case '/': 
                return opp1 / opp2; 
                break;

            case '%': 
                return opp1 % opp2;
                break;
                
            case '^': 
                return powr(opp1,opp2);
                break;
            
            default:
                printf("An error has occured in the computation of an equasion");
                break;
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