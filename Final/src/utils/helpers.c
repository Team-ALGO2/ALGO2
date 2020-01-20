#include "../main.h" 
// WARNING: self referencing 


//A general helper file for all misc tools

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
    return -1;
}
// Trims stuff
char* trimOperator(char* input)
{
    int i = 0;
    int lenght = strlen(input);
    char * out[MAX_INPUT_LENGHT];
    for (i = 0; i < lenght && isNum(input[i]); i++)
    {
        if(isNum(input[i]))
        {
            printf("Num\n");
        }
    }

    strcat(out, &input[i]);
    // printf("out: %s\n", out);
    return out;
}
