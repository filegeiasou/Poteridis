#include "Map.h"
#include "Player.h"
#include "Diamond.h"
#include "Bot.h"
using namespace std;
#include <iostream>
int main ()
{
    int x ,y;
    initscr(); 
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    Map map;
    char n2map[15][15]={
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
        {'*', '.', '*', '*', '.', '*', '*', '.', '*', '*', '.', '*', '*', '.', '*'},
        {'*', '.', '*', '.', '.', '.', '*', '.', '*', '.', '.', '*', '.', '.', '*'},
        {'*', '.', '*', '.', '*', '.', '*', '.', '*', '.', '*', '*', '.', '.', '*'},
        {'*', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
        {'*', '.', '*', '*', '*', '.', '*', '*', '*', '.', '*', '*', '.', '*', '*'},
        {'*', '.', '.', '.', '*', '.', '.', '.', '.', '.', '.', '.', '.', '.', '*'},    
        {'*', '*', '.', '.', '*', '*', '.', '*', '*', '.', '*', '.', '.', '*', '*'},
        {'*', '.', '.', '.', '.', '.', '.', '.', '.', '.', '*', '.', '.', '.', '*'},
        {'*', '.', '*', '.', '*', '.', '*', '*', '*', '.', '*', '*', '.', '.', '*'},
        {'*', '.', '*', '.', '.', '.', '.', '.', '*', '.', '.', '*', '.', '.', '*'},
        {'*', '.', '*', '*', '.', '*', '*', '.', '*', '.', '*', '*', '.', '.', '*'},
        {'*', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };
    map.display(n2map);
    Diamond diam;
    int d_x,d_y;
    diam.spawn(n2map,&d_x,&d_y);
    Bot bot;
    int b_x,b_y;
    bot.spawn(n2map,&b_x,&b_y);
    Player player1;
    player1.spawn(n2map , &x,&y);
    int t;
    while(true)
    {
        int input = getch();       
        t=player1.move_p(n2map,&x,&y,input);
        bot.move_b(n2map,d_x,d_y,&b_x,&b_y);     
        if((b_x==d_x)&&(b_y==d_y))
        {
            break;
        }
        else if((x==d_x)&&(y==d_y))
        {
            break;
        }
        else if((t==1 )|| (t==2))
        {
            break;
        }      
    }
    refresh();
    endwin(); 
    if((b_x==d_x)&&(b_y==d_y))
    {
         cout<<"Bot wins"<<endl;
    }
    else if(((x==d_x)&&(y==d_y))|| (t==2))
    {
         cout<<"Player wins"<<endl;
    }
    cout<<"Bye Bye See you soon"<<endl;
    return 0;   
}