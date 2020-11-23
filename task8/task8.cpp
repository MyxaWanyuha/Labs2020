#include <iostream>
#include "Maze.h"

void PrintLadder()
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

    for (int i = 0; i < 4; i++)//remove all conections
    {
        auto iIncr = i + 1;
        maze.removeConnection(i, iIncr, iIncr, iIncr);
        maze.removeConnection(iIncr, iIncr, iIncr, iIncr + 1);
    }
    maze.printMaze();
    std::cout << '\n';
}

void PrintMazeWithAllSymbols()
{
    Maze maze(6, 6);
    /*
    0┐0000
    ┌┤0000
    ├┼┬┐00
    └┼┼┘00
    0│└┐00
    └┴─┘00
    */
    maze.makeConnection(0, 1, 1, 1);
    maze.makeConnection(1, 0, 1, 1);
    maze.makeConnection(1, 0, 2, 0);
    maze.makeConnection(1, 1, 2, 1);
    maze.makeConnection(2, 0, 2, 1);
    maze.makeConnection(2, 0, 3, 0);
    maze.makeConnection(2, 1, 2, 2);
    maze.makeConnection(2, 1, 3, 1);
    maze.makeConnection(2, 2, 2, 3);
    maze.makeConnection(2, 2, 3, 2);
    maze.makeConnection(2, 3, 3, 3);
    maze.makeConnection(3, 0, 3, 1);
    maze.makeConnection(3, 1, 3, 2);
    maze.makeConnection(3, 1, 4, 1);
    maze.makeConnection(3, 2, 3, 3);
    maze.makeConnection(3, 2, 4, 2);
    maze.makeConnection(4, 1, 5, 1);
    maze.makeConnection(4, 2, 4, 3);
    maze.makeConnection(4, 3, 5, 3);
    maze.makeConnection(5, 0, 5, 1);
    maze.makeConnection(5, 1, 5, 2);
    maze.makeConnection(5, 2, 5, 3);
    maze.printMaze();
}

int main()
{
    PrintLadder();
    PrintMazeWithAllSymbols();
    return 0;
}
