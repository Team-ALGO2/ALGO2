// Queue is zero indexed

/*
 * Queue only accepts numbers
 * Queue is initialized to -1 to help debugging
 * 
 * queue_getFront() returs the "top" (Last In Last Out)
 * it will NOT pop it
 * it will return false if queue is empty
 * 
 * queue_getRear() return the last value of queue. This value should stay the same until the queu is empty
 * it will NOT pop it
 * it will return false if queue is empty
 * 
 * queue_enqueue() inserts an int into the queue, in the end
 * returns false if queue is full
 * returns the value inserted if succesful
 * 
 * queue_dequeue() will increase the frint value by one
 * returns true if sucessful and false if not
 * pop does NOT return the top value
 * 
 * 
 * == UPDATE WITH THE USE OF STRUCTURES ==
 * NOTE: STACK IS NOW A POINTER!!! 
 * 
 * 
 * How To Create A Queue ->
 * | queue queueName = {-1, -1, {0}};  |
 * *Dont change the values unless you know what your doing
 * *Note the 2 -1 values
 * 
 * How To Use Functions ->
 * | function(&queueName, arguments)   |
 * *Must Add `& Infront Of Stack Name`
 * 
 * Examples ->
 * | queue test = {-1, {0}};                 |
 * | queue_enqueue(&test, 5)                 |
 * | queue_getFront(&test)                   |
 * | queue_dequeue(&test)                    |
 * | queue_printer(&test)                    |
 * 
 * WARNING: We havent actually been taught (Pointers and Structs) yet, but oh well
 * ¯\_(ツ)_/¯
 * 
*/

//
//
//TODO: CIRCULAR ARRAY!!
//
//

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

//prints out queue array WARN: THIS DOES NOT TAKE IN COUNT FRONT AND REAR. IT ONLY PRINTS OUT RAW ARRAY
void queue_raw_printer(queue *q)
{
    printf("\n");
    for (int i = 0; i < QUEUE_MAX_LENGTH; i++)
    {
        printf("%i ", q->A[i]);
    }
    printf("\n");
}

void queue_printer(queue *q)
{
    printf("Not Implemented");
    //Todo implement after we implement Circular Array
}


/*
 * 
 * DATASTRUCTURE OF QUEUE (For Refrence)
 * F - Front | R - Rear
 * 
 * -----------------
 * 00000000 (Rest Cut Off To Save Space)
 * ^
 * |
 * FR
 * -----------------
 * 
 * queue_enqueue(&queue, 4)            |
 * queue_enqueue(&queue, 5)            |
 * queue_enqueue(&queue, 6)            |
 * queue_enqueue(&queue, 7)            |
 * queue_enqueue(&queue, 8)            |
 * queue_enqueue(&queue, 9)            |
 * 
 * -----------------
 * 45678900
 * ^    ^
 * |    |
 * F    R
 * -----------------
 * 
 * queue_dequeue(&queue)               |
 * queue_dequeue(&queue)               |
 * 
 * -----------------
 * 45678900
 *   ^  ^
 *   |  |
 *   F  R
 * -----------------
 * 
*/

