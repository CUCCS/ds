#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 20
typedef struct List
{
	int data[Max];//data[0]��Ϊ������λ
	int length;
}SqList;//List�Ľṹ����
void BubbleSort(SqList *l,int* compare,int* move)
{
	int i, j;
	for (i = 0;i < l->length;i++)
	{
		for (j = i + 1;j < l->length;j++)
		{
			(*compare)++;
			if (l->data[i] > l->data[j])
			{
				int temp = l->data[i];
				l->data[i] = l->data[j];
				l->data[j] = temp;
				(*move)++;
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
	int length;//��������б���
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
		L.data[i] = 0;
	}
	for (i = 0;i < length;i++)
	{
		a = rand() % 20;//��������б�Ԫ��
		L.data[i] = a;
	}
	Print(&L);
	BubbleSort(&L,&compare,&move);
	printf("\nAfter Sort:\n");
	Print(&L);
	printf("\ncompare time:%d\nmove time:%d\n", compare, move);
}