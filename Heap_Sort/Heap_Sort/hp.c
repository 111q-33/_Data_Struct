#define _CRT_SECURE_NO_WARNINGS
#include"hp.h"
void HeapSort(int* a, int n)
{
	//�����
	int parent = (n - 1 - 1) / 2;
	for (; parent >= 0; parent--)
	{
		adjustdown(a, n, parent);
	}
	//���������һ��Ҷ�ӽڵ㽻�����������Ľڵ�--�������µ�����ֱ�����Ľڵ�==0
	swap(&a[0], &a[n - 1]);
	int end = n - 1;
	for (; end > 0; end--)
	{
		adjustdown(a, end, 0);
		swap(&a[0], &a[end-1]);
	}
}
//����
void swap(int* a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//���µ���
void adjustdown(int* s, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && s[child] < s[child + 1])
		{
			child++;
		}
		if (s[parent] < s[child])
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
//topk����
int* TopK(int*a, int n,int k,int* returnsize)
{
	//��һ���ڵ�Ϊk�Ĵ��
	int i = 0;
	int* tmp = (int*)malloc(sizeof(int)*n);
	for (; i < n; i++)
	{
		tmp[i] = a[i];
	}
	for (int parent = (k - 1 - 1) / 2; parent >= 0; parent--)
	{
		adjustdown(tmp, k, parent);
	}
	//����k��֮��Ľڵ��������Ƚϣ���С�ͻ���ֱ����n��
	for (i = k; i < n; i++)
	{
		if (a[0]>a[i])
		{
			swap(&a[0], &a[i]);
			adjustdown(a, k, 0);
		}
	}
	*returnsize = k;
	return a;
}
