#include "Sort.h"
void CreatArray(SqList *s)
{
	int i;
	for (i = 1; i <= LENGTH; i++)
	{
		s->r[i].key = rand() % 101;  //产生0-100的随机数	
	}
	s->length = i - 1;
	printf("随机生成10个序列中的元素：\n");
	for (i = 1; i <= LENGTH; i++)
	{
		printf("%d ", s->r[i].key);
	}
}
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
		if ((++sum1) && LT(L->r[i].key, L->r[i - 1].key))//若找到r[i]<r[i-1],将r[i]插入有序子表
		{
			L->r[0] = L->r[i];//使用r[0]保存r[i],以便后续直接交换
			for (j = i - 1; LT(L->r[0].key, L->r[j].key); --j) //如果r[0]一直小于r[j]，则一直交换；直到找到r[0]>r[j]的位置
			{
				L->r[j + 1] = L->r[j];
				sum2++;
			}
			L->r[j + 1] = L->r[0];//将r[0]放入位置
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
	L->r[0].key = L->r[low].key;//用r[0]储存r[low]
	pivotkey = L->r[low].key;//用r[low]做枢轴量
	while (low < high) //low=high的时候结束循环
	{
		while (++(*sum1) && low < high && L->r[high].key >= pivotkey)//找到右端比枢轴量小的值跳出
		{
			(*sum2)++;
			--high;
		}
		L->r[low] = L->r[high];//右端与左端进行交换
		while (++(*sum1) && low < high&&L->r[low].key <= pivotkey)//找到左端比枢轴量大的数
		{
			(*sum2)++;
			++low;
		}
		L->r[high] = L->r[low];//左端与右端进行交换
	}
	L->r[low].key = L->r[0].key;//将枢轴量放进中间，实现一轮交换
	return low;
}
void QSort(SqList *L, int low, int high, int *sum1, int *sum2)
{
	int pivotloc;
	if (low < high) {
		pivotloc = Partition(L, low, high, sum1, sum2);
		QSort(L, low, pivotloc - 1, sum1, sum2);//右端进行一次快排
		QSort(L, pivotloc + 1, high, sum1, sum2);//左端进行一次快排
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
		if (L.r[k].key > L.r[j].key)//找到最小一项的序号数
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
	for (i = 1; i < L->length; ++i)
	{
		j = SelectMinKey(*L, i);//在表中选出最小一项的序号数，赋值给j
		if ((++sum1) && i != j)//将挑选出来的最小项依次与表中1，2，3...项交换
		{
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
	bool exchange;//定义一个布尔变量来检验数组是否已经有序
	RedType t;
	int sum1 = 0;
	int sum2 = 0;
	int i;
	for (i = L->length - 1; i > 0; i--) {
		exchange = false;//先定义数组为无序
		for (int j = 0; (++sum1) && j <= i; j++)
		{
			if (L->r[j].key > L->r[j + 1].key)//比较r[j]与r[j+1]的大小
			{
				t = L->r[j];
				L->r[j] = L->r[j + 1];
				L->r[j + 1] = t;
				sum2 = sum2 + 3;
			}
			exchange = true;
		}
		if (!exchange) return;//如果某一趟算法下来没有交换元素，就说明此时数组已经有序
	}
	printf("\n已经排好序，序列为：\n");
	for (i = 1; i <= LENGTH; i++)
	{
		printf("%d ", L->r[i].key);

	}
	print(MAXSIZE, sum1, sum2);
}
void ShellInsert(SqList *L, int dk, int *sum1, int *sum2) {
	int i, j;
	for (i = dk + 1; i <= L->length; i++)
	{
		if (++(*sum1) && LT(L->r[i].key, L->r[i - dk].key))//若r[i]小于r[j-dk],则进行插入
		{
			L->r[0].key = L->r[i].key;//用r[0]来储存r[i]
			for (j = i - dk; j > 0 && LT(L->r[0].key, L->r[j].key) && (++(*sum1)); j -= dk)
				//比较r[i]与r[j]之间大小，如果小于则将r[j]移动到r[i]的位置
			{
				L->r[j + dk] = L->r[j];
				(*sum2)++;
			}
			L->r[j + dk].key = L->r[0].key;
		}
	}

}
void ShellSort(SqList *L) {
	int i;
	int sum1 = 0;
	int sum2 = 0;
	for (i = L->length / 2; i > 0; i = i / 2)//先定义增量为L->length/2,后序循环为其一半
	{
		ShellInsert(L, i, &sum1, &sum2);
	}
	printf("\n已经排好序，序列为：\n");
	for (i = 1; i <= LENGTH; i++)
	{
		printf("%d ", L->r[i].key);

	}
	print(MAXSIZE, sum1, sum2);
}

