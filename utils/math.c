
// Basic Configurations
#define TRIGACCURACY 9
// DO NOT CHANGE: The factorial will overflow, causing everything to go wack

// wonky PI definitions (d at the end makes it a double instead of flaot)
#define PI 3.141592653589

/*

=== BASIC MATH ===

*/

double add(double a, double b)
{
    return a+b;
}

double subtract(double a, double b)
{
    return a-b;
}

double multiply(double a, double b)
{
    return a*b;
}

double divide(double a, double b)
{
    return a/b;
}

long mod(long a, long b)
{
    return a%b;
}

/*

=== ADVANCED MATH ===

*/

double powr(double a, double b){
  double result = 1;
  for(int i = 1; i <= b; i ++)
  {
   result = a*result;
  }


  return result;

}

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

double sine(double a){
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

double cosine(double a){
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

double tangent(double a){
    return sine(a) / cosine(a);
}

double sineh(double a){
    double total = a;
    for(int i = 0; i < TRIGACCURACY; i++){
        double powNum = i*2 + 3;
        total = total + (powr(a, powNum)/factorial(powNum));
    }
    return total;
}

double cosineh(double a){
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

long aChooseB(long n, long k){
    return (factorial(n))/(factorial(k)*factorial(n-k));
}

long aPermB(long n, long r){
    return (factorial(n))/factorial(n-r);
}

