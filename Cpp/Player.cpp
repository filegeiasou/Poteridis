#include "Player.h"
#include <iostream>
using namespace std;
void Player::spawn(const char n2MapArray[15][15] , int * p_x1 , int *p_y1)
{
    srand((unsigned) time(0));
    int x,y;
    bool a=false;
    while (a==false)
    {
        y = rand()%16;
        x = rand()%16;
        if (n2MapArray[x][y]=='.') 
        {
                *p_x1 = x;
                *p_y1 = y;
                break; 
                a=true;
        }
    }
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvprintw(*p_x1,*p_y1,"L");
    move(*p_x1,*p_y1);
}
int Player::move_p(const char n2MapArray[15][15], int dx , int dy )
{   
    int ch2 = getch();
    while(true)
    {
        if(ch2==KEY_UP)
        {
            if(n2MapArray[dx-1][dy]=='.')
            {
                int a = dx-1;
                move(a,dy);
                init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(a,dy,"L");
                init_pair(1,COLOR_WHITE,COLOR_BLACK);
                mvprintw(dx,dy,".");
                move(a,dy);
                //return 0;
            }
            else if (n2MapArray[dx-1][dy]=='*')
            {
                ch2 = getch();
                continue;
            }
            else if(n2MapArray[dx-1][dy]=='#')
            {
                refresh();
                clear();
                mvprintw(0,0,"You win");
                getch();
                return 1;
            }
            dx--;
        }
        if(ch2==KEY_DOWN)
        {
            if(n2MapArray[dx + 1][dy]=='.')
            {
                int a = dx+1;
                move(a,dy);
                init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(a,dy,"L");
                init_pair(1,COLOR_WHITE,COLOR_BLACK);
                mvprintw(a-1,dy,".");
                move(a,dy);
                //return 0;
            }
            else if (n2MapArray[dx+1][dy]=='*')
            {
                ch2 = getch();
                continue;
            }
            else if(n2MapArray[dx+1][dy]=='#')
            {
                refresh();
                clear();
                mvprintw(0,0,"You win");
                getch();
                return 1;
            }
            dx++;
        }
        if(ch2==KEY_LEFT)
        {
            if(n2MapArray[dx][dy-1]=='.')
            {
                int b = dy-1;
                move(dx,b);
                init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(dx,b,"L");
                init_pair(1,COLOR_WHITE,COLOR_BLACK);
                mvprintw(dx,b+1,".");
                move(dx,b);
                //return 0;
            }
            else if (n2MapArray[dx][dy-1]=='*')
            {
                ch2 = getch();
                continue;
            }
            else if(n2MapArray[dx][dy-1]=='#')
            {
                refresh();
                clear();
                mvprintw(0,0,"You win");
                getch();
                return 1;
            }
            dy--;
        }
        if(ch2==KEY_RIGHT)
        {
            if(n2MapArray[dx][dy+1]=='.')
            {
                int b = dy+1;
                move(dx,b);
                init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(dx,b,"L");
                init_pair(1,COLOR_WHITE,COLOR_BLACK);
                mvprintw(dx,b-1,".");
                move(dx,b);
                //return 0;
            }
            else if (n2MapArray[dx][dy+1]=='*')
            {
                ch2 = getch();
                continue;
            }
            else if(n2MapArray[dx][dy+1]=='#')
            {
                clear();
                mvprintw(0,0,"You win");
                getch();
                return 1;
            }
            dy++;
        }
        if(ch2==32)
        {
            move(dx,dy);
            //return 0;
        }
        ch2 = getch();
        if (ch2==27)
            break;
    }
    return 2;
}