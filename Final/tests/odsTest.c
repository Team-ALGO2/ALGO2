#include "../src/main.h"

int main(void)
{
    odsMain * testODS = createOperation();
    odsMain * testODS2 = createOperation();

    printf("Test Empty\n");
    odsDebugTravelHeadToTail(testODS);

    printf("\n\n\nTest With Values\n");
    addOperandToTail(testODS, 1);
    addOperatorToTail(testODS, 2);
    addOperandToTail(testODS, 3);
    addOperatorToTail(testODS, 4);
    addOperandToTail(testODS, 5);
    addOperatorToTail(testODS, 6);
    odsDebugTravelHeadToTail(testODS);
    odsDebugTravelTailToHead(testODS);

    printf("\n\n\nTest With Values (BACKWARDS)\n");
    addOperandToHead(testODS2, 111);
    addOperatorToHead(testODS2, 222);
    addOperandToHead(testODS2, 333);
    addOperatorToHead(testODS2, 444);
    addOperandToHead(testODS2, 555);
    addOperatorToHead(testODS2, 666);
    odsDebugTravelHeadToTail(testODS2);
    odsDebugTravelTailToHead(testODS2);
}
