#include "src/main.h"

int main(void)
{   
    printf("GENERATE STACKS\n");
    stack test = {-1, {0}};
    stack test2 = {-1, {0}};
    stack test3 = {-1, {0}};

    printf("\n\nAdding Values For test\n");
    stack_printer(&test);
    stack_push(&test, 1);
    stack_push(&test, 2);
    stack_push(&test, 3);
    stack_printer(&test);

    printf("Popping Values For test\n");
    printf("top: %i\n", stack_top(&test));
    stack_pop(&test);
    stack_printer(&test);
    printf("top: %i\n", stack_top(&test));
    stack_pop(&test);
    stack_printer(&test);
    printf("top: %i\n", stack_top(&test));
    stack_pop(&test);
    stack_printer(&test);

    printf("Testing Underflows\n");
    printf("top: %i\n", stack_top(&test));
    stack_pop(&test);

    printf("\n\nAdding Values For test2\n");
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
    stack_printer(&test2);

    printf("\n\nTesting Overflows\n");
    for(int a = 0; a < STACK_MAX_LENGTH-1; a++){
        stack_push(&test3, 1);
    }
    stack_printer(&test3);
    printf("Adding One More SHOULD WORK\n");
    stack_push(&test3, 1111);
    stack_printer(&test3);
    printf("Adding One More ==SHOULD NOT WORK==\n");
    stack_push(&test3, 9999);
    stack_printer(&test3);
}
