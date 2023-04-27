#include "Bot.h"
#include <ncurses.h>
#include<iostream>
using namespace std;
void Bot::spawn(char n2MapArray[15][15] , int *e , int *p)
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
    *e=dx;
    *p=dy;
    n2MapArray[dx][dy]='M';
    attron(COLOR_PAIR(2));
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    mvprintw(dx,dy,"M");
    attroff(COLOR_PAIR(2));  
    //move(dx,dy);
}

void Bot::move_b(char n2MapArray[15][15] , int diamond_x , int diamond_y,int *d,int *y)
{

        if ((dx< diamond_x)&&(n2MapArray[dx+1][dy]!='*')) {
            dx++;
            //move(dx,dy);
            attron(COLOR_PAIR(2));
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            mvaddch(dx,dy,'M');
            attroff(COLOR_PAIR(2));  
            mvaddch(dx-1,dy,'.');
        }
         else if ((dx>diamond_x)&&(n2MapArray[dx-1][dy]!='*')) {
            dx--;
            //move(dx,dy);
            attron(COLOR_PAIR(2));
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            mvaddch(dx,dy,'M');
            attroff(COLOR_PAIR(2));  
            mvaddch(dx+1,dy,'.');
        }
        else if ((dy<diamond_y)&&(n2MapArray[dx][dy+1]!='*')) {
            dy++;
            //move(dx,dy);
            attron(COLOR_PAIR(2));
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            mvaddch(dx,dy,'M');
            attroff(COLOR_PAIR(2));  
            mvaddch(dx,dy-1,'.');
        }
        else if ((dy>diamond_y)&&(n2MapArray[dx][dy-1]!='*')) {
            dy--;
            //move(dx,dy);
            attron(COLOR_PAIR(2));
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            mvaddch(dx,dy,'M');
            attroff(COLOR_PAIR(2));  
            mvaddch(dx,dy+1,'.');
        }
        *d=dx;
        *y=dy;
        if(n2MapArray[dx][dy]=='#')
        {
            return;
        }
}