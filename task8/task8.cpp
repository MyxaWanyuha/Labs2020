#include <iostream>
#include "Maze.h"
#include "MTreeNode.h"

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

void PrintTreeLadder()
{
    /* Function output
    ┌┬──0
    │├┬─0
    ││├┬0
    │││├┐
    00000

    0 1 2 3 4
    1 2 3 4 5
    2 3 4 5 6
    3 4 5 6 7
    4 5 6 7 8
    */
    Maze maze(mazeDim, mazeDim);

    for (int x = -1; x < mazeDim - 1; x++)
    {
        for (int i = x; i < mazeDim; i++)
            maze.makeConnection(i, x + 1, i + 1, x + 1);
        for (int j = x; j < mazeDim; j++)
            maze.makeConnection(x, j, x, j + 1);
    }
    maze.printMaze();
    std::cout << '\n';

    auto root = MTreeNode::beginTree(0, 0);
    for (int i = 0; i < mazeDim; i++)
        for (int j = 0; j < mazeDim; j++)
        {
            if (maze.hasConnection(i, j, i + 1, j) && !root->hasChild(i + 1, j))
                root->addChild(i + 1, j);
            if (maze.hasConnection(i, j, i, j + 1) && !root->hasChild(i, j + 1))
                root->addChild(i, j + 1);
        }

    for (int i = 0; i < mazeDim; i++)
    {
        for (int j = 0; j < mazeDim; j++)
        {
            auto point = root->hasChild(i, j);
            if (point)
                std::cout << point->distance() << ' ';
        }
        std::cout << '\n';
    }
    delete root;
}

int main()
{
    PrintLadder();
    PrintTreeLadder();
    return 0;
}
