#include "src/main.h"

#define INFINITY 2147483647


typedef struct{
    int name;
    int distance_to;
} node;

typedef struct{
    node from;
    node too;
    int weigth;
} vertice;


int main(void)
{

    /* Create "graph" */

    node A = {1, 0};
    node B = {2, INFINITY};
    node C = {3, INFINITY};
    node D = {4, INFINITY};

    vertice one = {A, B, 10};
    vertice two = {A, C, 10};
    vertice three = {B, C, 10};
    vertice four = {B, D, 10};
    vertice five = {C, D, 10};

    vertice ALL_vertice[] = {one, two, three, four, five};

    int all_length = 5;


    node s = A;

    for (int i = 1; i < all_length; i++)
    {
        node from = s;
        node too = ALL_vertice[i].too;

        // itearte over verices to find mathcing weitgh

        for (j = 0; j < all_length; j++)
        {
            if (ALL_vertice[j]. == )
        }




    

    }








}