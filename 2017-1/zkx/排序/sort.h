#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20
typedef int KeyType;
typedef int InfoType;

typedef struct
{
	KeyType key;                   //关键字项
	InfoType otherinfo;          //其他数据项
}RecordType;                       //记录类型

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef  enum _bool
{
	TRUE,
	FALSE
}bool;

Status InsertSort(RecordType *r, int length, int *compare, int *move);      //直接插入排序

Status ShellSort(RecordType *r, int length, int *compare, int *move);   //希尔排序

Status BubbleSort(RecordType *r, int length, int *compare, int *move);   //起泡排序

Status _QuickSort(RecordType*r, int length, int *compare, int* move);

Status QuickSort(RecordType*arr, int length, int *compare, int* move);  //快速排序

Status _SelectSort(RecordType *r, int length, int *compare, int *move);

Status SelectSort(RecordType *r, int length, int *compare, int *move);   //简单选择排序

void input(RecordType*r, int length);   //生成测试数据

void Print(RecordType *r, int length);   //输出测试数据

void Showtimes(int *compare, int *move);   //输出移动次数和比较次数

void CopyArr(RecordType* dest, const RecordType* source, int length);  //进行数组的拷贝，用于进行同一组数据多种不同的排序
