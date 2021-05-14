#include"Linked list.h"
//��̬����һ���ڵ�
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


// �������ӡ
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


// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* cur = *pplist;
	if (cur == NULL)//��curΪNULL��β���ı�ͷ�����ֻ��һ��ָ�룬ֻ��ԭָ��Ŀ���������ı�ԭָ������ݡ����Ե���ͷ���ʱ���贩����ָ�롣
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
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* tmp = *pplist;
	*pplist = BuySListNode(x);
	(*pplist)->next = tmp;
}

// �������βɾ
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


// ������ͷɾ
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


// ���������
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
	printf("������\n");
	return	NULL;
}


// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* dst = pos->next;
	SListNode* tmp = BuySListNode(x);
	pos->next = tmp;
	tmp->next = dst;
}


// ������ɾ��posλ��֮���ֵ
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


// �����������
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