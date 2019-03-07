#ifndef _BSTREE_HPP_
#define _BSTREE_HPP_

#include <vector>
#include <assert.h>
/*
�����������Binary Search Tree�������֣�������������������������
��������һ�ÿ����������Ǿ����������ʵĶ������� 

- ���������������գ��������������н���ֵ��С�����ĸ�����ֵ�� 
- ���������������գ��������������н���ֵ���������ĸ�����ֵ�� 
- ������������Ҳ�ֱ�Ϊ������������
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
	void InsertNode(int v);
	void DeleteNode(int v);
	void DeleteNode(BSTNode *pNode);
	BSTNode* FindByValue(int v);

#if 0
	BSTNode* GetSuccessor(int v);
	BSTNode* GetSuccessor(BSTNode *pNode);

	BSTNode* GetPredecessor(int v);
	BSTNode* GetPredecessor(BSTNode *pNode);
#endif
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
		Ҫɾ���Ľ���޺��ӽ��
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
		Ҫɾ���Ľ������ֻ��һ�����ӽ��
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
		Ҫɾ���Ľ�����������ӽ��
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

//����ɣ�����һ������ǰ�����̽��
#if 0
BSTNode* MyBST::GetSuccessor(BSTNode *pNode)
{
	assert(nullptr != pNode);

	BSTNode *cur = pNode, *child;
	if (cur->BothLRareNull())
	{
		if (nullptr != cur->parent && cur == cur->parent->left)
		{
			return cur->parent;
		}
		while (nullptr != cur->parent && cur == cur->parent->right)
		{
			cur = cur->parent;
			if (nullptr != cur->parent && cur == cur->parent->left)
			{
				return cur->parent;
			}
		}
	}
	else if (child = cur->LorRisNull())
	{
		if (child == cur->right)
			return child;
		else
		{
			cur = cur->parent;
			//todo
		}
	}
}

BSTNode* MyBST::GetPredecessor(BSTNode *pNode)
{
	assert(nullptr != pNode);

}

BSTNode* MyBST::GetSuccessor(int v)
{

}

BSTNode* MyBST::GetPredecessor(int v)
{

}
#endif
#endif // !_BSTREE_HPP_

