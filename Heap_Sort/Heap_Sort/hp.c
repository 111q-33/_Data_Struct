#define _CRT_SECURE_NO_WARNINGS
#include"hp.h"
void HeapSort(int* a, int n)
{
	//建大堆
	int parent = (n - 1 - 1) / 2;
	for (; parent >= 0; parent--)
	{
		adjustdown(a, n, parent);
	}
	//将根与最后一个叶子节点交换，并将树的节点--，再向下调整，直到树的节点==0
	swap(&a[0], &a[n - 1]);
	int end = n - 1;
	for (; end > 0; end--)
	{
		adjustdown(a, end, 0);
		swap(&a[0], &a[end-1]);
	}
}
//交换
void swap(int* a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//向下调整
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
//topk问题
int* TopK(int*a, int n,int k,int* returnsize)
{
	//建一个节点为k的大堆
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
	//将第k个之后的节点与树根比较，若小就换，直到第n个
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
