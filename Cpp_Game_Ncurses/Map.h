#ifndef MAP_H
#define MAP_H
class Map
{
    private:
        char example_array[15][15];
    public:
        void display(char [15][15]);
        void create(char []);
        char(*getArray())[15];
};

#endif
