#ifndef _MAINGUARD
#define _DISABLECALC // Prevent Redefinitions
#include "../main.h"
#endif

//compute the postfix string
int parseString(char exp[MAX_INPUT_LENGTH])
{
    int i = 0;

    while (exp[i] != '\0')
    {
        char currentScan = exp[i];

        if (isCapAlpha(currentScan))    // Detected a special function (STORE; GET ...)
        {
            parseStringWithSpecialFunc(exp);
            break;

        }
        

        // printf("%c", currentScan);
        i++;
    }
    return 0;

/*
    int i = 0;
    int j = 0;
    int counter = 0;
    long number;
    char val[MAX_INPUT_LENGTH];
    if (isCapAlpha(exp[1]))     // Special command: STORE, BASECHANGE
    {
        if (strncmp(exp, "STORE", 6) == 0)
        {
            printf("store comamnd\n");
        }
    }
    while (exp[i] != '\0')
    {
        switch (exp[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                    val[j] = exp[i];
                    j++;
                    break;
            case '+':
                    if (j>0) {
                        number = strtol(val, (char **)NULL, 10);
                        j = 0;
                    }
        }
        
    }
*/
}

int parseStringWithSpecialFunc(char exp[MAX_INPUT_LENGTH])
{
    int i = 0;
    char function[MAX_INPUT_LENGTH] = "";
    char varvalue[MAX_INPUT_LENGTH] = "";
    int ivarvalue;

    while (exp[i] != '\0' && isCapAlpha(exp[i]))  // Parse to get function
    {
        char currentScan = exp[i];
        char appending[2];
        appending[0] = currentScan;
        appending[1] = '\0';
        strcat(function, appending);
        i++;
    }

    if (strcmp(function, "STORE") == 0)
    {
        fprintf(stderr, "STORE\n");

        while (exp[i] != ' ' && exp[i] != '\0')  // Skip whitespace
        {
            i++;
        }
        i++;
        char varname[MAX_INPUT_LENGTH] = "";
        while (exp[i] != ' ' && exp[i] != '\0')  // get var name
        {
            char currentScan = exp[i];
            char appending[2];
            appending[0] = currentScan;
            appending[1] = '\0';
            strcat(varname, appending);
            i++;

        }
        fprintf(stderr, "VARNAME: %s\n", varname);

        while (exp[i] != ' ' && exp[i] != '\0')  // Skip whitespace
        {
            i++;
        }
        i++;

        while (exp[i] != ' ' && exp[i] != '\0')  // get var value
        {
            char currentScan = exp[i];
            char appending[2];
            appending[0] = currentScan;
            appending[1] = '\0';
            strcat(varvalue, appending);
            i++;

        }
        sscanf(varvalue, "%d", &ivarvalue);
        fprintf(stderr, "VARVALUE as int: %d\n", ivarvalue);

        cacheSET(varname, ivarvalue);

        return 0; //success








    } // Add more elif when more special functions are added
    
}

//Main Function For Testing! Uncomment When needed

/*
int main(void)
{
    parseString("test");
} 
*/