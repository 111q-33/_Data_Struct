#define _CRT_SECURE_NO_WARNINGS
#include"sort.h"
void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void test1(int *a, int n)
{
	ShellSort(a, n);
	print(a, n);
}
void test2(int *a, int n)
{
	InsertSort(a, n);
	print(a, n);
}
int main()
{
	int a[] = { 2, 5, 4, 13, 8, 6, 9, 7, 1, 0 };
	test1(a, sizeof(a) / sizeof(a[0]));
	test2(a, sizeof(a) / sizeof(a[0]));
	return 0;
}