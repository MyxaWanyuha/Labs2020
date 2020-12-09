#pragma once
class MCell
{
public:
	friend class Maze;
	bool right() const;
	bool down() const;
private:
	MCell();
	bool m_down = false;
	bool m_right = false;
};
