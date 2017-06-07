#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 20
typedef struct List
{
	int data[Max];
	int length;
}SqList;//List的结构定义
void ShellSort(SqList *l) 
{
	int gap = l->length / 2;  //设置步长为list长度的一半
	for (;gap >= 1;gap = gap / 2) 
	{  //步长每次减半，直至步长为一，进行直接插入排序
		int m;
		for (m = 0;m < gap;m++) 
		{  //找到每个子序列的起点，m,m+gap,m+gap+gap...则我们对这个序列进行直接插入排序
			int i;
			int temp;
			for (i = m + gap;i < l->length;i = i + gap) 
			{
				int j = i;
				while (j != m) 
				{
					if (l->data[j] <= l->data[j - gap]) 
					{
						temp = l->data[j - gap];
						l->data[j - gap] = l->data[j];
						l->data[j] = temp;
					}
					j = j - gap;  //下标跳转到下一个元素 					
				}			
			}				
		}		
	}
}
void Print(SqList*l)
{
	int i;
	for (i = 0;i < l->length;i++)
	{
		printf("%d ", l->data[i]);

	}
}
int main()
{
	srand(time(NULL));
	SqList L;
	int length;//随机生成列表长度
	do
	{
		length = rand() % 10;
	} while (length < 5);
	L.length = length;
	int i, a;
	int compare, move;
	compare = move = 0;
	for (i = 0;i < Max;i++)
	{
		L.data[i] = 0;//初始化data数组
	}
	for (i = 0;i < length;i++)
	{
		a = rand() % 20;//随机生成列表元素
		L.data[i] = a;//依次插入数据进入数组
	}
	Print(&L);//打印无序列表
	ShellSort(&L, 0, L.length - 1);
	printf("\nAfter Sort:\n");
	Print(&L);
	//printf("\ncompare time:%d\nmove time:%d\n", compare, move);
}