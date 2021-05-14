#define _CRT_SECURE_NO_WARNINGS

// ��������
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

// ϣ������
void ShellSort(int* a, int n)
{
	//1.Ԥ���򣬽�ÿ��gap������Ϊһ����в�������
    //gapԽ�󣬴�����С���ƶ���Խ�죬����Խ���ӽ�����
	//gapԽС��������С���ƶ���Խ��������Խ�ӽ�����
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