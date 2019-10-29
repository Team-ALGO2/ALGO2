#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


int main(void)
{
    // create list
    int first[10];
    int second[10];
    int third[10];
    time_t t;

    int one, two, three;

    // init rand
    srand((unsigned) time(&t));

    // create array of rands
    for (int i = 0; i < 10; i++)
    {
        first[i] = rand() % 10;
        second[i] = rand() % 10;
        third[i] = rand() % 10;
    }

    // clear screen
    system("clear");

    // create a random starting point for iteration
    int j = rand() % 10;

    // number of times to rotate
    for (int k = 0; k < 10; k ++)
    {
        // wait/clear
        sleep(1);
        system("clear");


        // print full array starting at index j
        for (int i = 0; i < 10; i++)
        {


            if (i == 5)  // if i is in middle print in RED
            {
                printf(CYN "%d ", first[j]);
                printf("%d ", second[j]);
                printf("%d\n" RESET, third[j]);

                one = first[j];
                two = second[j];
                three = third[j];
            }
            else if (i == 4 || i == 6) // if i is directly beside index 5, print them
            {
                printf("%d ", first[j]);
                printf("%d ", second[j]);
                printf("%d\n", third[j]);
            }
            else                        // hide the other numbers
            {
                printf(WHT "%d ", first[j]);
                printf("%d ", second[j]);
                printf("%d\n" RESET, third[j]);
            }


            // j goes up for iteration
            j++;
            j = j % 10;
        }


        // starting point += 1
        j++;
        j = j % 10;
    }

    system("clear");

    // end
    for (int l = 0; l < 10; l++)
    {
        printf(RED "%d %d %d" RESET, one, two, three);
        sleep(1);

        system("clear");

        printf(GRN "%d %d %d" RESET, one, two, three);
        sleep(1);

        system("clear");
    }


    return 0;
}