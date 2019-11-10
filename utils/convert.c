#include <stdio.h>
#include "stack.c"

int baseConvert(int start, int base)
{
    int i, mod, x;
    //printf("%d in base %d is: ", start , base);
    
    //Creates Stack
    //stack result = {-1, {0}};

    //converts from base 10 to base x
    i=start;
    int returnNum = 0;
    int valueIndex = 0;
    while (i != 0)
    {
        mod= i%base;
        returnNum = returnNum + powr(10, valueIndex) * mod;
        valueIndex++;
        i = (i - mod)/base;
        x++;
    }
    return(returnNum);
}