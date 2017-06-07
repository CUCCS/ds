#include "Sort.h"
void print(int n, int sum1, int sum2)//打印数组
{
	int i;

	printf("\n总的比较次数 %d\n", sum1);
	printf("\n总的移动次数 %d\n", sum2);
	printf("\n二者次数之和为 %d\n", sum1 + sum2);


	printf("\n");
}
void InsertSort(SqList *L)
{
	int i, j;
	int sum1 = 0, sum2 = 0;
	for (i = 2; i <= L->length; ++i) {
		if ((++sum1) && LT(L->r[i].key, L->r[i - 1].key))
		{
			L->r[0] = L->r[i];
			for (j = i - 1; LT(L->r[0].key, L->r[j].key); --j) {
				L->r[j + 1] = L->r[j];
				sum2++;
			}
			L->r[j + 1] = L->r[0];

		}
	}
	printf("\n已经排好序，序列为：\n");
	for (i = 1; i <= LENGTH; i++)
	{
		printf("%d ", L->r[i].key);

	}
	print(MAXSIZE, sum1, sum2);
}

int Partition(SqList *L, int low, int high, int *sum1, int *sum2) {
	int pivotkey;
	L->r[0] = L->r[low];
	pivotkey = L->r[low].key;
	while (low < high) {
		while (++(*sum1) && low < high&&L->r[high].key <= pivotkey) {
			--high;
			(*sum2)++;
		}
		L->r[low] = L->r[high];

		while (++(*sum1) && low < high&&L->r[high].key >= pivotkey) {
			++low;
			(*sum2)++;
		}
		L->r[high] = L->r[low];
	}
	L->r[low] = L->r[0];
	return low;
}
void QSort(SqList *L, int low, int high, int *sum1, int *sum2)
{
	int pivotloc;
	if (low < high) {
		pivotloc = Partition(L, low, high, sum1, sum2);
		QSort(L, low, pivotloc - 1, sum1, sum2);
		QSort(L, pivotloc + 1, high, sum1, sum2);
	}
}
void QuickSort(SqList *L) {
	int sum1 = 0;
	int sum2 = 0;
	int i;
	QSort(L, 1, L->length, &sum1, &sum2);
	printf("\n已经排好序，序列为：\n");
	for (i = 1; i <= LENGTH; i++)
	{
		printf("%d ", L->r[i].key);

	}
	print(MAXSIZE, sum1, sum2);
}
int SelectMinKey(SqList L, int i)
{
	int k;
	int j;
	k = i;
	for (j = i; j < L.length + 1; j++)
		if (L.r[k].key > L.r[j].key)
		{
			k = j;
		}
	return k;
}
void SelectSort(SqList*L) {
	RedType t;
	int i, j;
	int sum1 = 0;
	int sum2 = 0;
	for (i = 1; i < L->length; ++i) {
		j = SelectMinKey(*L, i);
		if ((++sum1) && i != j) {
			t = L->r[i];
			L->r[i] = L->r[j];
			L->r[j] = t;
			sum2 += 3;
		}
	}
	printf("\n已经排好序，序列为：\n");
	for (i = 1; i <= LENGTH; i++)
	{
		printf("%d ", L->r[i].key);

	}
	print(MAXSIZE, sum1, sum2);
}

void BubbleSort(SqList*L) {
	bool exchange;
	RedType t;
	int sum1 = 0;
	int sum2 = 0;
	int i;
	for (i = L->length - 1; i > 0; i--) {
		exchange = false;
		for (int j = 0; (++sum1) && j <= i; j++) {
			if (L->r[j].key > L->r[j + 1].key)
			{
				t = L->r[j];
				L->r[j] = L->r[j + 1];
				L->r[j + 1] = t;
				sum2 = sum2 + 3;
			}
			exchange = true;
		}
		if (!exchange) return;
	}
	printf("\n已经排好序，序列为：\n");
	for (i = 0; i <= LENGTH; i++)
	{
		printf("%d ", L->r[i].key);

	}
	print(MAXSIZE, sum1, sum2);
}
void ShellInsert(SqList *L, int dk, int *sum1, int *sum2) {
	int i, j;
	int temp;
	for (i = dk; i <= L->length; i++)
	{
		if (++(sum1) && LT(L->r[i].key, L->r[i - dk].key))
		{
			temp = L->r[i].key;
			(sum1)++;
			for (j = i - dk; j > 0 && LT(temp, L->r[j].key) && (++(sum1)); j -= dk)
			{
				L->r[j + dk] = L->r[j];
				(sum2)++;
			}
			L->r[j + dk].key = temp;
		}
	}

}
void ShellSort(SqList *L) {
	int i;
	int temp;
	int sum1 = 0;
	int sum2 = 0;
	i = (L->length - 1) / 2;
	for (i = L->length / 2; i > 0; i = i / 2) {
		ShellInsert(L, i, &sum1, &sum2);
	}
	printf("\n已经排好序，序列为：\n");
	for (i = 0; i <= LENGTH; i++)
	{
		printf("%d ", L->r[i].key);

	}
	print(MAXSIZE, sum1, sum2);
}

