#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <iostream>
#include <vector>
#include <cstdio>

class Heap
{
	typedef std::vector<int> int_vec;
private:
	int_vec _arr;
public:
	Heap(const int_vec& arr);
	void MakeHeap(const int_vec& arr);
	void Shift_up(int );
	void Shift_down(int,int);
};

Heap::Heap(const int_vec& arr = Heap::int_vec()):_arr(arr) {}

void Heap::Shift_up(int i)
{
	int flag = 1;
	if (0 == i)return;			//元素已到堆顶
	while (0 != i && flag)
	{
		if (_arr[i] < _arr[i / 2])			//元素小于父节点元素
			swap(_arr[i], _arr[i / 2]);		//交换
		else
			flag = 0;					//结束上浮
				
		i /= 2;								//处理父节点元素
	}
}

void Heap::Shift_down(int i, int size)
{
	int min_index, flag = 1;
	while (i * 2 <= size && flag)
	{
		if (_arr[i] > _arr[i * 2])
			min_index = i * 2;
		else
			min_index = i;

		if (i * 2 + 1 <= size)
		{
			if (_arr[i * 2 + 1] < min_index)
				min_index = i * 2 + 1;
			else
				min_index = i;
		}

		if (min_index != i)
		{
			swap(_arr[min_index], _arr[i]);
			i = min_index;
		}
		else
			flag = 0;
	}
}

#endif
