//Main Graphical Library Using Ncurses

/*
 * WARNING: YOU MUST INSTALL NCURSES BEFOREHAND
 * Linux: Type the following apt-get command to install ncurses header and lib
 * sudo apt-get install libncurses5-dev libncursesw5-dev
 * 
 * Mac: No idea, but i think its preinstalled
 * 
 * Windows: Currently Not SUpported. Maybe Port Later To PDCurses
 */

/* IMPORTANT: Compile with the flag: -lncurses $ cc graphics.c -o graphics -lncurses */

#include <ncurses.h>
#include <panel.h>
#include <menu.h>
#include <form.h>
#include <stdlib.h>
#include <string.h>

int initScreen(void)
{

    /* initialize curses */

    initscr();          // Create Screen
    cbreak();           // Allow Control Characters
    noecho();           // Turns Off Tech Echoing
    keypad(stdscr, 1);  // Enables Arrow ANd Function Keys

    clear();            // Clears Screen


    refresh();

    getch();
    endwin();

    exit(0);

    //Test
}