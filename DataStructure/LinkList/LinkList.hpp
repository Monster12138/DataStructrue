/*
	这是一个用C++实现，带头结点的双向循环链表
	- 默认数据类型:int
*/

#ifndef _LINKLIST_HPP_
#define _LINKLIST_HPP_

#include <iostream>	
typedef int DataType;

typedef struct ListNode{
	DataType data;
	struct ListNode* prev;
	struct ListNode* next;

	ListNode(DataType d = 0) :data(d), prev(nullptr), next(nullptr)
	{}
}ListNode, *pListNode;

class LinkList {
private:
	pListNode head;
	size_t size;
public:
	LinkList():head(new ListNode), size(0)
	{
		head->next = head;
		head->prev = head;
		std::cout << "构造" << std::endl;
	}

	~LinkList()
	{
		pListNode cur = head->next;
		while (head != cur)
		{
			pListNode tmp = cur->next;
			delete cur;
			cur = tmp;
		}

		delete head;
		head = nullptr;
		std::cout << "析构" << std::endl;
	}

	LinkList(const LinkList& l)
	{
		head = new ListNode;
		head->next = head;
		head->prev = head;

		pListNode cur = head,  lcur = l.head->next;
		while (lcur != l.head)
		{
			pListNode NewNode = new ListNode;
			NewNode->data = lcur->data;

			NewNode->prev = cur;
			cur->next = NewNode;

			NewNode->next = head;
			head->prev = NewNode;

			lcur = lcur->next;
			cur = cur->next;
		}
		size = l.size;
		std::cout << "拷贝构造" << std::endl;
	}

	void Clear()
	{
		pListNode cur = head->next;
		while (head != cur)
		{
			pListNode tmp = cur->next;
			delete cur;
			cur = tmp;
		}
		head->next = head;
		head->prev = head;
		size = 0;
		std::cout << "清空" << std::endl;
	}

	const LinkList* operator=(const LinkList& l)
	{
		Clear();
		pListNode cur = head, lcur = l.head->next;
		while (lcur != l.head)
		{
			pListNode NewNode = new ListNode;
			NewNode->data = lcur->data;

			NewNode->prev = cur;
			cur->next = NewNode;

			NewNode->next = head;
			head->prev = NewNode;

			lcur = lcur->next;
			cur = cur->next;
		}
		size = l.size;
		std::cout << "赋值运算符重载" << std::endl;

		return this;
	}

	void PushBack(const DataType& d)
	{
		pListNode NewNode = new ListNode(d);

		NewNode->prev = head->prev;
		head->prev->next = NewNode;

		NewNode->next = head;
		head->prev = NewNode;
		
		++size;
		std::cout << "尾插" << std::endl;
	}

	void PushFront(const DataType& d)
	{
		pListNode NewNode = new ListNode(d);

		head->next->prev = NewNode;
		NewNode->next = head->next;

		NewNode->prev = head;
		head->next = NewNode;

		++size;
		std::cout << "头插" << std::endl;
	}

	void PopBack()
	{
		if (0 == size) {
			std::cout << "链表为空！尾删失败！！" << std::endl;
			exit(2);
		}

		pListNode del = head->prev;
		head->prev->prev->next = head;
		head->prev = head->prev->prev;

		delete del;
		del = nullptr;

		--size;
		std::cout << "尾删" << std::endl;
	}

	void PopFront()
	{
		if (0 == size) {
			std::cout << "链表为空！尾删失败！！" << std::endl;
			exit(2);
		}

		pListNode del = head->next;
		head->next->next->prev = head;
		head->next = head->next->next;

		delete del;
		del = nullptr;

		--size;
		std::cout << "头删" << std::endl;
	}

	size_t Size()
	{
		return size;
	}

	bool Empty()
	{
		return 0 == size;
	}
};
#endif
