#include "../utils/stack.c"


int main(void)
{ 
    stack test = {-1, {0}};
    
    int testInt = 5;
    printer(&test);
    push(&test, testInt);
    push(&test, testInt + 100);
    push(&test, testInt - 7);
    printf("top: %i", top(&test));
    printer(&test);
    pop(&test);
    printf("top: %i ", top(&test));
    printer(&test);
}
