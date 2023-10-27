#include "Map.h"
#include "Player.h"
#include "Diamond.h"
#include "Bot.h"
using namespace std;
#include <iostream>
int main (int argc , char **argv)
{
    if (argc<2)
    {
        cout<<"Must put a map.txt to play"<<endl;
        exit(0);
    }
    int x ,y;
    initscr(); 
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    Map map;
    map.create(argv[1]);
    char (*n2map)[15]= map.getArray();
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
    int found=0;
    while(true)
    {
        int input = getch();       
        t=player1.move_p(n2map,&x,&y,input);
        //bot.move_b(n2map,d_x,d_y,&b_x,&b_y);     
        bot.bfs(n2map,d_x,d_y);
        vector<int> path = bot.get_path(d_x,d_y);
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
        if (path.empty()) {
            break;
        }
        int d = path[0];
        bot.move_e(n2map,d,d_x,d_y,&found);
        if (found)
        {
            break;
        }
    }
    refresh();
    endwin(); 
    if(found)
    {
        cout<<"Bot wins"<<endl;
    }
    else if((b_x==d_x)&&(b_y==d_y))
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
