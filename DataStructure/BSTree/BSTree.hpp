#ifndef _BSTREE_HPP_
#define _BSTREE_HPP_

#include <vector>
#include <assert.h>
/*
二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）
它或者是一棵空树，或者是具有下列性质的二叉树： 

- 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
- 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 
- 它的左、右子树也分别为二叉排序树。
*/

struct BSTNode
{
	int value;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;

	BSTNode(int v = 0):
		value(v),
		left(nullptr),
		right(nullptr),
		parent(nullptr)
	{}

	bool BothLRareNull()
	{
		return nullptr == left && nullptr == right;
	}

	BSTNode* LorRisNull()
	{
		if (nullptr != left && nullptr != right) return nullptr;
		return left ? left : right;
	}
};

class MyBST
{
public:
	MyBST() :root(nullptr) {};
	MyBST(const std::vector<int>&);
	void DisCharge(BSTNode *&);
	~MyBST();
	void InsertNode(int v);
	void DeleteNode(int v);
	void DeleteNode(BSTNode *pNode);
	BSTNode* FindByValue(int v);

	BSTNode* GetSuccessor(int v);
	BSTNode* GetSuccessor(BSTNode *pNode);

	BSTNode* GetPredecessor(int v);
	BSTNode* GetPredecessor(BSTNode *pNode);

	BSTNode* GetRoot() { return root; }
private:
	BSTNode *root;
};

MyBST::MyBST(const std::vector<int>& vec)
{
	for (auto e : vec)
	{
		InsertNode(e);
	}
}

void MyBST::InsertNode(int v)
{
	if (nullptr == root)
	{
		root = new BSTNode(v);
		return;
	}

	BSTNode *cur = root, *last = nullptr;
	while (nullptr != cur)
	{
		if (cur->value > v)
		{
			last = cur;
			cur = cur->left;
		} 
		else if(cur->value < v){
			last = cur;
			cur = cur->right;
		}
		else {
			return;
		}
	}

	BSTNode *newNode = new BSTNode(v);
	newNode->parent = last;

	if (last->value > v)
		last->left = newNode;
	else
		last->right = newNode;
}

void MyBST::DeleteNode(BSTNode *pNode)
{
	assert(pNode != nullptr);

	/*
		要删除的结点无孩子结点
	*/
	if (pNode->BothLRareNull())
	{
		if (pNode == pNode->parent->left)
			pNode->parent->left = nullptr;
		else
			pNode->parent->right = nullptr;

		delete pNode;
		return;
	}

	/*
		要删除的结点有且只有一个孩子结点
	*/
	BSTNode *child;
	if (child = pNode->LorRisNull())
	{
		if (pNode == pNode->parent->left)
			pNode->parent->left = child;
		else
			pNode->parent->right = child;

		child->parent = pNode->parent;
		delete pNode;
	}

	/*
		要删除的结点有两个孩子结点
	*/
	BSTNode *cur = pNode->right;
	while (nullptr != cur->left)
		cur = cur->left;

	pNode->value = cur->value;
	DeleteNode(cur);
}

void MyBST::DeleteNode(int v)
{
	BSTNode *pNode = FindByValue(v);
	if (pNode)
		DeleteNode(pNode);
}

BSTNode* MyBST::FindByValue(int v)
{
	if (nullptr == root)return nullptr;

	BSTNode *cur = root;
	while (cur)
	{
		if (cur->value > v)cur = cur->left;
		else if (cur->value < v)cur = cur->right;
		else return cur;
	}
	return cur;
}

//待完成：查找一个结点的前驱或后继结点
#if 1
BSTNode* MyBST::GetSuccessor(BSTNode *pNode)
{
	assert(nullptr != pNode);

	if (pNode->right)
	{
		BSTNode *cur = pNode->right;
		while (cur->left)
		{
			cur = cur->left;
		}
		return cur;
	}
	if (pNode->parent)
	{
		BSTNode *cur = pNode->parent;
		while (nullptr != cur->parent && cur != cur->parent->left)
			cur = cur->parent;

		return cur->parent;
	}
	else
	{
		return nullptr;
	}
}

BSTNode* MyBST::GetPredecessor(BSTNode *pNode)
{
	assert(nullptr != pNode);
	if (pNode->left)
	{
		BSTNode *cur = pNode->left;
		while (cur->right)
		{
			cur = cur->right;
		}
		return cur;
	}

	if (pNode->parent)
	{
		BSTNode *cur = pNode->parent;
		while (nullptr != cur->parent && cur != cur->parent->right)
			cur = cur->parent;

		return cur->parent;
	}
	else
	{
		return nullptr;
	}
}

BSTNode* MyBST::GetSuccessor(int v)
{
	return GetSuccessor(FindByValue(v));
}

BSTNode* MyBST::GetPredecessor(int v)
{
	return GetPredecessor(FindByValue(v));
}

void MyBST::DisCharge(BSTNode *&pNode)
{
	if (nullptr == pNode)return;

	DisCharge(pNode->left);
	DisCharge(pNode->right);

	if (pNode->BothLRareNull())
	{
		if (nullptr == pNode->parent)
		{
			delete pNode;
			pNode = nullptr;
			return;
		}
		if (pNode == pNode->parent->right)
		{
			pNode->parent->right = nullptr;
		}
		else
		{
			pNode->parent->left = nullptr;
		}
		delete pNode;
		pNode = nullptr;
		return;
	}
}

MyBST::~MyBST()
{
	DisCharge(root);
}
#endif
#endif // !_BSTREE_HPP_

