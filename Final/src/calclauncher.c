#include <ncurses.h>
#include "main.h"        

#define LENGTH 35
#define HEIGTH 15

// ncurses key
#define K_DOWN 258
#define K_UP 259
#define K_LEFT 260
#define K_RIGHT 261
#define K_ENTER 10

// Turn On The Manual Run Flag
#define _AUTORUN

// Import All The Programs
#include "calc.c"
#include "slots.c"

int os;
int compatible; //NOTE: I dont know why this was a bool.s

// While RadioactiveHydras hads mainguard

/*
int main(void) 
{
    system(CLEAR);
    os = 2; // set default to windows because 90%
    char all_os[3][7] = {"APPLE", "LINUX", "WINDOWS"};
    #ifdef __APPLE__
        printf("APPLE OS detected\n");
        os = 0;
    #endif
    #ifdef __linux__
        printf("LINUX OS detected\n");
        os = 1;
    #endif
    #ifdef _WIN32
        printf("WINDOWS OS detected\n");
        os = 2;
    #endif


    char ans[3];
    printf("We detected that you are using a %s operating system. Is this correct? (yes/no): ", all_os[os]);
    scanf("%s", ans);
    
    if (strcmp(ans, "yes") == 0 || strcmp(ans, "y") == 0)
    {
        if (os < 2) // compatible with NCURSES
        {
            printf("Your computer is compatible with the NCURSES library.\n");
            printf("Launching the NCURSES menu in 3 seconds.\n");
            sleep(3);
            compatible = true;
        } else {    // not copatible
            printf("Your computer is not compatible with the NCURSES library.\n");
            // Launch non-ncurses "menu"
            return 0;
            compatible = false;
        }
    } else if (strcmp(ans, "no") == 0 || strcmp(ans, "n") == 0)
    {
        char nans[3];
        printf("Choose your Operating System");
        printf("\n 1-OSX\n 2-LINUX\n 3-WINDOWS\nEnter a number between 1 and 3: ");
        scanf("%s", nans);
        os = atoi(nans) - 1;
        if (os < 2) // compatible with NCURSES
        {
            printf("Your computer is compatible with the NCURSES library.\n");
            printf("Launching the NCURSES menu in 3 seconds.\n");
            sleep(3);
            compatible = true;
        } else {    // not copatible
            printf("Your computer is not compatible with the NCURSES library.\n");
            // Launch non-ncurses "menu"
            return 0;
            compatible = false;
        } 
    }

    
    WINDOW *w;
    int ch, i = 0, width = 7;
    char items[7][20] = {"Calc (DEC)", "Calc (BIN)", "Calc (HEX)", "Calc (AST)", "Slots", "Slots (INFINITE)", "EXIT"};
    int len = 7; 
 
    initscr(); // initialize Ncurses
    w = newwin( HEIGTH, LENGTH, 0, 20 ); // create a new window
    box( w, 0, 0 ); // sets default borders for the window
    keypad(stdscr, TRUE);





    while(1)
    {
        ch = getch();        //Pause until character
        if (ch == K_UP)
        {
            i--;
            if (i<0){i=len;}
        } else if (ch==K_DOWN) {
            i++;
            if (i>=len){i=0;}
        }

        for (int j = 0; j < len; j++)
        {
            if (j == i )
            {
                wattron(w, A_STANDOUT);    // Put on highlite if selected
            } else {
                wattroff(w, A_STANDOUT);   // else take it off
            }
            mvwprintw(w, j + 1, 2, "%s", items[j]);   // print the items in order
        }
        wrefresh(w);    // refresh the window

        if (ch == K_ENTER)      // Stop
        {
            break;      
        }



    }

 
    delwin(w);          // delete the window
    endwin();


    // Iterates over options
    if (strncmp(items[i], "Calc (DEC)", 20) == 0) {
        system("./calc DEC");
        return 0;
    } else if (strncmp(items[i], "Calc (BIN)", 20) == 0) {
        system("./calc BIN");
        return 0;
    } else if (strncmp(items[i], "Calc (HEX)", 20) == 0) {
        system("./calc HEX");
        return 0;
    } else if (strncmp(items[i], "Calc (AST)", 20) == 0) {
        system("./calc AST");
        return 0;
    } else if (strncmp(items[i], "Slots", 20) == 0) {
        system("./slots");
        return 0;
    } else if (strncmp(items[i], "Slots (INFINITE)", 20) == 0) {
        system("./slots -1");
        return 0;
    } else if (strncmp(items[i], "EXIT", 20) == 0) {
        system("clear");
        return 0;
    }


}
*/