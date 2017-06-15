#include "sort.h"

//交换元素
void Swap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//直接插入排序
void InsertSort(int *array, int n, int *comp, int *mov)
{
	*comp = *mov = 0;
	int i, j;
	int tmp;            // 待排序元素
	for (i = 0; i < n; i++)
	{
		tmp = array[i];
		for (j = i - 1; j >= 0 && tmp < array[j]; j--)
		{
			Swap(array[j], array [j + 1]);
			(*mov) += 3;
			++(*comp);
		}
		array[j + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int *array, int n, int *comp, int *mov)
{
	*comp = *mov = 0;
	int i, j;
	int d = n / 2;
	int temp;
	while (d >= 1)
	{
		for (i = d; i < n; i++)
		{
			temp = array[i];
			for (j = i - d; j >= 0 && temp < array[j]; j = j - d)
			{
				Swap(array[j + d], array [j]);
				(*mov) += 3;
				++(*comp);
			}
			if (array[j + d] != temp)
			{
				Swap(array[j + d], temp);
				(*mov) += 3;
				++(*comp);
			}
		}
		d /= 2;
	}
}

//起泡排序
void BubbleSort(int *array, int n, int *comp, int *mov)
{
	*comp = *mov = 0;
	int i, j;
	int flag = 1;            //标记循环过程是否进行过交换，如果为1则进行了交换    
	for (i = 0; i < n && flag; i++)
	{
		flag = 0;
		for (j = 1; j < n - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				Swap(array[j], array[j - 1]);
				(*mov) += 3;
				flag = 1;
			}
			++(*comp);
		}
	}
}

//快速排序
void QuickSort(int *array, int left, int right, int count, int *comp, int *mov)
{    //left 和 count初始值为0  right 初始值为数组长度 - 1
	int i;
	int count_temp = count + 1;
	if (left < right)
	{
		int base = array[left];
		while (left < right)
		{
			while (left < right && base < array[right])
			{
				right--;
				(*comp)++;
			}

			array[left] = array[right];
			(*mov)++;

			while (left < right && array[left] < base)
			{
				left++;
				(*comp)++;
			}
			array[right] = array[left];
			(*mov)++;
		}

		array[left] = base;
		i = left;
		QuickSort(array, left, i - 1, count_temp, comp, mov);
		QuickSort(array, i + 1, right, count_temp, comp, mov);
	}
}

//简单选择排序
void SelectSort(int * array, int n, int *comp, int *mov)
{
	*comp = *mov = 0;
	int i, j;
	int tmp;    //记录待排序元素的下标
	for (i = 0; i < n - 1; i++)
	{
		tmp = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[tmp] > array[j])
			{
				tmp = j;
			}
			++(*comp);
		}
		if (tmp != i)
		{
			Swap(array[tmp], array[i]);
			(*mov) += 3;
		}

	}
}

//随机生成测试数据
void input(int *a, int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100 + 1;
	}
}

//打印输出测试数据
void output(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}

//输出次数
void outTime(int comp, int mov)
{
	printf("比较次数: %d\n", comp);
	printf("移动次数: %d\n", mov);
	printf("二者之和: %d\n", comp + mov);
	comp = mov = 0;
	printf("\n");
}

//初始数组保存
void originArray(int* array, int* origin, int n)
{
	for (int i = 0; i < n; ++i)
	{
		array[i] = origin[i];
	}
}