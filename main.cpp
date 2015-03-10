#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //initialize terminal here to get size
    initscr();
    cbreak(); 
    curs_set(FALSE);
    noecho();

    
    //game vars
    bool game = true;
    //world vars
    //map size fits to terminal
    int y,x;
    getmaxyx(stdscr,y,x);
    int map_size_x = x;
    int map_size_y = y;
    int map_size_z = 10; // depth
    int map[map_size_z][map_size_y][map_size_x];
    //view the layers of the world
    int level = 0;
    
    srand (time(NULL));
    for (int z = 0; z < map_size_z;z++)
    {
        for (int y = 0; y < map_size_y; y++)
        {
            for (int x = 0;x < map_size_x; x++)
            {
               map[z][y][x] = (0 + (rand() % 2));    
            }
        }
    }
    
    
    
    while (game == true)
    {  
        char input = getch();
        printf("%d",input);     
        //render the plane
        clear();
        ///refresh();
        for (int y = 0; y < map_size_y; y++)
        {
            for (int x = 0;x < map_size_x; x++)
            {
                if (map[level][y][x] != 0)
                {
                    //Draw the blocks green, spaces black
                    start_color();
                    init_pair(1,COLOR_BLACK,COLOR_GREEN);
                    attron(COLOR_PAIR(1));
                    mvprintw(y,x," ");
                    attroff(COLOR_PAIR(1));
                }
            }
        }
        //Show layer
        mvprintw(0,0,"Layer: %d", level);

        if ((input == 119) and level < map_size_z-1)
        {
            level += 1;
        }
         if ((input == 115) and level > 0)
        {
            level -= 1;
        }       
        refresh();
        
    }
    endwin();
    return(0);
}