#ifndef _MAINGUARD
#define _DISABLECALC // Prevent Redefinitions
#include "../main.h"
#endif // _MAINGUARD

//Create structure 
typedef struct{
    unsigned int base;
    char * error;
} calcProfile;


calcProfile * initCalc(int base){
    //Use malloc to create profile
    calcProfile * profile = (calcProfile*) malloc(sizeof(calcProfile));
    //Set base
    profile->base = base;
    //Set error
    profile->error = NULL;
    
    return profile;
}   

int closeCalc(calcProfile * profile){
    //Check if error pointer is NULL
    if(profile->error){
        //Free error memory
        free(profile->error);
    }
    //Free profile memory
    free(profile);
    return 0;
}


//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(void)
{
    calcProfile * a = initCalc(10);
    printf("%d", a->base);
    printf("%s", a->error);
    closeCalc(a);
} 
#endif // _DEFMAIN