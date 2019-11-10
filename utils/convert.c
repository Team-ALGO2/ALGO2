#include <stdio.h>

int convert(void)
{
    int start,i,mod,x = 0;
    int base = 10;
    //ask the input numbers
    printf("What is your starting number? (base 10) \n");
    scanf("%d", &start);
    printf("In what base would you like this number? \n");
    scanf("%d", &base);

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
}