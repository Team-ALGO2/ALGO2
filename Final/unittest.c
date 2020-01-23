#include "src/main.h"

int tests_ran = 0;
int tests_successful = 0;
int tests_failed = 0;

void log_test(int success);
void test_math();
void test_stack();
void test_queue();

void ASSERT_TRUE(int expression, char* name)
{
    int success;
    if (expression)
    {
        printf("    -   %s  "GRN"\xE2\x9C\x93\n"RESET, name);
        success = 1;
    } else {
        printf("    -   %s  "RED"x\n"RESET, name);
        success = 0;
    }
    log_test(success);
}

void ASSERT_FALSE(int expression, char* name)
{
    int success;
    if (!expression)
    {
        success = 1;
        printf("    -   %s  "GRN"\xE2\x9C\x93\n"RESET, name);
    } else {
        success = 0;
        printf("    -   %s  "RED"x\n"RESET, name);
    }
    log_test(success);
}

void ASSERT_EQUAL_INT(int expr1, int expr2, char* name)
{
    int success;
    if (expr1 == expr2)
    {
        success = 1;
        printf("    -   %s  "GRN"\xE2\x9C\x93\n"RESET, name);
    } else {
        success = 0;
        printf("    -   %s  "RED"x\n"RESET, name);
    }
    log_test(success);
}

void ASSERT_EQUAL_STR(char* expr1, char* expr2, char* name)
{
    int success;
    if (expr1 == expr2)
    {
        success = 1;
        printf("    -   %s  "GRN"\xE2\x9C\x93\n"RESET, name);
    } else {
        success = 0;
        printf("    -   %s  "RED"x\n"RESET, name);
    }
    log_test(success);
}

void log_test(int success)
{
    tests_ran++;
    if (success)
    {
        tests_successful++;
    } else {
        tests_failed++;
    }
} 

int main(void)
{
    system(CLEAR);
    clock_t begin = clock();

    /* Begin Tests */
	test_math();
    test_stack();
    test_queue();

    /* End Tests */

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\n======================================\n");
    printf("Test successful: "GRN"%d"RESET"\n", tests_successful);
    printf("Test failed: "RED"%d"RESET"\n", tests_failed);
    printf("Ran %d tests in %lfs\n", tests_ran, time_spent);
    printf("======================================\n\n");

}

void test_math()
{
	printf("\n---------- Math Tests ----------\n");
	ASSERT_EQUAL_INT(add(3, 5), 8, "Add");
	ASSERT_EQUAL_INT(subtract(5, 2), 3, "Substract");
	ASSERT_EQUAL_INT(multiply(6, 5), 30, "Multiply");
	ASSERT_EQUAL_INT(divide(10, 2), 5, "Divide");
	ASSERT_EQUAL_INT(mod(5, 2), 1, "Mod");
	ASSERT_EQUAL_INT(powr(5, 2), 25, "Exponent");
	ASSERT_EQUAL_INT((int)squarert(81), 9, "Squareroot");
	ASSERT_EQUAL_INT(factorial(4), 24, "Factorial");
	printf("-------- End Math Tests --------\n");
}

void test_stack()
{
    stack test = {-1, {0}};
	printf("\n---------- Stack Tests ----------\n");
    stack_push(&test, 5);
	ASSERT_EQUAL_INT(stack_top(&test), 5, "Push 5");
    stack_push(&test, 15);
	ASSERT_EQUAL_INT(stack_top(&test), 15, "Push Twice");
    stack_pop(&test);
	ASSERT_EQUAL_INT(stack_top(&test), 5, "Pop");
	ASSERT_FALSE(stack_isFull(&test), "Is full");
    ASSERT_FALSE(stack_isEmpty(&test), "Is empty");
    stack_pop(&test);
    ASSERT_TRUE(stack_isEmpty(&test), "Is actually empty");
    stack_push(&test, 15);
    stack_push(&test, 15);
    stack_push(&test, 15);
    ASSERT_EQUAL_INT(stack_length(&test), 2, "Stack lenght");
	printf("-------- End Stack Tests --------\n");
}

void test_queue()
{
    queue test = {-1, {0}};
	printf("\n---------- Queue Tests ----------\n");
    queue_enqueue(&test, 5);
	ASSERT_EQUAL_INT(queue_getFront(&test), 5, "Enqueue");
    queue_enqueue(&test, 15);
	ASSERT_EQUAL_INT(queue_getFront(&test), 5, "Enqueue order");
    queue_dequeue(&test);
	ASSERT_EQUAL_INT(queue_getFront(&test), 15, "Dequeue");
	ASSERT_FALSE(queue_isFull(&test), "Is full");
    ASSERT_FALSE(queue_isEmpty(&test), "Is empty");
    queue_dequeue(&test);
    ASSERT_TRUE(queue_isEmpty(&test), "Is actually empty");
    queue_enqueue(&test, 1);
    queue_enqueue(&test, 2);
    queue_enqueue(&test, 3);
    ASSERT_EQUAL_INT(queue_getRear(&test), 3, "Get rear");
	printf("-------- End Queue Tests --------\n");
}