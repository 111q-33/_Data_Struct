#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
// ��������ж�����
void HeapSort(int* a, int n);
//����
void swap(int* a, int *b);
//���µ���
void adjustdown(int* hp, int n);
//topk����
int* TopK(int*a, int n,int k,int*returnsize);
