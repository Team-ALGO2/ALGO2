// Stack is zero indexed

/*
 * Stack only accepts numbers
 * Stack is initialized to -1 to help debugging
 * 
 * stack_top() return the top value of stack
 * it will NOT pop it
 * it will return false if stack is empty
 * 
 * stack_push() inserts an int into the stack and increase counter
 * returns false if stack is full
 * returns the value inserted if succesful
 * 
 * stack_pop() will decrese the counter by 1
 * returns true if sucessful and false if not
 * pop does NOT return the top value
 * 
 * 
 * == UPDATE WITH THE USE OF STRUCTURES ==
 * NOTE: STACK IS NOW A POINTER!!! 
 * 
 * 
 * How To Create A Stack ->
 * | stack stackName = {-1, {0}};      |
 * *Dont change the values unless you know what your doing
 * 
 * How To Use Functions ->
 * | function(&stackName, arguments)   |
 * *Must Add `& Infront Of Stack Name`
 * 
 * Examples ->
 * | stack test = {-1, {0}};                 | 
 * | stack_push(&test, 5)                    |
 * | stack_top(&test)                        |
 * | stack_pop(&test)                        |
 * | stack_printer(&test)                    |
 * 
 * WARNING: We havent actually been taught (Pointers and Structs) yet, but oh well
 * ¯\_(ツ)_/¯
 * 
*/

//includes main utils
#include "../main.h"

//defines the max length of the stack
#define STACK_MAX_LENGTH 128

// Define Error Codes
#define PRINT_ERROR   true
#define STACK_EMPTY   0
#define STACK_FULL    0

typedef struct{
    int counter;
    int A[STACK_MAX_LENGTH];
} stack;

int stack_isEmpty(stack *s)
{
    if (s->counter < 0)
    {
        return true;
    } 
    else
    {
        return false;
    }
    
}

int stack_isFull(stack *s)
{   
    if (s->counter + 1 >= STACK_MAX_LENGTH)
    {
        return true;
    } 
    else
    {
        return false;
    }
    
}

int stack_top(stack *s)
{
    if (!stack_isEmpty(s))
    {
        return s->A[s->counter];
    }
    else
    {
        if(PRINT_ERROR){printf("Error: Queue is empty, canot get the top value.\n Note: The value returned my be junk.\n");}
        return STACK_EMPTY;
    }
    
}

int stack_push(stack *s, int x)
{
    if (!stack_isFull(s))
    {
        s->counter++;
        s->A[s->counter] = x;
        return s->A[s->counter];
    }
    else
    {
        if(PRINT_ERROR){printf("Error: Queue is full, canot push.\n");}
        return STACK_FULL;
    }
    
}

int stack_pop(stack *s)
{
    if (!stack_isEmpty(s))
    {
        s->counter--;
        return true;
    }
    else
    {
        if(PRINT_ERROR){printf("Error: Queue is empty, canot pop.\n");}
        return STACK_EMPTY;
    }
    
}

void stack_printer(stack *s)
{
    printf("\n");
    if(s->counter != -1){printf("[");}
    for (int i = 0; i < STACK_MAX_LENGTH; i++)
    {
        printf("%i ", s->A[i]);
        if(i == s->counter){printf("]");}
    }
    printf("\n");
}
