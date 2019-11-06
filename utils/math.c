// wonky PI definitions (d at the end makes it a double instead of flaot)
#define PI 3.141592653589d

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
double sqrt(double a, double b)
{
    sqrt = a / 2;
    temp = 0;
    while(sqrt != temp){
        temp = sqrt;


        sqrt = ( number/temp + temp) / 2;
    }
    printf("%f", sqrt);
}
//int main(){}
