#include "main.h"


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

        // iterate over vertices 
        for (int j = 0; j < all_length; j++)
        {
            // find which ones leave from s
            if (ALL_vertice[j].from.name == s.name)
            {
                // if the weigth is smaller than the current disctance
                if (ALL_vertice[j].too.distance_to > ALL_vertice[j].weigth + s.distance_to)
                {
                    printf("\n%d\n", ALL_vertice[j].too.distance_to); //intial

                    ALL_vertice[j].too.distance_to = ALL_vertice[j].weigth;

                    printf("%d\n", ALL_vertice[j].too.distance_to); // after
                }
            }
        }

        printf("==================\n");




    

    }








}