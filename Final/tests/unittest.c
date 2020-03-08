#define TESTS
#include "../src/main.h"
#include "../../Server/main.c"
#define _DEFMAIN

int tests_ran = 0;
int tests_successful = 0;
int tests_failed = 0;

void log_test(int success);

void test_math();
void test_stack();
void test_queue();
void test_helpers();
void test_cache();
void test_calculator();

long double calculate(char exp[MAX_INPUT_LENGTH]);

void ASSERT_TRUE(long double expression, char* name)
{
    int success;
    if (expression)
    {
        printf("    -   %s  "GRN"\xE2\x9C\x94\n"RESET, name);
        success = 1;
    } else {
        printf("    -   %s  "RED"x\n"RESET, name);
        success = 0;
    }
    log_test(success);
}

void ASSERT_FALSE(long double expression, char* name)
{
    int success;
    if (!expression)
    {
        success = 1;
        printf("    -   %s  "GRN"\xE2\x9C\x94\n"RESET, name);
    } else {
        success = 0;
        printf("    -   %s  "RED"x\n"RESET, name);
    }
    log_test(success);
}

void ASSERT_EQUAL_INT(long double expr1, long double expr2, char* name)
{
    int success;
    if (compare(expr1, expr2))
    {
        success = 1;
        printf("    -   %s  "GRN"\xE2\x9C\x94\n"RESET, name);
    } else {
        success = 0;
        printf("    -   %s  "RED"x EXPECTED:%.20Lf GOT:%.20Lf\n"RESET, name, expr2, expr1);
    }
    log_test(success);
}

void ASSERT_EQUAL_STR(char* expr1, char* expr2, char* name)
{
    int success;
    if (expr1 == expr2)
    {
        success = 1;
        printf("    -   %s  "GRN"\xE2\x9C\x94\n"RESET, name);
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
    test_helpers();
    test_cache();
    test_calculator();

    /* End Tests */

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\n======================================\n");
    printf("Test successful: "GRN"%d"RESET"\n", tests_successful);
    printf("Test failed: "RED"%d"RESET"\n", tests_failed);
    printf("Ran %d tests in %lfs\n", tests_ran, time_spent);
    printf("======================================\n\n");
    return tests_failed;
}

void test_math()
{
	printf("\n---------- Math Tests ----------\n");
    //Comparison Code
	ASSERT_EQUAL_INT(compare(1, 2), false, "Compare False");
	ASSERT_EQUAL_INT(compare(2, 2), true, "Compare True");
	ASSERT_EQUAL_INT(compare(0.01, 0.02), false, "Compare False (LD)");
	ASSERT_EQUAL_INT(compare(0.02, 0.02), true, "Compare True (LD)");
	ASSERT_EQUAL_INT(compare(-1, 2), false, "Compare False (NEG)");
	ASSERT_EQUAL_INT(compare(-2, -2), true, "Compare True (NEG)");
	ASSERT_EQUAL_INT(compare(-0.01, -0.02), false, "Compare False (LD) (NEG)");
	ASSERT_EQUAL_INT(compare(-0.02, -0.02), true, "Compare True (LD) (NEG)");
    //Absolute Value
	ASSERT_EQUAL_INT(ldAbs(11), 11, "Absolute");
	ASSERT_EQUAL_INT(ldAbs(-11), 11, "Absolute (NEG)");
	ASSERT_EQUAL_INT(ldAbs(11.11), 11.11, "Absolute (LD)");
	ASSERT_EQUAL_INT(ldAbs(-11.11), 11.11, "Absolute (LD) (NEG)");
    //Addition
	ASSERT_EQUAL_INT(add(3, 5), 8, "Add");
	ASSERT_EQUAL_INT(add(0.1, 0.2), 0.3, "Add (LD)");
	ASSERT_EQUAL_INT(add(3, -5), -2, "Add (NEG)");
	ASSERT_EQUAL_INT(add(-0.1, -0.2), -0.3, "Add (LD) (DEG)");
    //Subtraction
	ASSERT_EQUAL_INT(subtract(5, 2), 3, "Substract");
	ASSERT_EQUAL_INT(subtract(0.3, 0.2), 0.1, "Substract (LD)");
	ASSERT_EQUAL_INT(subtract(-5, 3), -8, "Substract (NEG)");
	ASSERT_EQUAL_INT(subtract(-0.3, -0.2), -0.1, "Substract (LD) (NEG)");
    //Multiplication
	ASSERT_EQUAL_INT(multiply(6, 5), 30, "Multiply");
	ASSERT_EQUAL_INT(multiply(0.5, 0.5), 0.25, "Multiply (LD)");
	ASSERT_EQUAL_INT(multiply(6, -5), -30, "Multiply (NEG)");
	ASSERT_EQUAL_INT(multiply(0.5, -0.5), -0.25, "Multiply (LD) (NEG)");
    //Division
	ASSERT_EQUAL_INT(divide(10, 2), 5, "Divide");
	ASSERT_EQUAL_INT(divide(0.5, 0.2), 2.5, "Divide (LD)");
	ASSERT_EQUAL_INT(divide(10, -2), -5, "Divide (NEG)");
	ASSERT_EQUAL_INT(divide(0.5, -0.2), -2.5, "Divide (LD) (NEG)");
    //Modulo
	ASSERT_EQUAL_INT(dmod(5, 2), 1, "Modulo Operation");
	ASSERT_EQUAL_INT(dmod(0.9, 0.4), 0.1, "Modulo Operation (LD)");
	ASSERT_EQUAL_INT(dmod(13, -3), -2, "Modulo Operation (NEG)");
	ASSERT_EQUAL_INT(dmod(-0.9, 0.4), 0.3, "Modulo Operation (LD) (NEG)");
    //Factorial
	ASSERT_EQUAL_INT(factorial(4), 24, "Factorial");
	ASSERT_EQUAL_INT(factorial(-4), -24, "Factorial (NEG)");
    //Power
	ASSERT_EQUAL_INT(powr(5, 2), 25, "Power");
    ASSERT_EQUAL_INT(fastPower(5, 2), 25, "Fast Power");
	ASSERT_EQUAL_INT(powr(0.5, 0.5), 0.70710678118, "Power (LD)");
	ASSERT_EQUAL_INT(powr(5, -2), 0.04, "Power (NEG)");
	ASSERT_EQUAL_INT(powr(0.5, -0.5), 1.41421356237, "Power (LD) (NEG)");
    //Squareroot
	ASSERT_EQUAL_INT(squarert(81), 9, "Squareroot");
	ASSERT_EQUAL_INT(squarert(1.522756), 1.234, "Squareroot (LD)");
    //Logarithm
	//ASSERT_EQUAL_INT(logn(256, 3), 5, "Logarithm");
	//ASSERT_EQUAL_INT(logn(-256, 3), -5, "Logarithm (NEG)");
	//ASSERT_EQUAL_INT(logn(12.34, 5.1), 8.73141597305, "Logarithm (LD)");
	//ASSERT_EQUAL_INT(logn(-12.34, 5.1), -8.73141597305, "Logarithm (NEG) (LD)");
    //Exponential Function
	ASSERT_EQUAL_INT(expFunc(2), 7.38905609538413621351, "Exponential Function");
	ASSERT_EQUAL_INT(expFunc(-2), 0.13533528043580964062, "Exponential Function (NEG)");
	ASSERT_EQUAL_INT(expFunc(1.2), 3.32011692274, "Exponential Function (LD)");
	ASSERT_EQUAL_INT(expFunc(-1.2), 0.30119421191, "Exponential Function (NEG) (LD)");
    //Natural Logarithm
    ASSERT_EQUAL_INT(lnFunc(1.5), 0.40546473959254725195, "Natural Logarithm (LD SUB 2)");
	ASSERT_EQUAL_INT(lnFunc(3), 1.09861192015254727217, "Natural Logarithm");
	ASSERT_EQUAL_INT(lnFunc(4.5), 1.50407739677638274678, "Natural Logarithm (LD)");
    //Combinatronics
	ASSERT_EQUAL_INT(aChooseB(8, 5), 56, "Combinatronics");
	ASSERT_EQUAL_INT(aChooseB(8, -5), 0, "Combinatronics (NEG)");
    //Permutations
	ASSERT_EQUAL_INT(aPermB(8, 5), 6720, "Permutations");
	ASSERT_EQUAL_INT(aPermB(8, -5), 0, "Permutations (NEG)");
    //Rounding
	ASSERT_EQUAL_INT(ldFloor(9.999654345), 9, "Round Down");
	ASSERT_EQUAL_INT(ldFloor(-9.999654345), -10, "Round Down (NEG)");
	ASSERT_EQUAL_INT(ldFloor(9), 9, "Round Down (SAME)");
	ASSERT_EQUAL_INT(ldCeil(9.1), 10, "Round Up");
	ASSERT_EQUAL_INT(ldCeil(-9.1), -9, "Round Up (NEG)");
	ASSERT_EQUAL_INT(ldCeil(9), 9, "Round Up (SAME)");
	ASSERT_EQUAL_INT(ldRound(5.9), 6, "Round General (UP)");
	ASSERT_EQUAL_INT(ldRound(5.1), 5, "Round General (DOWN)");
	ASSERT_EQUAL_INT(ldRound(-5.9), -6, "Round General (UP) (NEG)");
	ASSERT_EQUAL_INT(ldRound(-5.1), -5, "Round General (DOWN) (NEG)");
    //NumLen
	ASSERT_EQUAL_INT((long double)numLen(123456789), 9, "Number Length");
	ASSERT_EQUAL_INT((long double)numLen(-123456789), 9, "Number Length (NEG)");
    //NOTE: Trig is only accurate up to 4 places!!
    //Sine
    ASSERT_EQUAL_INT(sine(10), -0.54402056886293170823, "Sine");
    ASSERT_EQUAL_INT(sine(-10), 0.54402111137642517047, "Sine (NEG)");
    ASSERT_EQUAL_INT(sine(7.5), 0.93799997677528901274, "Sine (LD)");
    ASSERT_EQUAL_INT(sine(-7.5), -0.93781024815856517396, "Sine (NEG) (LD)");
    //Cosine
    ASSERT_EQUAL_INT(cosine(10), -0.83906876766939819667, "Cosine");
    ASSERT_EQUAL_INT(cosine(-10), -0.83907152549440211509, "Cosine (NEG)");
    ASSERT_EQUAL_INT(cosine(7.5), 0.34663531783354295523, "Cosine (LD)");
    ASSERT_EQUAL_INT(cosine(-7.5), 0.34734244474843672945, "Cosine (NEG) (LD)");
    //Tangent
    ASSERT_EQUAL_INT(tangent(10), 0.64836231525338039461, "Tangent");
    ASSERT_EQUAL_INT(tangent(-10), -0.64836083080745021689, "Tangent (NEG)");
    ASSERT_EQUAL_INT(tangent(7.5), 2.70601386678585376089, "Tangent (LD)");
    ASSERT_EQUAL_INT(tangent(-7.5), -2.69995867863996741320, "Tangent (NEG) (LD)");
    //Secant
    ASSERT_EQUAL_INT(secant(10), -1.19179742892540896371, "Secant");
    ASSERT_EQUAL_INT(secant(-10), -1.19179351177573900067, "Secant (NEG)");
    ASSERT_EQUAL_INT(secant(7.5), 2.88487626203227209842, "Secant (LD)");
    ASSERT_EQUAL_INT(secant(-7.5), 2.87900317142136596971, "Secant (NEG) (LD)");
    //Cosecant
    ASSERT_EQUAL_INT(cosecant(10), -1.83816579231575749631, "Cosecant");
    ASSERT_EQUAL_INT(cosecant(-10), 1.83816395924398023887, "Cosecant (NEG)");
    ASSERT_EQUAL_INT(cosecant(7.5), 1.06609810741985122640, "Cosecant (LD)");
    ASSERT_EQUAL_INT(cosecant(-7.5), -1.06631378998421832982, "Cosecant (NEG) (LD)");
    //Cotangent
    ASSERT_EQUAL_INT(cotangent(10), 1.54234750613042570500, "Cotangent");
    ASSERT_EQUAL_INT(cotangent(-10), -1.54235103739167644932, "Cotangent (NEG)");
    ASSERT_EQUAL_INT(cotangent(7.5), 0.36954725630721874108, "Cotangent (LD)");
    ASSERT_EQUAL_INT(cotangent(-7.5), -0.37037603868208957003, "Cotangent (NEG) (LD)");
    /*
    //Hyperbolic Sin
    ASSERT_EQUAL_INT(sineh(10), 0, "Hyperbolic Sine");
    ASSERT_EQUAL_INT(sineh(-10), 0, "Hyperbolic Sine (NEG)");
    ASSERT_EQUAL_INT(sineh(7.5), 0, "Hyperbolic Sine (LD)");
    ASSERT_EQUAL_INT(sineh(7.5), 0, "Hyperbolic Sine (NEG) (LD)");
    //Hyperbolic Cosine
    ASSERT_EQUAL_INT(cosineh(10), 0, "Hyperbolic Cosine");
    ASSERT_EQUAL_INT(cosineh(-10), 0, "Hyperbolic Cosine (NEG)");
    ASSERT_EQUAL_INT(cosineh(7.5), 0, "Hyperbolic Cosine (LD)");
    ASSERT_EQUAL_INT(cosineh(7.5), 0, "Hyperbolic Cosine (NEG) (LD)");
	ASSERT_EQUAL_INT(sine(10), -0.54402112881732278549, "TEST");
    */
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
    queue test = {-1, -1, {0}}; //f
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

void test_helpers()
{
	printf("\n---------- Helpers Tests ----------\n");
	ASSERT_TRUE(isNum('6'), "Is number true");
    ASSERT_FALSE(isNum('a'), "Is number false");
    ASSERT_TRUE(isAlpha('a'), "Is alpha true");
    ASSERT_FALSE(isAlpha('!'), "Is alpha false");
    ASSERT_TRUE(isCapAlpha('A'), "Is cap alpha true");
    ASSERT_FALSE(isCapAlpha('a'), "Is cap alpha false");
    ASSERT_TRUE(isHex('A'), "Is hex true");
    ASSERT_FALSE(isHex('a'), "Is hex false");
    ASSERT_TRUE(isAlphanumerical('A'), "Is alphanumerical true (letter)");
    ASSERT_TRUE(isAlphanumerical('2'), "Is alphanumerical true (number)");
    ASSERT_FALSE(isAlphanumerical('['), "Is alphanumerical false");
	printf("-------- End Helpers Tests --------\n");
}

void test_cache()
{
	printf("\n---------- Cache Tests ----------\n");
	ASSERT_EQUAL_INT(cacheGET("str"), NEG_INFINITY, "Empty cache");
    ASSERT_EQUAL_INT(cacheSET("str", 1), 0, "Adding to cache");
    ASSERT_EQUAL_INT(cacheSET("str2", 2), 0, "Adding to cache twice");
    ASSERT_EQUAL_INT(cacheGET("str2"), 2, "Getting cache");
    ASSERT_EQUAL_INT(cacheSET("str", 3), 0, "Overwrite cache");
    ASSERT_EQUAL_INT(cacheGET("str"), 3, "Overwrite reading cache");
	printf("-------- End Cache Tests --------\n");
}

void test_calculator()
{
    printf("\n---------- Calculator Tests ----------\n");
    ASSERT_EQUAL_INT(calculate("7+2"), 9, "7+2 -- Addition");
    ASSERT_EQUAL_INT(calculate("7-2"), 5, "7-2 -- Subtraction");
    ASSERT_EQUAL_INT(calculate("6/2"), 3, "6/2 -- Division");
    ASSERT_EQUAL_INT(calculate("7*2"), 14, "7*2 -- Multiplication");
    ASSERT_EQUAL_INT(calculate("1+6/2"), 4, "1+6/2 -- PEDMAS");
    ASSERT_EQUAL_INT(calculate("(1+6)/2"), 3.5, "(1+6)/2 -- Parentheses");
    ASSERT_EQUAL_INT(calculate("4*7/2"), 14, "4*7/2 -- Order");
    ASSERT_EQUAL_INT(calculate("(1+2)*5"), 15, "(1+2)*5 -- Parentheses");
    ASSERT_EQUAL_INT(calculate("3^2"), 9, "3^2 -- Exponents");
   //  ASSERT_EQUAL_INT(calculate("1*17^2+3"), 292, "1*17^2+3 -- PEDMAS"); // Interresting bug where teh value GOT depeends on the definiton of E
    ASSERT_EQUAL_INT(calculate("5+(7/2)"), 8.5, "5+(7/2) -- Decimals");
    ASSERT_EQUAL_INT(calculate("5-7*2"), -9, "5-7*2 -- Negative");
    printf("-------- End Calculator Tests --------\n");
}
