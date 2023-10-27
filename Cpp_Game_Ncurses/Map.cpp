#include "Map.h"
#include<ncurses.h>
#include <iostream>
#include<fstream>
#include <string>
using namespace std;
void Map::display(char n2MapArray[15][15])
{
    for (int y = 0; y < 15; y++) {          
        for (int x = 0; x <15; x++) {
            mvaddch(y,x,n2MapArray[y][x]);
        }
    }
}
void Map::create(char argv[])
{
    ifstream mymap(argv);
    int g=0;
    string text;
    while(getline(mymap,text))
    {
        for(int i=0; i<=15; i++)
        {
            example_array[g][i] = text[i];   
        }
        g++;
    }
}
char(* Map ::getArray())[15]
{
    return example_array;
}
