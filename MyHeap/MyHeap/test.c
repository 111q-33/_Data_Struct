#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
//27
//15 19
//18 28 34 65
//49 25 37
void test1()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	adjustdown(a, 10, 0);
}
void test2()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };
	Heap s1;
	HeapCreate(&s1, a, 6);
	HeapPush(&s1, 10);
	HeapPop(&s1);
	HeapPrint(&s1, s1._size);
}
int main()
{
	test2();
	/*test1();*/
	/*int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };*/
	return 0;
}