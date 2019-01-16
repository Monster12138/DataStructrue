#include "SeqList\SeqList.hpp"
#include "LinkList\LinkList.hpp"
#include <my_check_mem.h>
#include <iostream>
using namespace std;

int main()
{
	atexit(memCheck);
	LinkList l1;
	l1.PushBack(1);
	l1.PopBack();
	l1.PushFront(2);
	l1.PopFront();
#if 0
	SeqList s1;
	SeqList s2;
	s1.Init();
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	s2 = s1;
	cout << s2.Size() << endl;
	if (!s1.Empty()) {
		s1.Clear();
	}
	cout << s1.Size() << endl;
#endif
	return 0;
}

