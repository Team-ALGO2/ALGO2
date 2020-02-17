// Import Libraries + Modules
#include "main.h"


//FUNCTION:

int populateDummy(queue data, queue bin) 
{
    //populate the data
    printf("%d\n\n", queue_length(&data));
    queue_enqueue(&data, 5);
    printf("%d\n\n", queue_length(&data));
    queue_enqueue(&data, 1);
    printf("%d\n\n", queue_length(&data));
    queue_enqueue(&data, 53);
    queue_enqueue(&data, 2);
    queue_enqueue(&data, 2);
    queue_enqueue(&data, 1);
    queue_enqueue(&data, 34);
    queue_enqueue(&data, 2);
    queue_enqueue(&data, 19);
    printf("%d", queue_length(&data));

    //populate the bin
    queue_enqueue(&bin, 0);
    queue_enqueue(&bin, 1);
    queue_enqueue(&bin, 0);
    queue_enqueue(&bin, 1);
    queue_enqueue(&bin, 0);
    queue_enqueue(&bin, 1);
    queue_enqueue(&bin, 0);
    queue_enqueue(&bin, 1);
    queue_enqueue(&bin, 0);
}

// Main Calculator Function
int main (void)
{
    queue dummyData = {-1, -1, 0};
    queue dummyBin = {-1, -1, 0};
    populateDummy(dummyData, dummyBin);
    
    queue_printer(&dummyData);
    queue_printer(&dummyBin);

    queue goodData = {-1, -1, 0};
    queue goodBin = {-1, -1, 0};

    //infixToPostfix(dummyData, dummyBin, &goodData, &goodBin);

    queue_printer(&goodData);
    queue_printer(&goodBin);

}