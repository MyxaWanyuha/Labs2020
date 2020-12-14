#include <iostream>
#include "Maze.h"
class Maze;
int main()
{
    Maze maze(5, 5);
    for (int i = -1; i < 4; i++)
    {
        auto iIncr = i + 1;
        maze.makeConnection(i, iIncr, iIncr, iIncr);
        maze.makeConnection(iIncr, iIncr, iIncr, iIncr + 1);
    }
    maze.printMaze();
    return 0;
}
