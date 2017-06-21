#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int KeyType; // 关键字类型

typedef enum { // 函数返回值
	ERROR,
	OK
}Status;

typedef enum { // 定义布尔函数值
	FALSE,
	TRUE
}bool;

typedef struct RecordType { // 记录结构
	KeyType key;
} RecordType;

//==================直接插入排序==================//
Status InsSort(RecordType **r, int length, int *compare, int *move);

//==================希尔排序==================//
Status ShellInsert(RecordType **r, int length, int delta, int *compare, int *move);
Status ShellSort(RecordType **r, int length, int *compare, int *move);

//==================冒泡排序==================//
Status BubbleSort(RecordType **r, int length, int *compare, int *move);

//==================快速排序==================//
Status QKSort(RecordType *r, int low, int high, int *compare, int *move);
int QKPass(RecordType **r, int left, int right, int *compare, int *move);

//==================简单选择排序==================//
Status SelectSort(RecordType **r, int length, int *compare, int *move);

//==================堆排序==================//
Status HeapAdjust(RecordType **r, int s, int m, int *compare, int *move);
Status HeapSort(RecordType **r, int length, int *compare, int *move);

//==================归并排序==================//
Status Merge(RecordType **r, RecordType **r1, int i, int m, int n, int *compare, int *move);
Status MSort(RecordType **r, RecordType **r1, int s, int t, int *compare, int *move);
Status MergeSort(RecordType **r, int length, int *compare, int *move);

//==================对数组的操作==================//
bool Empty(RecordType **r);
int CreateTest(RecordType **r);
Status Fresh(RecordType **r, int n, RecordType **p, int *compare, int *move);
Status Sort(RecordType **r, int n, int *compare, int *move);

//==================输出函数==================//
Status PrintCase(RecordType **r, int n);
Status PrintNum(int *compare, int *move);
Status Print(RecordType **r, int n, int *compare, int *move);