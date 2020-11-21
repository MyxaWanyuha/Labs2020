#pragma once
#include "MCell.h"
class Maze
{
public:
	Maze(int n, int m) : m_field(new MCell[(long long)n * m]), n(n), m(m) {}
	~Maze() { delete m_field; }
	const MCell& cell(int i, int j) const { return m_field[i * n + j]; }
	bool hasConnection(int i1, int j1, int i2, int j2) const;
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze() const;
private:
	MCell& cell(int i, int j) { return const_cast<MCell&>(static_cast<const Maze&>(*this).cell(i, j)); }
	Maze() = delete;
	MCell* m_field;
	int n;
	int m;
};
