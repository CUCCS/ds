#include "Sort.h"

Bool LT(KeyType a, KeyType b)
{
	if (a < b)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*=========ֱ�Ӳ����������=========*/
void InsSort(RecordType *r, int length,int *cmp_count,int *mov_count)
{
	RecordType temp;
	int i, j;
	for (i = 1; i < length; i++)
	{
		temp = r[i];
		(*mov_count)++;
		j = i - 1;
		while ((*cmp_count)++,LT(temp.key, r[j].key) && j >= 0)
		{
			r[j + 1] = r[j];
			(*mov_count)++;
			j = j - 1;
		}
		r[j + 1] = temp;
		(*mov_count)++;
	}
}

/*==========ϣ���������=========*/
void ShellSort(RecordType *r, int length, int *cmp_count, int *mov_count)
{
	int d = length / 2;
	while (d >= 1)
	{
		ShellInsert(r, length, d, cmp_count, mov_count);
		d = d / 2;
	}
}
void ShellInsert(RecordType *r, int length, int delta, int *cmp_count, int *mov_count)
{
	RecordType temp;
	int i, j;
	for (i = delta; i < length; i++)
	{
		if ((*cmp_count)++,LT(r[i].key, r[i-delta].key))
		{
			temp = r[i];
			(*mov_count)++;
			for ((*cmp_count)++,j = i-delta; j >= 0 &&LT(temp.key , r[j].key); j -= delta) 
			{
				r[j + delta] = r[j];
				(*mov_count)++;
			}
			r[j + delta] = temp;
			(*mov_count)++;
		}
		
	}
}


/*=========ð���������=========*/
void BubbleSort(RecordType *r, int length, int *cmp_count, int *mov_count)
{
	RecordType temp;
	int i, j;
	Bool change = TRUE;
	for (i = 0; i < length && change; i++)
	{
		change = FALSE;
		for (j = 0; j < length-i-1; j++)
		{
			if ((*cmp_count)++,LT(r[j+1].key, r[j].key))
			{
				temp = r[j];
				r[j] = r[j+1];
				r[j+1] = temp;
				change = TRUE;
				(*mov_count) =(*mov_count) + 3;
			}
		}
	}
}


/*=========�����������=========*/
void QKSort(RecordType *r, int low, int high,int *cmp_count,int *mov_count)


{
	int pivot;
	if (low < high)
	{
		pivot = QKPass(r, low, high,cmp_count,mov_count);
		QKSort(r, low, pivot - 1,cmp_count,mov_count);
		QKSort(r, pivot + 1, high,cmp_count,mov_count);
	}
}

int QKPass(RecordType *r, int left, int right, int *cmp_count, int *mov_count)
{
	RecordType x = r[left];             // ѡ���׼��¼
	int low = left;
	int high = right;
	while (LT(low , high)) 
	{
		while ((*cmp_count)++,LT(low , high) && r[high].key >= x.key) //high���ҵ�����С��x.key�ļ�¼
		{ 
			high--;
		}
		r[low] = r[high]; //�ҵ�С��x.key�ļ�¼������н��� 
		(*mov_count)++;
		while ((*cmp_count)++, LT(low, high) && r[low].key < x.key)// low�������Ҳ�С��x.key�ļ�¼ 
		{ 
			low++;
		}
		r[high] = r[low]; // �ҵ���С��x.key�ļ�¼���򽻻�
		(*mov_count)++;
	}

	r[low] = x;  //����׼��¼���浽low=high��λ�� 
	(*mov_count)++;
	return low;  //���ػ�׼��¼��λ��
}

/*=========��ѡ������=========*/
void SelectSort(RecordType *r, int length,int *cmp_count,int *mov_count) 
{
	int i, j, k;
	RecordType temp;
	for (i = 0; i < length-1; ++i) 
	{
		k = i;
		for (j = i + 1; j < length; ++j) 
		{
			if ((*cmp_count)++,LT(r[j].key , r[k].key)) 
			{
				k = j;
			}
		}

		if (k != i) 
		{
			temp = r[i];
			r[i] = r[k];
			r[k] = temp;
			(*mov_count) = (*mov_count) + 3;
		}
	}
}

/*=========�������=========*/
void print(RecordType *r,int length,int cmp_count,int mov_count)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d ", r[i].key);
	}
	printf("\n�Ƚϴ�����%d\n", cmp_count);
	printf("�ƶ�������%d\n\n", mov_count);
}

/*=========��ֵ�ָ�=========*/
void Inital(RecordType *counts, RecordType *count,int length, int *cmp_count, int *mov_count)
{
	int i;
	for (i = 0; i < length; i++)
	{
		count[i] = counts[i];
	}
	(*cmp_count) = 0;
	(*mov_count) = 0;
}
