//This is going to be a int queue and Tommcn will show me how to make a instance one

//includes the standard libraires
#include<stdio.h>

//defines the max length of the queue
#define QueueLength 50

//defines all the prototypes
int Enqueue(int input);
int Dequeue(void);
int IsEmpty(void);
int IsFull(void);
int GetFront(void);
int GetRear(void);

//initialise the queue and the traking variables
int queue[QueueLength];
int front, rear = -1;

//adds to the back of the queue the value inputed
int Enqueue(int input)
{
    if(IsFull())
    {
        printf("Error: Queue is full, canot insert %d.", input);
        return(1);
    }
    else if (IsEmpty())
    {
        front = 0;
        rear = 0;
        queue[rear] = input;
        return(0);
    }
    else
    {
        rear++;
        queue[rear] = input;
        return(0);
    }
    
    
}

//deques the front value
int Dequeue(void)
{
    if (IsEmpty())
    {
        printf("Error: Queue is empty, canot dequeue.");
        return(1);
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        return(2);
    }
    else
    {
        front++;
        return(0);
    }
}

//a function to check if the stack is empty which may result in undefined behaviour
int IsEmpty(void)
{
    if (front == -1 && rear == -1)
    {
        return(1);
    }
    else
    {
        return(0);
    }
    
}

//a funtion to check if the stack is full
int IsFull(void)
{
    //looks if the stack is at its maximum capacity
    if (rear == QueueLength - 1)
    {
        return(1);
    }
    else
    {
        return(0);
    }
    
}

//a function to get the front value of the stack
int GetFront(void)
{
    //checks if the stack is empty and warns in that case
    if (IsEmpty())
    {
        printf("Error: Queue is empty, canot get the front value.\n Note: The value returned my be junk.");
    }
    
    return(queue[front]);
}

//a function to get the rear value of the queue
int GetRear(void)
{
    //checks if the stack is empty and warns in that case
    if (IsEmpty())
    {
        printf("Error: Queue is empty, canot get the rear value.\n Note: The value returned my be junk.");
    }
    
    return(queue[rear]);
}

