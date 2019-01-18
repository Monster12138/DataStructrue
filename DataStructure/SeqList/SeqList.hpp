/* 
	����һ����C++ʵ�ֵĶ�̬����SeqList
	- Ĭ���������ͣ�int
	- ��ʼ������3
	- ���ݷ�ʽ��ÿ������*2����
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
			std::cout << "���ݳɹ�" << std::endl;
		}
		else {
			std::cout << "�����ڴ��������ʧ�ܣ���" << std::endl;
			exit(1);
		}
	}
public:
	SeqList():array(nullptr), size(0), capacity(0)
	{
		std::cout << "����" << std::endl;
	}

	void Init()
	{
		array = new DataType[init_size];
		size = 0;
		capacity = init_size;
		std::cout << "��ʼ��" << std::endl;
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
			std::cout << "�����ڴ���󣡿�������ʧ�ܣ���" << std::endl;
			exit(1);
		}
		std::cout << "��������" << std::endl;
	}

	const SeqList* operator=(const SeqList& s)
	{
		SeqList tmpSeqList(s);
		DataType* tmp = array;
		array = tmpSeqList.array;
		tmpSeqList.array = tmp;

		size = s.size;
		capacity = s.capacity;
		std::cout << "��ֵ���������" << std::endl;
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
		std::cout << "����" << std::endl;
	}

	void PushBack(const DataType& d)
	{
		Check_capacity();
		array[size++] = d;
		std::cout << "β��" << std::endl;
	}

	void PopBack()
	{
		if (0 == size) {
			std::cout << "����Ϊ�գ�βɾʧ�ܣ���" << std::endl;
			exit(2);
		}
		--size;
		std::cout << "βɾ" << std::endl;
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