#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

// colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// basic defines
#define SIZE  12
#define WIDE  6
#define ROTATIONTIMES rand() % 30 + 3

// define booleans
#define false 0
#define true 1


int main(void)
{
    // create number list
    int slotMap[WIDE][SIZE];

    // create time var
    time_t t;

    // rolled values
    int rolledValues[WIDE];

    // roll delay
    //TODO: FINISH
    int rollDelay[WIDE];

    // is stop
    int isStop = false;


    // init rand
    srand((unsigned) time(&t));


    // create array of rands
    for (int x = 0; x < WIDE; x++){
        for (int i = 0; i < SIZE; i++){
            slotMap[x][i] = rand() % 10;
        }
    }


    // Set Default Rolled Values
    // Idk how to set values to "NULL", so im just gonna use 1t as it sould never be above 10 lmao
    for (int n = 0; n < WIDE; n++){
        rolledValues[n] = 15;
    }

    // Set Random Roll Delay
    for (int r = 0; r < WIDE; r++){
        rollDelay[r] = (rand() % 3) + 1;
    }

    // clear screen
    system("clear");

    // create a random starting point for iteration
    int j = rand() % SIZE;

    // number of times to rotate
    for (int k = 0; k < ROTATIONTIMES; k ++)
    {

        // wait/clear
        sleep(1);
        system("clear");


        // print full array starting at index j
        for (int i = 0; i < SIZE; i++)
        {


            if (i == SIZE/2)  // if i is in middle print in RED
            {
                for (int e = 0; e < WIDE*2-1; e++){printf("=");}
                printf("\n" CYN);
                for (int v = 0; v < WIDE; v++){
                    printf("%d ", slotMap[v][j]);
                    rolledValues[v] = slotMap[v][j];
                }
                printf("\n" RESET);
                for (int e = 0; e < WIDE*2-1; e++){printf("=");}
                printf("\n");

                //one = first[j];
                //two = second[j];
                //three = third[j];
            }
            else if (i == SIZE/2 - 1 || i == SIZE/2 + 1) // if i is directly beside index 5, print them
            {

                //printf("%d ", first[j]);
                //printf("%d ", second[j]);
                //printf("%d\n", third[j]);
                for (int v = 0; v < WIDE; v++){
                    printf("%d ", slotMap[v][j]);
                }
                printf("\n");
            }
            else // hide the other numbers
            {
                printf(WHT);
                for (int v = 0; v < WIDE; v++){
                    printf("%d ", slotMap[v][j]);
                }
                printf("\n" RESET);
            }


            // j goes up for iteration
            j++;
            j = j % SIZE;
        }


        // starting point += 1
        j--;
        if(j < 0){j=SIZE-1;}
    }

    //system("clear");

    // end

    /*
    for (int l= 0; l < 10; l++)
    {
        printf(RED "%d %d %d" RESET, one, two, three);
        printf("\n");
        sleep(1);
        system("clear");
        printf(GRN "%d %d %d" RESET, one, two, three);
        printf("\n");
        sleep(1);
        system("clear");
    }
    */

   //TEMPORARY PRINT AND THE ONE ABOVE IS BROKNE

   double end = 0;

    printf("\n\n\n");
    for(int p = 0; p < WIDE; p++)
    {
        printf("%d ", rolledValues[p]);

        end = end + (rolledValues[p] * pow(10, SIZE + 1 - p));
    }

    end = end / 100000000;

   printf("\n %f \n", end);


    return 0;
}
