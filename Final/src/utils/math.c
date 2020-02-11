// Basic Configurations
#define TRIGACCURACY 9
// DO NOT CHANGE: The factorial will overflow, causing everything to go wack

// wonky PI definitions (d at the end makes it a double instead of flaot)
#define PI 3.141592653589

//NOTE: "(" and ")" are id's 16 and 17 respectivley

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
    return a/b;
}

// % id(4)
long long mod(long long a, long long b)
{
    return a%b;
}

/*

=== ADVANCED MATH ===

*/

// d% id(5)
long double dmod(long double x, long double y) {
    return x - (long long)(x/y) * y;
} //This is because normal mod "%" does not supoort doubles >:(

// ^ id(6)
long double powr(long double a, long double b){
  long double result = 1;
  for(int i = 1; i <= b; i ++)
  {
   result = a*result;
  }


  return result;

}

// sqrt id(7)
long double squarert(long double b){
    long double temp, sqrt;
    sqrt = b / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;


        sqrt = ( b/temp + temp) / 2;
    }
   return sqrt;
}

// ! id(8)
long double factorial(long double b){ // lmao l o n g l o n g <- its changed now, but im keeping the joke
    long double result = 1;
    for(int i = 0; i < b; i++){
        result = result * (b - i);
    }
    return result;
}

/*

=== TRIGONOMETRY MATH ===

*/

// sin id(9)
long double sine(long double a){
    a = dmod(a, PI); //Number Overflows If Too Big
    long double total = a;
    for(int i = 0; i < TRIGACCURACY; i++){
        long double powNum = i*2 + 3;
        if(i%2 == 0){
            total = total - (powr(a, powNum)/factorial(powNum));
        }
        else if(i%2 == 1){
            total = total + (powr(a, powNum)/factorial(powNum));
        }
    }
    return total;
}

// cos id(10)
long double cosine(long double a){
    a = dmod(a, PI); //Number Overflows If Too Big
    long double total = 1;
    for(int i = 0; i < TRIGACCURACY; i++){
        long double powNum = i*2 + 2;
        if(i%2 == 0){
            total = total - (powr(a, powNum)/factorial(powNum));
        }
        else if(i%2 == 1){
            total = total + (powr(a, powNum)/factorial(powNum));
        }
    }
    return total;
}

// tan id(11)
long double tangent(long double a){
    return sine(a) / cosine(a);
}

// sineh id(12)
long double sineh(long double a){
    a = dmod(a, PI); //Number Overflows If Too Big
    long double total = a;
    for(int i = 0; i < TRIGACCURACY; i++){
        long double powNum = i*2 + 3;
        total = total + (powr(a, powNum)/factorial(powNum));
    }
    return total;
}

// cosineh id(13)
long double cosineh(long double a){
    a = dmod(a, PI); //Number Overflows If Too Big
    long double total = 1;
    for(int i = 0; i < TRIGACCURACY; i++){
        long double powNum = i*2 + 2;
        total = total + (powr(a, powNum)/factorial(powNum));
    }
    return total;
}


/*

=== COMBINATRONICS MATH ===

*/

// aCb id(14)
long double aChooseB(long double n, long double k){
    #ifdef FASTCHOOSEPERM
    #endif
    long double top = 1;
    long double bottom = 1;
    for (int x = 0; x < (n-k); x++){
        top = top * (n-x);
        bottom = bottom * (x+1);
    }
    return top/bottom;
    #ifndef FASTCHOOSEPERM
    return (factorial(n))/(factorial(k)*factorial(n-k));
    #endif
}

// aPb id(15)
long double aPermB(long double n, long double r){

    #ifdef FASTCHOOSEPERM
    long double result = 1;
    for (int x = 0; x < r; x++){
        result = result * (n-x);
    }
    return result;
    #endif

    #ifndef FASTCHOOSEPERM
    return (factorial(n))/factorial(n-r);
    #endif
}