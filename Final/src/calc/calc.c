#include "../main.h"

//this is a funciton to run the calculator without the GUI
#ifdef _DEFMAIN
int main(void)
{
    char str[MAX_INPUT_LENGTH];

    printf("Please input an infix expression with no spaces or negative numbers:\n");
    scanf("%s", &str);
    printf("Result is: %Lf\n", calculate(str));
} 
#endif // _DEFMAIN

long double calculate(char str[MAX_INPUT_LENGTH])
{
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
    long double res = postfixCalc(goodData, goodBin);
    return res;
}