
// Import Libraries + Modules
#include "main.h"


//FUNCTION:

int populateDummy(stack data, stack bin) 
{
    //populate the data
    stack_push(&data, 5);
    stack_push(&data, 1);
    stack_push(&data, 53);
    stack_push(&data, 2);
    stack_push(&data, 2);
    stack_push(&data, 1);
    stack_push(&data, 34);
    stack_push(&data, 2);
    stack_push(&data, 19);

    //populate the bin
    stack_push(&bin, 0);
    stack_push(&bin, 1);
    stack_push(&bin, 0);
    stack_push(&bin, 1);
    stack_push(&bin, 0);
    stack_push(&bin, 1);
    stack_push(&bin, 0);
    stack_push(&bin, 1);
    stack_push(&bin, 0);
}

// Main Calculator Function
int main (void)
{
    stack dummyData = {-1, {0}};  
    stack dummyBin = {-1, {0}};
    populateDummy(dummyData, dummyBin);
    stack_printer(&dummyData);
    stack_printer(&dummyBin);
}




//MAIN:
/*
int main(void)
{
    /*
    stack data = {-1, {0}}; //to store the data that is being manipulated
    stack bin = {-1, {0}}; //to store the binairy info that describes if the data in "data" is a char or an int
    char str[MAX_INPUT_LENGTH] = "3+8*98";
    parseString(str, &data, &bin);
    char in[100] = "whatever you want but change this to a stack";
    printf ("postfix evaluation: %d", postFixcalc(in));

   ///



   stack input = {-1, {0}};
   stack inputBits = {-1, {0}};
   stack *dataOut = {-1, {0}};
   stack *bitsOut = {-1, {0}};

   stack_push(&input, 5);
   stack_push(&inputBits, 0);
   stack_push(&input, 43);
   stack_push(&inputBits, 1);
   stack_push(&input, 7);
   stack_push(&inputBits, 0);

   infixToPostfix(input, inputBits, &dataOut, &bitsOut);
   stack_printer(&dataOut);
   stack_printer(&bitsOut);

} 
*/