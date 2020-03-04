//A general helper file for all misc tools

#define OPPNUM 4 //this is the same value as defined in the first box of oppC

#ifndef _MAINGUARD
#include "../main.h"
#endif

//FOR CALC:
char numberC[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
char oppC[OPPNUM] = {"+-*/"};

//Checking Different Ascii Character Types
int isNum(char analyze)
{
    if (analyze >= '0' && analyze <= '9'){return True;}
    else {return False;}
}

int getNum(char analyze)
{
    return analyze - '0';
}

/*
int isStrNum(char analyse[MAX_INPUT_LENGTH])
{
    int len = strlen(analyse);
    for (int i = 0; i < len; i++)
    {
        if (!isNum(analyse[i]) && (analyse[i] != '.') && (analyse[i] != '-'))
        {
            return false;
        }
    }
    return true;
}
*/
//What is this for?

int isAlpha(char analyze)
{
    if (analyze >= 'a' && analyze <= 'z'){return True;}
    else {return False;}
}

int isCapAlpha(char analyze)
{
    if (analyze >= 'A' && analyze <= 'Z'){return True;}
    else {return False;}
}

int isHex(char analyze)
{
    if (analyze >= 'A' && analyze <= 'F'){return True;}
    else {return False;}
}

int isAlphanumerical(char analyze)
{
    if (analyze >= '0' && analyze <= '9'){return True;}
    else if (analyze >= 'a' && analyze <= 'z'){return True;}
    else if (analyze >= 'A' && analyze <= 'Z'){return True;}
    else {return False;}
}

//FOR CALC:
int mathID(char analyze)
{
    for (int i = 0; i < OPPNUM; i++)
    {
        printf("comparingk %d with %d   ", analyze, oppC[i]);
        
        if (analyze == oppC[i])
        {
            printf("returning %d\n", i);
            return i;
        }
    }
    printf("returning %d\n", -1);
    return -1;
}

//removes the first "i" characters from the "input" string and returns the new string
char* trim(char input[MAX_INPUT_LENGTH], int remv)
{
    int i;
    while(input[i])
    {
        input[i] = input[i+remv];
        i++;
    }
    return input;
}

// Trims strings to the next non number character
char* trimOperator(char input[MAX_INPUT_LENGTH])
{
    //No idea what this does; not fixing it
    /*
    int i = 0;
    int lenght = strlen(input);
    char out[MAX_INPUT_LENGTH] = "";
    for (i = 0; i < lenght && (isNum(input[i]) || input[i] == ' ');  i++)
    {}
    //out = trim(input, i);
    // printf("out: %s\n", out);
    return out;
    */
   //Code causing warning, commeting out
}

//a function that will remove all specified characters within a string
//outputs the string without the character
char* removeCharacter(char input[MAX_INPUT_LENGTH], char remv)
{
    //We should remove these items during parsing, and not here to increase preformance 
    int i;
    int removed = 0;
    while(input[i])
    {
        if(input[i+removed] == remv){
            removed++;
        }
        input[i] = input[i+removed];
    }
    return input;
}

//converts nubmers in int form to char* of the numbers
//EX: int i = 21312321 -> char* i = "21312321"
/*char* itoa(int input)
{
    char* out = "";
    char* str; 
    sprintf(str,"%d", input);
    return str;
}
*/
//TODO REINPLEMENT

//a function to see if which opperator has presedce
//it will output -1 if the opperator on the left is heigher, 1 if the opperator on the right is heigher
//and 0 if they are equal
//and 2 for an error
int oppPres(char left, char right)
{
    //idc about the spagehti you are about to read idk how to make it do a loop with 2 different inputs
    //https://tenor.com/view/fullhouse-ohboy-spagheti-michelle-gif-4870369
    
    //for PEDMAS 
    //P = 3
    //E = 2
    //D = 1
    //M = 1
    //A = 0
    //S = 0
    
    int leftPres, rightPres;

    #ifdef DEBUG
     //   printf("%d, %d\n", left, right);
    #endif
    
    //for the left opperator
    switch (left)
    {
        case 43:
            leftPres = 0;
            break;

        case 45:
            leftPres = 0;
            break;
        
        case 42:
            leftPres = 1;
            break;

        case 47:
            leftPres = 1;
            break;
        
        default:
        //for a problem
            return 2;
            break;
    }

    // for the right opperator
    switch (right)
    {
        case 43:
            rightPres = 0;
            break;

        case 45:
            rightPres = 0;
            break;
        
        case 42:
            rightPres = 1;
            break;

        case 47:
            rightPres = 1;
            break;
            
        default:
        //for a problem
            return 2;
            break;
    }

    //find which is bigger
    if (leftPres > rightPres)
    {
        return -1;
    }
    else if (leftPres < rightPres)
    {
        return 1;
    }
    else if (leftPres == rightPres)
    {
        return 0;
    }
    else
    {
        return 3;
    }
}