// Import Libraries + Modules
#include "main.h"


//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main (void)
{

    printf("%d\n", getNum('5'));
    calcProfile * testProfile = initCalc(10);

    //char * testString = "Hello World! This Is A Test!!!";
    
    //TESTING
    char * exp = "test"; 
    lookAheadResult testLookResult;
    printf("%d - %d - %d\n", testLookResult.length, testLookResult.index, testLookResult.indexId);
    lookAheadString(exp, 0, &testLookResult, &testList, testProfile);
    printf("%d - %d - %d\n", testLookResult.length, testLookResult.index, testLookResult.indexId);
    printf("===========================\n");
    char * testStringXX = "STORE  A   10";
    parseString(testStringXX, testProfile);
    printf("===========================\n");
    char * testStringXX2 = "TEST";
    parseString(testStringXX2, testProfile);
    printf("===========================\n");
    char * testStringXX2plus = "WASD";
    parseString(testStringXX2plus, testProfile);
    printf("===========================\n");
    char * testString = "1234";
    parseString(testString, testProfile);
    printf("===========================\n");
    char * testString2 = "-1234";
    parseString(testString2, testProfile);
    printf("===========================\n");
    char * testString3 = "1234.4321";
    parseString(testString3, testProfile);
    printf("===========================\n");
    char * testString4 = "-1234.4321";
    parseString(testString4, testProfile);
    printf("===========================\n");
    char * testString5 = ".4321";
    parseString(testString5, testProfile);
    printf("===========================\n");
    char * testString6 = "-.4321";
    parseString(testString6, testProfile);
    printf("===========================\n");

}
#endif // _DEFMAIN