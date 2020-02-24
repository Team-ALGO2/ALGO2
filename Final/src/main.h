//Defining _MAINGUARD
//C Does Not Like When Headers Are Called Twice (Also Self Refrencing). 
//Mainguard Checks If main.h Has Already Been Defined, 
//And Prevents Redefinitions If It Occurs
#ifndef _MAINGUARD
#define _MAINGUARD

// Define Debug (Comment Out To Disable Debug Mode)
#define DEBUG //Checking Definitions Instead Of Variables Because ifdef Removes Debug Code In Compilation!

// Define Calculator Configuration Flags
#define RECURSIVECONVERT //Uses recursive techneques to convert bases *
#define FASTCHOOSEPERM //Uses optimitation techneques to create faster and more accurate combinatronics and permutations calculations
#define SYSTEMMATH //(Used For Debugging) Uses System Functions Instead Of Self-Made Functions *
#define FORCEHIGHBASE //Bypasses The 36 Digit Max *
#define FULLTEXTVARIABLES //Allows Experimental Multi-Letter Variables *
#define LOOKAHEADMODE 2 //(!do not comment out!) Sets Look Ahead Priority (0: First come first serve, chooses first word that matches definition | 1: Lowest length priority | 2: Highest length Priority)

// cache.c
#define MAX_VARIABLE_NUMBER 25 // Max number of variables user is allowed 
#define MAX_VARIABLE_LENGTH 10 // Max length of var name

// input.c
#define MAXCOMMANDLEN 32
#define MAXCOMMANDARGUMENTLEN 32


// Define Booleans
#define false 0
#define true 1
#define False 0
#define True 1
#define FALSE 0
#define TRUE 1

// Set Colours
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// Min/Max Functions
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

//Array Size Functions
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))

// Numbers
#define INFINITY 2147483647
#define NEG_INFINITY -2147483647

// settings
#define MAX_INPUT_LENGTH 4096


// STACK
//defines the max length of the stack
#define STACK_MAX_LENGTH 128

// Define Error Codes
#define STACK_EMPTY   0
#define STACK_FULL    0


// QUEUE
//defines the max length of the queue
#define QUEUE_MAX_LENGTH 128

// Define Error Codes
#define QUEUE_EMPTY   0
#define QUEUE_FULL    0


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

// Import Calculator Modules
#ifndef _DISABLECALC // Checks For Special Flag To Disable Calculator Import If Not Needed

#include "calc/init.c"
#include "calc/error.c"
#include "calc/input.c"
#include "calc/infixtopostfix.c"
#include "calc/eval.c"

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