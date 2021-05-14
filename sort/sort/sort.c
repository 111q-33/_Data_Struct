#define _CRT_SECURE_NO_WARNINGS

// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int tmp = a[i + 1];
		int c = i;
		while (c >= 0)
		{
			if (a[c] > tmp)
			{
				a[c + 1] = a[c];
				c--;
			}
			else
			{
				break;
			}
		}
		a[c + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	//1.预排序，将每隔gap的数分为一组进行插入排序
    //gap越大，大数和小数移动得越快，数组越不接近有序
	//gap越小，大数和小数移动得越慢，数组越接近有序
	int gap = n;
	while (gap > 1)
	{
		gap = (gap / 3 + 1);
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[i + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}