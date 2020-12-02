#pragma once
class MTreeNode
{
public:
	int i() const { return m_i; }
	int j() const { return m_j; }
	const MTreeNode* parent() const { return m_parent; }
	int distance() const { return m_distance; }
	const MTreeNode* child(int i) const;
	int childCount() const;
	bool addChild(int i, int j);
	MTreeNode* hasChild(int i, int j) const;
	static MTreeNode* beginTree(int i, int j);
	~MTreeNode() { delete[] m_children; };
private:
	MTreeNode* preOrderTravers(MTreeNode* root, int i, int j) const;
	MTreeNode* child(int i) { return  const_cast<MTreeNode*>(static_cast<const MTreeNode&>(*this).child(i)); }

	MTreeNode(MTreeNode* parent) : m_distance(parent ? parent->m_distance + 1 : 0), m_parent(parent) {};
	int m_i = -1;
	int m_j = -1;
	int m_distance = 0;
	MTreeNode* m_parent = nullptr;
	MTreeNode* m_children = nullptr;
};
