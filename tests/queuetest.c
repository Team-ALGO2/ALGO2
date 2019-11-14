#include "../main.h"

int main(void)
{ 
    printf("GENERATE STACKS\n");
    queue test = {-1, -1, {0}};
    queue test2 = {-1, -1, {0}};

    queue_raw_printer(&test);
    
    printf("Adding Values For test\n");
    queue_enqueue(&test, 1);
    queue_enqueue(&test, 2);
    queue_enqueue(&test, 3);

    printf("Adding Values For test2\n");
    queue_enqueue(&test2, 99);
    queue_enqueue(&test2, 99);
    queue_enqueue(&test2, 99);
    queue_enqueue(&test2, 99);
    queue_enqueue(&test2, 99);
    queue_enqueue(&test2, 5);

    printf("Test test\n");
    queue_raw_printer(&test);
    printf("top: %i", queue_getFront(&test));
    queue_dequeue(&test);
    printf("top: %i", queue_getFront(&test));
    queue_dequeue(&test);
    printf("top: %i", queue_getFront(&test));
    queue_dequeue(&test);
    queue_raw_printer(&test);

    printf("Test test2\n");
    queue_raw_printer(&test2);
    printf("top: %i", queue_getRear(&test2));
    queue_dequeue(&test2);
    printf("top: %i", queue_getRear(&test2));
    queue_dequeue(&test2);
}
