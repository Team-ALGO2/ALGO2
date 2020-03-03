// Basic Configurations


//NOTE: "(" and ")" are id's 16 and 17 respectivley


/*

=== PRE-DECLARE FUNCTIONS ===

*/
//Important Functions
int compare(long double a, long double b);
long double ldAbs(long double num);
long double ldFloor(long double num);
long double ldCeil(long double num);
long double ldRound(long double num);
int numLen(int num);
//Basic Math
long double add(long double a, long double b);
long double subtract(long double a, long double b);
long double multiply(long double a, long double b);
long double divide(long double a, long double b);
long double mod(long double a, long double b);
//Advanced Math
long double dmod(long double x, long double y);
long double factorial(long double b);
//Exponential Math
long double fastPower(long double a, long double b);
long double recPowrHelper(long double a, long double b, long double precision);
long double powr(long double a, long double b);
long double babylonianGuess(long double num);
long double squarert(long double b);
long double expFunc(long double x);
long double lnFunc(long double x);
//long double logn(long double n, long double r);
//Trigonometry Math
long double sine(long double a);
long double cosine(long double a);
long double tangent(long double a);
long double secant(long double a);
long double cosecant(long double a);
long double cotangent(long double a);
long double sineh(long double a);
long double cosineh(long double a);
//Combinatronics Math
long double aChooseB(long double n, long double k);
long double aPermB(long double n, long double r);

/*

=== IMPORTANT FUNCTIONS ===

*/

int compare(long double a, long double b)
{
  return ldAbs(a - b) < EPSILON;
}

long double ldAbs(long double num){
    if(num < 0){
        return -1 * num;
    }
    else{
        return num;
    }
}

long double ldFloor(long double num){
    if(num < 0){
        return -1 * ldCeil(-1 * num);
    }
    else{
        return (long double)(long long)num;
    }
}

long double ldCeil(long double num){
    if(num < 0){
        return -1 * ldFloor(-1 * num);
    }
    else{
        long double diff = num - ldFloor(num);
        //printf("%Lf - %Lf", num, diff);
        if(compare(diff, 0)){
            return num - diff;
        }
        else{
            return num - diff + 1;
        }
    }
}

long double ldRound(long double num){
    long double diff = num - ldFloor(num);
    #ifdef POINTFIVEROUNDOWN
    if(diff > 0.5){
    #endif
    #ifndef POINTFIVEROUNDOWN
    if(diff >= 0.5){
    #endif
        return ldCeil(num);
    }
    else{
        return ldFloor(num);
    }
}

//Takes in int because its impossible to calculate floats / LongFloats due to Floating Point Percision
int numLen(int num){
    if(numLen < 0){
        #ifdef NUMLENNEG
        return numLen(-1 * num) + 1;
        #endif
        #ifndef NUMLENNEG
        return numLen(-1 * num);
        #endif
    }
    else{  
        int totalDigits = 0;
        while (num != 0){
            num = num / 10;
            totalDigits++;
        }
        return totalDigits;
    }
}


/*

=== BASIC MATH ===

*/
    
// + id(0)
long double add(long double a, long double b)
{
    return a+b;
}

// - id(1)
long double subtract(long double a, long double b)
{
    return a-b;
}

// * id(2)
long double multiply(long double a, long double b)
{
    return a*b;
}

// / id(3)
long double divide(long double a, long double b)
{
    if(b == 0){
        //ERROR
        return 0;
    }
    return a/b;
}

// % id(4)
long double mod(long double a, long double b)
{
    a = ldAbs(a);
    b = ldAbs(b);
    return (long double)((long long)a%(long long)b);
}

/*

=== ADVANCED MATH ===

*/

// d% id(5)
long double dmod(long double x, long double y) {
    //x = ldAbs(x);
    //y = ldAbs(y);
    #ifdef ADVANCEDMODULO
    long double s1 = (x - (long long)(x/y) * y) + y;
    return s1 - (long long)(s1/y) * y;
    #endif
    #ifndef ADVANCEDMODULO
    return x - (long long)(x/y) * y;
    #endif
} //This is because normal mod "%" does not supoort doubles >:(

// ! id(8)
long double factorial(long double b){ // lmao l o n g l o n g <- its changed now, but im keeping the joke
    if(b < 0){
        return -1 * factorial(-1 * b);
    }
    else if(b == 1){
        return 1;
    }
    else{
        long long result = 1;
        for(int i = 0; i < b; i++){
            result = result * (b - i);
        }
        //printf("%lld\n", result);
        return (long double)result;
    }
}


/*

=== EXPONENTIAL MATH ===

*/

//Fast Power (Used for some calculations)
//Faster for high-intensity Taylor Series Calculations
//AlsoPrevents Recursions
//Increases Speed !!BY NOT SUPPORTING DECIMAL OR NEGATIVE EXPONENTS!!
long double fastPower(long double a, long double b){
    if(b > 0){
        long double result = 1;
        for(int i = 1; i <= b; i ++)
        {
        result = a*result;
        }
        return result;
    }
    else if (b == 0){
        return 1;
    }
    else if(b < 0){
        //CAUTION: may cause infinate recursion if I coded this badly
        return 1/fastPower(a, b*-1);    
    }
    else{
        //Give error? this is not sposed to happen
        return 0;
    }

}

long double recPowrHelper(long double base, long double power, long double precision ){   
    if (power < 0){
        return 1 / recPowrHelper(base, -power, precision);
    }
    else if (power >= 10){
        return fastPower(recPowrHelper( base, power/2, precision/2 ), 2);
    }
    else if (power >= 1){
        return base * recPowrHelper(base, power-1, precision);
    }
    else if (precision >= 1){
        return squarert(base);
    }
    else{
        return squarert(recPowrHelper(base, power*2, precision*2));
    }
}

// ^ id(6)
long double powr(long double a, long double b){
    
    if(b > 0){

        #if POWRMODE == 0
        long long result = 1;
        for(int i = 1; i <= b; i ++)
        {
        result = a*result;
        }
        return result;
        #elif POWRMODE == 1
        return recPowrHelper(a, b, EPSILON/100);
        #elif POWRMODE == 2
        return expFunc(b * lnFunc(a));
        #endif

    }
    else if (compare(b, 0)){
        return 1;
    }
    else if(b < 0){
        //CAUTION: may cause infinate recursion if I coded this badly
        return 1/powr(a, b*-1);    
    }
    else{
        //Give error? this is not sposed to happen
        return 0;
    }

}

//Uses prime guessing system
//to decrease number of calculations for square root
//Guessing Techneque by Rick Wicklin
//https://blogs.sas.com/content/iml/2016/05/16/babylonian-square-roots.html
//Transposed Into C
long double babylonianGuess(long double num){
    long double len = numLen((int)ldFloor(num));
    long double d = ldCeil(len/2);
    long double guess2 = 2*fastPower(10, d-1);
    long double guess7 = 7*fastPower(10, d-1);
    if (ldAbs(fastPower(guess2, 2) - num) < ldAbs(fastPower(guess7, 2) - num)){
        return guess2;
    }
    else{
        return guess7;
    }
}

// sqrt id(7)
long double squarert(long double b){
    //Babylonian's Formula For Square Root!
    if(b < 0){
        //ERROR
        return 0;
    }
    else{
        long double prev, sqrt;
        #ifdef SMARTBABYLONIANGUESS
        sqrt = babylonianGuess(b);
        #endif
        #ifndef SMARTBABYLONIANGUESS
        sqrt = b / 2;
        #endif
        prev = 0;
        //printf("%Lf, %Lf, %Lf\n", prev, sqrt, b);
        while(!compare(sqrt, prev)){ //Compare already takes EPSILON into account!
            prev = sqrt;
            sqrt = ( b/prev + prev) / 2;
            // Used for debugging, pls ignore
            //printf("%Lf, %Lf, %Lf\n", prev, sqrt, b);
        }
        return sqrt;
    }
}

/*
long double logn(long double n, long double r) { 
    if(n > r - 1){
        return 1 + logn(n / r, r);
    }
    else{
        return 0;
    }
}
*/

long double expFunc(long double x){
    long double total = 0;
    //printf("beg - %Lf\n", total);
    for(int i = 0; i < MAXTAYLORACCURACY*2; i++){
        //printf("%Lf, ", total);
        //printf("%Lf, ", fastPower(x, i));
        //printf("%Lf, ", factorial(i));
        //printf("%Lf\n", (fastPower(x, i) / factorial(i)));
        total = total + (fastPower(x, i) / factorial(i));
    }
    return total;
}

long double lnFunc(long double x){
    if(x > 2){ //lnFunc does not work for numbers over 2, so workaround required
        int extra = (int)x / 2;
        //printf("%d\n", extra);
        //Workaround for calculating numbers over 2
        //https://math.stackexchange.com/questions/3117459/natural-logarithm-approximation-of-numbers-greater-than-2-for-computers
        #ifdef CACHEDLNTWO
        return lnFunc(x / fastPower(2, extra)) + extra * LNTWO;
        #endif
        #ifndef CACHEDLNTWO
        return lnFunc(x / fastPower(2, extra)) + extra * lnFunc(2);
        return
        #endif
    }
    else if (x > 0){ //ln returns imaginary numbers ofr numbers less than 0
        long double total = 0;
        #ifdef SMARTLNAVG
        long double lastTotal = 0;
        #endif
        #if LNFUNCMODE == 0
        x = 1-x;
        for(int i = 1; i < MAXTAYLORACCURACY*2; i++){
            //printf("%Lf, ", total);
            //printf("%Lf, ", fastPower(x, i));
            //printf("%Lf\n", (fastPower(x, i) / i));
            lastTotal = total;
            total = total - (fastPower(x, i) / i);
        }
        #elif LNFUNCMODE == 1
        x = x-1;
        for(int i = 1; i < MAXTAYLORACCURACY*2; i++){
            //printf("%Lf, ", total);
            //printf("%Lf, ", fastPower(x, i));
            //printf("%Lf\n", (fastPower(x, i) / i));
            lastTotal = total;
            total = total + fastPower(-1, i+1)*(fastPower(x, i) / i);
        }
        #elif LNFUNCMODE == 2
        for(int i = 1; i < MAXTAYLORACCURACY*2; i++){
            //printf("%Lf, ", total);
            //printf("%Lf, ", fastPower(x, i));
            //printf("%Lf\n", (fastPower(-1, i+1)*(fastPower(x-1, i))) / x);
            lastTotal = total;
            total = total + (fastPower(-1, i+1)*(fastPower(x-1, i))) / i;
        }
        #endif
        #ifdef SMARTLNAVG
        return (total + lastTotal)/2;
        #endif
        return total;
    }
    else{
        //Give Error
        return 0;
    }
}


/*

=== TRIGONOMETRY MATH ===

*/

//Uses Taylor / Maclaurin series To Calculate Trig
//https://en.wikipedia.org/wiki/Taylor_series

//NOTE: Trig Math Is SUPER Inaccurate!!
//Only Accurate Up To 4 digits!!!

// sin id(9)
long double sine(long double a){
    a = dmod(a, 2 * PI); //Number Overflows If Too Big
    long double total = a;
    //printf("beg - %Lf\n", total);
    for(int i = 0; i < MAXTAYLORACCURACY; i++){
        long double powNum = i*2 + 3;
        total = total + fastPower(-1, i+1) * (fastPower(a, powNum)/factorial(powNum));
        //printf("neg - %Lf\n", total);
    }
    return total;
}

// cos id(10)
long double cosine(long double a){
    a = dmod(a, 2 * PI); //Number Overflows If Too Big
    long double total = 1;
    for(int i = 0; i < MAXTAYLORACCURACY; i++){
        long double powNum = i*2 + 2;
        total = total + fastPower(-1, i+1) * (fastPower(a, powNum)/factorial(powNum));
    }
    return total;
}

// tan id(11)
long double tangent(long double a){
    return sine(a) / cosine(a);
}

long double secant(long double a){
    return 1 / cosine(a);
}

long double cosecant(long double a){
    return 1 / sine(a);
}

long double cotangent(long double a){
    return cosine(a) / sine(a);
}

//Commented out because formula wrong
//TODO FIX
/*
// sineh id(12)
long double sineh(long double a){
    a = dmod(a, 2 * PI); //Number Overflows If Too Big
    long double total = a;
    for(int i = 0; i < MAXTAYLORACCURACY; i++){
        long double powNum = i*2 + 3;
        total = total + (fastPower(a, powNum)/factorial(powNum));
    }
    return total;
}

// cosineh id(13)
long double cosineh(long double a){
    a = dmod(a, 2 * PI); //Number Overflows If Too Big
    long double total = 1;
    for(int i = 0; i < MAXTAYLORACCURACY; i++){
        long double powNum = i*2 + 2;
        total = total + (fastPower(a, powNum)/factorial(powNum));
    }
    return total;
}
*/


/*

=== COMBINATRONICS MATH ===

*/

// aCb id(14)
long double aChooseB(long double n, long double k){
    if(n < 0 || k < 0){
        return 0;
    }
    else{
        #ifdef FASTCHOOSEPERM
        long long top = 1;
        long long bottom = 1;
        for (int x = 0; x < (n-k); x++){
            top = top * (n-x);
            bottom = bottom * (x+1);
        }
        return (long double)top/(long double)bottom;
        #endif
        #ifndef FASTCHOOSEPERM
        return (factorial(n))/(factorial(k)*factorial(n-k));
        #endif
    }
}

// aPb id(15)
long double aPermB(long double n, long double r){
    if(n < 0 || r < 0){
        return 0;
    }
    else{
        #ifdef FASTCHOOSEPERM
        long long result = 1;
        for (int x = 0; x < r; x++){
            result = result * (n-x);
        }
        return (long double)result;
        #endif

        #ifndef FASTCHOOSEPERM
        return (factorial(n))/factorial(n-r);
        #endif
    }
}