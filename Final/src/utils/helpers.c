//A general helper file for all misc tools

#define OPPNUM 4 //this is the same value as defined in the first box of oppC

#ifndef _MAINGUARD
#include "../main.h"
#endif

//Types of math functions
enum math{
    //Defult First Value! Plz Ignore
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
};

//List of SINGLE CHARACTER operators and its operation!
const int opperatorInfo[][2] = {
    {'+', math_add},
    {'-', math_subtract},
    {'*', math_multiply},
    {'/', math_divide},
    {'!', math_factorial},
    {'^', math_power},
    {'C', math_choose},
    {'P', math_perm}
};

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

int checkOperator(char analyze){
    int totalOperators = sizeof(opperatorInfo) / sizeof(opperatorInfo[0]);
    for(int i = 0; i < totalOperators; i++){
        if(analyze == opperatorInfo[i][0]){
            return opperatorInfo[i][1];
        }
    }
    return 0;
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
        //+
        case 43:
            leftPres = 0;
            break;

        //-
        case 45:
            leftPres = 0;
            break;
        
        //*
        case 42:
            leftPres = 1;
            break;

        //</>
        case 47:
            leftPres = 1;
            break;
        
        //%
        case 37:
            leftPres = 1;
            break;
        
        //^
        case 94:
            leftPres = 2;
            break;
        
        default:
        //for a problem
            return 2;
            break;
    }

    // for the right opperator
    switch (right)
    {
        
        //+
        case 43:
            rightPres = 0;
            break;

        //-
        case 45:
            rightPres = 0;
            break;
        
        //*
        case 42:
            rightPres = 1;
            break;

        //</>
        case 47:
            rightPres = 1;
            break;

        //%
        case 37:
            rightPres = 1;
            break;
        
        //^
        case 94:
            rightPres = 2;
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