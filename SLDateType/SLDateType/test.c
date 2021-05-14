#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
int main()
{
	SeqList ps;
	SeqListInit(&ps);
    SeqListPushBack(&ps, 1);
    SeqListPushBack(&ps, 2); 
	SeqListPushFront(&ps, 3);
	SeqListPushFront(&ps, 4);
	SeqListPopFront(&ps);
	SeqListPopBack(&ps);
	SeqListPrint(&ps);
	SeqListPushFront(&ps, 3);
	SeqListPushFront(&ps, 4);
	SeqListPrint(&ps);
	SeqListInsert(&ps, 3, 5);
	SeqListPrint(&ps);
	SeqListErase(&ps, 3);
	SeqListPrint(&ps);
	return 0;
}