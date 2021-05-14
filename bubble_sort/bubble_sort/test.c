#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void print(int arr[], int  n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
void exa(char* n1, char* n2,int n)
{
	while (n)
	{
		char tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
		n1++;
		n2++;
		n--;
	}
}
void bubble_sort(void * arr, int width, int num, int (*cmp)(void* n1, void* n2))
{
	int i, j;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if ((cmp((char*)arr + j*width, (char*)arr + (j + 1)*width)>0))
			{
				exa((char*)arr + j*width, (char*)arr + (j + 1)*width,width);
			}
		}
	}
}
int cmp(void *n1, void *n2)
{

	return *(int*)n1 - *(int *)n2;
}
int main()
{
	int arr[] = { 3, 5, 4, 2, 1, 6, 8, 7, 9, 10 };
	bubble_sort(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), cmp);
	print(arr, 10);
	return 0;
}