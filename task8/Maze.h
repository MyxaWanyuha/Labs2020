#pragma once
#include "MCell.h"
class MCell;
class Maze
{
public:
	Maze(int n, int m) : m_field(new MCell[(long long)n * m]), n(n), m(m) {}
	~Maze();
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2) const;
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze() const;
private:
	Maze() = delete;
	MCell* m_field;
	int n;
	int m;
};
