//#include "SeqList\SeqList.hpp"
//#include "LinkList\LinkList.hpp"
//#include "Stack\Stack.hpp"
//#include "Queue\Queue.hpp"
//#include "BSTree\BSTree.hpp"
//#include <my_check_mem.h>
#include "AVLTree\AVLTree.hpp"
//#include "Heap.hpp"
#include <iostream>
using namespace std;

int main()
{
	//atexit(memCheck);

	AVLTree avlt;
	avlt.Insert(40);
	avlt.Insert(30);
	avlt.Insert(50);
	avlt.Insert(45);
	avlt.Insert(60);
	avlt.Insert(44);



	//¶þ²æËÑË÷Ê÷²âÊÔ
#if 0
	MyBST bstree;
	bstree.InsertNode(5);
	bstree.InsertNode(3);
	bstree.InsertNode(2);
	bstree.InsertNode(4);
	bstree.InsertNode(8);
	bstree.InsertNode(7);
	bstree.InsertNode(10);
	bstree.InsertNode(9);

	BSTNode* n1 = bstree.GetSuccessor(3);
	cout << n1->value << endl;
	n1 = bstree.GetSuccessor(4);
	cout << n1->value << endl;

	n1 = bstree.GetPredecessor(10);
	cout << n1->value << endl;
	n1 = bstree.GetPredecessor(8);
	cout << n1->value << endl;
#endif
	//********************************
	//¶ÓÁÐ²âÊÔ
#if 0
	Queue q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	cout << q1.Top() << endl;
	q1.Pop();
	cout << q1.Top() << endl;

	Queue q2(q1);
	cout << q2.Size() << endl;

	Queue q3;
	q3 = q1;
	cout << q2.Size() << endl;
#endif
	//********************************

	//Õ»²âÊÔ
#if 0
	Stack s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	cout << s1.Top() << endl;
	s1.Pop();
	cout << s1.Top() << endl;
	Stack s2(s1);
	Stack s3;
	s3 = s1;

	cout << s3.Size() << endl;
#endif 
	//********************************

	//Ë«ÏòÑ­»·Á´±í²âÊÔ
#if 0
	LinkList l1;
	l1.PushBack(1);
	l1.PopBack();
	l1.PushFront(2);
	l1.PopFront();
#endif
	//*******************************

	//¶¯Ì¬Êý×é²âÊÔ
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
	//********************************
	return 0;
}