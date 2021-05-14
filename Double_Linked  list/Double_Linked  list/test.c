#define _CRT_SECURE_NO_WARNINGS
#include"list.h"
int main()
{
	ListNode* p = ListCreate();
	ListPushBack(p, 1);
	ListPushBack(p, 2);
	ListPushBack(p, 3);
	ListPushBack(p, 4);
	ListInsert(p->_next, 5);
	ListPopBack(p);
	ListPopFront(p);
	ListPrint(p);
	ListDestory(p);
	p = NULL;
	return 0;
}