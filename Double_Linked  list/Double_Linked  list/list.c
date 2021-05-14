#define _CRT_SECURE_NO_WARNINGS
#include"list.h"


//创建一个节点
ListNode* ListBuy(int x)
{
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	tmp->_prev = tmp->_next = NULL;
	tmp->_data = x;
	return tmp;
}
// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* tmp = ListBuy(0);
	tmp->_prev = tmp->_next = tmp;
	return tmp;
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

// 双向链表尾插
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->_next!=pHead);
	ListNode* tail = pHead->_prev;
	tail->_prev->_next = tail->_next;
	tail->_next->_prev = tail->_prev;
    free(tail);
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* head = pHead->_next;
	ListNode* tmp = ListBuy(x);
	tmp->_prev = pHead;
	pHead->_next = tmp;
	tmp->_next = head;
	head->_prev = tmp;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	ListNode* head = pHead->_next;
	pHead->_next = head->_next;
	head->_prev = pHead;
	if (head != pHead)
	{
		free(head);
	}
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* tmp = ListBuy(x);
	ListNode* prev = pos->_prev;
	tmp->_prev = prev;
	tmp->_next = pos;
	pos->_prev = tmp;
	prev->_next = tmp;

}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(pos->_next != pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}