// Import Libraries + Modules
#include "main.h"


//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main (void)
{
    calcProfile * testProfile = initCalc(10);

    //char * testString = "Hello World! This Is A Test!!!";
    char * testString = "test";
    parseString(testString, MAX_INPUT_LENGTH, testProfile);

}
#endif // _DEFMAIN