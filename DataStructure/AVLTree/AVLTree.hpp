#ifndef _AVLTREE_HPP_
#define _AVLTREE_HPP_

#include <assert.h>
#include <vector>
struct AVLTNode
{
	int value;
	AVLTNode *left;
	AVLTNode *right;
	AVLTNode *parent;
	int bf;

	AVLTNode(int v):value(v), 
		left(nullptr), right(nullptr),
		parent(nullptr), bf(0)
	{}

	inline int GetHeight()
	{
		if (nullptr == this)return -1;
		int lheight = left->GetHeight();
		int rheight = right->GetHeight();
		return (lheight > rheight? lheight:rheight) + 1;
	}
};

class AVLTree
{
public:
	AVLTree():root(nullptr) {}
	AVLTree(const std::vector<int> &);
	~AVLTree();
	AVLTNode* SingleRotateLL(AVLTNode *);
	AVLTNode* SingleRotateRR(AVLTNode *);
	AVLTNode* DoubleRotateLR(AVLTNode *);
	AVLTNode* DoubleRotateRL(AVLTNode *);
	AVLTNode* Insert(int);
	AVLTNode* Insert(AVLTNode *);
	void DeleteNode(AVLTNode *);
	void DeleteNode(int);
	AVLTNode* Find(int);
private:
	AVLTNode *root;
	void DisCharge(AVLTNode *&);
};
AVLTree::AVLTree(const std::vector<int>& vec)
{
	for (auto e : vec)
		Insert(e);
}

AVLTNode* AVLTree::SingleRotateRR(AVLTNode *pn)
{
	assert(nullptr != pn);

	AVLTNode *cur = pn->right;

	pn->right = cur->left;
	if(cur->left)cur->left->parent = pn;

	cur->left = pn;
	cur->parent = pn->parent;
	pn->parent = cur;

	return cur;
}

AVLTNode* AVLTree::SingleRotateLL(AVLTNode *pn)
{
	assert(nullptr != pn);
	
	AVLTNode *cur = pn->left;

	pn->left = cur->right;
	if (cur->right)cur->right->parent = pn;

	cur->right = pn;
	cur->parent = pn->parent;
	pn->parent = cur;

	return cur;
}

AVLTNode* AVLTree::DoubleRotateLR(AVLTNode *pn)
{
	pn->left = SingleRotateRR(pn->left);
	return SingleRotateLL(pn);
}

AVLTNode* AVLTree::DoubleRotateRL(AVLTNode *pn)
{
	pn->right = SingleRotateLL(pn->right);
	return SingleRotateRR(pn);
}

AVLTNode* AVLTree::Insert(AVLTNode* pn)
{
	assert(nullptr != pn);
	AVLTNode *cur = root;
	while (cur)
	{
		if (cur->value < pn->value)
		{
			if (nullptr == cur->right)
			{
				cur->right = pn;
				pn->parent = cur;
				++cur->bf;
				break;
			}
			else
				cur = cur->right;
		}
		else if (cur->value > pn->value)
		{
			if (nullptr == cur->left)
			{
				cur->left = pn;
				pn->parent = cur;
				--cur->bf;
				break;
			}
			else
				cur = cur->left;
		}
		else
			return cur;
	}

	if (nullptr == root)
	{
		root = pn;
		return root;
	}

	if (0 == cur->bf)return root;

	AVLTNode *parent = cur->parent;
	while ( cur != root && cur->bf != 0)
	{
		parent = cur->parent;
		if (cur == parent->left)--parent->bf;
		else ++parent->bf;
			
		if (abs(parent->bf) > 1)break;
		cur = parent;
		if (parent == root)return root;
	}

	if (parent && abs(parent->bf) > 1)
	{
		if (cur == parent->left)
		{
			if (pn->value < cur->value)
			{
				if (parent == root)root = SingleRotateLL(parent);
				else parent->parent = SingleRotateLL(parent);
			}
			else
			{
				if (parent == root)root = DoubleRotateLR(parent);
				else parent->parent = DoubleRotateLR(parent);
			}
		}
		else
		{
			if (pn->value > cur->value)
			{
				if (parent == root)root = SingleRotateRR(parent);
				else parent->parent = SingleRotateRR(parent);
			}
			else
			{
				if (parent == root)root = DoubleRotateRL(parent);
				else parent->parent = DoubleRotateRL(parent);
			}
		}
	}
	return root;
}

AVLTNode* AVLTree::Insert(int v)
{
	AVLTNode *newNode = new AVLTNode(v);
	
	return Insert(newNode);;
}

void AVLTree::DisCharge(AVLTNode *&pNode)
{
	if (nullptr == pNode)return;

	DisCharge(pNode->left);
	pNode->left = nullptr;
	DisCharge(pNode->right);
	pNode->right = nullptr;

	delete pNode;
	pNode = nullptr;
}

AVLTNode* AVLTree::Find(int v)
{
	if (nullptr == root)return nullptr;

	AVLTNode *cur = root;
	while (cur)
	{
		if (cur->value > v)cur = cur->left;
		else if (cur->value < v)cur = cur->right;
		else return cur;
	}
	return cur;
}

void AVLTree::DeleteNode(AVLTNode *pNode)
{
	assert(pNode != nullptr);

	AVLTNode *parent = root;
	AVLTNode *child;
	while (parent)
	{
		if (parent->left == pNode || parent->right == pNode)
			break;
		if (parent->value > pNode->value)
			parent = parent->left;
		else if (parent->value < pNode->value)
			parent = parent->right;
		else
		{
			delete pNode;
			root = nullptr;
			return;
		}
	}
	/*
		要删除的结点不是此树中的结点
	*/
	if (nullptr == parent)return;

	/*
	要删除的结点无孩子结点
	*/
	if (nullptr == pNode->left && nullptr == pNode->right)
	{
		if (parent->left == pNode)parent->left = nullptr;
		else parent->right = nullptr;
		delete pNode;
	}

	/*
	要删除的结点有且只有一个孩子结点
	*/

	else if (((child = pNode->left) && nullptr == pNode->right) || ((child = pNode->right) && nullptr == pNode->left))
	{
		if (pNode == parent->left)
			parent->left = child;
		else
			parent->right = child;

		delete pNode;
	}

	/*
	要删除的结点有两个孩子结点
	*/
	else
	{
		AVLTNode *cur = pNode->right;
		while (nullptr != cur->left)
			cur = cur->left;

		pNode->value = cur->value;
		DeleteNode(cur);
	}

	if (root->left->GetHeight() - root->right->GetHeight() > 1)
	{
		AVLTNode* cur = root;
		while (cur->left)
		{
			cur = cur->left;
		}
		if (nullptr == cur->right)
			root = SingleRotateLL(root);
		else
			root = DoubleRotateLR(root);
	}
	else if (root->left->GetHeight() - root->right->GetHeight() < -1)
	{
		AVLTNode* cur = root;
		while (cur->right)
		{
			cur = cur->right;
		}
		if (nullptr == cur->left)
			root = SingleRotateRR(root);
		else
			root = DoubleRotateRL(root);
	}
}

void AVLTree::DeleteNode(int v)
{
	AVLTNode *pNode = Find(v);
	if (pNode)
		DeleteNode(pNode);
}

AVLTree::~AVLTree()
{
	DisCharge(root);
}
#endif
