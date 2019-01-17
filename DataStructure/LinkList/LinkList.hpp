/*
	����һ����C++ʵ�֣���ͷ����˫��ѭ������
	- Ĭ����������:int
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
		std::cout << "����" << std::endl;
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
		std::cout << "����" << std::endl;
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
		std::cout << "��������" << std::endl;
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
		std::cout << "���" << std::endl;
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
		std::cout << "��ֵ���������" << std::endl;

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
		std::cout << "β��" << std::endl;
	}

	void PushFront(const DataType& d)
	{
		pListNode NewNode = new ListNode(d);

		head->next->prev = NewNode;
		NewNode->next = head->next;

		NewNode->prev = head;
		head->next = NewNode;

		++size;
		std::cout << "ͷ��" << std::endl;
	}

	void PopBack()
	{
		if (0 == size) {
			std::cout << "����Ϊ�գ�βɾʧ�ܣ���" << std::endl;
			exit(2);
		}

		pListNode del = head->prev;
		head->prev->prev->next = head;
		head->prev = head->prev->prev;

		delete del;
		del = nullptr;

		--size;
		std::cout << "βɾ" << std::endl;
	}

	void PopFront()
	{
		if (0 == size) {
			std::cout << "����Ϊ�գ�βɾʧ�ܣ���" << std::endl;
			exit(2);
		}

		pListNode del = head->next;
		head->next->next->prev = head;
		head->next = head->next->next;

		delete del;
		del = nullptr;

		--size;
		std::cout << "ͷɾ" << std::endl;
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
