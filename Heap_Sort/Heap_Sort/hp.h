#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
// 对数组进行堆排序
void HeapSort(int* a, int n);
//交换
void swap(int* a, int *b);
//向下调整
void adjustdown(int* hp, int n);
//topk问题
int* TopK(int*a, int n,int k,int*returnsize);
