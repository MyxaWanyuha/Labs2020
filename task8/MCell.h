#pragma once
class Maze;
class MCell
{
public:
	friend Maze;
	bool right() const noexcept { return m_right; }
	bool down() const noexcept { return m_down; }
private:
	MCell() {};
	bool m_down = false;
	bool m_right = false;
};

