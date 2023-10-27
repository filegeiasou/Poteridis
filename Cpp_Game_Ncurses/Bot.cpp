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
    //attron(COLOR_PAIR(2));
    //init_pair(1,COLOR_GREEN,COLOR_BLACK);
    mvprintw(dx,dy,"M");
    //attroff(COLOR_PAIR(2));  
    //move(dx,dy);
}

/*void Bot::move_b(char n2MapArray[15][15] , int diamond_x , int diamond_y,int *d,int *y)
{

        if ((dx<diamond_x)&&((n2MapArray[dx+1][dy]!='*')&&(visited[dx+1][dy]==false))) {
            dx++;
            //move(dx,dy);
            attron(COLOR_PAIR(2));
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            mvaddch(dx,dy,'M');
            attroff(COLOR_PAIR(2));  
            mvaddch(dx-1,dy,'.');
            n2MapArray[dx-1][dy]='.';
            visited[dx+1][dy]==true;
        }
         if ((dx>diamond_x)&&((n2MapArray[dx-1][dy]!='*')&&(visited[dx-1][dy]==false))) {
            dx--;
            //move(dx,dy);
            attron(COLOR_PAIR(2));
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            mvaddch(dx,dy,'M');
            attroff(COLOR_PAIR(2));  
            mvaddch(dx+1,dy,'.');
            n2MapArray[dx+1][dy]='.';
            visited[dx-1][dy]==true;
        }
        if ((dy<diamond_y)&&((n2MapArray[dx][dy+1]!='*')&&(visited[dx][dy+1]==false))) {
            dy++;
            //move(dx,dy);
            attron(COLOR_PAIR(2));
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            mvaddch(dx,dy,'M');
            attroff(COLOR_PAIR(2));  
            mvaddch(dx,dy-1,'.');
            n2MapArray[dx][dy-1]='.';
            visited[dx][dy+1]==true;
        }
        if ((dy>diamond_y)&&((n2MapArray[dx][dy-1]!='*')&&(visited[dx][dy-1]==false))) {
            dy--;
            //move(dx,dy);
            attron(COLOR_PAIR(2));
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            mvaddch(dx,dy,'M');
            attroff(COLOR_PAIR(2));  
            mvaddch(dx,dy+1,'.');
            n2MapArray[dx][dy+1]='.';
            visited[dx][dy-1]==true;
        }
        *d=dx;
        *y=dy;
        if(n2MapArray[dx][dy]=='#')
        {
            return;
        }
}*/
void Bot::bfs(char n2MapArray[15][15],int diamond_x , int diamond_y)
{
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    queue <pair<int, int>> q;
    q.push({dx, dy});
    dist[dx][dy] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx1[i];
            int ny = y + dy1[i];
            if (nx >= 0 && nx < 15 && ny >= 0 && ny < 15 && n2MapArray[nx][ny] != '*' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = i;
                q.push({nx, ny});
                if (nx == diamond_x && ny == diamond_y) {
                    return;
                }
            }
        }
    }
}

vector<int> Bot::get_path(int diamond_x,int diamond_y)
{
    vector<int> path;
    int x = diamond_x, y = diamond_y;
    while (parent[x][y] != -1) {
        int d = parent[x][y];
        path.push_back(d);
        x -= dx1[d];
        y -= dy1[d];
    }
    reverse(path.begin(), path.end());
    return path;
}
void Bot::move_e(char n2MapArray[15][15],int d,int d_x,int d_y,int *found)
{
    n2MapArray[dx][dy]='.';
    mvaddch(dx,dy,'.');
    dx += dx1[d];
    dy += dy1[d];
    //attron(COLOR_PAIR(2));
    //init_pair(1,COLOR_GREEN,COLOR_BLACK);
    mvaddch(dx,dy,'M');
    //attroff(COLOR_PAIR(2));  
    if(dx==d_x && dy==d_y)
    {
        *found=1;
    }

}

