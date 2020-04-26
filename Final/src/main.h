/**
 * @file src/main.h
 * @brief Main header file for the project
 * 
 * This file contains all of the settings for the project
 * including debugs, math implementations ... 
 */


//Defining _MAINGUARD
//C Does Not Like When Headers Are Called Twice (Also Self Refrencing). 
//Mainguard Checks If main.h Has Already Been Defined, 
//And Prevents Redefinitions If It Occurs
#ifndef _MAINGUARD
#define _MAINGUARD

// Define Debug (Comment Out To Disable Debug Mode)
#define DEBUG //Checking Definitions Instead Of Variables Because ifdef Removes Debug Code In Compilation!

#ifdef TESTS         // If this run by unittest, remove debug messages
    #undef DEBUG
#endif


/*
 * Definition of math related macros
 */
//#define NUMLENNEG //Count the '-' symbol in numLen 
//#define POINTFIVEROUNDOWN //In some odd cases while rounding floating point, 0.5 rounds down to 0 (instead of 1). Turn this on to enable that feature!
#define MAXTAYLORACCURACY 8 ///< Defines Maximum Accuracy / Maximum Amount Of Cycles For Talor Series Calculations (Trig, Log, Exponent, Etc.) Set to prevent overflows
#define POWRMODE 1 ///< Sets formula used for exponential calculations. See Bottom For Options
#define ADVANCEDMODULO ///< Adds extra check to implement Python-style modulo operations with negative numbers. Keep off for original c-like implementation
#define LNFUNCMODE 2 ///< Sets formula used for natural logarithm. See Bottom For Options
#define SMARTLNAVG ///< Averages the last two natural logarithm estimation results to create a (semi) close guess. Not mathmatically sound, but it works.
#define CACHEDLNTWO ///< Uses Pre-calculated LN2 instead of caluclating it live. Increases speed and "accuracy"
//#define ADVANCEDTRIGFORMULA //Uses advanced Taylor/Maclaurin Series Formuals Instead of Shortcut *
//#define SYSTEMMATH //(Used For Debugging) Uses System Functions Instead Of Self-Made Functions *

#define RECURSIVECONVERT ///< Uses recursive techneques to convert bases *
#define FASTCHOOSEPERM ///< Uses optimitation techneques to create faster and more accurate combinatronics and permutations calculations
#define SMARTBABYLONIANGUESS ///< Uses interesting formulas to increate accuracy of initial initial square root guess
//#define FORCEHIGHBASE //Bypasses The 36 Digit Max *
//#define FULLTEXTVARIABLES //Allows Experimental Multi-Letter Variables *
#define LOOKAHEADMODE 2 ///< Sets Look Ahead Priority. See Bottom For Options

//Different Modes For Different Configs
/*
== LOOKAHEADMODE ==
0: First come first serve, chooses first word that matches KeyList.
1: Lowest length priority, chooses word that has the least matching characters.
2: Highest length Priority, chooses word that has the most matching characters. (Recommended)
*/
/*
== POWRMODE ==
0: Inaccurate And Old (But Fast) Power Calculation Meathod. Only Supports Integer Exponents. Still Used In fastPower 
1: Recursive Meathod. Matmatically Less Accurate, But Good Complexity/Speed To Percision. (Recommended)
2: Mathmatical Meathod. Uses Exponential Identities. Inaccurate Due To Implementation Limitations, But Most Mathmatically (Formula Wise) Accutate!
*/
/*
== LNFUNCMODE ==
0: Uses Formula Derived From (1-X)
1: Uses Formula Derived From (1+X)
2: Uses Adaptiton Formula Derived From X. (Recomended)
*/

//
//
//

/* Sets Floating Point Epsilon (AKA decimal accuracy of numbers)
 * https://en.wikipedia.org/wiki/Machine_epsilon
 *Currently set to 1 * 10 ^ -12
 */
#define EPSILON 0.0000000001l ///< Sets Floating Point Epsilon (AKA decimal accuracy of numbers). See https://en.wikipedia.org/wiki/Machine_epsilon
//#define EPSILON 0.0001l

//Math Numbers
#define PI 3.141592653589l 
#define EULER 2.718281828459045l
#define LNTWO 0.69314718056l

// cache.c
#define MAX_VARIABLE_NUMBER 25 ///< Max number of variables user is allowed 
#define MAX_VARIABLE_LENGTH 10 ///< Max length of var name

// parsing.c
#define MAXCOMMANDLEN 32  ///< Max length of a command
#define MAXCOMMANDARGUMENTLEN 32 ///< Max len for an argument


// Define Booleans
#define false 0
#define true 1
#define False 0
#define True 1
#define FALSE 0
#define TRUE 1

// Set Colours
#define RED   "\x1B[31m"  ///< ANSI code for red
#define GRN   "\x1B[32m"  ///< ANSI code for green
#define YEL   "\x1B[33m"  ///< ANSI code for yellow
#define BLU   "\x1B[34m"  ///< ANSI code for blue
#define MAG   "\x1B[35m"  ///< ANSI code for magenta
#define CYN   "\x1B[36m"  ///< ANSI code for cyan
#define WHT   "\x1B[37m"  ///< ANSI code for white
#define RESET "\x1B[0m"  ///< ANSI code for resetting

// Min/Max Functions
#define MAX(x, y) (((x) > (y)) ? (x) : (y)) ///< returns max
#define MIN(x, y) (((x) < (y)) ? (x) : (y)) ///< returns min

//Array Size Functions
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0])) ///< returns the size of an array

// Numbers
#define INFINITY 2147483647
#define NEG_INFINITY -2147483647

// settings
#define MAX_INPUT_LENGTH 4096   ///< Max length of an expression


// STACK
//defines the max length of the stack
#define STACK_MAX_LENGTH 128  ///< Max length of a stack

// Define Error Codes
#define STACK_EMPTY   0 ///< WIP
#define STACK_FULL    0 ///< WIP


// QUEUE
//defines the max length of the queue
#define QUEUE_MAX_LENGTH 128 ///< Max length of a queue

// Define Error Codes
#define QUEUE_EMPTY   0 ///< WIP
#define QUEUE_FULL    0 ///< WIP

// Operator Data System Flags
#define ODS_OPERAND 0  ///< ??
#define ODS_OPERATOR 1 ///< ??

// For Server/main.c    
#define MAX_FILE_LEN 255000  ///< Max file length in chars
#define MAX_FILE_NAME_LEN 100  ///<  Max filename length

// Import Important Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

// Import Utils
#include "utils/math.c"
#include "utils/stack.c"
#include "utils/queue.c"
#include "utils/helpers.c"
#include "utils/convert.c"
#include "utils/cache.c"
#include "utils/opDataSystem.c"

// Import Calculator Modules
#ifndef _DISABLECALC ///< Checks For Special Flag To Disable Calculator Import If Not Needed

#include "calc/init.c"
#include "calc/error.c"
#include "calc/parsing.c"
#include "calc/infixtopostfix.c"
#include "calc/eval.c"
#include "calc/calc.c"

#endif

/* Clear command
 * Windows: cls
 * Everything else: clear
 */ 

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

//Define Main Flag
//Makes sure main() only gets defined once!
//Defined AFTER all other modules gets included!
//This way only the main file after main.h gets included gets compiled
//(Aka no main files of modules gets compiled)
#define _DEFMAIN 



// Import Graphics
// TODO - Add when done
// #include "utils/graphics.c"

#endif // _MAINGUARD

//ignore this