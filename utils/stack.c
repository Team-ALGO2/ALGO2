// Stack is zero indexed

/*
 * Stack only accepts numbers
 * Stack is initialized to -1 to help debugging
 * 
 * top() return the top value of stack
 * it will NOT pop it
 * it will return false if stack is empty
 * 
 * 
 * push() inserts an int into the stack and increase counter
 * returns false if stack is full
 * returns the value inserted if succesful
 * 
 * pop() will decrese the counter by 1
 * returns true if sucessful and false if not
 * pop does NOT return the top value
 * 
 * 
 * == UPDATE WITH THE USE OF STRUCTURES ==
 * NOTE: STACK IS NOW A POINTER!!! 
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
 * | stack test = {-1, {0}};           |
 * | push(&test, 5)                    |
 * | top(&test)                        |
 * | pop(&test)                        |
 * | printer(&test)                    |
 * 
 * WARNING: We havent actually been taught (Pointers and Structs) yet, but oh well
 * ¯\_(ツ)_/¯
 * 
*/
#include "../main.h"

#define MAX_LENGTH 128

typedef struct{
    int counter;
    int A[MAX_LENGTH];
} stack;

int isEmpty(stack *s)
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

int isFull(stack *s)
{
    if (s->counter >= MAX_LENGTH)
    {
        return true;
    } 
    else
    {
        return false;
    }
    
}

int top(stack *s)
{
    if (!isEmpty(s))
    {
        return s->A[s->counter];
    }
    else
    {
        return false;
    }
    
}

int push(stack *s, int x)
{
    if (!isFull(s))
    {
        s->counter++;
        s->A[s->counter] = x;
        return s->A[s->counter];
    }
    else
    {
        return false;
    }
    
}

int pop(stack *s)
{
    if (!isEmpty(s))
    {
        s->counter--;
        return true;
    }
    else
    {
        return false;
    }
    
}

void printer(stack *s)
{
    printf("\n");
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        printf("%i ", s->A[i]);
    }
    printf("\n");
}
