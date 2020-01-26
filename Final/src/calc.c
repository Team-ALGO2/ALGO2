#include "main.h"

//PROTOTYPING:

int infixToPostfix(stack input, stack inputBits, stack * dataOut, stack * bitsOut);
int parseString(char* inputString, stack *dataOut, stack *binOut);


//MAIN:

int main(void)
{
    stack data = {-1, {0}}; //to store the data that is being manipulated
    stack bin = {-1, {0}};//to store the binairy info that describes if the data in "data" is a char or an int
    char *str = "3+8*98";
    parseString(str, &data, &bin);
} 

//FUNCTIONS:

//a function to split the inputed string into individual arguments in a stack(should be in infix notation)
int parseString(char* inputString, stack *dataOut, stack *binOut)
{
     printf("Begin parsing\n");
    //itterate over the arguments of the input string
    //length needs to be checked every time since we are changeing the size of the string during the loop
    for(int i = 0; i < strlen(inputString); i++)
    {
        
        
        if(isNum(inputString[i]))
        {
            printf("%d is a number\n", atoi(inputString));
            stack_push(dataOut, atoi(inputString)); //pushes the data
            stack_push(binOut, 0); //shows that the data should be interpreted as an int
            inputString = trimOperator(inputString);          
        }
        else
        {
            printf("%c is an opperator\n", inputString[i]);
            int push = inputString[i];
            stack_push(dataOut, push); //pushes the data
            stack_push(binOut, 1); //shows that the data should be interpreted as an char
        }
        
    }
    printf("Done parsing\n");
    return 0;
}

// to convert from an inputed string to postfix notation 
//results are outputed to the dataOut and bitsOut stacks
int infixToPostfix(stack input, stack inputBits, stack * dataOut, stack * bitsOut)
{
    printf("Begin infix to postfix \n");
    //working is only a stack of chars in int form so we do not need to give it a bin stack
    stack working = {-1, {0}};

    //NEED TO FILP BOTH INPUT STACKS

    // set length to the number of inputs in the stack
    int length = stack_length(&input);
    for(int i = 0; i < length - 1; i++)
    {
        // if it is an opperand then push to the output
        if(stack_top(&inputBits) == 0)
        {
            stack_push(dataOut ,(stack_top(&input)));
            stack_pop(&input); //get rid of the data at the top of the stack
            stack_push(bitsOut, 0); // used to identify if a number or char (0 is number)
            stack_pop(&inputBits);//get rid of the bin just inputed
        }
        // if it is a opperator then figure out if to push or directly to output
        else if (stack_top(&inputBits) == 1)
        {
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
    printf("Done infix to postfix \n");
    return 0; //return 0 if done and not failed
}