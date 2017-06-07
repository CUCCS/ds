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

/*=========直接插入排序输出=========*/
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

/*==========希尔排序输出=========*/
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


/*=========冒泡排序输出=========*/
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


/*=========快速排序输出=========*/
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
	RecordType x = r[left];             // 选择基准记录
	int low = left;
	int high = right;
	while (LT(low , high)) 
	{
		while ((*cmp_count)++,LT(low , high) && r[high].key >= x.key) //high从右到左找小于x.key的记录
		{ 
			high--;
		}
		r[low] = r[high]; //找到小于x.key的记录，则进行交换 
		(*mov_count)++;
		while ((*cmp_count)++, LT(low, high) && r[low].key < x.key)// low从左到右找不小于x.key的记录 
		{ 
			low++;
		}
		r[high] = r[low]; // 找到不小于x.key的记录，则交换
		(*mov_count)++;
	}

	r[low] = x;  //将基准记录保存到low=high的位置 
	(*mov_count)++;
	return low;  //返回基准记录的位置
}

/*=========简单选择排序=========*/
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

/*=========数据输出=========*/
void print(RecordType *r,int length,int cmp_count,int mov_count)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d ", r[i].key);
	}
	printf("\n比较次数：%d\n", cmp_count);
	printf("移动次数：%d\n\n", mov_count);
}

/*=========初值恢复=========*/
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
