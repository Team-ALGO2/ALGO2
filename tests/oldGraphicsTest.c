#include <curses.h>  // I put curses here so nothing breaks in main.h if you don't have the library
#include <stdlib.h>
#include <string.h>


#define ITERMAX 10000

int show(int x, int y, int ch, char *snum);

int x = 0;
int y = 0;

int main(void)
{

    /* initialize curses */

    initscr();          // Create Screen
    cbreak();           // Allow Control Characters
    noecho();           // Turns Off Tech Echoing
    keypad(stdscr, 1);  // Enables Arrow ANd Function Keys

    clear();            // Clears Screen

    int ch;
    char snum[5];
    int x = 0;
    while (1)
    {
        
        ch = getch();
        sprintf(snum, "%d", ch);
        x = x + show(y, x, ch, snum) + 1;
        

    }

    /* iterate the triangle */


    refresh();

    getch();
    endwin();

    exit(0);
}

int show(int x, int y, int ch, char *snum)
{
    if (ch == 48)                   // 0
        mvprintw(x, y, "0");    
    if (ch == 49)                   // 1
        mvprintw(x, y, "1");
    else if (ch == 50)              // 2
        mvprintw(x, y, "2");
    else if (ch == 51)              // 3
        mvprintw(x, y, "3");
    else if (ch == 52)              // 4
        mvprintw(x, y, "4");
    else if (ch == 53)              // 5
        mvprintw(x, y, "5");
    else if (ch == 54)              // 6
        mvprintw(x, y, "6");
    else if (ch == 55)              // 7
        mvprintw(x, y, "7");
    else if (ch == 56)              // 8
        mvprintw(x, y, "8");
    else if (ch == 57)              // 9
        mvprintw(x, y, "9");
    
    else if (ch == 42)              // *
        mvprintw(x, y, "*");
    else if (ch == 43)              // +
        mvprintw(x, y, "+");
    else if (ch == 45)              // -
        mvprintw(x, y, "-");
    else if (ch == 47)              // /
        mvprintw(x, y, "/");
    

    /* User pressed equal or enter, do something */
    else if (ch == 10)              // ENTER
        mvprintw(x, y, "=");
    else if (ch == 61)              // =
        mvprintw(x, y, "=");
    




    else  
        mvprintw(x, y, snum);
    


   return strlen(snum);




}