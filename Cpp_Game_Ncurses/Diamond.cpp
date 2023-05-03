#include "Diamond.h"
#include <iostream>
#include <ncurses.h>
using namespace std;
void Diamond::spawn( char n2MapArray[15][15],int *c,int *b)
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
    *c=dx;
    *b=dy;
    n2MapArray[dx][dy]='$';
    mvprintw(dx,dy,"$");
    //move(dx,dy);
}