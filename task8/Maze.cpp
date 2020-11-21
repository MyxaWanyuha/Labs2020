#include "Maze.h"
#include <iostream>

bool Maze::hasConnection(int i1, int j1, int i2, int j2) const
{
    return i1 < i2 && cell(i1, j1).right() || j1 < j2 && cell(i1, j1).down();
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
    if (i1 < i2 && j1 == j2)
    {
        cell(i1, j1).m_right = true;
        return true;
    }
    if (j1 < j2 && i1 == i2)
    {
        cell(i1, j1).m_down = true;
        return true;
    }
    return false;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
    if (i1 < i2 && j1 == j2)
    {
        cell(i1, j1).m_right = false;
        return true;
    }
    if (j1 < j2 && i1 == i2)
    {
        cell(i1, j1).m_down = false;
        return true;
    }
    return false;
}

void Maze::printMaze() const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (hasConnection(i, j, i + 1, j))
                std::cout << (char)191;
            else if(hasConnection(i, j, i, j + 1))
                std::cout << (char)192;
            else
                std::cout << 0;
        }
        std::cout << '\n';
    }
}
