
// wonky PI definitions (d at the end makes it a double instead of flaot)
#define PI 3.141592653589

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
