#ifndef _MAINGUARD
#define _DISABLECALC // Prevent Redefinitions
#include "../main.h"
#include "eval.c"
#endif // _MAINGUARD

// to convert from an inputed string to postfix notation 
//the input is 2 queues of data and binairy to discribe how to interpret the data
//results are outputed to the dataOut and bitsOut queue
int infixToPostfix(queue input, queue inputBits, queue * dataOut, queue * bitsOut)
{
    //working is only a stack of chars in int form so we do not need the give it a bin stack
    stack working = {-1, {0}};

    // set length to the number of inputs in the queue
    int length = queue_length(&input);
    for(int i = 0; i < length; i++)
    {
    //    #ifdef DEBUG
    //        queue_printer_formatted(dataOut);
    //        queue_printer_formatted(bitsOut);
    //        stack_printer_formatted(&working);
    //    #endif
        // if it is an opperand then push to the output
        if(queue_getFront(&inputBits) == 0)
        {
            queue_enqueue(dataOut ,(queue_getFront(&input)));
            queue_dequeue(&input); //get rid of the data at the top of the queue
            queue_enqueue(bitsOut, 0); // used to identify if a number or char (0 is number)
            queue_dequeue(&inputBits);//get rid of the bin just inputed
        }
        // if it is a opperator (but not a '(' or a ')') then figure out if to push or directly to output
        else if ((queue_getFront(&inputBits) == 1) && (queue_getFront(&input) != 40) && (queue_getFront(&input) != 41))
        {
            while ((!stack_isEmpty(&working)) && (oppPres(stack_top(&working), queue_getFront(&input)) != 1) && (oppPres(stack_top(&working), queue_getFront(&input)) != 2) && (stack_top(&working) != 40))
            {
                queue_enqueue(dataOut, stack_top(&working)); //push the data
                queue_enqueue(bitsOut, 1); //push 1 becaus it is a opperator
                stack_pop(&working);
            }
            stack_push(&working, queue_getFront(&input));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
        //if the character is (
        else if (queue_getFront(&input) == 40)
        {
            stack_push(&working, queue_getFront(&input));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
        //if the character is )
        else if (queue_getFront(&input) == 41)
        {
            while (!stack_isEmpty(&working) && stack_top(&working) != 40)
            {
                queue_enqueue(dataOut, stack_top(&working)); //push the data
                queue_enqueue(bitsOut, 1); //push 1 because it is a opperator
                stack_pop(&working);
            }
            stack_pop(&working);
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
    }
    //need to push the remaining chars to the end once all of the opperands have been pushed
    while(!stack_isEmpty(&working))
    {
        queue_enqueue(dataOut, stack_top(&working)); //push the data
        queue_enqueue(bitsOut, 1); //push 1 because it is a char
        stack_pop(&working);
    }
    #ifndef WEBMODE
    #ifdef DEBUG
        printf("Done Infix to postfix:\n");
    #endif
    #endif
    return 0; //return 0 if done and not failed
}

//FUNCTION:

void populate(queue *data, queue *bin, char exp[MAX_INPUT_LENGTH]) 
{
    int len = strlen(exp);

    for (int i = 0; i < len; i++)
    {
        char curNum[MAX_INPUT_LENGTH] = "";
        if (isNum(exp[i]))
        {
            
            while (isNum(exp[i]))
            {   
                char add[2];
                add[0] = exp[i];
                add[1] = '\0';
                strcat(curNum, add);
                i++;
            }
            i--;
            int asInt = 0;
            sscanf(curNum, "%d", &asInt);
            queue_enqueue(data, asInt);
            queue_enqueue(bin, 0);
        } else {
            queue_enqueue(data, exp[i]);
            queue_enqueue(bin, 1);
        }
    }
}

/* Convert to char array */
int dataQueueToString(queue input, queue inputBits)
{
    char string[MAX_INPUT_LENGTH] = "";
    int len = queue_length(&input);
    for (int i = 0; i < len; i++)
    {
        int num = queue_getFront(&input);
        int bin = queue_getFront(&inputBits);

        queue_dequeue(&input);
        queue_dequeue(&inputBits);

        if (bin == 0) // number
        {
            char adding[30];
            sprintf(adding, "%d", num);
            strcat(string, adding);
            strcat(string, " ");
        } else {  // operator
            char adding[2];
            adding[0] = num;
            adding[1] = '\0';
            strcat(string, adding);
            strcat(string, " ");
        }
    }
    #ifdef DEBUG
        fprintf(stderr, "%s\n", string);
    #endif
    
    return 0;
}

//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(void)
{
    queue dummyData = {-1, -1, 0};
    queue dummyBin = {-1, -1, 0};
    
    populate(&dummyData, &dummyBin,"15+2");

    dataQueueToString(dummyData, dummyBin);
    
    
    //queue_printer_formatted(&dummyData);
    //queue_printer_formatted(&dummyBin);

    queue goodData = {-1, -1, 0};
    queue goodBin = {-1, -1, 0};

    infixToPostfix(dummyData, dummyBin, &goodData, &goodBin);

    //queue_printer_formatted(&goodData);
    //queue_printer_formatted(&goodBin);

    dataQueueToString(goodData, goodBin);
    printf("Evaluating:\n");
    long double res = postfixCalc(goodData, goodBin);
    printf("Result is: %Lf\n", res);
    return 0;
} 
#endif // _DEFMAIN
