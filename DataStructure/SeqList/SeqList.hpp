/* 
	这是一个用C++实现的动态数组SeqList
	- 默认数据类型：int
	- 初始容量：3
	- 扩容方式：每次容量*2增加
*/

#ifndef _SEQLIST_HPP_
#define _SEQLIST_HPP_
#include <iostream>

typedef int DataType;

const int init_size = 15;

class SeqList {
private:
	DataType *array;
	size_t size;
	size_t capacity;

	void Check_capacity()
	{
		if (size < capacity)return;
		DataType *tmp = new DataType[capacity * 2];
		if (nullptr != tmp) {
			delete[] array;
			array = tmp;
			capacity *= 2;
			std::cout << "扩容成功" << std::endl;
		}
		else {
			std::cout << "申请内存错误！扩容失败！！" << std::endl;
			exit(1);
		}
	}
public:
	SeqList():array(nullptr), size(0), capacity(0)
	{
		std::cout << "构造" << std::endl;
	}

	void Init()
	{
		array = new DataType[init_size];
		size = 0;
		capacity = init_size;
		std::cout << "初始化" << std::endl;
	}

	SeqList(const SeqList& s)
	{
		DataType *tmp = new DataType[s.capacity];
		if (nullptr != tmp)
		{
			for (int i = 0; i < (int)s.capacity; ++i)
			{
				tmp[i] = s.array[i];
			}
			array = tmp;
			size = s.size;
			capacity = s.capacity;
		}
		else {
			std::cout << "申请内存错误！拷贝构造失败！！" << std::endl;
			exit(1);
		}
		std::cout << "拷贝构造" << std::endl;
	}

	const SeqList* operator=(const SeqList& s)
	{
		SeqList tmpSeqList(s);
		DataType* tmp = array;
		array = tmpSeqList.array;
		tmpSeqList.array = tmp;

		size = s.size;
		capacity = s.capacity;
		std::cout << "赋值运算符重载" << std::endl;
		return this;
	}

	~SeqList()
	{
		if (array)
		{
			delete[] array;
			array = nullptr;
		}
		size = 0;
		capacity = 0;
		std::cout << "析构" << std::endl;
	}

	void PushBack(const DataType& d)
	{
		Check_capacity();
		array[size++] = d;
		std::cout << "尾插" << std::endl;
	}

	void PopBack()
	{
		if (0 == size) {
			std::cout << "数组为空！尾删失败！！" << std::endl;
			exit(2);
		}
		--size;
		std::cout << "尾删" << std::endl;
	}

	bool inline Empty()const
	{
		return 0 == size;
	}

	size_t inline Size()const
	{
		return size;
	}

	void inline Clear()
	{
		size = 0;
	}
};

#endif