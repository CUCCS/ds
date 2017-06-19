#include"Sort.h"
void swap(SqList*L, int i, int j)
{
	RedType temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void ShellSort(SqList*L)
{
	int i, j;
	int count1 = 0, count2 = 0;
	int rise = L->length;
	do
	{
		rise = rise / 5 + 1;
		for (i = rise + 1; i <= L->length; i++)
		{
			count1++;
			if (LT(L->r[i].key, L->r[i - rise].key))
			{
				L->r[0] = L->r[i];
				count2++;
				for (j = i - rise; LT(L->r[0].key, L->r[j].key) && j > 0; j = j - rise)
				{
					count1++;
					L->r[j + rise] = L->r[j];
					count2++;
				}
				count1++;
				L->r[j + rise] = L->r[0];
				count2++;
			}
		}
	} while (rise > 1);
	printf("希尔排序为: ");
	for (i = 1; i <= L->length; i++)
	{
		printf("%d ", L->r[i].key);
	}
	printf("\n比较次数：%d  交换次数: %d  二者之和: %d\n", count1, count2, count1 + count2);
	printf("\n");
}
void InsertSort(SqList*L)
{
	int i, j;
	int count1 = 0;
	int count2 = 0;
	for (i = 2; i <= L->length; i++)
	{
		++count1;
		if (LT(L->r[i].key, L->r[i - 1].key))
		{
			L->r[0] = L->r[i];
			count2++;
			//L->r[i] = L->r[i - 1];
			for (j = i - 1; LT(L->r[0].key, L->r[j].key); --j)
			{
				count1++;
				count2++;
				L->r[j + 1] = L->r[j];
			}
			count1++;
			L->r[j + 1] = L->r[0];
			count2++;
		}
	}
	printf("插入排序后为：");
	for (i = 1; i <= L->length; i++)
	{
		printf("%d ", L->r[i].key);
	}
	printf("\n比较次数：%d  交换次数: %d  二者之和: %d\n", count1, count2, count1 + count2);
	printf("\n");
}
void BubbleSort(SqList*L)
{
	int i, j;
	int count1 = 0;
	int count2 = 0;
	for (i = 1; i < L->length; i++)
	{
		for (j = i + 1; j < L->length; j++)
		{
			count1++;
			if (LT(L->r[j].key, L->r[i].key))
			{
				swap(L, i, j);
				count2 += 3;
			}
		}
	}
	printf("冒泡排序后为：");
	for (i = 1; i<L->length; i++)
	{
		printf("%d ", L->r[i].key);
	}
	printf("\n比较次数：%d  交换次数: %d  二者之和: %d\n", count1, count2, count1 + count2);
	printf("\n");
}
int Partition(SqList*L, int low, int high, int*count1, int*count2)
{
	int pivotkey;
	//L->r[0] = L->r[low];
	pivotkey = L->r[low].key;
	while (low < high)
	{
		while (L->r[high].key >= pivotkey && low < high)
		{
			(*count1)++;
			high--;
		}
		(*count1)++;
		swap(L, low, high);
		(*count2) += 3;
		while (L->r[low].key <= pivotkey && low < high)
		{
			(*count1)++;
			low++;
		}
		(*count1)++;
		swap(L, low, high);
		(*count2) += 3;
	}
	return low;
}

void QSort(SqList*L, int low, int high, int*count1, int*count2)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high, count1, count2);
		QSort(L, low, pivot - 1, count1, count2);
		QSort(L, pivot + 1, high, count1, count2);
	}
}
void QuickSort(SqList*L)
{
	int i;
	int count1 = 0, count2 = 0;
	QSort(L, 1, L->length, &count1, &count2);
	printf("快速排序后为：");
	for (i = 1; i <= L->length; i++)
	{
		printf("%d ", L->r[i].key);
	}
	printf("\n比较次数：%d  交换次数: %d  二者之和: %d\n", count1, count2, count1 + count2);
}
void SelectSort(SqList*L)
{
	int i, j, min;
	int count1 = 0;
	int count2 = 0;
	for (i = 1; i < L->length; i++)
	{
		min = i;
		for (j = i + 1; j <= L->length; j++)
		{
			count1++;
			if (LT(L->r[j].key, L->r[min].key))
			{
				min = j;
			}
		}
		if (i != min)
		{
			swap(L, i, min);
			count2 += 3;
		}
	}
	printf("\n简单选择排序为：");
	for (i = 1; i <= L->length; i++)
	{
		printf("%d ", L->r[i].key);
	}
	printf("\n比较次数：%d  交换次数: %d  二者之和: %d\n", count1, count2, count1 + count2);
	printf("\n");
}
