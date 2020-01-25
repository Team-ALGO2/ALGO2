//A general helper file for all misc tools

//FOR CALC:
int oppNum = 5; //this is the same value as defined in the first box of oppC
char numberC[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
char oppC[5] = {"+-*/%"};

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
int mathID(char analyze)
{
    for (int i = 0; i < oppNum; i++)
    {
        
        if (analyze == oppC[i])
        {
            return i;
        }
    }
    return -1;
}

//removes the first "i" characters from the "input" string and returns the new string
char* trim(char* input, int i)
{
    char* out = "";
    strcat(out, input[i]);
    printf("out: %s\n", out);
    return out;
}



// Trims strings to the next non number character
char* trimOperator(char* input)
{
    int i = 0;
    int lenght = strlen(input);
    char* out = "";
    for (i = 0; i < lenght && isNum(input[i]); i++)
    {}
    out = trim(input, i);
    // printf("out: %s\n", out);
    return out;
}


//converts nubmers in int form to char* of the numbers
//EX: int i = 21312321 -> char* i = "21312321"
char* unAtoi(int input)
{
    char* out = "";
    char* str; 
    sprintf(str,"%d", input);
    return str;
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
    
    //for the left opperator
    switch (mathID(left))
    {
    case 0:
        leftPres = 0;
        break;

    case 1:
        leftPres = 0;
        break;
    
    case 2:
        leftPres = 1;
        break;

    case 3:
        leftPres = 1;
        break;

    case 4:
        leftPres = 2;
        break;
    
    default:
    //for a problem
        return 2;
        break;
    }

    // for the right opperator
    switch (mathID(right))
    {
    case 0:
        rightPres = 0;
        break;

    case 1:
        rightPres = 0;
        break;
    
    case 2:
        rightPres = 1;
        break;

    case 3:
        rightPres = 1;
        break;

    case 4:
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
        return 2;
    }
    
    
    
}