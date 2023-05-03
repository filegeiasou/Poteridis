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
    p_x=*p_x1;
    p_y=*p_y1;
    //start_color();
    //init_pair(1,COLOR_RED,COLOR_BLACK);
    //attron(COLOR_PAIR(1));
    mvprintw(*p_x1,*p_y1,"L");
    //attroff(COLOR_PAIR(1));
    //move(*p_x1,*p_y1);
}

int Player::move_p(const char n2MapArray[15][15], int *dx , int *dy ,int input)
{
    switch (input) {
        // Move the player up
        case KEY_UP:
            if(n2MapArray[(*dx)-1][*dy]=='.')
            {
                int a = (*dx)-1;
                //move(a,*dy);
                //attron(COLOR_PAIR(1));
                //init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(a,*dy,"L");
                //attroff(COLOR_PAIR(1));
                mvprintw(*dx,*dy,".");
                //move(a,*dy);
                (*dx)--;
            }
            else if(n2MapArray[(*dx)-1][*dy]=='$')
            {
                //cout<<"I am here"<<endl;
                /*int c = (*dx)-1;
                mvprintw(c,*dy,"*");
                move(*dx,*dy);*/
                return 2;
            }
            //(*dx)--;
            break;

        // Move the player down
        case KEY_DOWN:
            if(n2MapArray[(*dx) + 1][*dy]=='.')
            {
                int a = (*dx)+1;
                //move(a,*dy);
                //attron(COLOR_PAIR(1));
                //init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(a,*dy,"L");
                //attroff(COLOR_PAIR(1));   
                mvprintw(a-1,*dy,".");
                //move(a,*dy);
                (*dx)++;
                //return 0;
            }
            else if(n2MapArray[(*dx)+1][*dy]=='$')
            {
                /*int c = (*dx)+1;
                mvprintw(c,*dy,"*");
                move(*dx,*dy);*/
                return 2;
            }
            //(*dx)++;
            break;

        // Move the player left
        case KEY_LEFT:
            if(n2MapArray[*dx][(*dy)-1]=='.')
            {
                int b = (*dy)-1;
                //move(*dx,b);
                //attron(COLOR_PAIR(1));
                //init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(*dx,b,"L");
                //attroff(COLOR_PAIR(1));  
                mvprintw(*dx,b+1,".");
                //move(*dx,b);
                (*dy)--;
                //return 0;
            }
            else if(n2MapArray[*dx][(*dy)-1]=='$')
            {
                /*int c = (*dy)-1;
                mvprintw(*dx,c,"*");
                move(*dx,*dy);*/
                return 2;
            }
            //(*dy)--;
            break;

        // Move the player right
        case KEY_RIGHT:
            if(n2MapArray[*dx][(*dy)+1]=='.')
            {
                int b = (*dy)+1;
                //move(*dx,b);
                //attron(COLOR_PAIR(1));
                //init_pair(1,COLOR_RED,COLOR_BLACK);
                mvprintw(*dx,b,"L");
                //attroff(COLOR_PAIR(1));  
                mvprintw(*dx,b-1,".");
                //move(*dx,b);
                //return 0;
                (*dy)++;
            }
            else if(n2MapArray[*dx][(*dy)+1]=='$')
            {
                /*int c = (*dy)+1;
                mvprintw(*dx,c,"*");
                move(*dx,*dy);*/
                return 2;
            }
            //(*dy)++;
            break;
        case 27:
            return 1;
            break;
        case 32:
            break;
        default:
            return 3;
    }
    return 3;
}