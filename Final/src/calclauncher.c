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
#define _MANUALRUN

// Import All The Programs
#include "calc.c"
#include "slots.c"



int main(void) 
{
     
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
        runCalc(0);
        return 0;
    } else if (strncmp(items[i], "Calc (BIN)", 20) == 0) {
        runCalc(1);
        return 0;
    } else if (strncmp(items[i], "Calc (HEX)", 20) == 0) {
        runCalc(2);
        return 0;
    } else if (strncmp(items[i], "Calc (AST)", 20) == 0) {
        runCalc(3);
        return 0;
    } else if (strncmp(items[i], "Slots", 20) == 0) {
        runSlots(0);
        return 0;
    } else if (strncmp(items[i], "Slots (INFINITE)", 20) == 0) {
        runSlots(-1);
        return 0;
    } else if (strncmp(items[i], "EXIT", 20) == 0) {
        system("clear");
        return 0;
    }






}