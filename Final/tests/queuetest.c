#include "src/main.h"

int main(void)
{ 
    printf("GENERATE QUEUE\n");
    queue test = {-1, -1, {0}};
    queue test2 = {-1, -1, {0}};
    queue test3 = {-1, -1, {0}};
    queue test4 = {-1, -1, {0}};





    //Testing if stack successfully generated
    queue_raw_printer(&test);
    
    printf("\n\nAdding Values For test\n");
    queue_enqueue(&test, 1);
    queue_enqueue(&test, 2);
    queue_enqueue(&test, 3);

    //Testing Rear Incrementation
    printf("\n\nTest test\n");
    queue_raw_printer(&test);
    printf("front: %i\n", queue_getFront(&test));
    printf("dequeue\n");
    queue_dequeue(&test);
    queue_raw_printer(&test);
    printf("front: %i\n", queue_getFront(&test));
    printf("dequeue\n");
    queue_dequeue(&test);
    queue_raw_printer(&test);
    printf("front: %i\n", queue_getFront(&test));
    printf("dequeue\n");
    queue_dequeue(&test);
    queue_raw_printer(&test);





    //Testing Multiple Values
    printf("\n\nAdding Values For test2\n");
    queue_enqueue(&test2, 11);
    queue_enqueue(&test2, 22);
    queue_enqueue(&test2, 33);
    queue_enqueue(&test2, 44);
    queue_enqueue(&test2, 55);
    queue_enqueue(&test2, 66);

    printf("\n\nTest test2\n");
    queue_raw_printer(&test2);
    printf("rear: %i\n", queue_getRear(&test2));
    queue_dequeue(&test2);
    printf("rear: %i\n", queue_getRear(&test2));
    queue_dequeue(&test2);





    //Testing queue_printer
    printf("\n\nPrinter Test\n");
    printf("rear: %i\n", queue_getRear(&test2));
    printf("front: %i\n", queue_getFront(&test2));
    queue_raw_printer(&test2);
    queue_printer(&test2);





    //Testing If IsFull and IsEmpty Works
    printf("\n\nOverflow and Underflow Testing\n");
    printf("Adding Values\n");
    queue_raw_printer(&test3);
    queue_enqueue(&test3, 101);
    queue_raw_printer(&test3);
    queue_enqueue(&test3, 101);
    queue_raw_printer(&test3);

    printf("Removing Value 1 SHOULD WORK\n");
    queue_dequeue(&test3);
    queue_raw_printer(&test3);
    printf("Removing Value 2 SHOULD WORK\n");
    queue_dequeue(&test3);
    queue_raw_printer(&test3);
    printf("Removing Value 3 ===SHOULD NOT WORK===\n");
    queue_dequeue(&test3);
    queue_raw_printer(&test3);

    printf("Filling Values To  Near Max\n");
    for(int a = 0; a < QUEUE_MAX_LENGTH-1; a++){
        queue_enqueue(&test3, a);
    }
    queue_raw_printer(&test3);
    printf("Adding One More SHOULD WORK\n");
    queue_enqueue(&test3, 1111);
    queue_raw_printer(&test3);
    printf("Adding One More ==SHOULD NOT WORK==\n");
    queue_enqueue(&test3, 9999);
    queue_raw_printer(&test3);





    //Testing If Circular Array Works
    printf("\n\nCircular Array Testing\n");
    for(int a = 0; a < QUEUE_MAX_LENGTH-2; a++){
        queue_enqueue(&test4, 1);
    }
    queue_raw_printer(&test4);
    queue_printer(&test4);
    printf("rear: %i\n", queue_getRear(&test4));
    printf("front: %i\n", queue_getFront(&test4));

    printf("Clearing Up Space\n");
    for(int a = 0; a < QUEUE_MAX_LENGTH-4; a++){
        queue_dequeue(&test4);
    }
    queue_raw_printer(&test4);
    queue_printer(&test4);
    printf("rear: %i\n", queue_getRear(&test4));
    printf("front: %i\n", queue_getFront(&test4));

    printf("Adding Values\n");
    for(int a = 0; a < QUEUE_MAX_LENGTH/2; a++){
        queue_enqueue(&test4, 2);
    }
    queue_raw_printer(&test4);
    queue_printer(&test4);
    printf("rear: %i\n", queue_getRear(&test4));
    printf("front: %i\n", queue_getFront(&test4));

    printf("Looping Rear To Front\n");
    for(int a = 0; a < 6; a++){
        queue_dequeue(&test4);
    }
    queue_raw_printer(&test4);
    queue_printer(&test4);
    printf("rear: %i\n", queue_getRear(&test4));
    printf("front: %i\n", queue_getFront(&test4));
}
