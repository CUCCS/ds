#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 20
typedef struct List
{
	int data[Max];
	int length;
}SqList;//List�Ľṹ����

int FindPos(SqList*l, int i, int j)
{
	int val = l->data[i];
	while (i<j)
	{  //��һ�ο���������ֻҪi��ֵ��jС�����Ǿ�Ӧ��ȥ�ƶ�����Ϊ��ǰ�������û����� 
		while (i<j&&l->data[j] >= val)
		{  //��ʾֻ�е�ǰָ��û���غϲ��ҵ�ǰ�ұ�jָ���ֵ����valʱ���Ż������ƶ�j
			j = j - 1;
		}
		l->data[i] = l->data[j];  //����valС��ֵ����i 
		while (i<j&&l->data[i] <= val)
		{
			i = i + 1;
		}
		l->data[j] = l->data[i];  //����val���ֵ����j�� 

	}
	l->data[i] = val;
	return j;
}
void QuickSort(SqList* l, int low, int high)//��������
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
	QuickSort(&L, 0, L.length - 1);
	printf("\nAfter Sort:\n");
	Print(&L);
	//printf("\ncompare time:%d\nmove time:%d\n", compare, move);
}