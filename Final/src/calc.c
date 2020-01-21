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

//a funtion the will translate an infix stack of opperands and opperators into a stack in postfix order
stack infixToPostfix(stack input)
{
    //TODO
}

int main(void)
{
    char *str = "3+8*(sqrt8)";
    parseString(str);
} 