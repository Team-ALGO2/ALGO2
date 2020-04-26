/**
 * @file stack.c
 * @brief Implementation of a stack in C
 *  
 * This file contains our implementation of a stack in C
 * along with a few examples.
 */

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

/**
 * @brief Stack data structure
 * 
 */
typedef struct{
    int counter;  ///< Marker for the top of the stack  
    long double A[STACK_MAX_LENGTH];  ///< The actual stack data
} stack;

/**
 * @brief Check if the stack is empty
 * 
 * The function will return a boolean based of a pointer to a stack
 * It will return true (1) if the stack is empty 
 * and false (0) if the stack is populated. This function is important
 * because performing operations on an empty stack can lead to errors due
 * to garbage values being returned
 * 
 * @param s the pointer to the stack we check
 * @return boolean, true if stack is empty, false otherwise 
 */
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

/**
 * @brief Check if stack is full
 * 
 * The function will return a boolean based of a pointer to a stack
 * It will return true (1) if the stack is full 
 * and false (0) if the stack is not full (either empty or populated). This function is important
 * because pushing to a full stack can lead to loss of data, or cause segfaults.
 *  pushing to the queue performs the check automatically.
 * 
 * @param s the pointer to the stack we check
 * @return boolean, true if stack is full, false otherwise 
 */
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

/**
 * @brief Get the length of the stack
 * 
 * The functions returns the length of the stack, using the 
 * variable `counter`
 * 
 * @param s the pointer to the stack we want to get the length if
 * @return int 
 */
int stack_length(stack *s)
{   
    return s->counter;
}

/**
 * @brief Returns the top of the stack
 * 
 * @param s the pointer to the stack we want
 * @return long double 
 */
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

/**
 * @brief Push a number to the queue
 * 
 * This function pushes a number x to the queue, it **does not**
 * return the top value
 * 
 * @param s the pointer to the stack
 * @param x the number we want to push, as a long double
 * @return int 
 */
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

/**
 * @brief Removes the first item in the queue
 * 
 * The function removes the last value in the stack
 * It **does not** return it, see stack_top()
 * 
 * @param s the pointer to a stack
 * @return int 
 */
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


/**
 * @brief Print the stack
 * 
 * This function prints the stack and marks the where the counter is
 * 
 * @param s the pointer to the stack
 * 
 * @note For debug purposes only

 */
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

/**
 * @brief Print the stack
 * 
 * This function prints the stack and marks the where the counter is, without
 * all the 0s.
 * 
 * 
 * @param s the pointer to the stack
 * 
 * @note For debug purposes only
 */
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