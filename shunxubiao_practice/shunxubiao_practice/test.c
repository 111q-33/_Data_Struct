#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//int removeElement(int* nums, int numsSize, int val)
//{
	//int cur = 0;
	//int next = 0;
	//while (next < numsSize)
	//{
	//	if (val == nums[next])
	//	{
	//		next++;
	//	}
	//	else
	//	{
	//		nums[cur] = nums[next];
	//		cur++;
	//		next++;
	//	}
	//}
	//return cur;
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 6, 7, 9, 10 };
//	int i = removeElement(arr, 10, 6);
//	int n = 0;
//	for (; n < i; n++)
//	{
//		printf("%d ", arr[n]);
//	}
//	return 0;
//}

//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize == 0)
//	{
//		return 0;
//	}
//	int dst = 0;
//	int cur = 0;
//	int next = 1;
//	while (next < numsSize)
//	{
//		if (nums[cur] != nums[next])
//		{
//			nums[dst] = nums[cur];
//			dst++;
//			cur++;
//			next++;
//		}
//		else
//		{
//			while (next<numsSize && nums[cur] == nums[next])
//			{
//				next++;
//			}
//			nums[dst] = nums[cur];
//			dst++;
//			cur = next;
//			next++;
//		}
//	}
//	if (cur < numsSize)
//	{
//		nums[dst++] = nums[cur];
//	}
//	return dst;
//}
//
//int main()
//{
//	int arr[] = { 1, 1 };
//	printf("%d\n", removeDuplicates(arr, 4));
//	return 0;
//}
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
//	int aSize = numSize;
//	int ret = 0;
//	int count = 0;
//	int nums = 0;
//	int kSize = 0;
//	int n = k;
//	while (n)
//	{
//		kSize++;
//		n /= 10;
//	}
//	int sSize = aSize > kSize ? aSize + 1 : kSize + 1;
//	int *tmp = (int *)malloc(sizeof(int)*sSize);
//	while ((aSize-1) >= 0 || k > 0)
//	{
//		if ((aSize-1 )>= 0)
//		{
//			nums = num[aSize-1] + k%10 + ret;
//		}
//		else
//		{
//			nums = k%10 + ret;
//		}
//		if (nums > 9)
//		{
//			tmp[count++] = nums - 10;
//			ret = 1;
//		}
//		else
//		{
//			tmp[count++] = nums;
// 			ret = 0;
//		}
//		k /= 10;
//		aSize--;
//		kSize--;
//	}
//	if (ret == 1)
//	{
//		tmp[count++] = ret;
//		ret = 0;
//	}
//	int begin = 0;
//	int end = count - 1;
//	while (begin < end)
//	{
//		int ttmp = tmp[begin];
//		tmp[begin] = tmp[end];
//		tmp[end] = ttmp;
//		begin++;
//		end--;
//	}
//	*returnSize = count;
//	return tmp;
//}
//int main()
//{
//	int arr[] = { 1,2,0,0 };
//	int k = 34;
//	int count = 0;
//	int *tmp=addToArrayForm(arr, 4, k, &count);
//	int i = 0;
//	for (; i < count; i++)
//	{
//		printf("%d", tmp[i]);
//	}
//	return 0;
//}

