/**
 * @file queue.c
 * @brief Implementation of a queue in C.
 * 
 * This file contains our implementation of a queue in C
 * along with a few examples.
 */

/**
 * Queue only accepts numbers
 * Queue is initialized to -1 to help debugging
 * 
 * `queue_getFront()` returs the "top" (Last In Last Out)
 * it will NOT pop it
 * it will return false if queue is empty
 * 
 * `queue_getRear()` return the last value of queue. This value should stay the same until the queu is empty or until you add new values
 * it will NOT pop it
 * it will return false if queue is empty
 * 
 * `queue_enqueue()` inserts an int into the queue, at the end
 * returns false if queue is full
 * returns the value inserted if succesful
 * 
 * `queue_dequeue()` will remove the first value in the queue
 * returns true if sucessful and false if not
 * pop does NOT return the top value
 * 
 * See queue.c for more details
 * 
 * **UPDATE WITH THE USE OF STRUCTURES**  
 * 
 * 
 * 
 * How To Create A Queue ->
 * | \code
 *      queue queueName = {-1, -1, {0}};
 *   \endcode
 *  Dont change the values unless you know what your doing
 *  Note the 2 -1 values
 * 
 * How To Use Functions ->
 * `function(&queueName, arguments)`
 * *Must Add `& Infront Of Stack Name`*
 * 
 * Examples ->
 *  \code
 *  queue test = {-1, -1, 0};                 
 *  queue_enqueue(&test, 5);               
 *  queue_getFront(&test);                   
 *  queue_dequeue(&test);                    
 *  queue_printer(&test); 
 *  \endcode                   
 * 
 * WARNING: We havent actually been taught (Pointers and Structs) yet, but oh well
 * ¯\_(ツ)_/¯
 * 
*/

//includes main utils
#include "../main.h"



//Create structure containing the queue and the traking variables
/**
 * @brief Queue data structure
 */
typedef struct{
    int front;      ///< The front of the queue (beggining)  
    int rear;       ///< The rear of the queue (end marker)  
    long double A[QUEUE_MAX_LENGTH]; ///< The actual data as an int list, works because circular queue  
} queue;

/**
 * @brief Function to check if a queue is empty
 * 
 * The function will return a boolean based of a pointer to a queue
 * It will return true (1) if the queue is empty 
 * and false (0) if the queue is populated. This function is important
 * because performing operations on an empty queue can lead to errors due
 * to garbage values being returned
 * @param q A pointer to the queue that we want to check
 * 
 * @returns boolean, true if queue is empty, false otherwise
 */
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

/**
 * @brief Function to check if a queue is full
 * 
 * The function will return a boolean based of a pointer to a queue
 * It will return true (1) if the queue is full 
 * and false (0) if the queue is noit full (either empty or populated). This function is important
 * because pushing to a full queue can lead to loss of data, or cause segfaults.
 *  Enqueuing to the queue performs the check automatically.
 * 
 * @param q A pointer to the queue that we want to check
 * @returns boolean, true if queue is full, false otherwise
 */
int queue_isFull(queue *q)
{
    //looks if the stack is at its maximum capacity
    if ((q->rear + 1) % QUEUE_MAX_LENGTH == q->front)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

/**
 * @brief Function to get the length of a queue
 * 
 * The function will return an integer representing the length of a queue.
 * By length, we mean the number of values between `q->rear` and `q->front`
 * (the number of values push by the user - the number of values pulled by the user)
 * 
 * @param q A pointer to the queue that we want to check
 * @returns int, the length of the queue
 */
int queue_length(queue *q)
{   
    if(!queue_isEmpty(q)){
        return q->rear - q->front + 1;
    }
    else{
        return 0;
    }
}

/**
 * @brief Add a value to the queue
 * 
 * This functions adds a number to the queue, after checking if the 
 * queue is full. This includes an implementation of a circular queue
 * 
 * @param q A pointer to the queue that we want to add a value to 
 * @param input The number we want to add, long double for more flexibility
 * 
 * @returns int, true if enqueuing is successful 
 */
int queue_enqueue(queue *q, long double input)
{
    if(queue_isFull(q))
    {   
        //Error Message
        #ifdef DEBUG
        #ifndef WEBMODE
        printf(RED"Error: Queue is full, canot insert %Lf.\n"RESET, input);
        #endif
        #endif
        return QUEUE_FULL;
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
        q->rear = (q->rear + 1) % QUEUE_MAX_LENGTH;
        q->A[q->rear] = input;
        return true;
    }
    
    
}

/**
 * @brief Removes last value it the queue
 * 
 * The function removes the last value in the queue
 * It **does not** return it, see queue_getFront()
 * 
 * @param q the pointer to the queue to dequeue from
 * @return int, true if dequeuing is successful 
 */
int queue_dequeue(queue *q)
{
    if (queue_isEmpty(q))
    {
        //Error Message
        #ifdef DEBUG
        #ifndef WEBMODE
        printf(RED"Error: Queue is empty, canot dequeue.\n"RESET);
        #endif
        #endif
        return QUEUE_EMPTY;
    }
    else if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
        return true;
    }
    else
    {
        q->front = (q->front + 1) % QUEUE_MAX_LENGTH;
        return true;
    }
}

/**
 * @brief Function to get the front of the queue
 * 
 * This function returns the front of the queue.
 * it **does not** dequeue, see queue_dequeue()
 * 
 * @param q the pointer to the queue
 * @return long double, the front value
 */
long double queue_getFront(queue *q)
{
    //checks if the stack is empty and warns in that case
    if (queue_isEmpty(q))
    {
        //Error Message
        #ifdef DEBUG
        #ifndef WEBMODE
        printf(RED"Error: Queue is empty, canot get the front value.\n Note: The value returned my be junk.\n"RESET);
        #endif
        #endif
        return QUEUE_EMPTY;
        
    }
    
    return(q->A[q->front]);
}

/**
 * @brief Function to get the rear of the queue
 * 
 * This function returns the rear of the queue.
 * 
 * @param q the pointer to the queue
 * @return long double, the rear value
 */
long double queue_getRear(queue *q)
{
    //checks if the stack is empty and warns in that case
    if (queue_isEmpty(q))
    {
        //Error Message
        #ifdef DEBUG
        printf(RED"Error: Queue is empty, canot get the rear value.\n Note: The value returned my be junk.\n"RESET);
        #endif
        return QUEUE_EMPTY;
    }
    
    return(q->A[q->rear]);
}

/**
 * @brief prints the raw array in the queue
 * 
 * The functions prints the array in the queue without
 * formatting or caring for front and rear. The function may
 * print weird or junk characters
 * 
 * @param q the pointer to a queue to print
 */
void queue_raw_printer(queue *q)
{
    printf("\n");
    for (int i = 0; i < QUEUE_MAX_LENGTH; i++)
    {
        if(i == q->front){printf("[");}
        printf("%Lf ", q->A[i]);
        if(i == q->rear){printf("]");}
    }
    printf("\n");
}

/**
 * @brief Prints the queue nicely
 * 
 * The function prints the queue's array nicely and in order
 * 
 * @param q the pointer to a queue to print
 */
void queue_printer(queue *q)
{
    printf("\n");
    for (int i = 0; i < QUEUE_MAX_LENGTH; i++)
    {
        printf("%Lf ", q->A[(i + q->front) % QUEUE_MAX_LENGTH]);
    }
    printf("\n");
}

/**
 * @brief Same as queue_printer()
 * 
 * Same as queue_printer() but not 0 padded
 * 
 * @param q the pointer to a queue to print
 */
void queue_printer_formatted(queue *q)
{
    printf("\n");
    for (int i = 0; i < queue_length(q); i++)
    {
        printf("%LF ", q->A[(i + q->front) % QUEUE_MAX_LENGTH]);
    }
    printf("\n");
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
 * Current Values: []
 * 
 * queue_enqueue(&queue, 4)            |
 * queue_enqueue(&queue, 5)            |
 * queue_enqueue(&queue, 6)            |
 * queue_enqueue(&queue, 7)            |
 * queue_enqueue(&queue, 8)            |
 * queue_enqueue(&queue, 9)            |
 * -----------------
 * 45678900
 * ^    ^
 * |    |
 * F    R
 * -----------------
 * Current Values: [4, 5, 6, 7, 8, 9]
 * 
 * queue_dequeue(&queue)               |
 * queue_dequeue(&queue)               |
 * queue_dequeue(&queue)               |
 * -----------------
 * 45678900
 *    ^ ^
 *    | |
 *    F R
 * -----------------
 * Current Values: [7, 8, 9]
 * 
 * Front Just Moves Up!
 * 
 * NEW: Circular array!
 * 
 * Front Can Loop To Back When Full, Not Surpassing Rear!!
 * 
 * queue_enqueue(&queue, 1)            |
 * queue_enqueue(&queue, 1)            |
 * queue_enqueue(&queue, 1)            |
 * queue_enqueue(&queue, 1)            |
 * -----------------
 * 11678911
 *  ^ ^ 
 *  | | 
 *  R F 
 * -----------------
 * Current Values: [7, 8, 9, 1, 1, 1, 1]
 * 
 * Tail Or Front Can Loop Back As well!
 * 
 * queue_dequeue(&queue)               |
 * queue_dequeue(&queue)               |
 * queue_dequeue(&queue)               |
 * queue_dequeue(&queue)               |
 * queue_dequeue(&queue)               |
 * -----------------
 * 11678911
 * ^^  
 * || 
 * FR
 * -----------------
 * Current Values: [1, 1]
 * 
*/

