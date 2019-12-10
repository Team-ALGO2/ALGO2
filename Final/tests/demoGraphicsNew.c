// Very hacky graphics demo
// dont judge. This is only for an example

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#define SIZE_X 30
#define SIZE_Y 10

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3



int main()
{	
    initscr();
    curs_set(0);
    clear();
    refresh();
    int direction = RIGHT;
    int x = 0;
    int y = 0;
    while(1)
    {
        mvprintw(0, 0, "debug: x: %d, y: %d, dir: %d\n", x, y, direction);
        mvprintw(1, 0, "**NEW** GRAPHICS ENGINE\n");
        //mvwdelch(stdscr, 3, 3);
        if(direction == RIGHT){
            x++;
            if(x + 1 >= SIZE_X){
                direction = DOWN;
            }
        }
        else if(direction == DOWN){
            y++;
            if(y + 1 >= SIZE_Y){
                direction = LEFT;
            }
        }
        else if(direction == LEFT){
            x--;
            if(x <= 0){
                direction = UP;
            }
        }
        else if(direction == UP){
            y--;
            if(y <= 0){
                direction = RIGHT;
            }
        }
        mvwaddch(stdscr, y + 2, x, 'X');
        refresh();
        usleep(50000);
        mvwaddch(stdscr, y + 2, x, ' ');
        refresh();
    }
}