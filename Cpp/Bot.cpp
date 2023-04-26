#include "Bot.h"
#include <ncurses.h>
#include<iostream>
using namespace std;
void Bot::spawn(char n2MapArray[15][15])
{
    srand((unsigned) time(0));
    int x,y;
    bool a=false;
    while (a==false)
    {
        y = rand()%15;
        x = rand()%15;
        if (n2MapArray[x][y]=='.') 
        {
                dx = x;
                dy = y;
                break; 
                a=true;
        }
    }
    n2MapArray[dx][dy]='M';
    mvprintw(dx,dy,"M");
    move(dx,dy);
}
