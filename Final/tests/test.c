#include "../src/main.h"

int tests_ran = 0;
int tests_successful = 0;
int tests_failed = 0;

void log_test(int success);
void test_math();

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
	printf("---------- Math Tests ----------\n");
	ASSERT_EQUAL_INT(add(3, 5), 8, "Add");
	ASSERT_EQUAL_INT(subtract(5, 2), 3, "Substract");
	ASSERT_EQUAL_INT(multiply(6, 5), 30, "Multiply");
	ASSERT_EQUAL_INT(divide(10, 2), 5, "Divide");
	ASSERT_EQUAL_INT(mod(5, 2), 1, "Mod");
	ASSERT_EQUAL_INT(powr(5, 2), 25, "Exponent");
	ASSERT_EQUAL_INT(squarert(81), 9, "Squareroot");
	ASSERT_EQUAL_INT(factorial(4), 24, "Factorial");
	printf("-------- End Math Tests --------");
}