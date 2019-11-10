#include <stdio.h>

int baseConvert(int start, int base)
{
    int i, mod, x;
    printf("%d in base %d is: ", start , base);
    
    //converts from base 10 to base x
    i=start;
    while (i != 0)
    {
        mod= i%base;
        printf("%d" ,mod);
        i = (i - mod)/base;
        x++;
    }
    
    //need to use a stack here to make it print properly
    printf(" (nubmber is read right to left) \n");
    return(1);
}