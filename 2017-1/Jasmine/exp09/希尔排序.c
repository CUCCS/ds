#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Max 20
typedef struct List
{
	int data[Max];
	int length;
}SqList;//List�Ľṹ����
void ShellSort(SqList *l) 
{
	int gap = l->length / 2;  //���ò���Ϊlist���ȵ�һ��
	for (;gap >= 1;gap = gap / 2) 
	{  //����ÿ�μ��룬ֱ������Ϊһ������ֱ�Ӳ�������
		int m;
		for (m = 0;m < gap;m++) 
		{  //�ҵ�ÿ�������е���㣬m,m+gap,m+gap+gap...�����Ƕ�������н���ֱ�Ӳ�������
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
					j = j - gap;  //�±���ת����һ��Ԫ�� 					
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
	ShellSort(&L, 0, L.length - 1);
	printf("\nAfter Sort:\n");
	Print(&L);
	//printf("\ncompare time:%d\nmove time:%d\n", compare, move);
}