#include "../src/main.h"

int tests_ran = 0;
int tests_successful = 0;
int tests_failed = 0;

void log_test(int success);

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
    ASSERT_TRUE(true, "Make sure 1 is true");
    ASSERT_FALSE(false, "Make sure 0 is false");
    ASSERT_EQUAL_INT(5, 5, "5 is equal to 5");
    ASSERT_EQUAL_STR("Hello", "Hello", "hello is the same");
    /* End Tests */

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\n======================================\n");
    printf("Test successful: "GRN"%d"RESET"\n", tests_successful);
    printf("Test failed: "RED"%d"RESET"\n", tests_failed);
    printf("Ran %d tests in %lfs\n", tests_ran, time_spent);
    printf("======================================\n\n");

}
