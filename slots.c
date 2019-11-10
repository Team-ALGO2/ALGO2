#include "main.h"

// For Global Defines, Use Utils. For Local, Use Here.

// basic defines
#define HEIGHT  12
#define WIDTH   6
#define CNTSPIM 12 // Constant Spin (Minimum Spin Amount)
#define SPINDWN true // Spin Down (If False Spimn Up)
#define DEBUG   true

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
    // seed the rand
    srand(time(NULL));
    
    
    //Define CONSTANT rotation times
    // Not using #define becasue it gets a new number every thime i referece it
    int rotationtimes = (rand() % 25) + CNTSPIM;
    
    // Slot Characters And Colors
    char *slotCharacters[10] = {"$", "X", "#", "O", "?", "=", ">", "7", ".", "9"};
    char *slotColours[10] = {"\x001b[43m\x001b[30m", "\x1B[31m", "\x1B[34m", "\x1B[36m\x1B[35m", "\x001b[46m\x001b[30m", "\x001b[47m\x001b[37;1m\x001b[30m", "\x1B[35m", "\x1B[32m", "\x1B[33m", "\x1B[37m"};

    // create number list
    int slotMap[WIDTH][HEIGHT];

    // create time var
    time_t t;

    // rolled values
    int rolledValues[WIDTH];

    // roll delay
    int rollIteration[WIDTH];

    // is stop
    int isStop = false;


    // init rand
    srand((unsigned) time(&t));


    // create array of rands
    for (int x = 0; x < WIDTH; x++)
    {
        for (int i = 0; i < HEIGHT; i++)
        {
            slotMap[x][i] = rand() % 10;
        }
    }


    // Set Default Rolled Values
    // Idk how to set values to "NULL", so im just gonna use 1t as it sould never be above 10 lmao
    for (int n = 0; n < WIDTH; n++)
    {
        rolledValues[n] = 15;
    }

    // Set Random Roll Delay
    for (int r = 0; r < WIDTH; r++)
    {
        rollIteration[r] = (rand() % 2) + 1;
    }

    // clear screen
    system("clear");

    // create a random starting point for iteration
    int j = rand() % HEIGHT;

    // number of times to rotate
    for (int k = 0; k <= rotationtimes; k ++)
    {

        // Calculate Rotation Speed
        // Dont worry about how it works
        float rotateSpeed = (long)(((float)(MAX(CNTSPIM - rotationtimes + k, 1))/(float)CNTSPIM)* 900)+100;
        // wait/clear
        msleep(rotateSpeed);
        system("clear");
        if(DEBUG)
        {
            printf("~~DEBUG~~ \nNumber Index: %d\nTimes Updated:%d\nTotal Updates:%d\nConstant Spin Time:%d\nRotation Speed:%lf\n\n\n", j, k, rotationtimes, CNTSPIM, rotateSpeed);
        }

        // print full array starting at index j
        for (int i = 0; i < HEIGHT; i++)
        {

            if (i == HEIGHT/2)  // if i is in middle print in RED
            {
                //Prints out lines
                for (int e = 0; e < WIDTH*2-1; e++){printf("=");}
                printf("\n" CYN);
                for (int v = 0; v < WIDTH; v++)
                {
                    //printf("%d ", slotMap[v][j]);
                    printf("%s%s%s ", slotColours[slotMap[v][j]], slotCharacters[slotMap[v][j]], "\x001b[0m");
                    rolledValues[v] = slotMap[v][j];
                }
                printf("\n" RESET);
                //Prints out lines
                for (int e = 0; e < WIDTH*2-1; e++){printf("=");}
                printf("\n");

            }


            else // hide the other numbers
            {
                for (int v = 0; v < WIDTH; v++)
                {
                    printf("%s%s%s ", slotColours[slotMap[v][j]], slotCharacters[slotMap[v][j]], "\x001b[0m");
                }
                printf("\n");
            }


            // j goes up for iteration 
            j++;
            j = j % HEIGHT;
        }


        // starting point -= or += 1
        if(SPINDWN)
        {
            j--;
            if(j < 0){j=HEIGHT-1;}
        }
        else
        {
            j++;
            j = j % HEIGHT;
        }
    }


    /* END OF SPIN */ 

    j++;

    for (int k = 0; k < 100; k++)
    {
        msleep(100);
        system("clear");
        // print full array starting at index j
        for (int i = 0; i < HEIGHT; i++)
        {

            if (i == HEIGHT/2)  // if i is in middle print in RED
            {
                //Prints out lines
                
                if (k % 2 == 0)
                {
                    for (int e = 0; e < WIDTH*2-1; e++){printf(RED"="RESET);}
                }
                else
                {
                    for (int e = 0; e < WIDTH*2-1; e++){printf("=");}
                }
                printf("\n" CYN);
                for (int v = 0; v < WIDTH; v++)
                {
                    //printf("%d ", slotMap[v][j]);
                    printf("%s%s%s ", slotColours[slotMap[v][j]], slotCharacters[slotMap[v][j]], "\x001b[0m");
                    rolledValues[v] = slotMap[v][j];
                }
                printf("\n" RESET);
                //Prints out lines ( ================ )
                if (k % 2 == 0)
                {
                    for (int e = 0; e < WIDTH*2-1; e++){printf(RED"="RESET);}
                }
                else
                {
                    for (int e = 0; e < WIDTH*2-1; e++){printf("=");}
                }
                printf("\n");

            }


            else // hide the other numbers
            {
                for (int v = 0; v < WIDTH; v++)
                {
                    printf("%s%s%s ", slotColours[slotMap[v][j]], slotCharacters[slotMap[v][j]], "\x001b[0m");
                }
                printf("\n");
            }


            // j goes up for iteration 
            j++;
            j = j % HEIGHT;
        }
    }


    printf("\n");
    return 0;
}
