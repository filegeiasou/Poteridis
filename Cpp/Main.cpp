#include "Map.h"
#include "Player.h"
#include "Diamond.h"
#include "Bot.h"
using namespace std;
#include <iostream>
int main ()
{
    int x ,y;
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
    diam.spawn(n2map);
    Bot bot;
    bot.spawn(n2map);
    Player player1;
    player1.spawn(n2map , &x,&y);
    int t=0;
    while(t==0)
    {
        t=player1.move_p(n2map,x,y);
    }
    //refresh();
    endwin(); 
    cout<<"Bye Bye See you soon"<<endl;
    return 0;   
}