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
    printf("Begin infix to postfix \n");
    //working is only a stack of chars in int form so we do not need the give it a bin stack
    stack working = {-1, {0}};

    // set length to the number of inputs in the queue
    int length = queue_length(&input);
    for(int i = 0; i < length; i++)
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
        else if ((queue_getFront(&inputBits) == 1) && (queue_getFront(&input) != 40) && (queue_getFront(&input) != 41))
        {
            printf("Pushing operator: %d\n", queue_getFront(&input));
            printf("%d %d %d\n", stack_isEmpty(&working), oppPres(stack_top(&working), queue_getFront(&input)), stack_top(&working));
            stack_printer_formatted(&working);
            while ((!stack_isEmpty(&working)) && (oppPres(stack_top(&working), queue_getFront(&input)) != 1) && (oppPres(stack_top(&working), queue_getFront(&input)) != 2) && (stack_top(&working) != 40))
            {
                printf("YAYs\n");
                queue_enqueue(dataOut, stack_top(&working)); //push the data
                queue_enqueue(bitsOut, 1); //push 1 becaus it is a opperator
                stack_pop(&working);
            }
            stack_push(&working, queue_getFront(&input));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
        else if (queue_getFront(&input) == 40)
        {
            stack_push(&working, queue_getFront(&input));
            queue_dequeue(&input);
            queue_dequeue(&inputBits);
        }
        else if (queue_getFront(&input) == 41)
        {
            while (!stack_isEmpty(&working) && stack_top(&working) != 40)
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

/*
    //populate the data
    queue_enqueue(data, 5);
    queue_enqueue(data, 43);
    queue_enqueue(data, 53);
    queue_enqueue(data, 42);
    queue_enqueue(data, 2);
    queue_enqueue(data, 45);
    queue_enqueue(data, 34);
    queue_enqueue(data, 43);
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
    */
}


//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(void)
{
    queue dummyData = {-1, -1, 0};
    queue dummyBin = {-1, -1, 0};
    
    populate(&dummyData, &dummyBin,"(1+2)*3");
    
    queue_printer_formatted(&dummyData);
    queue_printer_formatted(&dummyBin);

    queue goodData = {-1, -1, 0};
    queue goodBin = {-1, -1, 0};

    infixToPostfix(dummyData, dummyBin, &goodData, &goodBin);

    queue_printer_formatted(&goodData);
    queue_printer_formatted(&goodBin);


    /* Convert to char array */
    char strInfToPost[MAX_INPUT_LENGTH] = "";
    int len = queue_length(&goodData);
    for (int i = 0; i < len; i++)
    {
        int num = queue_getFront(&goodData);
        int bin = queue_getFront(&goodBin);

        queue_dequeue(&goodData);
        queue_dequeue(&goodBin);


        if (bin == 0) // number
        {
            char adding[30];
            sprintf(adding, "%d", num);
            strcat(strInfToPost, adding);
            strcat(strInfToPost, " ");
        } else {  // operator
            char adding[2];
            adding[0] = num;
            adding[1] = '\0';
            strcat(strInfToPost, adding);
            strcat(strInfToPost, " ");
        }
    }
    printf("%s\n", strInfToPost);
    int res = postFixcalc(strInfToPost);
    printf("res: %d\n", res);
} 
#endif // _DEFMAIN
