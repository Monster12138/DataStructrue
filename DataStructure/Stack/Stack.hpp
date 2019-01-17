/*
	����һ��C++ʵ�ֵ�ջ
	- Ĭ����������:int
*/

#ifndef _STACK_HPP_
#define _STACK_HPP_
#include <iostream>
typedef int DataType;

const int init_size = 5;

class Stack 
{
private:
	DataType *s;
	size_t size;
	size_t capacity;

	void CheckCapacity()
	{
		if (size == capacity)
		{
			DataType* tmp = new DataType[capacity * 2];
			for (int i = 0; i < (int)size; ++i)
			{
				tmp[i] = s[i];
			}
			delete[] s;
			s = tmp;
			capacity *= 2;
			std::cout << "���ݳɹ�" << std::endl;
		}
	}
public:
	Stack():s(new DataType[init_size]), size(0), capacity(init_size)
	{
		std::cout << "����" << std::endl;
	}

	~Stack()
	{
		if (nullptr != s)
		{
			delete[] s;
			s = nullptr;
 		}
		size = 0;
		capacity = 0;
		std::cout << "����" << std::endl;
	}

	void Clear()
	{
		size = 0;
		std::cout << "���" << std::endl;
	}

	Stack(const Stack& rs)
	{
		s = new DataType[rs.capacity];
		for (int i = 0; i < (int)rs.size; ++i)
		{
			s[i] = rs.s[i];
		}
		size = rs.size;
		capacity = rs.capacity;
		std::cout << "��������" << std::endl;
	}

	const Stack* operator=(const Stack& rs)
	{
		Stack tmpStack(rs);
		DataType* tmp = s;
		s = tmpStack.s;
		tmpStack.s = tmp;

		size = rs.size;
		capacity = rs.capacity;
		std::cout << "��ֵ���������" << std::endl;

		return this;
	}

	void Push(const DataType& data)
	{
		CheckCapacity();
		s[size++] = data;
		std::cout << "ѹջ" << std::endl;
	}

	const DataType Top()
	{
		if (0 == size)
		{
			std::cout << "ջΪ��!!" << std::endl;
			exit(2);
		}
		return s[size - 1];
	}

	void Pop()
	{
		if (0 == size)
		{
			std::cout << "ջΪ��!!" << std::endl;
			exit(2);
		}
		--size;
	}

	bool Empty()
	{
		return 0 == size;
	}

	size_t Size()
	{
		return size;
	}
};

#endif