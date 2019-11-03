#include "utils.h"

// For Global Defines, Use Utils. For Local, Use Here.

// basic defines
#define SIZE  12
#define WIDE  6
#define DEBUG 1

// some sleep thing i edited lol
int msleep(long msec)
{
    struct timespec ts;
    int res;
    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;
    res = nanosleep(&ts, &ts);
    return res;
}

int main(void)
{
    //Define CONSTANT rotation times
    // Not using #define becasue it gets a new number every thime i referece it
    int rotationtimes = (rand() % 30) + 3;
    
    // Slot Characters And Colors
    char *slotCharacters[10] = {"$", "X", "#", "O", "?", "=", ">", "7", ".", "9"};
    char *slotColours[10] = {"\x001b[43m\x001b[30m", "\x1B[31m", "\x1B[34m", "\x1B[36m\x1B[35m", "\x001b[46m", "\x001b[47m\x001b[37;1m", "\x1B[35m", "\x1B[32m", "\x1B[33m", "\x1B[37m"};

    // create number list
    int slotMap[WIDE][SIZE];

    // create time var
    time_t t;

    // rolled values
    int rolledValues[WIDE];

    // roll delay
    //TODO: FINISH
    int rollIteration[WIDE];

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
        rollIteration[r] = (rand() % 2) + 1;
    }

    // clear screen
    system("clear");

    // create a random starting point for iteration
    int j = rand() % SIZE;

    // number of times to rotate
    for (int k = 0; k < rotationtimes; k ++)
    {

        // Calculate Rotation Speed
        float rotateSpeed = (long)(((float)k/(float)rotationtimes)* 1000);
        // wait/clear
        msleep(rotateSpeed);
        system("clear");
        if(DEBUG){
            printf("~~DEBUG~~ \nNumber Index: %d\nTimes Updated:%d\nTotal Updates:%d\nRotation Speed:%lf\n\n\n", j, k, rotationtimes, rotateSpeed);
        }

        // print full array starting at index j
        for (int i = 0; i < SIZE; i++)
        {

            if (i == SIZE/2)  // if i is in middle print in RED
            {
                //Prints out lines
                for (int e = 0; e < WIDE*2-1; e++){printf("=");}
                printf("\n" CYN);
                for (int v = 0; v < WIDE; v++){
                    //printf("%d ", slotMap[v][j]);
                    printf("%s%s%s ", slotColours[slotMap[v][j]], slotCharacters[slotMap[v][j]], "\x001b[0m");
                    rolledValues[v] = slotMap[v][j];
                }
                printf("\n" RESET);
                //Prints out lines
                for (int e = 0; e < WIDE*2-1; e++){printf("=");}
                printf("\n");

                //one = first[j];
                //two = second[j];
                //three = third[j];
            }
            /*
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
            */

           //IDK WHAT THIS DOES ^^^

            else // hide the other numbers
            {
                for (int v = 0; v < WIDE; v++){
                    printf("%s%s%s ", slotColours[slotMap[v][j]], slotCharacters[slotMap[v][j]], "\x001b[0m");
                }
                printf("\n");
            }


            // j goes up for iteration
            j++;
            j = j % SIZE;
        }


        // starting point -= 1
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
