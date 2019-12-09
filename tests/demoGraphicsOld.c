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
    int direction = RIGHT;
    int x = 0;
    int y = 0;
    while(1)
    {
        printf("debug: x: %d, y: %d, dir: %d\n", x, y, direction);
        printf("OLD GRAPHICS ENGINE\n");
        for (int gy = 0; gy < SIZE_Y; gy++){
            for (int gx = 0; gx < SIZE_X; gx++){
                if(gx == x && gy == y){
                    printf("X");
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
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
        sleep(0.3);
        system("clear");
    }
}