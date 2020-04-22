//Error Handling :)

#ifndef _MAINGUARD
#define _DISABLECALC // Prevent Redefinitions
#include "../main.h"
#include "init.c" //Used so vscode will stop complaining
#endif // _MAINGUARD


void setError(char * error, calcProfile * profile){
    //
}

void getError(calcProfile * profile){
    //
}

void removeError(calcProfile * profile){
    //
}


//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(void)
{

} 
#endif // _DEFMAIN