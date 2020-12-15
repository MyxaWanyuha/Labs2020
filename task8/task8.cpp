#include <iostream>
#include "Maze.h"
#include "MTreeNode.h"
class Maze;
class MTreeNode;

void PrintTreeLadder()
{
    const int mazeDim = 5;
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
    Maze maze(5, 5);
    for (int i = -1; i < 4; i++)
    {
        maze.makeConnection(i, i + 1, i + 1, i + 1);
        maze.makeConnection(i + 1, i + 1, i + 1, i + 2);
    }
    maze.printMaze();
    std::cout << '\n';

    PrintTreeLadder();
    return 0;
}
