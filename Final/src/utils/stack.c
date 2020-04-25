/// Implementation of a stack in C

/**
 * Stack only accepts numbers
 * Stack is initialized to -1 to help debugging
 * 
 * `stack_top()` return the top value of stack
 * it will NOT pop it
 * it will return false if stack is empty
 * 
 * `stack_push()` inserts an int into the stack and increase counter
 * returns false if stack is full
 * returns the value inserted if succesful
 * 
 * `stack_pop()` will decrese the counter by 1
 * returns true if sucessful and false if not
 * pop does NOT return the top value
 * 
 * 
 * **UPDATE WITH THE USE OF STRUCTURES**  
 * 
 * 
 * How To Create A Stack ->
 *  \code
 *  stack stackName = {-1, {0}};      
 * \endcode
 * *Dont change the values unless you know what your doing
 * 
 * *Must Add `& Infront Of Stack Name`*
 * 
 * Examples ->
 * \code
 *  stack test = {-1, {0}};                  
 *  stack_push(&test, 5);                    
 *  stack_top(&test);                        
 *  stack_pop(&test);                        
 *  stack_printer(&test);                    
 * \endcode
 * 
 * WARNING: We havent actually been taught (Pointers and Structs) yet, but oh well
 * ¯\_(ツ)_/¯
 * 
*/

//includes main utils
#include "../main.h"

//Custom Stack Structure
//counter -> The "pointer" of the top of the graph
//A -> The Array where the stack elements will be stored
typedef struct{
    int counter;  ///< Marker for the top of the stack  
    long double A[STACK_MAX_LENGTH];  ///< The actual stack data
} stack;

//Check if the stack is empty by checking the counter
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

//Check if the stack is full by checking if the counter is one under the Max Length (STACK_MAX_LENGTH)
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

//Getting the current length of the stack
int stack_length(stack *s)
{   
    return s->counter;
}

//Getting the top element of stack
long double stack_top(stack *s)
{
    if (!stack_isEmpty(s))
    {
        return s->A[s->counter];
    }
    else
    {
        //Error Message
        #ifdef DEBUG
        #ifndef WEBMODE
        printf(RED"Error: Stack is empty, canot get the top value.\n Note: The value returned my be junk.\n"RESET);
        #endif
        #endif

        return STACK_EMPTY;
    }
    
}

//Pushing element to the top of the stack
int stack_push(stack *s, long double x)
{
    if (!stack_isFull(s))
    {
        s->counter++;
        s->A[s->counter] = x;
        return s->A[s->counter];
    }
    else
    {
        //Error Message
        #ifdef DEBUG
        #ifndef WEBMODE
        printf(RED"Error: Stack is full, canot push.\n"RESET);
        #endif
        #endif
        return STACK_FULL;
    }
    
}

//Removing element from the top of the stack
int stack_pop(stack *s)
{
    if (!stack_isEmpty(s))
    {
        s->counter--;
        return true;
    }
    else
    {
        //Error Message
        #ifdef DEBUG
        #ifndef WEBMODE
        printf("Error: Stack is empty, canot pop.\n");
        #endif
        #endif
        return STACK_EMPTY;
    }
    
}

//Debug printer for printing all elements of the stack
void stack_printer(stack *s)
{
    printf("\n");
    if(s->counter != -1){printf("[");}
    for (int i = 0; i < STACK_MAX_LENGTH; i++)
    {
        printf("%Lf ", s->A[i]);
        if(i == s->counter){printf("]");}
    }
    printf("\n");
}

//stack_printer without trailing zeros
void stack_printer_formatted(stack *s){
    for (int i = 0; i <= s->counter; i++)
    {
        printf("%Lf ", s->A[i]);
    }
    printf("\n");
}

//We dont need this >:(
/*
stack stack_reverse(stack *s)
{
    stack out = {-1, {0}};
    for (int i = 0; i < stack_length(s); i++)
    {
        stack_push(&out, stack_pop(s));
    }
    return out;
}
*/