#include "main.h"


typedef struct{
    int name;
    int distance_to;
} node;

typedef struct{
    node from;
    node to;
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

    node ALL_node[] = {A, B, C, D};
    int node_length = 4;

    

    node s = A;
    // for all the nodes do
    for (int i = 0; i < node_length; i++)
    {
        s = ALL_node[i];

        // iterate over all vertices 
        for (int j = 0; j < all_length; j++)
        {
            node cur = ALL_vertice[j].from;
            // find which ones leave from cur
            if (cur.name == s.name)
            {
                // if the weigth is smaller than the current disctance
                if (ALL_vertice[j].too.distance_to > ALL_vertice[j].weigth + ALL_vertice[j].from.distance_to)
                {

                    printf("From: %d -- To: %d: ", ALL_vertice[j].from.name, ALL_vertice[j].too.name);
                    printf("ALL_vertice[j].from.distance_to = %d, ALL_vertice[j].from = %d\n", ALL_vertice[j].from.distance_to, ALL_vertice[j].from.name);
                    printf("%d --> ",ALL_vertice[j].too.distance_to);
                    
                    ALL_vertice[j].too.distance_to = ALL_vertice[j].weigth + ALL_vertice[j].from.distance_to;
                    printf("%d \n",ALL_vertice[j].too.distance_to);
                    printf("==================\n");

                }
            }
        }

        printf("~~~~~~~~~~~~~~~~~~~~~~~\n");



    }


}
