#include "main.h"

//a function to split the inputed string into individual arguments
queue parseString(char* inputString)
{
    // queue for operators(stored by their ID) and number(stored as ints)
    queue numberQ = {-1, -1, {0}};
    queue oppQ = {-1, -1, {0}};
    int len = strlen(inputString);
    int isOpp = false;

    char numberC[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    char oppC[18][7] = {"+", "-", "*", "/", "%", "d%", "^", "sqrt", "!", "sin", "cos", "tan", "sineh", "cosineh", "aCb", "aPb", "(", ")"};
    // iterate over the number of characters inputed to be parsed
    for (int i = 0; i < len; i++)
    {
       if (isNum(inputString[i]))
       {
           if (isOpp)
           {
               isOpp = false;
               printf("%s was detected as an opperand (ID = %d) \n", opp, mathID(opp));
                queue_enqueue(&oppQ, mathID(opp));
           }
           printf("%c was detected as an int\n", inputString[i]);
           queue_enqueue(&numberQ, inputString[i]); //if i am correct we dont need atoi because inputing a char as an int will automaticaly convert
       } else {
           // go forward until next number to get full operator
           //get the string of the opperator
           if (!isOpp)
           {
               
           }
           char* opp = ")";
           
       }
    }
}

int main(void)
{
    char *str = "3+8*(sqrt8)";
    parseString(str);
}