#ifndef _SEQLIST_HPP_
#define _SEQLIST_HPP_
#include <iostream>

typedef int DataType;

const int init_size = 3;

class SeqList {
private:
	DataType *array;
	size_t size;
	size_t capacity;
public:
	SeqList():array(new DataType[init_size]), size(0), capacity(init_size)
	{
		std::cout << "¹¹Ôì" << std::endl;
	}

	SeqList(const SeqList& s)
	{
		DataType *tmp = new DataType[s.capacity];
		if (nullptr != tmp)
		{
			for (int i = 0; i < s.capacity; ++i)
			{
				tmp[i] = s.array[i];
			}
			array = tmp;
			size = s.size;
			capacity = s.capacity;
		}
		else {
			std::cout << "ÉêÇëÄÚ´æÊ§°Ü" << std::endl;
			exit(1);
		}
		std::cout << "¿½±´¹¹Ôì" << std::endl;
	}

	SeqList& operator=(const SeqList& s)
	{
		DataType *tmp = new DataType[s.capacity];
		if (nullptr != tmp)
		{
			for (int i = 0; i < s.capacity; ++i)
			{
				tmp[i] = s.array[i];
			}
			array = tmp;
			size = s.size;
			capacity = s.capacity;
		}
		else {
			std::cout << "ÉêÇëÄÚ´æÊ§°Ü" << std::endl;
			exit(2);
		}
		std::cout << "¸³ÖµÔËËã·ûÖØÔØ" << std::endl;
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
		std::cout << "Îö¹¹" << std::endl;
	}


};

#endif