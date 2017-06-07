#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fpo;

#define MAXSIZE 20
typedef enum{
	FALSE,
	TRUE
}Bool;

//刷新数组
int *Fresh(int a[]);

//直接插入排序
void InsertSort( int a[], int n );

//希尔排序
void ShellSort( int a[], int n );

//起泡排序
void BubbleSort( int a[], int n );

//快速排序
void QuickSort( int a[], int l, int r );

//简单选择排序
void SelectSort( int a[], int n );

//堆排序
void HeapAdjust(int a[], int i, int n);
void HeapSort( int a[], int n ); 

//归并排序
void MergeArray( int a[], int first, int mid, int last, int temp[]);
void MergeSort(int a[], int first, int last, int temp[]);
Bool MergeSort(int a[], int n);

//输出排序结果
void printSort(int a[]);