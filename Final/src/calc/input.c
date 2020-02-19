#ifndef _MAINGUARD
#define _DISABLECALC // Prevent Redefinitions
#include "../main.h"
#endif

//Create structure containing list pointer, list length, and max length of list value
typedef struct{
    char ** list; //Pointer to list
    int values; //Number of values inside list
    int maxLen; //Maximum length of values
} keyWordList;

//Create commandList Keyword
char * commandListTemp[] = {"STORE", "TEST", "GETALL"};
keyWordList commandList = {commandListTemp, 3, MAXCOMMANDLEN};

//Create test list
char * testListTemp[] = {"wasd", "test1", "test", "test12"};
keyWordList testList = {testListTemp, 4, MAXCOMMANDLEN};


//Predefine Function
int lookAheadString(char * exp, int strMaxLen, int currentOffset, keyWordList * kwl);
int parseStringWithSpecialFunc(char * exp);


//Parse from string to Eval
int parseString(char * exp, int strMaxLen, int base){
    // Set i (Current Scanning Letter)
    int i = 0;

    //Running Look Ahead For Commands
    int lookAheadResult = lookAheadString(exp, strMaxLen, i, &commandList);

    //TESTING
    //printf("%d", lookAheadString(exp, strMaxLen, i, &testList));

    //printf("%d", lookAheadResult);
    //Check if lookAheadResult succeded
    if(lookAheadResult){ // Detected a special function (STORE; GET ...)
        parseStringWithSpecialFunc(exp);
    }
    else{
        while (exp[i] != '\0' && i < strMaxLen){
            char currentScan = exp[i];
            
            #ifdef DEBUG
            #ifndef WEBMODE
            printf("CURRENTLY SCANNING: %c\n", currentScan);
            #endif
            #endif

            //Check if should run base10 pipeline or baseX pipeline
            if(base == 10){
                //do stuff
            }
            else{

            }

            i++;
        }
    }
//  printf("\n");
//  printf("ok!\n");
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

//Look Ahead Function
//Used to check if a word is present from a list (keyWordList)
//Scans letter by letter until hits word or hits nothing
//Note: this is not that efficient, but it gets the job done
int lookAheadString(char * exp, int strMaxLen, int currentOffset, keyWordList * kwl){
    //Look Ahead Offset Index
    int i2 = 0;
    //If Completed
    int matched = false;
    // Min/Max values (If Applicable)
    #if LOOKAHEADMODE == 1
    int minVal = INFINITY;
    #endif
    #if LOOKAHEADMODE == 2
    int maxVal = 0;
    #endif
    //Loop through all key words
    for(int keyWordIndex = 0; keyWordIndex < kwl->values; keyWordIndex++){
        int keyWordLen = strlen(kwl->list[keyWordIndex]);
        #if LOOKAHEADMODE == 0
        if(matched){
            break;
        }
        #endif
        //Reset Look Ahead Offset Index
        i2 = 0;
        while (exp[i2 + currentOffset] != '\0' && (i2 + currentOffset) < strMaxLen && i2 < kwl->maxLen){
            char LAScanExp = exp[i2 + currentOffset];
            char LAScanKwl = kwl->list[keyWordIndex][i2];
            //printf("-%c|%c-", LAScanExp, LAScanKwl);
            //Check if letter scanning does not match letter in key list
            if(LAScanExp != LAScanKwl){
                //Fail for this case
                break;
            }
            if(i2 == keyWordLen-1){
                //Set matched and save (if applicable) value
                matched = true;
                i2++;
                #if LOOKAHEADMODE == 1
                if(i2 < minVal){
                    minVal = i2;
                }
                #endif
                #if LOOKAHEADMODE == 2
                if(i2 > maxVal){
                    maxVal = i2;
                }
                #endif
                break;
            }
            //printf("%c", LAScan);
            i2++;
        }
    }
    if(matched){
        //Check modes
        #if LOOKAHEADMODE == 0
        return i2;
        #elif LOOKAHEADMODE == 1
        return minVal;
        #elif LOOKAHEADMODE == 2
        return maxVal;
        #endif
    }
    else{
        //Always return zero if all cases fail
        return 0;
    }
}

int parseStringWithSpecialFunc(char * exp)
{
    int i = 0;
    char function[MAXCOMMANDLEN] = "";

    while (exp[i] != '\0' && isCapAlpha(exp[i]))  // Parse to get function
    {
        char currentScan = exp[i];
        char appending[2];
        appending[0] = currentScan;
        appending[1] = '\0';
        strcat(function, appending);
        i++;
    }

    #ifdef WEBMODE
    printf("<li><strong>%s</strong> command detected</li>", function); // Send this to browser!
    #endif

    if (strcmp(function, "STORE") == 0)     /* Store Command */
    {
        char argument[MAXCOMMANDARGUMENTLEN] = "";
        int iargument;

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
            strcat(argument, appending);
            i++;

        }
        sscanf(argument, "%d", &iargument);
        fprintf(stderr, "ARGUMENT as int: %d\n", iargument);

        cacheSET(varname, iargument);

        #ifdef WEBMODE
        printf("<li>Successfully stored the variable <strong>%s</strong> as <strong>%d</strong>!</li>", varname, iargument); // Send this to browser!
        #endif
        return 0; //success

    } else if (strcmp(function, "GETALL") == 0) 
    {
        int i = 0;

        while (i < MAX_VARIABLE_NUMBER)  // For every cache in list until \0 (end) is reached     strcmp(list.caches[i].name, "\0") != 0 && 
        {
                #ifdef WEBMODE
                printf("<li><strong>%s</strong> = <strong>%d</strong></li>", list.caches[i].name, list.caches[i].value);
                #endif
                i++;
        }       

    }
    else { /* No match */
        #ifdef WEBMODE
        printf("<li>The function didn't match any known special function</li>"); // Send this to browser!
        #endif

    }
}

//Main Function For Testing! Uncomment When needed





/*
int main(void)
{
    //char * testString = "Hello World! This Is A Test!!!";
    char * testString = "test12";
    parseString(testString, MAX_INPUT_LENGTH, 10);
} 
*/


