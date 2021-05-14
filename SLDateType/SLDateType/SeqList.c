#include"SeqList.h"
void AddSeqList(SeqList* ps)
{
	int* tmp =(int*) realloc(ps->a, ps->capacity*(sizeof(int)) * 2);
	if (tmp == NULL)
	{
		printf("����ʧ��\n");
		exit(0);
	}
	ps->a = tmp;
	ps->capacity = ps->capacity * 2;
}
//��ʼ������
void SeqListInit(SeqList* ps)
{
	assert(ps != NULL);
	int* tmp = (int*)malloc(sizeof(int));
	if (tmp == NULL)
	{
		printf("��ʼ��ʧ��\n");
		exit(0);
	}
	ps->a = tmp;
	ps->capacity = 1;
	ps->size = 0;
	return;
}
//ɾ������
void SeqListDestory(SeqList* ps)
{
	assert(ps != NULL);
	free(ps);
	ps = NULL;
}

//�������
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	if (ps->size == ps->capacity)
	{
		AddSeqList(ps);
	}
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	if (ps->size == ps->capacity)
	{
		AddSeqList(ps);
	}
	int n = ps->size;
	while (n > 0)
	{
		ps->a[n] = ps->a[n - 1];
		n--;
	}
	ps->a[0] = x;
	ps->size++;
}
//ɾ������

void SeqListPopFront(SeqList* ps)
{
	assert(ps != NULL);
	size_t n = 0;
	for (; n < ps->size;n++)
	{
		ps->a[n] = ps->a[n + 1];
	}
	ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps != NULL);
	ps->size--;
}
//˳������
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	size_t n = 0;
	for (; n < ps->size; n++)
	{
		if (x == ps->a[n])
			return n;
	}
	printf("�޴�����\n");
	return -1;
}
//˳����������
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps != NULL);
	if (ps->size == ps->capacity)
	{
		AddSeqList(ps);
	}
	size_t n = pos;
	for (; n < ps->size; n++)
	{
		ps->a[n + 1] = ps->a[n];
	}
	ps->a[pos] = x;
	ps->size++;
}
//ɾ��ָ��λ�õ�����
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps != NULL);
	size_t n = pos;
	for (; n < ps->size; n++)
	{
		ps->a[n] = ps->a[n + 1];
	}
	ps->size--;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps != NULL);
	size_t n = 0;
	for (; n < ps->size; n++)
	{
		printf("%d", ps->a[n]);
	}
	printf("\n");
}