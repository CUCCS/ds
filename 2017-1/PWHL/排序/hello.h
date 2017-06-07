//参考jackcily作业
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Maxsize 25
void copy(int *a, int *b, int n);
void print(int *p, int n, int sum1, int sum2);//打印数组
int Make(int *p);//随机生成数组
void insertSort(int *p, int n);//直接插入排序
void ShellSort(int *p, int n);   //希尔排序算法
void ShellInsert(int *q, int d, int *sum1, int *sum2, int n);
void BubbleSort(int *p, int n);//冒泡排序
int Partition(int *q, int n, int low, int high, int *sum1, int *sum2);//快速排序
void QSort(int *q, int n, int low, int high, int *sum1, int *sum2);//快速排序
void QuickSort(int *q, int n);
int change(int *q, int n, int low, int high);
void SelectSort(int *p, int n);//简单选择排序

