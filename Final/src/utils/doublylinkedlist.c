//Doubly Linked List

/*
 * Documentation
*/

//includes main utils
#include "../main.h"

//Custom Doubly Linked List Structure
//data -> Data stored inside node
//next -> Pointer to next node
//prev -> Pointer to previous node
typedef struct{
    int data;
    DLLNode * next;
    DLLNode * prev;
} DLLNode;

//TODO