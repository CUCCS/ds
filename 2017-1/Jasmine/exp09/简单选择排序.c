#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 20
typedef struct List
{
	int data[Max];
	int length;
}SqList;//List的结构定义
void SelectSort(SqList* l, int* compare, int* move)
{
	int min;
	for (int i = 0; i < l->length-1; i++) 
	{
		min = i;
		for (int j = i + 1; j < l->length; j++) 
		{
			(*compare)++;
			if (l->data[min]  > l->data[j]) 
			{
				min = j;
			}
		}
		if (min != i) 
		{
			int temp = l->data[i];
			l->data[i] = l->data[min];
			l->data[min] = temp;
			(*move)++;
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
	SelectSort(&L, &compare, &move);
	printf("\nAfter Sort:\n");
	Print(&L);
	printf("\ncompare time:%d\nmove time:%d\n", compare, move);
}