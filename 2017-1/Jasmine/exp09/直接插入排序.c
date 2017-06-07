#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 20
typedef struct List
{
	int data[Max];//data[0]作为监视哨位
	int length;
}SqList;//List的结构定义
void InsertSort(SqList *l,int a)
{
	int i, j;
	l->length++;
	l->data[0] = a;//将插入的数据先放入监视哨位
	i = l->length - 1;
		while (l->data[0] < l->data[i])
		{
			l->data[i + 1] = l->data[i];//数据后移
			i--;
		}
		l->data[i+1] = l->data[0];//合理位置插入数据
}

void Print(SqList*l)
{
	int i;
	for (i = 1;i < l->length;i++)
	{
		printf("%d ", l->data[i]);
	
	}
	//printf("compare time:%d\nmove time:%d\n", compare, move);
}
int main()
{
	srand(time(NULL));
	SqList L;
	L.length = 0;
	int length;//随机生成列表长度
	do 
	{ 
		length = rand() % 10;
	} while (length < 5);
	int i,a;
	int compare, move;
	compare = move = 0;
	for (i = 0;i < Max;i++)
	{
		L.data[i] = 0;
	}
	for (i = 0;i < length;i++)
	{
		a = rand() % 20;//随机生成列表元素
		InsertSort(&L, a);
		Print(&L);
	}

	
}