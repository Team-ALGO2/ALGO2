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
 *  pop() will decrese the counter by 1
 *  returns true if sucessful and false if not
 *  pop does NOT return the top value
 * 
 * 
 * 
 * 
*/
#include "../main.h"

#define MAX_LENGTH 10

// global vars
int A[MAX_LENGTH] = {0};
int counter = -1;


int isEmpty()
{
    if (counter == -1 && counter == 0)
    {
        return true;
    } 
    else
    {
        return false;
    }
    
}

int isFull()
{
    if (counter >= MAX_LENGTH)
    {
        return true;
    } 
    else
    {
        return false;
    }
    
}

int top()
{
    if (!isEmpty())
    {
        return A[counter];
    }
    else
    {
        return false;
    }
    
}

int push(int x)
{
    if (!isFull())
    {
        counter++;
        A[counter] = x;
        return A[counter];
    }
    else
    {
        return false;
    }
    
}

int pop()
{
    if (!isEmpty())
    {
        counter--;
        return true;
    }
    else
    {
        return false;
    }
    
}

void printer()
{
    printf("\n");
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        printf("%i \n", A[i]);
    }
}




int main(void)
{
    /*
    int testInt = 5;
    printer();
    push(testInt);
    push(testInt + 100);
    push(testInt - 7);
    printf("top: %i", top());
    printer();
    pop();
    printf("top: %i ", top());
    printer();
    */

}