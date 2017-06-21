#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fpo;

#define MAXSIZE 20
typedef enum{
	FALSE,
	TRUE
}Bool;

//ˢ������
int *Fresh(int a[]);

//ֱ�Ӳ�������
void InsertSort( int a[], int n );

//ϣ������
void ShellSort( int a[], int n );

//��������
void BubbleSort( int a[], int n );

//��������
void QuickSort( int a[], int l, int r );

//��ѡ������
void SelectSort( int a[], int n );

//������
void HeapAdjust(int a[], int i, int n);
void HeapSort( int a[], int n ); 

//�鲢����
void MergeArray( int a[], int first, int mid, int last, int temp[]);
void MergeSort(int a[], int first, int last, int temp[]);
Bool MergeSort(int a[], int n);

//���������
void printSort(int a[]);