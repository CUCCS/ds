#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 20
typedef struct List
{
	int data[Max];
	int length;
}SqList;//List的结构定义

int FindPos(SqList*l, int i, int j)
{
	int val = l->data[i];
	while (i<j)
	{  //再一次快速排序中只要i的值比j小，我们就应该去移动，因为当前这次排序还没有完成 
		while (i<j&&l->data[j] >= val)
		{  //表示只有当前指针没有重合并且当前右边j指向的值大于val时，才会向左移动j
			j = j - 1;
		}
		l->data[i] = l->data[j];  //将比val小的值赋到i 
		while (i<j&&l->data[i] <= val)
		{
			i = i + 1;
		}
		l->data[j] = l->data[i];  //将比val大的值赋到j上 

	}
	l->data[i] = val;
	return j;
}
void QuickSort(SqList* l, int low, int high)//快速排序
{
	int pos;
	if (low < high)
	{
		pos = FindPos(l, low, high);
		QuickSort(l, low, pos - 1);
		QuickSort(l, pos + 1, high);
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
	QuickSort(&L, 0, L.length - 1);
	printf("\nAfter Sort:\n");
	Print(&L);
	//printf("\ncompare time:%d\nmove time:%d\n", compare, move);
}