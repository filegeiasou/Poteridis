#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
class Bot
{
    private:
        int dx , dy;
        int dist[15][15];
        int parent[15][15];
        int dx1[4] = {-1, 0, 1, 0};
        int dy1[4] = {0, 1, 0, -1};
    public:
        void spawn(char [15][15],int * ,int*);
        void move_b(char [15][15],int,int,int*,int*);
        void bfs(char [15][15],int,int);
        vector<int> get_path(int ,int);
        void move_e(char [15][15],int,int,int,int *);
};