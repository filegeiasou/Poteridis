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
    mvprintw(*p_x1,*p_y1,"o");
    move(*p_x1,*p_y1);
}
void Player::move_p(const char n2MapArray[15][15], int dx , int dy )
{
    int k;
    char ch2 = getch();
    k = int(ch2);
    while(true)
    {
        if(k==119)
        {
            if(n2MapArray[dx-1][dy]=='.')
            {
                int a = dx-1;
                move(a,dy);
                init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(a,dy,"o");
                init_pair(1,COLOR_WHITE,COLOR_BLACK);
                mvprintw(dx,dy,".");
                move(a,dy);
            }
            else if (n2MapArray[dx-1][dy]=='*')
            {
                char ch1 = getch();
                k = int(ch1);
                continue;
            }
            dx--;
        }
        if(k==115)
        {
            if(n2MapArray[dx + 1][dy]=='.')
            {
                int a = dx+1;
                move(a,dy);
                init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(a,dy,"o");
                init_pair(1,COLOR_WHITE,COLOR_BLACK);
                mvprintw(a-1,dy,".");
                move(a,dy);
            }
            else if (n2MapArray[dx+1][dy]=='*')
            {
                char ch1 = getch();
                k = int(ch1);
                continue;
            }
            dx++;
        }
        if(k==97)
        {
            if(n2MapArray[dx][dy-1]=='.')
            {
                int b = dy-1;
                move(dx,b);
                init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(dx,b,"o");
                init_pair(1,COLOR_WHITE,COLOR_BLACK);
                mvprintw(dx,b+1,".");
                move(dx,b);
            }
            else if (n2MapArray[dx][dy-1]=='*')
            {
                char ch1 = getch();
                k = int(ch1);
                continue;
            }
            dy--;
        }
        if(k==100)
        {
            if(n2MapArray[dx][dy+1]=='.')
            {
                int b = dy+1;
                move(dx,b);
                init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(dx,b,"o");
                init_pair(1,COLOR_WHITE,COLOR_BLACK);
                mvprintw(dx,b-1,".");
                move(dx,b);
            }
            else if (n2MapArray[dx][dy+1]=='*')
            {
                char ch1 = getch();
                k = int(ch1);
                continue;
            }
            dy++;
        }
        if(k==32)
        {
            move(dx,dy);
        }
        char ch1 = getch();
        k = int(ch1);
        if (k==27)
            break;
    }
}