#include "../main.h"

int baseConvert(int start, int origBase, int base)
{
    if(origBase > base){
        int i, mod, x;
        //printf("%d in base %d is: ", start , base);
        
        //Creates Stack
        stack result = {-1, {0}};

        //converts from base 10 to base x
        i=start;
        int returnNum = 0;
        int valueIndex = 0;
        while (i != 0)
        {
            mod= i%base;
            stack_push(&result, mod);
            returnNum = returnNum + powr(10, valueIndex) * mod;
            valueIndex++;
            i = (i - mod)/base;
            x++;
        }
        if(base <= 10){
            return(returnNum);
        }
        else
        {
            //IDK do whatever you want to do here with the stack
            // Idk if we want string, or what
            printf("Error: Not Implemented\n");
            stack_printer(&result);
            return(0);
        }
    }
    else if(origBase < base){

    }
    else{
        
    }
}