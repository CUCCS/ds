#include "sort.h"

//����Ԫ��
void Swap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//ֱ�Ӳ�������
void InsertSort(int *array, int n, int *comp, int *mov)
{
	*comp = *mov = 0;
	int i, j;
	int tmp;            // ������Ԫ��
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

//ϣ������
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

//��������
void BubbleSort(int *array, int n, int *comp, int *mov)
{
	*comp = *mov = 0;
	int i, j;
	int flag = 1;            //���ѭ�������Ƿ���й����������Ϊ1������˽���    
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

//��������
void QuickSort(int *array, int left, int right, int count, int *comp, int *mov)
{    //left �� count��ʼֵΪ0  right ��ʼֵΪ���鳤�� - 1
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

//��ѡ������
void SelectSort(int * array, int n, int *comp, int *mov)
{
	*comp = *mov = 0;
	int i, j;
	int tmp;    //��¼������Ԫ�ص��±�
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

//������ɲ�������
void input(int *a, int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100 + 1;
	}
}

//��ӡ�����������
void output(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}

//�������
void outTime(int comp, int mov)
{
	printf("�Ƚϴ���: %d\n", comp);
	printf("�ƶ�����: %d\n", mov);
	printf("����֮��: %d\n", comp + mov);
	comp = mov = 0;
	printf("\n");
}

//��ʼ���鱣��
void originArray(int* array, int* origin, int n)
{
	for (int i = 0; i < n; ++i)
	{
		array[i] = origin[i];
	}
}