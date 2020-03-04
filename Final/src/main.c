// Import Libraries + Modules
#include "main.h"


//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main (void)
{

    printf("%d\n", getNum('5'));
    calcProfile * testProfile = initCalc(10);

    //char * testString = "Hello World! This Is A Test!!!";
    printf("===========================\n");
    char * testString = "1234";
    parseString(testString, MAX_INPUT_LENGTH, testProfile);
    printf("===========================\n");
    char * testString2 = "-1234";
    parseString(testString2, MAX_INPUT_LENGTH, testProfile);
    printf("===========================\n");
    char * testString3 = "1234.4321";
    parseString(testString3, MAX_INPUT_LENGTH, testProfile);
    printf("===========================\n");
    char * testString4 = "-1234.4321";
    parseString(testString4, MAX_INPUT_LENGTH, testProfile);
    printf("===========================\n");
    char * testString5 = ".4321";
    parseString(testString5, MAX_INPUT_LENGTH, testProfile);
    printf("===========================\n");
    char * testString6 = "-.4321";
    parseString(testString6, MAX_INPUT_LENGTH, testProfile);
    printf("===========================\n");

}
#endif // _DEFMAIN