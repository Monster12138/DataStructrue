/*
	����һ������˫��ѭ������ʵ�ֵĶ���
	- Ĭ����������:int
*/

#ifndef _QUEUE_HPP_ 
#define _QUEUE_HPP_

#include "../LinkList/LinkList.hpp"
typedef int DataType;

class Queue {
private:
	LinkList l;
public:
	Queue():l()
	{}

	Queue(const Queue& q) :l(q.l)
	{}

	const Queue* operator=(const Queue& q)
	{
		l = q.l;
		return this;
	}

	void Push(const DataType& data)
	{
		l.PushBack(data);
	}

	const DataType& Top()
	{
		return *l.Front();
	}

	void Pop()
	{
		l.PopFront();
	}
	
	size_t Size()
	{
		return l.Size();
	}

	bool Empty()
	{
		return l.Empty();
	}

	void Clear()
	{
		l.Clear();
	}
};

#endif // !_QUEUE_HPP_ 

