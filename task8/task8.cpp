#include <iostream>
#include "Maze.h"

constexpr int mazeDim = 5;
void PrintLadder()
{
    /* Function output
    0┐000
    0└┐00
    00└┐0
    000└┐
    00000

    */
    Maze maze(mazeDim, mazeDim);
    for (int i = 0; i < 4; i++)
    {
        auto iIncr = i + 1;
        maze.makeConnection(i, iIncr, iIncr, iIncr);
        maze.makeConnection(iIncr, iIncr, iIncr, iIncr + 1);
    }
    maze.printMaze();
    std::cout << '\n';
}

int main()
{
    PrintLadder();
    return 0;
}
