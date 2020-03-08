//Operation Data System

/*
 * Operation Data System
 * 
 * Adaptation of Doubly Linked List
 * to support Operators and Operand Data.
*/

//includes main utils
#include "../main.h"

//Custom Main Operation Data Structure
//head -> Front of linked list
//tail -> Tail of linked list
typedef struct{
    void * head;
    void * tail;
    int nodes;
} odsMain;

//Custom Node Template Structure
//HAS NO DATA VALUE so can cast into both!
//type -> Type of data
//next -> Pointer to next node
//prev -> Pointer to previous node
typedef struct{
    int type;
    void * next;
    void * prev;
} odsNode;

//Custom Operand Data Structure
//type -> Type of data (VALUE 0) (ODS_OPERAND)
//next -> Pointer to next node
//prev -> Pointer to previous node
//data -> Operand stored inside node
typedef struct{
    int type;
    void * next;
    void * prev;
    long double data;
} operandNode;

//Custom Operator Data Structure
//type -> Type of data (VALUE 1) (ODS_OPERATOR)
//next -> Pointer to next node
//prev -> Pointer to previous node
//data -> Operator stored inside node
typedef struct{
    int type;
    void * next;
    void * prev;
    int data;
} operatorNode;

//Enum Of Operatos
enum odsUpdateOperators{addTail, removeTail, addHead, removeHead}; 

//Get Operation Type
int getOdsNodeType(void * nodePtr){
    //Check if node is not NULL
    if(nodePtr != NULL){
        odsNode * node = (odsNode*)nodePtr;
        return node->type;
    }
    else{
        printf("getOdsNodeType node NULL! THIS ERROR IS NOT SUPPOSED TO HAPPEN!\n");
    }
}

//Update ODS Head and Tail
int updateOdsMain(odsMain * controller, int operation, void * node){
    //Check Operation Type
    if(operation == addTail){
        //Check amount of nodes
        //If there are no nodes, set head aswell
        if(controller->nodes == 0){
            controller->head = node;
            controller->tail = node;
        }
        else{
            controller->tail = node;
        }
    }
    else if(operation == removeTail){
    }
    else if(operation == addHead){
        //Check amount of nodes
        //If there are no nodes, set head aswell
        if(controller->nodes == 0){
            controller->head = node;
            controller->tail = node;
        }
        else{
            controller->head = node;
        }
    }
    else if(operation == removeHead){
    }
    else{
        printf("updateOdsMain operator unknown! THIS ERROR IS NOT SUPPOSED TO HAPPEN!\n");
    }
}

//Create Operation Controller
odsMain * createOperation(){
    //Create odsMain
    odsMain * opData = (odsMain*)malloc(sizeof(odsMain));

    //Set Empty Values
    opData->head = NULL;
    opData->tail = NULL;
    opData->nodes = 0;

    //Return Operation 
    return opData;
}

//Add Operand To Tail
int addOperandToTail(odsMain * controller, long double value){
    //Get Current Tail
    void * tail = controller->tail;
    
    //Create operandNode
    operandNode * node = (operandNode*)malloc(sizeof(operandNode));

    //Set Type Flag
    node->type = ODS_OPERAND;

    //Set Previous and Next
    node->prev = tail; //this may be NULL, but that is intentional
    node->next = NULL;

    //Set Data
    node->data = value;

    //Get Current Tail Node And Set Next Value Of Next Node (If Not NULL)
    if(tail != NULL){
        odsNode * tailNode = (odsNode*)tail;
        tailNode->next = node;
        //printf("Node %p Has Next Node %p\n", tailNode, node);
    }

    //Update ODS Main
    updateOdsMain(controller, addTail, node);

    //Increment Node Counter
    controller->nodes++;

    return true; //Completed
}

//Add Operator To Tail
int addOperatorToTail(odsMain * controller, int value){
    //Get Current Tail
    void * tail = controller->tail;
    
    //Create operatorNode
    operatorNode * node = (operatorNode*)malloc(sizeof(operatorNode));

    //Set Type Flag
    node->type = ODS_OPERATOR;

    //Set Previous and Next
    node->prev = tail; //this may be NULL, but that is intentional
    node->next = NULL;

    //Set Data
    node->data = value;

    //Get Current Tail Node And Set Next Value Of Next Node (If Not NULL)
    if(tail != NULL){
        odsNode * tailNode = (odsNode*)tail;
        tailNode->next = node;
        //printf("Node %p Has Next Node %p\n", tailNode, node);
    }

    //Update ODS Main
    updateOdsMain(controller, addTail, node);

    //Increment Node Counter
    controller->nodes++;

    return true; //Completed
}

//Add Operand To Head
int addOperandToHead(odsMain * controller, long double value){
    //Get Current Head
    void * head = controller->head;
    
    //Create operandNode
    operandNode * node = (operandNode*)malloc(sizeof(operandNode));

    //Set Type Flag
    node->type = ODS_OPERAND;

    //Set Previous and Next
    node->prev = NULL;
    node->next = head; //this may be NULL, but that is intentional

    //Set Data
    node->data = value;

    //Get Current Head Node And Set Next Value Of Previous Node (If Not NULL)
    if(head != NULL){
        odsNode * headNode = (odsNode*)head;
        headNode->prev = node;
        //printf("Node %p Has Next Node %p\n", headNode, node);
    }

    //Update ODS Main
    updateOdsMain(controller, addHead, node);

    //Increment Node Counter
    controller->nodes++;

    return true; //Completed
}

//Add Operator To Head
int addOperatorToHead(odsMain * controller, int value){
    //Get Current Head
    void * head = controller->head;
    
    //Create operatorNode
    operatorNode * node = (operatorNode*)malloc(sizeof(operatorNode));

    //Set Type Flag
    node->type = ODS_OPERATOR;

    //Set Previous and Next
    node->prev = NULL;
    node->next = head; //this may be NULL, but that is intentional

    //Set Data
    node->data = value;

    //Get Current Head Node And Set Next Value Of Previous Node (If Not NULL)
    if(head != NULL){
        odsNode * headNode = (odsNode*)head;
        headNode->prev = node;
        //printf("Node %p Has Next Node %p\n", headNode, node);
    }

    //Update ODS Main
    updateOdsMain(controller, addHead, node);

    //Increment Node Counter
    controller->nodes++;

    return true; //Completed
}

int setOperandAtTail(){}
int setOperatorAtTail(){}
int setOperandAtHead(){}
int setOperatorAtHead(){}

int getOperandAtTail(){}
int getOperatorAtTail(){}
int getOperandAtHead(){}
int getOperatorAtHead(){}

int removeOperandFromTail(){}
int removeOperatorFromTail(){}
int removeOperandFromHead(){}
int removeOperatorFromHead(){}

/*
 * DEBUG CODE
 */

int odsDebugTravelHeadToTail(odsMain * controller){
    void * next = controller->head;
    printf("DEBUG TRAVEL: --- Starting at node %p\n", next);
    if(next != NULL){
        int x = 0;
        while(next != NULL){
            x++;
            odsNode * nextNode = (odsNode*)next;
            printf("DEBUG TRAVEL: Node %p Has Next Node %p\n", next, nextNode->next);

            if(nextNode->type == ODS_OPERAND){
                operandNode * node = (operandNode*)next;
                printf("Operand Value: %Lf\n", node->data);
            }
            else if(nextNode->type == ODS_OPERATOR){
                operatorNode * node = (operatorNode*)next;
                printf("Operator Value: %d\n", node->data);
            }
            else{
                printf("Unknown Type\n");
            }

            next = nextNode->next;
            printf("---ODS TRAVEL %d\n", x);
        }
    }
    else{
        printf("ODS EMPTY\n");
    }
}

int odsDebugTravelTailToHead(odsMain * controller){
    void * next = controller->tail;
    printf("DEBUG TRAVEL: --- Starting at node %p\n", next);
    if(next != NULL){
        int x = 0;
        while(next != NULL){
            x++;
            odsNode * nextNode = (odsNode*)next;
            printf("DEBUG TRAVEL: Node %p Has Next Node %p\n", next, nextNode->next);

            if(nextNode->type == ODS_OPERAND){
                operandNode * node = (operandNode*)next;
                printf("Operand Value: %Lf\n", node->data);
            }
            else if(nextNode->type == ODS_OPERATOR){
                operatorNode * node = (operatorNode*)next;
                printf("Operator Value: %d\n", node->data);
            }
            else{
                printf("Unknown Type\n");
            }

            next = nextNode->prev;
            printf("---ODS TRAVEL %d\n", x);
        }
    }
    else{
        printf("ODS EMPTY\n");
    }
}

