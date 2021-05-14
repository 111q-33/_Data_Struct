#include"Linked list.h"
//动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode*));
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}


// 单链表打印
void SListPrint(SListNode* plist)
{
	assert(plist);
	while (plist)
	{
		printf("%d ", plist->data);
		plist = plist->next;
	}
	printf("\n");
}


// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* cur = *pplist;
	if (cur == NULL)//当cur为NULL，尾插会改变头，如果只传一级指针，只是原指针的拷贝，不会改变原指针的内容。所以当表头会变时，需穿二级指针。
	{
		cur = BuySListNode(x);
		*pplist = cur;
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = BuySListNode(x);
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* tmp = *pplist;
	*pplist = BuySListNode(x);
	(*pplist)->next = tmp;
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	SListNode* cur = *pplist;
	if (cur == NULL)
	{
		return;
	}
	else if (cur->next = NULL)
	{
		free(cur);
		*pplist = NULL;
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	free(cur);
	cur = NULL;
}


// 单链表头删
void SListPopFront(SListNode** pplist)
{
	SListNode* cur = *pplist;
	if (cur == NULL)
	{
		return;
	}
	SListNode* tmp = cur->next;
	free(cur);
	*pplist = tmp;
}


// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	printf("不存在\n");
	return	NULL;
}


// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* dst = pos->next;
	SListNode* tmp = BuySListNode(x);
	pos->next = tmp;
	tmp->next = dst;
}


// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* dst = pos->next;
	assert(dst);
	SListNode* next = dst->next;
	free(dst);
	dst = NULL;
	pos->next = next;
}


// 单链表的销毁
void SListDestory(SListNode* plist)
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		SListNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
}