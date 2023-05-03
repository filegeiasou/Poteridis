#include <ncurses.h>
class Player
{       
    private:
        int p_x ,p_y ; 
    public:
        void spawn( const char [15][15], int * , int *);
        int move_p(const char [15][15], int *, int* , int );
};