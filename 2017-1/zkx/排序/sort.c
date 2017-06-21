#include "sort.h"

Status InsertSort(RecordType *r, int length, int *compare, int *move)
{
	int j;
	RecordType temp;
	*compare = *move = 0;
	for (int i = 1; i < length; i++) 
	{
		temp = r[i];                             /* ���������¼��ŵ���ʱ������ */
		++(*move);
		j = i;                                /* ���һ����������ı߽�λ�� */
		while (++(*compare), (temp.key < r[j-1].key) && j > 0)    /* Ѱ�Ҳ���λ�� */
		{   
			r[j] = r[j - 1];               /* ��С�������򣬴�Ԫ������ */
			++(*move);
			j = j - 1;                           /* ������Ԫ��������������һ��������һλ��Ԫ�ؼ������бȽ� */
		}
		r[j] = temp;                     /* ���������¼���뵽������������� */
		++(*move);
	}
	return OK;
}

/* �Լ�¼����r��һ��ϣ����������lengthΪ����ĳ���, dΪ���� */
Status ShellSort(RecordType*arr, int length, int *compare, int *move)
{
	int i, j;
	RecordType temp;
	*compare = *move = 0;
	int d = length / 2;
	while (d >= 1)
	{
		for (int k = 0; k < d; k++)
		{
			for (i = d; i < length-k; i += d) 
			{
				temp = arr[i+k];
				++*move;
				j = i;
				while (++*compare, arr[j + k - d].key > temp.key && j > 0)
				{
					arr[j + k] = arr[j + k - d];
					j -= d;
					++*move;
				}
				arr[j + k] = temp;
				++*move;
			}
		}
		d = d / 2;
	}
	return OK;
}


Status BubbleSort(RecordType *r, int length, int *compare, int *move)
{
	*compare = *move = 0;
	int i, j;
	RecordType temp;
	for (i = length - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (++*compare,r[j].key > r[j + 1].key)
			{
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				(*move) += 3;
			}
		}
	}
	return OK;
}

Status _QuickSort(RecordType*r, int length, int *compare, int* move) 
{
	RecordType flag = r[0];
	if (length <= 1)return;

	int i = 1, j = length - 1;
	while (j >= i) 
	{
		while (++*compare, r[i].key <= flag.key && j >= i)++i;
		while (++*compare, r[j].key > flag.key && j >= i)--j;
		if (j < i) 
		{
			RecordType temp = r[0];
			r[0] = r[j];
			r[j] = temp;
			(*move) += 3;
			break;
		}

		RecordType temp = r[i];
		r[i] = r[j];
		r[j] = temp;
		(*move) += 3;
	}

	_QuickSort(r, j, compare, move);
	_QuickSort(r + j + 1, length - j - 1, compare, move);
	return OK;
}
Status QuickSort(RecordType*arr, int length, int *compare, int* move)
{
	*compare = *move = 0;
	_QuickSort(arr, length, compare, move);
	return OK;
}

Status _SelectSort(RecordType *r, int length, int *compare, int *move)
{
	int i;		
	int id = 0;
	RecordType temp;
	for (i = 1; i < length; i++)
	{
		if (++*compare, r[i].key < r[id].key)
		{
			id = i;
		}
	}
		temp = r[0];
		r[0] = r[id];
	    r[id] = temp;
		(*move) += 3;
	return OK;
}

Status SelectSort(RecordType*r, int length, int *compare, int* move)
{
	*compare = *move = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		_SelectSort(r + i, length - i, compare, move);
	}
}