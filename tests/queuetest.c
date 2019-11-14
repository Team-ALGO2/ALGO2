#include "../main.h"

int main(void)
{ 
    printf("GENERATE STACKS\n");
    queue test = {-1, -1, {0}};
    queue test2 = {-1, -1, {0}};

    queue_printer(&test);
    
    printf("Adding Values For test\n");
    queue_enqueue(&test, 1);
    queue_enqueue(&test, 2);
    queue_enqueue(&test, 3);

    queue_printer(&test);
    printf("top: %i", queue_getFront(&test));
    queue_dequeue(&test);
    printf("top: %i", queue_getFront(&test));
    queue_dequeue(&test);
    printf("top: %i", queue_getFront(&test));
    queue_dequeue(&test);
    queue_printer(&test);
}
