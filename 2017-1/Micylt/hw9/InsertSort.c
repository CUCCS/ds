#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int move, count=0;//设置全局变量来保存移动和比较的次数
void InsertSort(int p[],int size)  //实际上没有真正的设置监视哨
{
	int i, j;
	int temp;
	for (i = 0; i < size; i++)
	{
		temp = p[i];
		j = i - 1;
		while ((j >= 0) && (temp < p[j]))  //设置j>=0是为了防止下标越界
		{
			p[j + 1] = p[j];
			count = count + 1;
			j--;
			move = move + 1;
		}
		p[j + 1] = temp;
		count++;
	}
	

 }
void sran(int a[],int n)
{
	int i, count = 0;
	
	srand(time(NULL));
	for (i = 0; i<n; i++)
	{
		a[i] = rand() % 100 + 1;
		count++;
		if (count % 5 == 0)
		{ }
	}
}

int main()
{
	int array[20];
	int n;
	srand(time(0));
	n= rand()%20+1;
	sran(array,n);
	printf("原始顺序为：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("排序后的结果为：");
	InsertSort(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);

	}
	printf("\n");
	printf("总比较次数为：%d \n", count-1);
	printf("总移动次数为：%d \n", move);
	return 0;
}