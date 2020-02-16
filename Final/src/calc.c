#include "main.h"

//PROTOTYPING:

int infixToPostfix(stack input, stack inputBits, stack * dataOut, stack * bitsOut);
int postFixcalc(char* in);
int ParseString(char exp[MAX_INPUT_LENGTH]);
int populateDummy(stack data, stack bin);

stack dummyData = {-1, {0}};  
stack dummyBin = {-1, {0}};

/*
int main (void)
{
    populateDummy(dummyData, dummyBin);
    stack_printer(&dummyData);
    stack_printer(&dummyBin);
}
*/
//compute the postfix string
int ParseString(char exp[MAX_INPUT_LENGTH])
{
    int i = 0;
    int j = 0;
    int counter = 0;
    long number;
    char val[MAX_INPUT_LENGTH];
    if (isCapAlpha(exp[1]))     // Special command: STORE, BASECHANGE
    {
        if (strncmp(exp, "STORE", 6) == 0)
        {
            printf("store comamnd\n");
        }
    }
    while (exp[i] != '\0')
    {
        switch (exp[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                    val[j] = exp[i];
                    j++;
                    break;
            case '+':
                    if (j>0) {
                        number = strtol(val, (char **)NULL, 10);
                        j = 0;
                    }
        }
        
    }
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

//FUNCTIONS:

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