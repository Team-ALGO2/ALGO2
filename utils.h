#ifndef _DEFGUARD
#define _DEFGUARD

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <string.h>

// colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// basic defines
#define SIZE  12
#define WIDE  6
#define DEBUG 1

// define booleans
#define false 0
#define true 1

// min max functions
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// wonky PI definitions
#define PI 3.141592653589

#endif // _DEFGUARD