#include <iostream>
#include "Maze.h"

int main()
{
    Maze maze(5, 5);

    for (int i = 0; i < 4; i++)
    {
        auto iIncr = i + 1;
        maze.makeConnection(i, iIncr, iIncr, iIncr);
        maze.makeConnection(iIncr, iIncr, iIncr, iIncr + 1);
    }
    maze.printMaze();

    std::cout << '\n';

    maze.removeConnection(0, 1, 1, 1);
    maze.removeConnection(1, 2, 2, 2);
    maze.removeConnection(4, 4, 4, 5);
    maze.printMaze();

    return 0;
}