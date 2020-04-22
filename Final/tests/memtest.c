#include <stdio.h>

int main()
{
    long double x[50000];
    
    x[49998] = 12345.67879; 

    for(int i = 0; i < 50000; i++){
        printf("%d, %Lf\n", i, x[i]);
    }

    return 0;
}