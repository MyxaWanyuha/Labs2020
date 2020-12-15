#pragma once
class MTreeNode
{
public:
	int i() const;
	int j() const;
	const MTreeNode* parent() const;
	int distance() const;
	const MTreeNode* child(int i) const;
	int childCount() const;
	bool addChild(int i, int j);
	MTreeNode* hasChild(int i, int j) const;
	static MTreeNode* beginTree(int i, int j);
	~MTreeNode();
private:
	MTreeNode(MTreeNode* parent);
	int m_i = -1;
	int m_j = -1;
	int m_distance = 0;
	MTreeNode* m_parent = nullptr;
	MTreeNode* m_children = nullptr;
};
