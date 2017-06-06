#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int KeyType; 
typedef struct
{ 
	KeyType key; 
	//int  data;
} RecordType;
typedef enum
{
	OK,
	ERROR
}Status;

Status InsSort(RecordType r[], int length,int *compare,int *move);
Status ShellInsert(RecordType r[], int length, int delta,int *compare,int *move);
Status ShellSort(RecordType r[], int length,int *compare,int *move);
Status BubbleSort(RecordType r[], int length,int *compare,int *move);
int QKPass(RecordType r[], int left, int right,int *compare,int *move);
int QKPass(RecordType r[], int left, int right,int *compare,int *move);
Status SelectSort(RecordType r[], int length,int *compare,int *move);
Status MyPrint(RecordType **r,int *com,int *mov);

Status InsSort(RecordType r[], int length,int *compare,int *move)
{
	int i,j;
	RecordType temp;
	for(i = 1; i < length; i++)
	{ 
		temp = r[i]; /* ���������¼��ŵ���ʱ������ */
		j = i - 1; /* ���һ����������ı߽�λ�� */
		while(++(*compare),temp.key < r[j].key) { /* Ѱ�Ҳ���λ�� */
			r[j+1] = r[j];
			/* ��С�������򣬴�Ԫ������ */
			j = j - 1;
			*move += 3;
			/* ������Ԫ��������������һ��������һλ��Ԫ�ؼ������бȽ� */ 
		} 
		r[j+1] = temp;
		/* ���������¼���뵽������������� */
	}
	return OK;
}

Status ShellInsert(RecordType r[], int length, int delta,int *compare,int *move) {
	int i,j;
	RecordType temp;
	for(i = delta; i < length; i++) { /* 1+deltaΪ��һ�������еĵڶ���Ԫ�ص��±� */
		if(++(*compare) , r[i].key < r[i-delta].key) {
			temp = r[i];
			(*move)++;
			for(j = i - delta;(++(*compare)), j >= 0 && temp.key < r[j].key; j -= delta) {
				r[j+delta] = r[j];
				(*move)++;
			}
			r[j+delta] = temp;
			(*move)++;
		}
	}
	return OK;
}

/* �Լ�¼����r��ϣ������ lengthΪ����ĳ���*/
Status ShellSort(RecordType r[], int length,int *compare,int *move) {
	int d = length / 2;
	while(d >= 1) {
		ShellInsert(r, length, d,compare,move); 
		d = d / 2;
	}
	return OK;
}

/* �Լ�¼����r��ð������lengthΪ����ĳ��� */
Status BubbleSort(RecordType r[], int length,int *compare,int *move) {
	int i,j;
	int change = 1;
	RecordType *temp =(RecordType*)malloc(sizeof(RecordType));
	for(i = 0; i < length - 1 && change; ++i) {
		change = 0;
		for(j = 0; j < length - i - 1; ++j) {
			if( ++(*compare) && r[j].key > r[j+1].key) {
				*temp = r[j];
				r[j] = r[j+1];
				r[j+1] = *temp;
				++(*move);
				change = 1;
			}
		}
	}
	return OK;
}

/* �Լ�¼����r[low..high]�ÿ��������㷨�������� */
Status QKSort(RecordType r[],int low, int high,int *compare,int *move) {
	int pivot;
	if(low < high) {
		pivot = QKPass(r, low, high,compare,move); 
		QKSort(r, low, pivot - 1,compare,move);    
		QKSort(r, pivot + 1, high,compare,move);
	}
	return OK;
}

/* �Լ�¼����r �е�r[left]��r[right]���ֽ���һ�����򣬲��õ���׼��λ�ã�ʹ�������Ľ��������֮��ǰ���ļ�¼�Ĺؼ��־���С�ڣ����ڣ��ڻ�׼��¼ */
int QKPass(RecordType r[], int left, int right,int *compare,int *move) {
	int low,high;
	RecordType *x =(RecordType*)malloc(sizeof(RecordType));
	*x = r[left];             /* ѡ���׼��¼*/
	(*move)++;
	low = left;
	high = right;
	while(low < high) {
		while(low < high && ++(*compare) && r[high].key >= (*x).key) { /* high���ҵ�����С��x.key�ļ�¼ */ 
			high--;
		}
		r[low] = r[high]; /* �ҵ�С��x.key�ļ�¼������н��� */
		(*move)++;
		while(low < high  && ++(*compare) && r[low].key < (*x).key) { /* low�������Ҳ�С��x.key�ļ�¼ */
			low++;
		}
		r[high] = r[low]; /* �ҵ���С��x.key�ļ�¼���򽻻�*/
		(*move)++;
	}

	r[low] = (*x);  /* ����׼��¼���浽low=high��λ�� */
	(*move)++;
	return low;  /*���ػ�׼��¼��λ��*/
}

/* �Լ�¼����r����ѡ������lengthΪ����ĳ��� */
Status SelectSort(RecordType r[], int length,int *compare,int *move) {
	int i,j,k;
	RecordType *temp =(RecordType*)malloc(sizeof(RecordType));
	for(i = 0; i < length-1; ++i) {
		k = i;
		for(j = i+1 ; j < length; ++j) {
			if(++(*compare) && r[j].key < r[k].key) {
				k = j;
			}
		} 
		if(k != i) { 
			*temp = r[i];
			r[i] = r[k];
			r[k]=*temp;
			(*move) += 3;
		}
	}
	return OK;
}
Status MyPrint(RecordType (*r)[8],int *com,int *mov)
{
	int i,j;
	InsSort(r[0],8,com,mov);
	ShellSort(r[1],8,com+1,mov+1);
	BubbleSort(r[2],8,com+2,mov+2);
	QKSort(r[3],0,7,com+3,mov+3);
	SelectSort(r[4],8,com+4,mov+4);
	for (i = 0;i < 5 ;i++)
	{
		for (j = 0;j < 8;j++)
		{
			printf("%d ",r[i][j].key);
		}
		printf("\n%d %d %d\n",com[i],mov[i],com[i]+mov[i]);
	}
	return OK;
}
int main()
{
	RecordType (*r)[8] = (RecordType(*)[8])malloc(5*sizeof(RecordType[8]));
	int i,j;
	int *com = (int*)calloc(5,sizeof(int));
	int *mov = (int*)calloc(5,sizeof(int));
	srand( time(NULL) );
	for (i = 0;i < 5 ;i++)
	{
		for(j = 0;j < 8;j++)
		{
			r[i][j].key = rand()%57;
		}
	}
	MyPrint(r,com,mov);
	return 0;
}