#ifndef _MAINGUARD
#define _DISABLECALC // Prevent Redefinitions
#include "../main.h"
#endif // _MAINGUARD

// to convert from an inputed string to postfix notation 
//the input is 2 queues of data and binairy to discribe how to interpret the data
//results are outputed to the dataOut and bitsOut queue
int infixToPostfix(queue input, queue inputBits, queue * dataOut, queue * bitsOut)
{
    printf("Begin infix to postfix \n");
    //working is only a stack of chars in int form so we do not need to give it a bin stack
    stack working = {-1, {0}};

    // set length to the number of inputs in the queue
    int length = queue_length(&input);
    for(int i = 0; i < length - 1; i++)
    {
        // if it is an opperand then push to the output
        if(queue_getFront(&inputBits) == 0)
        {
            printf("Pushing number: %d\n", queue_getFront(&input));
            queue_enqueue(dataOut ,(queue_getFront(&input)));
            queue_dequeue(&input); //get rid of the data at the top of the queue
            queue_enqueue(bitsOut, 0); // used to identify if a number or char (0 is number)
            queue_dequeue(&inputBits);//get rid of the bin just inputed
        }
        // if it is a opperator (but not a '(' or a ')') then figure out if to push or directly to output
        else if (queue_getFront(&inputBits) == 1 && queue_getFront(&input) != 16 && queue_getFront(&input) != 17)
        {
            printf("Pushing operator: %d\n", queue_getFront(&input));
            while (!stack_isEmpty(&working) && oppPres(stack_top(&working), queue_getFront(&input)) == -1 && stack_top(&working) != 16);
            {
                queue_enqueue(dataOut, stack_top(&working)); //push the data
                queue_enqueue(bitsOut, 1); //push 1 because it is a opperator
                stack_pop(&working);
            }
            stack_push(&working, queue_getFront(&input));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
        else if (queue_getFront(&input) == 16)
        {
            stack_push(&working, queue_getFront(&input));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
        else if (queue_getFront(&input) == 17)
        {
            while (!stack_isEmpty(&working) && stack_top(&working) != 16);
            {
                queue_enqueue(dataOut, stack_top(&working)); //push the data
                queue_enqueue(bitsOut, 1); //push 1 because it is a opperator
                stack_pop(&working);
            }
        }
        
    }
    //need to push the remaining chars to the end once all of the opperands have been pushed
    while(!stack_isEmpty(&working))
    {
        queue_enqueue(dataOut, stack_top(&working)); //push the data
        queue_enqueue(bitsOut, 1); //push 1 because it is a char
        stack_pop(&working);
    }
    printf("Done infix to postfix \n");
    return 0; //return 0 if done and not failed
}

//FUNCTION:

int populateDummy(queue *data, queue *bin) 
{
    //populate the data
    queue_enqueue(data, 5);
    queue_enqueue(data, 1);
    queue_enqueue(data, 53);
    queue_enqueue(data, 2);
    queue_enqueue(data, 2);
    queue_enqueue(data, 1);
    queue_enqueue(data, 34);
    queue_enqueue(data, 2);
    queue_enqueue(data, 19);

    //populate the bin
    queue_enqueue(bin, 0);
    queue_enqueue(bin, 1);
    queue_enqueue(bin, 0);
    queue_enqueue(bin, 1);
    queue_enqueue(bin, 0);
    queue_enqueue(bin, 1);
    queue_enqueue(bin, 0);
    queue_enqueue(bin, 1);
    queue_enqueue(bin, 0);
}


//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(void)
{
    queue dummyData = {-1, -1, 0};
    queue dummyBin = {-1, -1, 0};
    
    populateDummy(&dummyData, &dummyBin);
    
    queue_printer_formatted(&dummyData);
    queue_printer_formatted(&dummyBin);

    queue goodData = {-1, -1, 0};
    queue goodBin = {-1, -1, 0};

    infixToPostfix(dummyData, dummyBin, &goodData, &goodBin);

    queue_printer_formatted(&goodData);
    queue_printer_formatted(&goodBin);
} 
#endif // _DEFMAIN
