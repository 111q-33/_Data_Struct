#define _CRT_SECURE_NO_WARNINGS
#include"hp.h"
int main()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 5, 49, 25, 37 };
	HeapSort(a, 10);
	//int count = 0;
	//int* ret = TopK(a, 10, 5, &count);
	//HeapSort(ret, count);
	//for (int i = 0; i < count; i++)
	//{
	//	printf("%d ", ret[i]);
	//}
	printf("\n");
	return 0;
}