#include "MTreeNode.h"

const MTreeNode* MTreeNode::child(int i) const
{
	if (i < 0 || i > 1)
		return nullptr;
	return m_children + i;
}

void checkCount(const MTreeNode* root, int& count)
{
	if (root)
	{
		count++;
		checkCount(root->child(0), count);
		checkCount(root->child(1), count);
	}
}

int MTreeNode::childCount() const
{
	auto count = -1;
	checkCount(this, count);
	return count;
}

bool MTreeNode::addChild(int i, int j)
{
	if(!m_children)
		m_children = new MTreeNode[2]{ this, this };

	auto c0i = child(0)->m_i;
	auto c1j = child(1)->m_j;
	if (child(0)->m_i >= 0 && child(0)->m_i <= i)
		return child(0)->addChild(i, j);
	if (child(1)->m_j >= 0 && child(1)->m_j <= j)
		return child(1)->addChild(i, j);

	auto index = -1;
	if (i > m_i && j == m_j)
		index = 0;
	else if (j > m_j && i == m_i)
		index = 1;
	else
		return false;
	auto childptr = child(index);
	childptr->m_i = i;
	childptr->m_j = j;
	return true;
}


MTreeNode* MTreeNode::preOrderTravers(MTreeNode* root, int i, int j) const
{
	if (root)
	{
		if (root->m_i == i && root->m_j == j)
			return root;

		auto left = root->m_children ? preOrderTravers(root->child(0), i, j) : nullptr;
		if (left)
			return left;

		auto right = root->m_children ? preOrderTravers(root->child(1), i, j) : nullptr;
		if (right)
			return right;
	}
	return nullptr;
}

MTreeNode* MTreeNode::hasChild(int i, int j) const
{
	return preOrderTravers(const_cast<MTreeNode*>(this), i, j);
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	auto root = new MTreeNode(nullptr);
	root->m_i = i;
	root->m_j = j;
	return root;
}
