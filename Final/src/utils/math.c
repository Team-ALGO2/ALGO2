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
double add(double a, double b)
{
    return a+b;
}

// - id(1)
double subtract(double a, double b)
{
    return a-b;
}

// * id(2)
double multiply(double a, double b)
{
    return a*b;
}

// / id(3)
double divide(double a, double b)
{
    return a/b;
}

// % id(4)
long mod(long a, long b)
{
    return a%b;
}

/*

=== ADVANCED MATH ===

*/

// d% id(5)
double dmod(double x, double y) {
    return x - (int)(x/y) * y;
} //This is because normal mod "%" does not supoort doubles >:(

// ^ id(6)
double powr(double a, double b){
  double result = 1;
  for(int i = 1; i <= b; i ++)
  {
   result = a*result;
  }


  return result;

}

// sqrt id(7)
double squarert( double b){
    float temp, sqrt;
    sqrt = b / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;


        sqrt = ( b/temp + temp) / 2;
    }
   return b;
}

// ! id(8)
long long factorial(int b){ // lmao l o n g l o n g
    long long result = 1;
    for(int i = 0; i < b; i++){
        result = result * (b - i);
    }
    return result;
}

/*

=== TRIGONOMETRY MATH ===

*/

// sin id(9)
double sine(double a){
    a = dmod(a, PI); //Number Overflows If Too Big
    double total = a;
    for(int i = 0; i < TRIGACCURACY; i++){
        double powNum = i*2 + 3;
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
double cosine(double a){
    a = dmod(a, PI); //Number Overflows If Too Big
    double total = 1;
    for(int i = 0; i < TRIGACCURACY; i++){
        double powNum = i*2 + 2;
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
double tangent(double a){
    return sine(a) / cosine(a);
}

// sineh id(12)
double sineh(double a){
    a = dmod(a, PI); //Number Overflows If Too Big
    double total = a;
    for(int i = 0; i < TRIGACCURACY; i++){
        double powNum = i*2 + 3;
        total = total + (powr(a, powNum)/factorial(powNum));
    }
    return total;
}

// cosineh id(13)
double cosineh(double a){
    a = dmod(a, PI); //Number Overflows If Too Big
    double total = 1;
    for(int i = 0; i < TRIGACCURACY; i++){
        double powNum = i*2 + 2;
        total = total + (powr(a, powNum)/factorial(powNum));
    }
    return total;
}


/*

=== COMBINATRONICS MATH ===

*/

// aCb id(14)
long aChooseB(long n, long k){
    return (factorial(n))/(factorial(k)*factorial(n-k));
}

// aPb id(15)
long aPermB(long n, long r){
    return (factorial(n))/factorial(n-r);
}

