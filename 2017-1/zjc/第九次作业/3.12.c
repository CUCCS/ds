#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 20         /*线性表中最多元素个数*/
typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
	KeyType key;
	InfoType data;
}RecType;

void InsertSort(RecType R[], int n,int compare,int move)
{
	
	int i, j, k;
	RecType temp;
	for (i = 1; i < n; i++)
	{
		temp = R[i];
		j = i - 1;
		while (j >= 0 && temp.key < R[j].key&&compare++)
		{
			R[j + 1] = R[j];
			j--;
			move++;
		}
		R[j + 1] = temp;
		printf("   i=%d   ", i);
		for (k = 0; k < n; k++)
			printf("%3d", R[k].key);
		printf("\n");
	}
}

void ShellSort(RecType R[], int n,int compare,int move)
{
	int i, j, d, k;
	
	RecType temp;
	d = n / 2;
	while (d > 0)
	{
		for (i = d; i < n; i++)
		{
			j = i - d;
			while (j >= 0 && R[j].key > R[j + d].key&&compare++)
			{
				temp = R[j];
				R[j] = R[j + d];
				R[j + d] = temp;
				j = j - d;
				move++;
			}
		}
		printf("   d=%d:   ", d);
		for (k = 0; k < n; k++)
			printf("%3d", R[k].key);
		printf("\n");
		d = d / 2;
	}
}

void BubbleSort(RecType R[], int n,int compare,int move)
{
	int i, j, k;
	RecType temp;
	for (i = 0; i < n-1 ; i++)
	{
		for (j = n - 1; j > i; j--)
			if (R[j].key < R[j - 1].key&&compare++)
			{
				temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;
				move++;
			}
		printf("   i=%d   ", i);
		for (k = 0; k < n; k++)
			printf("%3d", R[k].key);
		printf("\n");
	}
}

void QuickSort(RecType R[], int s, int t, int n,int compare,int move)
{
	int i = s, j = t, k;
	RecType temp;
	if (s < t)
	{
		temp = R[s];
		while (i != j)
		{
			while (j > i && R[j].key > temp.key&&compare++)
				j--;
			if (i < j)
			{
				R[i] = R[j];
				i++;
				move++;
			}
			while (i < j && R[i].key < temp.key&&compare++)
				i++;
			if (i < j)
			{
				R[j] = R[i];
				j--;
				move++;
			}
		}
		R[i] = temp;
		printf("      ");
		for (k = 0; k < n; k++)
			if (k == i)
				printf(" [%d]", R[k].key);
			else
				printf("%4d", R[k].key);
		printf("\n");
		QuickSort(R, s, i - 1, n,compare,move);
		QuickSort(R, i + 1, t, n,compare,move);
	}
}

void SelectSort(RecType R[], int n,int compare,int move)
{
	int i, j, k, l;
	RecType temp;
	compare=move=0;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (R[j].key < R[k].key&&compare++)
				k = j;
		if (k != i)
		{
			temp = R[i];
			R[i] = R[k];
			R[k] = temp;
			move++;
		}
		printf("    i=%d   ", i);
		for (l = 0; l < n; l++)
			printf("%3d", R[l].key);
		printf("\n");
	}
}

void DispHeap(RecType R[], int i, int n)    /*以括号表示法输出建立的堆*/
{
	if (i <= n)
		printf("%d", R[i].key);
	if (2 * i <= n)


	{
		printf("(");
		DispHeap(R, 2 * i, n);
		printf(",");
		if (2 * i + 1 <= n)
			DispHeap(R, 2 * i + 1, n);
		printf(")");
	}
}
void Sift(RecType R[], int low, int high,int compare,int move)                 /*调整堆*/
{
	int i = low, j = 2 * i;
	RecType temp = R[i];
	while (j <= high)
	{
		if (j < high && R[j].key < R[j + 1].key&&compare++)
			j++;
		if (temp.key < R[j].key&&compare++)
		{
			R[i] = R[j];
			i = j;
			j = 2 * i;
			move++;
		}
		else
			break;
	}
	R[i] = temp;
}
void HeapSort(RecType R[], int n,int compare,int move)               /*对R[1]到R[n]元素实现堆排序*/
{
	int i;
	RecType temp;
	for (i = n / 2; i >= 1; i--)
	Sift(R, i, n,compare,move);
	printf("初始堆：");
	DispHeap(R, 1, n);
	printf("\n");
	for (i = n; i >= 2; i--)
	{
		printf("交换%d与%d，输出%d\n", R[i].key, R[1].key, R[1].key);
		temp = R[1];
		R[1] = R[i];
		R[i] = temp;
		Sift(R, 1, i - 1,compare,move);
		printf("筛选调整得到堆：");
		DispHeap(R, 1, i - 1);
		printf("\n");
	}
}

void PrintArray(RecType R[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%3d", R[i].key);
	printf("\n");
}

void main()
{

	int i, n = 10, cord;
	RecType R[MAX], S[MAX];
	srand(time(0));                           /*用系统时间作为随机数种子*/
	for (i = 0; i < n; i++)
		S[i].key = 100 * rand() / RAND_MAX;   
		      /*利用随机函数产生10个100以内的随机整数*/
		int compare=0,move=0;
		printf("*****************************\n");
		printf("1-直接插入排序\n");
		printf("初始关键字：");
		PrintArray(S, n);
		for (i = 0; i < n; i++)
			R[i].key = S[i].key;
		InsertSort(R, n,compare,move);
		printf("最后结果 ：");
		PrintArray(R, n);
		printf("总比较次数：%d\n",compare);
		printf("总移动次数：%d\n",move);
		printf("两者之和：%d\n\n",move+compare);
			for (i = 0; i < n; i++)
		S[i].key = 100 * rand() / RAND_MAX;  
		compare=move=0;
		printf("2-希尔排序\n");
		printf("初始关键字：");
		PrintArray(S, n);
		for (i = 0; i < n; i++)
			R[i].key = S[i].key;
		ShellSort(R, n,compare,move);
		
		printf("最后结果 ：");
		PrintArray(R, n);
			printf("总比较次数：%d\n",compare);
		printf("总移动次数：%d\n",move);
		printf("两者之和：%d\n\n",move+compare);
			for (i = 0; i < n; i++)
		S[i].key = 100 * rand() / RAND_MAX; 
		compare=move=0 ;
		printf("3-冒泡排序\n");
		printf("初始关键字：");
		PrintArray(S, n);
		for (i = 0; i < n; i++)
			R[i].key = S[i].key;
		BubbleSort(R, n,compare,move);
		printf("最后结果 ：");
		PrintArray(R, n);
			printf("总比较次数：%d\n",compare);
		printf("总移动次数：%d\n",move);
		printf("两者之和：%d\n\n",move+compare);
			for (i = 0; i < n; i++)
		S[i].key = 100 * rand() / RAND_MAX;  
		compare=move=0;
		printf("4-快速排序\n");
		printf("初始关键字：");
		PrintArray(S, n);
		for (i = 0; i < n; i++)
			R[i].key = S[i].key;
		QuickSort(R, 0, n - 1, n,compare,move);
		printf("最后结果 ：");
		PrintArray(R, n);
			printf("总比较次数：%d\n",compare);
		printf("总移动次数：%d\n",move);
		printf("两者之和：%d\n\n",move+compare);
			for (i = 0; i < n; i++)
		S[i].key = 100 * rand() / RAND_MAX; 
		compare=move=0 ;
		printf("5-简单选择排序\n");
		printf("初始关键字：");
		PrintArray(S, n);
		for (i = 0; i < n; i++)
			R[i].key = S[i].key;
		SelectSort(R, n,compare,move);
		printf("最后结果 ：");
		PrintArray(R, n);
			printf("总比较次数：%d\n",compare);
		printf("总移动次数：%d\n",move);
		printf("两者之和：%d\n\n",move+compare);
			for (i = 0; i < n; i++)
		S[i].key = 100 * rand() / RAND_MAX;  
		compare=move=0;
		printf("6-堆排序\n");
		printf("初始关键字：");
		PrintArray(S, n);
		for (i = 1; i <= n; i++)
			R[i].key = S[i - 1].key;
		HeapSort(R, n,compare,move);
		printf("最后结果 ：");
		PrintArray(R, n);
			printf("总比较次数：%d\n",compare);
		printf("总移动次数：%d\n",move);
		printf("两者之和：%d\n\n",move+compare);
}
