#include "../main.h"
//a general helper file for all misc tools

//FOR CALC:
int oppNum = 18; //this is the same value as defined in the first box of oppC
char numberC[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
char oppC[18][7] = {"+", "-", "*", "/", "%", "d%", "^", "sqrt", "!", "sin", "cos", "tan", "sineh", "cosineh", "aCb", "aPb", "(", ")"};

int isNum(char analyze)
{
    if (analyze > 47 && analyze < 58)
       {
           return true;
       }
    else 
    {
        return false;
    }
}

//FOR CALC:
int mathID(char* analyze)
{
    for (int i = 0; i < oppNum; i++)
    {
        
        if (strcmp(analyze, oppC[i]) == 0)
        {
            return i;
        }
    }
}
