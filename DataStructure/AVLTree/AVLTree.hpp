#ifndef _AVLTREE_HPP_
#define _AVLTREE_HPP_

#include <assert.h>
#include <vector>
struct AVLTNode
{
	int value;
	AVLTNode *left;
	AVLTNode *right;
	int height;

	AVLTNode(int v):value(v), left(nullptr), right(nullptr), height(-1) {}
	inline int GetHeight()
	{
		int lheight = 0, rheight = 0;
		if (left)lheight = left->height;
		if (right)rheight = right->height;
		return lheight > rheight ? lheight : rheight + 1;
	}
};

class AVLTree
{
public:
	AVLTree():root(nullptr) {}
	AVLTree(const std::vector<int> &);
	~AVLTree();
	AVLTNode* SingleRotateWithLeft(AVLTNode *);
	AVLTNode* SingleRotateWithRight(AVLTNode *);
	AVLTNode* DoubleRotateWithLeftRight(AVLTNode *);
	AVLTNode* DoubleRotateWithRightLeft(AVLTNode *);
	AVLTNode* Insert(int v);
	AVLTNode* Insert(AVLTNode *);
private:
	AVLTNode *root;
};
AVLTree::AVLTree(const std::vector<int>& vec)
{
	for (auto e : vec)
		Insert(e);
}

AVLTNode* AVLTree::SingleRotateWithLeft(AVLTNode *pn)
{
	assert(nullptr != pn);
	AVLTNode *pr = pn->right;
	pn->right = pr->left;
	pr->left = pn;

	pn->height = pn->GetHeight();
	pr->height = pr->GetHeight();

	return pr;
}

AVLTNode* AVLTree::SingleRotateWithRight(AVLTNode *pn)
{
	assert(nullptr != pn);
	AVLTNode *pl = pn->left;
	pn->left = pl->right;
	pl->right = pn;

	pn->height = pn->GetHeight();
	pl->height = pl->GetHeight();

	return pl;
}

AVLTNode* AVLTree::DoubleRotateWithLeftRight(AVLTNode *pn)
{
	pn->left = SingleRotateWithLeft(pn->left);
	return SingleRotateWithRight(pn);
}

AVLTNode* AVLTree::DoubleRotateWithRightLeft(AVLTNode *pn)
{
	pn->right = SingleRotateWithRight(pn->right);
	return SingleRotateWithLeft(pn);
}

AVLTNode* AVLTree::Insert(AVLTNode* pn)
{
	//todo
}

AVLTNode* AVLTree::Insert(int v)
{
	AVLTNode *newNode = new AVLTNode(v);
	Insert(newNode);

	return nullptr;
}
#endif
