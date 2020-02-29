/* Compiple with: $cc slots.c -o b -lssl -lcrypto -lncurses -lsqlite3 */

#include "main.h"
// For Global Defines, Use Utils. For Local, Use Here.

// basic defines
#define HEIGHT  16
#define WIDTH   5
#define CNTSPIM 10 // Constant Spin (Minimum Spin Amount)
#define SPINDWN true // Spin Down (If False Spin Up)
#define DBSAVE  false // Save To Database??

#if DBSAVE
#undef _DEFMAIN
#include "users.c"
#define _DEFMAIN
#endif // DBSAVE

int analyseResults(char *values[WIDTH]);

int total_spins = 0;
int avg_spin;

char *user = "";

int user_bal;
int cost_per_spin = WIDTH * 7;

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

//Since C Does Not Support Default Argument Values >:(
// rotationflag > 0  -->  Use rotationtimes amount
// rotationflag = 0  -->  Use Random Rotations
// rotationflag < 0  -->  Infinate Rotations 
int runSlots(int rotationtimes)
{
    
    // seed the rand
    srand(time(NULL));
    
    
    // Define CONSTANT rotation times
    // Not using #define becasue it gets a new number every thime i referece it

    int infinate;

    if (rotationtimes < 0)
    {
        infinate = true;
        rotationtimes = 0;
    }else if (rotationtimes == 0)
    {
        infinate = false;
        rotationtimes = (rand() % 25) + CNTSPIM;
    }else
    {
        infinate = false;
    }

    if (!infinate && (strcmp(user, "") == 0))  // User must be signed in to play
    {
        #if DBSAVE
        char * sel_user;
        char * d_password;
        sqlite3 * db = create_db();
        

        printf("Sign in as: ");
        scanf("%s", sel_user);
        printf("Password: ");
        scanf("%s", d_password);
        printf(".\n");
        printf("Signing in %s with %s\n", sel_user, &d_password);

        sign_in(db, sel_user, &d_password);

        if (is_signed_in(db, sel_user))
        {
            printf("Y\n");
            user = sel_user;
            printf("Successful log in as %s!\n", user);
            user_bal = user_balance(db, user);
            printf("%s has %d\n", user, user_bal);
            if (user_bal < cost_per_spin)
            {
                printf("You are bankrupt, you need at least %d to play.\n", cost_per_spin);
            } else {
                printf("Spending %d to spin.\n", cost_per_spin);
            }
        } else {
            printf("Wrong username or password. Please try again or sign up.\n");
        }
        #else
        printf("Database Disabled! Skipping Login And Logging In As XXXXX");
        //More Login Logic Here!
        #endif // DBSAVE
    }
    msleep(7 * 1000);
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
    for (int k = 0; k <= rotationtimes || infinate == true; k ++)
    {

        // Calculate Rotation Speed
        // Dont worry about how it works

        float rotateSpeed;
        
        if (infinate)
        {
            rotateSpeed = 100;
        } else {
            rotateSpeed = (long)(((float)(MAX(CNTSPIM - rotationtimes + k, 1))/(float)CNTSPIM)* 995)+5;
        }
        
        // wait/clear
        msleep(rotateSpeed);
        system("clear");
        //Printing Debug Values
        #ifdef DEBUG
        printf("~~DEBUG~~ \nNumber Index: %d\nTimes Updated:%d\nTotal Updates:%d\nMinimum Spin Time:%d\nRotation Speed:%lf\n\n\n", j, k, rotationtimes, CNTSPIM, rotateSpeed);
        #endif // DBSAVE

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

    for (int k = 0; k < 10; k++)
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
    printf("\n\n");
    char *rolledChars[WIDTH];
    for (int q = 0; q < WIDTH; q++)
    {
        //printf("%s", slotCharacters[rolledValues[q]]);
        rolledChars[q] = slotCharacters[rolledValues[q]];
    }
    int total = analyseResults(rolledChars);
    printf("You won %d points\n", total);

    #if DBSAVE
    sqlite3 * db = create_db();
    set_user_balance(db, user, user_bal - cost_per_spin + total);
    #endif
    msleep(5*1000);
    return 0;
}

int analyseResults(char *values[WIDTH])
{
    int total = 0;
    for (int i = 0; i < WIDTH; i++)
    {
        char *search = values[i];
        int adding = 1;
        for (int j = i+1; j < WIDTH; j++)
        {
            if (strcmp(search, values[j]) == 0)
            {
                adding++;
            }
        }
        if (adding > 1)
        {
            for (int k = 1; k < adding + 1; k++)
            {
                total = total + (k*15);
            }
        }
    }
    int all_sum = total_spins*avg_spin;
    total_spins++;
    all_sum = all_sum + total;
    avg_spin = all_sum/total_spins;
    return total;
}


//Because C Does Not Like Redefinitions of Main, This Checks If Its Being Run Directly Or If Its Being Included
#ifdef _DEFMAIN
int main(int argc, char *argv[]){
    if (argc > 1)
    {
        if (strcmp(argv[1], "INFINITE") == 0)
        {
            runSlots(-1);
        }
        else
        {
            runSlots(atoi(argv[1]));
        }
    }
    else
    {
        runSlots(0);
    }
}

#endif // _DEFMAIN
