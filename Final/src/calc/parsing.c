#ifndef _MAINGUARD
#define _DISABLECALC // Prevent Redefinitions
#include "../main.h"
#undef _DEFMAIN
#include "init.c" //For testing purposes
#define _DEFMAIN
#endif // _MAINGUARD

//Enum Of Command Ids
enum commands{cmd_store, cmd_test, cmd_getall}; 

//Create structure containing list pointer, list length, and max length of list value
typedef struct{
    char ** list; //Pointer to list of values
    int * ids; //Pointer to list of ids (Pairs ID up with value)
    int values; //Number of values inside list
    int maxLen; //Maximum length of values
} keyWordList;

//Create Custom Dataformat For lookAheadString
typedef struct{
    int length; //Length of Matched String
    int index; //Index of element matched
    int indexId; //ID of Index of element matched (NULL if keyWordList if pointer is NULL)
} lookAheadResult;

//Create Command List
char * commandListTemp[] = {
    "STORE",
    "STOR",
    "STO",
    "TEST",
    "WASD",
    "GETALL"
};
int commandIdListTemp[] = {
    cmd_store,
    cmd_store,
    cmd_store,
    cmd_test,
    cmd_test,
    cmd_getall
    };
//As you can see, this is compatible with aliases by using commandIdListTemp
keyWordList commandList = {commandListTemp, commandIdListTemp, 6, MAXCOMMANDLEN};

/*
math_void,
    //Important 
    math_abs,
    math_floor,
    math_ceil,
    math_round,
    //Basic Math
    math_add,
    math_subtract,
    math_multiply,
    math_divide,
    //Advanced Math
    math_mod,
    math_factorial,
    //Exponential Math
    math_power,
    math_squareroot,
    math_nthroot,
    math_log,
    math_exp,
    math_ln,
    math_sine,
    math_cosine,
    math_tangent,
    math_secant,
    math_cosecant,
    math_cotangent,
    math_sineh,
    math_cosineh,
    math_tanh,
    //Combinatronics Math
    math_choose,
    math_perm
*/

//Create Full-Text Operator List
char * operatorListTemp[] = {
    "abs",
    "floor",
    "ceil",
    "round",
    "sqrt",
    "nsqrt",
    "log",
    "exp",
    "ln",
    "sin",
    "sine",
    "cos",
    "cosine",
    "tan",
    "tangent",
    "sec",
    "secant",
    "csc",
    "cosecant",
    "cot",
    "cotangent",
    "sinh",
    "sineh",
    "cosh",
    "cosineh",
    "tanh",
    "tangenth"
};
int opperatorIdListTemp[] = {
    math_abs,
    math_floor,
    math_ceil,
    math_round,
    math_squareroot,
    math_nthroot,
    math_log,
    math_exp,
    math_ln,
    math_sine,
    math_sine,
    math_cosine,
    math_cosine,
    math_tangent,
    math_secant,
    math_cosecant,
    math_cotangent,
    math_sineh,
    math_cosineh,
    math_tanh,
};
keyWordList stringOpperatorList = {operatorListTemp, opperatorIdListTemp, 27, MAXCOMMANDLEN};

//Create test list
char * testListTemp[] = {
    "wasd",
    "test1",
    "test",
    "test12"
};
int testIdListTemp[] = {
    1,
    22,
    333,
    4444
};
keyWordList testList = {testListTemp, testIdListTemp, 4, MAXCOMMANDLEN};


//Predefine Function
int lookAheadString(char * exp, int currentOffset, lookAheadResult * res, keyWordList * kwl, calcProfile * profile);
int parseStringWithSpecialFunc(char * exp, lookAheadResult * res, calcProfile * profile);


//Parse from string to Eval
int parseString(char * exp, calcProfile * profile){
    // Set i (Current Scanning Letter)
    int i = 0;

    //Running Look Ahead For Commands
    lookAheadResult cmdLookResult;
    lookAheadString(exp, i, &cmdLookResult, &commandList, profile);
    printf("%d - %d\n", cmdLookResult.length, cmdLookResult.index);

    //printf("%d", lookAheadResult);
    //Check if lookAheadResult succeded
    if(cmdLookResult.length){ // Detected a special function (STORE; GET ...)
        int commandResult = parseStringWithSpecialFunc(exp, &cmdLookResult, profile);
    }
    else{
        while (exp[i] != '\0' && i < profile->strMaxLen){
            char currentScan = exp[i];
            
            #ifdef DEBUG
            #ifndef WEBMODE
            printf("CURRENTLY SCANNING: %c\n", currentScan);
            #endif // WEBMODE
            #endif // DEBUG

            //Check if should run base10 pipeline or baseX pipeline
            if(profile->base == 10){
                printf("BASE10\n");
                //
                //do stuff for base 10
                //

                //Hacky way of checking if input should parse '-' as negative or subtraction and '+' as positive or addition
                int parseLogicSymbol = False;

                //Hacky way of checking if input should parse as multiplication or not (Turns "(5)(6)" into "(5)*(6)")
                int parseMultiplication = False;

                //Pre-Check Character Operators
                int operatorCharCheck = checkOperator(currentScan);
                //Pre-Check String Operators
                lookAheadResult operatorStringCheck;
                lookAheadString(exp, i, &operatorStringCheck, &stringOpperatorList, profile);

                //Do operations for brackets
                if(currentScan == '('){
                    printf("========================== TEMP -- CHAR DETECTED: (");
                    i++; //Increment I
                }
                else if(currentScan == ')'){
                    printf("========================== TEMP -- CHAR DETECTED: )");
                    i++; //Increment I
                }

                //Do operations for numbers
                else if(isNum(currentScan) || currentScan == '-' || currentScan == '+' || currentScan == '.'){
                    printf("NUMBER DETECTED!\n");
                    //Define Scan Variables
                    int numDigit = 0; //Current Number of Digits
                    int numSign = 0; //Current Sign (neg or pos)
                    int numDecimal = false; //Current Decimal (Above 0 or Under 0)
                    long double currentNum = 0;
                    while (exp[i] != '\0' && i < profile->strMaxLen){
                        char numCurrentCharacter = exp[i];
                        printf("NUMBER SCANNING: %c -- CURRENT NUM: %Lf\n", numCurrentCharacter, currentNum);

                        //Check if number is negative
                        if(numSign == 0){
                            if(numCurrentCharacter == '-'){
                                printf("negative!\n");
                                numSign = -1;
                                i++; //Since '-' takes up a character, increment i
                                continue;
                            }
                            else if(numCurrentCharacter == '+'){
                                printf("positive!\n");
                                numSign = 1;
                                i++; //Since '+' takes up a character, increment i
                                continue;
                            }
                            else{
                                printf("positive!\n");
                                numSign = 1;
                                //Since there was no character, do not increment i
                            }
                        }

                        //Check if a decimal appears
                        if(numDecimal == false){
                            if(numCurrentCharacter == '.'){
                                printf("decimal!\n");
                                numDecimal = true;
                                numDigit = -1;
                                i++; //Since '.' takes up a character, increment i
                                continue;
                            }
                        }

                        //Check if is digit
                        if(isNum(numCurrentCharacter)){
                            if(!numDecimal){ // Adds Digits For Non Decimal Numbers
                                currentNum = currentNum * 10 + getNum(numCurrentCharacter);
                                numDigit++;
                                i++;
                            }
                            else{ // Adds Digits For Decimal Numbers
                                currentNum = currentNum + getNum(numCurrentCharacter) * fastPower(10, numDigit);
                                numDigit--;
                                i++;
                            }
                        }

                        //Fail All Checks, Not A Number Anymore
                        else{
                            break; //Break out of loop
                        }
                    }
                    if(numSign == -1){
                        currentNum = -1 * currentNum;
                    }
                    printf("TEMP -- NUMBER DETECTED: %Lf\n", currentNum);
                    //continue; //Skip All Other Checks On Main Loop (Bypasses i++ On Bottom)
                }

                //Do operations for operators
                else if(false){
                    
                }
                //Do operations for full text operators
                else if(false){
                    
                }

                //Do operations for variables
                else if(false){
                    
                }

                //Do operations for whitespace
                else if(false){
                    
                }

                //All Conditions Fail (Error)
                else{
                    
                }

            }
            else if(profile->base > 36){
                #ifdef FORCEHIGHBASE //Check High Base Flag - VERY EXPERIMENTAL!!!
                printf("BASEOVER\n");
                //do stuff for base over 36
                #endif // FORCEHIGHBASE
                #ifndef FORCEHIGHBASE
                //GIVE ERROR
                printf("ERROR\n");
                #endif // FORCEHIGHBASE
            }
            else{
                printf("BASE10+\n");
                //do stuff for any other base
            }

            //i++;
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
int lookAheadString(char * exp, int currentOffset, lookAheadResult * res, keyWordList * kwl, calcProfile * profile){
    //printf("%d, %d, %d, %d\n", kwl->ids[0], kwl->ids[1], kwl->ids[2], kwl->ids[3]);
    //Look Ahead Offset Index
    int i2 = 0;
    //Element Matched (If Matched)
    int matchedIndex = 0;
    //Id of Element Matched (If Matched)
    int matchedIndexId = 0;
    //If Completed
    int matched = false;
    // Min/Max values (If Applicable)
    #if LOOKAHEADMODE == 1
    int minVal = INFINITY;
    #elif LOOKAHEADMODE == 2
    int maxVal = 0;
    #endif // LOOKAHEADMODE
    //Loop through all key words
    for(int keyWordIndex = 0; keyWordIndex < kwl->values; keyWordIndex++){
        int keyWordLen = strlen(kwl->list[keyWordIndex]);
        #if LOOKAHEADMODE == 0
        if(matched){
            break;
        }
        #endif // LOOKAHEADMODE
        //Reset Look Ahead Offset Index
        i2 = 0;
        while (exp[i2 + currentOffset] != '\0' && (i2 + currentOffset) < profile->strMaxLen && i2 < kwl->maxLen){
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
                #if LOOKAHEADMODE == 0
                matchedIndex = keyWordIndex;
                if(kwl->ids != NULL){
                    matchedIndexId = kwl->ids[keyWordIndex];
                }
                #elif LOOKAHEADMODE == 1
                if(i2 < minVal){
                    minVal = i2;
                    matchedIndex = keyWordIndex;
                if(kwl->ids != NULL){
                    matchedIndexId = kwl->ids[keyWordIndex];
                }
                }
                #elif LOOKAHEADMODE == 2
                if(i2 > maxVal){
                    maxVal = i2;
                    matchedIndex = keyWordIndex;
                if(kwl->ids != NULL){
                    matchedIndexId = kwl->ids[keyWordIndex];
                }
                }
                #endif // LOOKAHEADMODE
                break;
            }
            //printf("%c", LAScan);
            i2++;
        }
    }
    if(matched){
        //Check modes
        #if LOOKAHEADMODE == 0
        res->length = i2;
        res->index = matchedIndex;
        res->indexId = matchedIndexId;
        return 1;
        #elif LOOKAHEADMODE == 1
        res->length = minVal;
        res->index = matchedIndex;
        res->indexId = matchedIndexId;
        return 1;
        #elif LOOKAHEADMODE == 2
        res->length = maxVal;
        res->index = matchedIndex;
        res->indexId = matchedIndexId;
        return 1;
        #endif // LOOKAHEADMODE
    }
    else{
        //Always return zero if all cases fail
        res->length = 0;
        res->index = matchedIndex;
        res->indexId = matchedIndexId;
        return 0;
    }
}

//cmd_store, cmd_test, cmd_getall

int parseStringWithSpecialFunc(char * exp, lookAheadResult * res, calcProfile * profile)
{
    int i = res->length;

    /*
    if(i >= profile->strMaxLen){ // String Out Of Bounds
        return false; //Return Error
    }
    */

    if(res->indexId == cmd_store){
        char argument[MAXCOMMANDARGUMENTLEN] = "";
        int iargument;

        fprintf(stderr, "STORE\n");

        printf("??? %d\n", i);
        while (exp[i] == ' ' && exp[i] != '\0' && i < profile->strMaxLen)  // Skip whitespace
        {
            i++;
        }
        printf("??? %d\n", i);

        char varname[MAX_INPUT_LENGTH] = "";
        while (exp[i] != ' ' && exp[i] != '\0' && i < profile->strMaxLen)  // get var name
        {
            char currentScan = exp[i];
            char appending[2];
            appending[0] = currentScan;
            appending[1] = '\0';
            strcat(varname, appending);
            i++;

        }
        fprintf(stderr, "VARNAME: %s\n", varname);

        printf("??? %d\n", i);
        while (exp[i] == ' ' && exp[i] != '\0' && i < profile->strMaxLen)  // Skip whitespace
        {
            i++;
        }
        printf("??? %d\n", i);

        while (exp[i] != ' ' && exp[i] != '\0' && i < profile->strMaxLen)  // get var value
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
        #endif // WEBMODE
        return true; //Return success
    }
    else if(res->indexId == cmd_test){
        printf("=== TEST COMMAND RECEIVED ===\n");
    }
    else if(res->indexId == cmd_getall){
        int i = 0;

        while (i < MAX_VARIABLE_NUMBER)  // For every cache in list until \0 (end) is reached     strcmp(list.caches[i].name, "\0") != 0 && 
        {
                #ifdef WEBMODE
                printf("<li><strong>%s</strong> = <strong>%d</strong></li>", clist.caches[i].name, clist.caches[i].value);
                #endif // WEBMODE
                i++;
                return true; //Return success
        }
    }

    else{
        #ifdef WEBMODE
        printf("<li>The function didn't match any known special function</li>"); // Send this to browser!
        #endif // WEBMODE

        return false; //Return failure
    }

    //OLD CODD
    /*
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
    #endif // WEBMODE

    if (strcmp(function, "STORE") == 0)     //Store Command
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
        #endif // WEBMODE
        return true; //Return success

    } else if (strcmp(function, "GETALL") == 0) 
    {
        int i = 0;

        while (i < MAX_VARIABLE_NUMBER)  // For every cache in list until \0 (end) is reached     strcmp(list.caches[i].name, "\0") != 0 && 
        {
                #ifdef WEBMODE
                printf("<li><strong>%s</strong> = <strong>%d</strong></li>", clist.caches[i].name, clist.caches[i].value);
                #endif // WEBMODE
                i++;
                return true; //Return success
        }       

    }
    else { //No match
        #ifdef WEBMODE
        printf("<li>The function didn't match any known special function</li>"); // Send this to browser!
        #endif // WEBMODE

        return false; //Return failure

    }
    */
}


//Main Function For Testing! Uncomment When needed
//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(void)
{
    
}
#endif // _DEFMAIN



