#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 20
typedef struct List
{
	int data[Max];
	int length;
}SqList;//List�Ľṹ����
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
		L.data[i] = 0;//��ʼ��data����
	}
	for (i = 0;i < length;i++)
	{
		a = rand() % 20;//��������б�Ԫ��
		L.data[i] = a;//���β������ݽ�������
	}
	Print(&L);//��ӡ�����б�
	SelectSort(&L, &compare, &move);
	printf("\nAfter Sort:\n");
	Print(&L);
	printf("\ncompare time:%d\nmove time:%d\n", compare, move);
}