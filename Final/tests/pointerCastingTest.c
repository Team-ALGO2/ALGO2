#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int a;
    char b[20];
} wasd;

int main()
{
    wasd* aaa = (wasd*)malloc(sizeof(wasd));
    aaa->a = 1234;
    strcpy(aaa->b, "lolok");
    printf("%d, %s\n", aaa->a, aaa->b);
    
    int* test = (int*)aaa;
    printf("%d\n", *test);
    *test = 4321;
    printf("%d\n", *test);
    
    //aaa = (wasd*)test;
    
    printf("%d, %s\n", aaa->a, aaa->b);

    return 0;
}
