#include "Maze.h"
#include <algorithm>
#include <iostream>

Maze::~Maze()
{
    delete[] m_field;
}

const MCell& Maze::cell(int i, int j) const
{
    return m_field[i * n + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2) const
{
    if (std::abs(i1 - i2) > 1 || std::abs(j1 - j2) > 1
        || i1 >= n || i2 >= n || j1 >= m || j2 >= m
        || i1 < 0 || j1 < 0 || i2 < 0 || j2 < 0)
        return false;

    if (i2 < i1)
        std::swap(i1, i2);
    else if (j2 < j1)
        std::swap(j1, j2);

    return i1 != i2 && cell(i1, j1).down() || j1 != j2 && cell(i1, i2).right();
}


bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
    if(std::abs(i1 - i2) > 1 || std::abs(j1 - j2) > 1
        || i1 >= n || i2 >= n || j1 >= m || j2 >= m
        || i1 < 0 || j1 < 0 || i2 < 0 || j2 < 0)
        return false;

    if (i2 < i1)
        std::swap(i1, i2);
    else if (j2 < j1)
        std::swap(j1, j2);

    if (i1 < i2 && j1 == j2)
    {
        m_field[i1 * n + j1].m_down = true;
        return true;
    }
    if (j1 < j2 && i1 == i2)
    {
        m_field[i1 * n + j1].m_right = true;
        return true;
    }
    return false;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
    if (std::abs(i1 - i2) > 1 || std::abs(j1 - j2) > 1
        || i1 >= n || i2 >= n || j1 >= m || j2 >= m
        || i1 < 0 || j1 < 0 || i2 < 0 || j2 < 0)
        return false;

    if (i2 < i1)
        std::swap(i1, i2);
    else if (j2 < j1)
        std::swap(j1, j2);

    if (i1 < i2 && j1 == j2)
    {
        m_field[i1 * n + j1].m_down = true;
        return true;
    }
    if (j1 < j2 && i1 == i2)
    {
        m_field[i1 * n + j1].m_right = false;
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
            MCell beyond;
            auto upCell = (i - 1) < 0 ? beyond : cell(i - 1, j);
            auto leftCell = (j - 1) < 0 ? beyond : cell(i, j - 1);

            auto countConnections = 0;
            countConnections += upCell.down() ? 1 : 0;
            countConnections += leftCell.right() ? 1 : 0;
            countConnections += cell(i, j).down() ? 1 : 0;
            countConnections += cell(i, j).right() ? 1 : 0;

            if (countConnections < 2)
            {
                std::cout << '0';
                continue;
            }

            if (cell(i, j).down() && !cell(i, j).right())//down
            {
                if (upCell.down() && !leftCell.right())
                    std::cout << static_cast<uint8_t>(179);// │
                else if (upCell.down() && leftCell.right())
                    std::cout << static_cast<uint8_t>(180);// ┤
                else
                    std::cout << static_cast<uint8_t>(191);// ┐
            }
            else if (!cell(i, j).down() && cell(i, j).right())//right
            {
                if (!upCell.down() && leftCell.right())
                    std::cout << static_cast<uint8_t>(196);// ─
                else if (upCell.down() && leftCell.right())
                    std::cout << static_cast<uint8_t>(193);// ┴
                else
                    std::cout << static_cast<uint8_t>(192);// └
            }
            else if (cell(i, j).down() && cell(i, j).right())//down and right
            {
                if (!upCell.down() && leftCell.right())
                    std::cout << static_cast<uint8_t>(194);// ┬
                else if (upCell.down() && !leftCell.right())
                    std::cout << static_cast<uint8_t>(195);// ├
                else if (upCell.down() && leftCell.right())
                    std::cout << static_cast<uint8_t>(197);// ┼
                else
                    std::cout << static_cast<uint8_t>(218);// ┌
            }
            else if (upCell.down() && leftCell.right())
                std::cout << static_cast<uint8_t>(217);// ┘
            else
                std::cout << '0';
        }
        std::cout << '\n';
    }
}
