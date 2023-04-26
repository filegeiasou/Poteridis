#include "Map.h"
#include<ncurses.h>
#include <iostream>
using namespace std;
void Map::display(char n2MapArray[15][15])
{
    initscr(); 
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    for (int y = 0; y < 15; y++) {          
        for (int x = 0; x <15; x++) {
            mvaddch(y,x,n2MapArray[y][x]);
        }
    }
}