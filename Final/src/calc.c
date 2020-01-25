#include "main.h"

//a function to split the inputed string into individual arguments in a stack(should be in infix notation)
stack parseString(char* inputString)
{
    stack out = {-1, {0}};
    //itterate over the arguments of the input string
    //length needs to be checked every time since we are changeing the size of the string during the loop
    for(int i = 0; i < strlen(inputString); i++)
    {
        if(isNum(inputString[i]))
        {
            printf("%s is a number\n", unAtoi(atoi(inputString)));
            //push to the infix stack here
            inputString = trimOperator(inputString);
        }
        else
        {
            printf("%c is an opperator", inputString[i]);
            //push to the infix stack here
        }
        
    }
    printf("Done parsing\n");
    return out;
}

//to convert from an inputed string to postfix notation (output is a stack of all the opperands and opperators)
stack infixToPostfix(char* input)
{
    char* expression = input;
    stack working = {-1, {0}};
    stack out = {-1, {0}};
    //set length to the number of inputs in the stack
    int length = strlen(input);
    char * result = "";
    for(int i = 0; i < length - 1; i++)
    {
        //if it is an opperand then push to the output
        if(isNum(input[i]) == -1)
        {
            stack_push(&out, unAtoi(atoi(input)));
        }
        //if it is a opperator then figure out if to push or directly to output
        else if (!stack_isEmpty(&working))
        {
            while (!stack_isEmpty(&working) && oppPres(stack_top(&working), input[i]))
            {
                /* code */
            }
        }
    }
}

/*
int main(void)
{
    char *str = "3+8*(sqrt8)";
    parseString(str);
} 
*/