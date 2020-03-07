#include "../main.h"

int main(void)
{
    char str[MAX_INPUT_LENGTH];

    printf("Please input an infix expression with no spaces or negative numbers:\n");
    scanf("%s", &str);
    printf("Expression inputed, computing:\n");

    queue dummyData = {-1, -1, 0};
    queue dummyBin = {-1, -1, 0};
    
    populate(&dummyData, &dummyBin,str);

    dataQueueToString(dummyData, dummyBin);
    
    
    //queue_printer_formatted(&dummyData);
    //queue_printer_formatted(&dummyBin);

    queue goodData = {-1, -1, 0};
    queue goodBin = {-1, -1, 0};

    infixToPostfix(dummyData, dummyBin, &goodData, &goodBin);

    //queue_printer_formatted(&goodData);
    //queue_printer_formatted(&goodBin);

    dataQueueToString(goodData, goodBin);
    printf("Evaluating:\n");
    int res = postfixCalc(goodData, goodBin);
    printf("Result is: %d\n", res);
    return 0;
} 