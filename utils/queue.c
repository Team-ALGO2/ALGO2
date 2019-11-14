//This is going to be a int queue and Tommcn will show me how to make a instance one

//includes main utils
#include "../main.h"

//defines the max length of the queue
#define QUEUE_MAX_LENGTH 128

//defines all the prototypes
/*
int Enqueue(int input);
int Dequeue(void);
int IsEmpty(void);
int IsFull(void);
int GetFront(void);
int GetRear(void);
*/
// Idk why you created the protoypes here. Its only useful if you define functions before main func

//Create structure containing the queue and the traking variables
typedef struct{
    int front;
    int rear;
    int A[QUEUE_MAX_LENGTH];
} queue;

//a function to check if the stack is empty which may result in undefined behaviour
int queue_isEmpty(queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//a funtion to check if the stack is full
int queue_isFull(queue *q)
{
    //looks if the stack is at its maximum capacity
    if (q->rear == QUEUE_MAX_LENGTH - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//adds to the back of the queue the value inputed
int queue_enqueue(queue *q, int input)
{
    if(queue_isFull(q))
    {
        printf("Error: Queue is full, canot insert %d.", input);
        return false;
    }
    else if (queue_isEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
        q->A[q->rear] = input;
        return true;
    }
    else
    {
        q->rear++;
        q->A[q->rear] = input;
        return true;
    }
    
    
}

//deques the front value
int queue_dequeue(queue *q)
{
    if (queue_isEmpty(q))
    {
        printf("Error: Queue is empty, canot dequeue.");
        return false;
    }
    else if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
        return true;
    }
    else
    {
        q->front++;
        return true;
    }
}

//a function to get the front value of the stack
int queue_getFront(queue *q)
{
    //checks if the stack is empty and warns in that case
    if (queue_isEmpty(q))
    {
        printf("Error: Queue is empty, canot get the front value.\n Note: The value returned my be junk.");
    }
    
    return(q->A[q->front]);
}

//a function to get the rear value of the queue
int queue_getRear(queue *q)
{
    //checks if the stack is empty and warns in that case
    if (queue_isEmpty(q))
    {
        printf("Error: Queue is empty, canot get the rear value.\n Note: The value returned my be junk.");
    }
    
    return(q->A[q->rear]);
}

void queue_printer(queue *q)
{
    printf("\n");
    for (int i = 0; i < QUEUE_MAX_LENGTH; i++)
    {
        printf("%i ", q->A[i]);
    }
    printf("\n");
}

