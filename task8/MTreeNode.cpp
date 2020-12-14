#include "MTreeNode.h"

int MTreeNode::i() const
{
	return m_i;
}

int MTreeNode::j() const
{
	return m_j;
}

const MTreeNode* MTreeNode::parent() const
{
	return m_parent;
}

int MTreeNode::distance() const
{
	return m_distance;
}

const MTreeNode* MTreeNode::child(int i) const
{
	if (i < 0 || i > 1)
		return nullptr;
	return m_children + i;
}

int MTreeNode::childCount() const
{
	if (!m_children) return 0;
	auto count = 0;
	count += this->child(0)->childCount();
	count += this->child(1)->childCount();
	return count;
}

bool MTreeNode::addChild(int i, int j)
{
	if(!m_children)
		m_children = new MTreeNode[2]{ this, this };

	if (child(0)->m_i >= 0 && child(0)->m_i <= i)
		return m_children[0].addChild(i, j);

	if (child(1)->m_j >= 0 && child(1)->m_j <= j)
		return m_children[1].addChild(i, j);

	auto index = -1;
	if (i > m_i && j == m_j)
		index = 0;
	else if (j > m_j && i == m_i)
		index = 1;
	else
		return false;
	m_children[index].m_i = i;
	m_children[index].m_j = j;
	return true;
}

MTreeNode* MTreeNode::hasChild(int i, int j) const
{
	if (this->m_i == i && this->m_j == j)
		return const_cast<MTreeNode*>(this);

	auto left = this->m_children ? m_children[0].hasChild(i, j) : nullptr;
	if (left)
		return left;

	auto right = this->m_children ? m_children[1].hasChild(i, j) : nullptr;
	if (right)
		return right;
	return nullptr;
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	auto root = new MTreeNode(nullptr);
	root->m_i = i;
	root->m_j = j;
	return root;
}

MTreeNode::~MTreeNode()
{
	delete[] m_children;
}
