#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 10   //һ������ʾ����С˳������󳤶�

typedef struct
{
	int r[MAXSIZE + 1];        //r��0�����û������ڱ���Ԫ
	int length;                //˳�����
}SqList;                      //˳�������

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;         //ö�ٶ��壨����״̬��

typedef enum
{
	True,
	False
}Bool;          //���岼������

Status copy(SqList *L,SqList *p)
{
	int i;
	for(i = 0; i < MAXSIZE; i++)
	{
		L->r[i] = p->r[i];
	}
	return OK;
}

Status InsertSort(SqList* L,int* compare,int* move)
{
	int i,j;
	for (i = 1; i < L->length ; i++)
	{
		if(L->r[i] < L->r[i - 1])
		{
			L->r[0] = L->r[i];
			L->r[i] = L->r[i - 1];
			(*compare)++;
	        (*move)++;
			for(j = i - 2; L->r[0] < L->r[j];--j)
			{
				L->r[j + 1] = L->r[j];
				 (*move)++;
			}
			L->r[j + 1] = L->r[0];
			(*compare)++;
		}
	}
	return OK;
}

void BubbleSort(SqList *l,int* compare,int* move) 
{ 
	int i, j; 
	int temp;
	for (i = 0;i < l->length;i++) 
	{ 
		for (j = i + 1;j < l->length;j++) 
		{ 
			(*compare)++; 
			if (l->r[i] > l->r[j]) 
			{ 
				temp = l->r[i]; 
				l->r[i] = l->r[j]; 
				l->r[j] = temp; 
				(*move)++; 
			} 
		} 
	} 
} 

void ShellSort(SqList *l,int* compare,int* move)  
{ 
	int gap = l->length / 2;  //���ò���Ϊlist���ȵ�һ�� 
	for (;gap >= 1;gap = gap / 2)  
	{  //����ÿ�μ��룬ֱ������Ϊһ������ֱ�Ӳ������� 
		int m; 
		for (m = 0; m < gap; m++)  
		{  //�ҵ�ÿ�������е���㣬m,m+gap,m+gap+gap...�����Ƕ�������н���ֱ�Ӳ������� 
			int i; 
			int temp; 
			for (i = m + gap;i < l->length;i = i + gap)  
			{ 
				int j = i; 
				while (j != m)  
				{ 
					if (l->r[j] <= l->r[j - gap])  
					{ 
						(*compare)++; 
						temp = l->r[j - gap]; 
						l->r[j - gap] = l->r[j]; 
						l->r[j] = temp; 
					} 
					j = j - gap;  //�±���ת����һ��Ԫ�� 
					(*move)++;
				}			 
			}				 
		}		 
	} 
}

Status output(SqList L)
{
	int i;
	for(i = 0; i < MAXSIZE; i++)
	{
		printf("%d ",L.r[i]);
	}
	printf("\n");
	return OK;
}

int _QSort(SqList *L,int low,int high,int *compare,int *move)
{
	int pivotkey = L->r[low];
	while(low < high)
	{
		while(low < high && L->r[high] >= pivotkey && (*compare)++)
		{
			high--;
		}
		L->r[low] = L->r[high];
		++(*move);
		while(low < high && L->r[low] <= pivotkey && ((*compare)++))
		{
			low++;
		}
		L->r[high] = L->r[low];
		++(*move);
	}
	L->r[low] = L->r[0];
	(*move)++;
	return low;
}

Status QSort(SqList *L,int low,int high,int *compare,int *move)
{
	int pivotlo;
	if(low < high)
	{
		pivotlo = _QSort(L,low,high,compare,move);
		QSort(L,low,pivotlo - 1,compare,move);
		QSort(L,pivotlo + 1,high,compare,move);
	}
	return OK;
}

int SelectMinKey(SqList* L,int i,int *compare,int *move)
{
	int k = i;
	int j = i+1;
	for(;j < L->length; ++j)
	{
		if(L->r[k] > L->r[j])
		{
			(*compare)++;
			k = j;
		}
	}
	return k;
}

Status SetectSort(SqList *L,int *compare,int *move)
{
	int i;
	int j;
	int temp;
	for(i = 1; i < L->length; i++)
	{
		j = SelectMinKey(L,i,compare,move);
		if(i != j)
		{
			temp = L->r[i];
			L->r[i] = L->r[j];
			L->r[j] = temp;
			(*move)++;
		}
	}
	return OK;
}

int main()
{
	int compare = 0,move = 0;
	int i;
	SqList a,b;

	srand(time(NULL));
	a.length = b.length = 0;
	for(i = 0; i < MAXSIZE; i++)
	{
		a.r[i] = rand() % 100 + 1;
		b.r[i] = a.r[i];
		a.length++;
		b.length++;
	}

	printf("��������Ϊ��\n"); 
	output(a);
	printf("\n");

	printf("����ֱ������������Ϊ��"); 
	InsertSort(&b,&compare,&move); 
	output(b);
	printf("�ܱȽϴ�����%d\n�����������%d\n����֮�ͣ�%d\n\n",compare,move,compare+move); 

	copy(&a,&b);
	printf("����ϣ������������Ϊ��"); 
	ShellSort(&b,&compare,&move); 
	output(b);
	printf("�ܱȽϴ�����%d\n�����������%d\n����֮�ͣ�%d\n\n",compare,move,compare+move); 

	copy(&a,&b);
	printf("������������������Ϊ��"); 
	BubbleSort(&b,&compare,&move); 
	output(b);
	printf("�ܱȽϴ�����%d\n�����������%d\n����֮�ͣ�%d\n\n",compare,move,compare+move); 
    
	copy(&a,&b);
	printf("����������������Ϊ��"); 
	SetectSort(&b,&compare,&move); 
	output(b);
	printf("�ܱȽϴ�����%d\n�����������%d\n����֮�ͣ�%d\n\n",compare,move,compare+move); 

	copy(&a,&b);
	printf("������������������Ϊ��"); 
	QSort(&b,0,9,&compare,&move);
	output(b);
	printf("�ܱȽϴ�����%d\n�����������%d\n����֮�ͣ�%d\n\n",compare,move,compare+move); 

	
	return 0;
}