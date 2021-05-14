#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"

void HeapPrint(Heap* hp, int n)
{
	//1 3 7 15
	//0 2 6 14
	int i = 0;
	int count = 2;
	int high = 1;
	while (i < n)
	{
		printf("%d ", hp->_a[i]);
		i++;
		if (i == high)
		{
			printf("\n");
			count *= 2;
			high = count - 1;
		}
	}
}
//����
void swap(int* a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//���ϵ���
void adjustup(Heap* hp, int n)
{
	int child = n - 1;
	while (child)
	{
		int parent = (child - 1 )/ 2;
		if (hp->_a[child] > hp->_a[parent])
		{
			swap(&hp->_a[child], &hp->_a[parent]);
			child = parent;
		}
		else
		{
			break;
		}
	}
}
//���µ���
void adjustdown(int* s ,int n,int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && s[child] < s[child + 1])
		{
			child++;
		}
		if ( s[parent] < s[child])
		{
			swap(&s[parent], &s[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	HPDataType* tmp = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memcpy(tmp, a, sizeof(HPDataType)*n);
	for (int parent = (n - 1 - 1) / 2; parent >= 0; parent--)
	{
		adjustdown(tmp, n, parent);
	}
	hp->_a = tmp;
	hp->_capacity = n;
	hp->_size = n;
}

// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_capacity = 0;
	hp->_size = 0;
}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_a = (HPDataType*)realloc
			(hp->_a, sizeof(HPDataType)* hp->_size * 2);
		if (hp->_a == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	adjustup(hp, hp->_size);
}

// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_size--;
	adjustdown(hp->_a, hp->_size, 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}