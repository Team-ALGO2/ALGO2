#include "../main.h"

int main(void)
{   
    printf("%d", FALSE);
    printf("GENERATE STACKS\n");
    stack test = {-1, {0}};
    stack test2 = {-1, {0}};
    int testInt = 5;

    printf("Adding Values For test\n");
    stack_printer(&test);
    stack_push(&test, testInt);
    stack_push(&test, testInt + 100);
    stack_push(&test, testInt - 7);

    printf("Adding Values For test2\n");
    stack_push(&test2, -1);
    stack_push(&test2, -2);
    stack_push(&test2, -3);
    stack_push(&test2, -4);
    stack_push(&test2, -5);
    stack_push(&test2, -6);
    stack_push(&test2, -7);
    stack_push(&test2, -8);
    stack_push(&test2, -9);
    stack_push(&test2, -10);
    stack_push(&test2, -11);
    stack_push(&test2, -12);

    stack_printer(&test);
    stack_printer(&test2);

    printf("top: %i", stack_top(&test));
    stack_pop(&test);
    printf("top: %i", stack_top(&test));
    stack_pop(&test);
    printf("top: %i", stack_top(&test));
    stack_pop(&test);

    printf("top: %i", stack_top(&test));
    stack_pop(&test);
    stack_pop(&test);
    stack_pop(&test);
    stack_pop(&test);
    stack_pop(&test);
    stack_pop(&test);
    stack_pop(&test);
    stack_pop(&test);
    stack_pop(&test);
    printf("top: %i", stack_top(&test));
}
