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
		temp = r[i]; /* 将待插入记录存放到临时变量中 */
		j = i - 1; /* 最近一次排序结束的边界位置 */
		while(++(*compare),temp.key < r[j].key) { /* 寻找插入位置 */
			r[j+1] = r[j];
			/* 从小到大排序，大元素右移 */
			j = j - 1;
			*move += 3;
			/* 待插入元素与已排序区下一个（左移一位）元素继续进行比较 */ 
		} 
		r[j+1] = temp;
		/* 将待插入记录插入到已排序的序列中 */
	}
	return OK;
}

Status ShellInsert(RecordType r[], int length, int delta,int *compare,int *move) {
	int i,j;
	RecordType temp;
	for(i = delta; i < length; i++) { /* 1+delta为第一个子序列的第二个元素的下标 */
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

/* 对记录数组r做希尔排序， length为数组的长度*/
Status ShellSort(RecordType r[], int length,int *compare,int *move) {
	int d = length / 2;
	while(d >= 1) {
		ShellInsert(r, length, d,compare,move); 
		d = d / 2;
	}
	return OK;
}

/* 对记录数组r做冒泡排序，length为数组的长度 */
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

/* 对记录数组r[low..high]用快速排序算法进行排序 */
Status QKSort(RecordType r[],int low, int high,int *compare,int *move) {
	int pivot;
	if(low < high) {
		pivot = QKPass(r, low, high,compare,move); 
		QKSort(r, low, pivot - 1,compare,move);    
		QKSort(r, pivot + 1, high,compare,move);
	}
	return OK;
}

/* 对记录数组r 中的r[left]至r[right]部分进行一趟排序，并得到基准的位置，使得排序后的结果满足其之后（前）的记录的关键字均不小于（大于）于基准记录 */
int QKPass(RecordType r[], int left, int right,int *compare,int *move) {
	int low,high;
	RecordType *x =(RecordType*)malloc(sizeof(RecordType));
	*x = r[left];             /* 选择基准记录*/
	(*move)++;
	low = left;
	high = right;
	while(low < high) {
		while(low < high && ++(*compare) && r[high].key >= (*x).key) { /* high从右到左找小于x.key的记录 */ 
			high--;
		}
		r[low] = r[high]; /* 找到小于x.key的记录，则进行交换 */
		(*move)++;
		while(low < high  && ++(*compare) && r[low].key < (*x).key) { /* low从左到右找不小于x.key的记录 */
			low++;
		}
		r[high] = r[low]; /* 找到不小于x.key的记录，则交换*/
		(*move)++;
	}

	r[low] = (*x);  /* 将基准记录保存到low=high的位置 */
	(*move)++;
	return low;  /*返回基准记录的位置*/
}

/* 对记录数组r做简单选择排序，length为数组的长度 */
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