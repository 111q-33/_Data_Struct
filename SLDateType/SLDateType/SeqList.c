#include"SeqList.h"
void AddSeqList(SeqList* ps)
{
	int* tmp =(int*) realloc(ps->a, ps->capacity*(sizeof(int)) * 2);
	if (tmp == NULL)
	{
		printf("扩容失败\n");
		exit(0);
	}
	ps->a = tmp;
	ps->capacity = ps->capacity * 2;
}
//初始化数据
void SeqListInit(SeqList* ps)
{
	assert(ps != NULL);
	int* tmp = (int*)malloc(sizeof(int));
	if (tmp == NULL)
	{
		printf("初始化失败\n");
		exit(0);
	}
	ps->a = tmp;
	ps->capacity = 1;
	ps->size = 0;
	return;
}
//删除数据
void SeqListDestory(SeqList* ps)
{
	assert(ps != NULL);
	free(ps);
	ps = NULL;
}

//添加数据
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
//删除数据

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
//顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	size_t n = 0;
	for (; n < ps->size; n++)
	{
		if (x == ps->a[n])
			return n;
	}
	printf("无次数据\n");
	return -1;
}
//顺序表插入数据
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
//删除指定位置的数据
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