#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAXSIZE 20
#define LENGTH 10
#define LT(a,b) ((a)<(b))
typedef int KeyType;
typedef int InfoType;
typedef struct
{
	KeyType key;
	InfoType otherinof;
}RedType;
typedef struct
{
	RedType r[MAXSIZE];
	int length;
}SqList;
void CreatArray(SqList *s);
void print(int n, int sum1, int sum2);
void InsertSort(SqList *L);
int Partition(SqList *L, int low, int high, int *sum1, int *sum2);
void QSort(SqList *L, int low, int high, int *sum1, int *sum2);
void QuickSort(SqList *L);
int SelectMinKey(SqList L, int i);
void SelectSort(SqList*L);
void BubbleSort(SqList*L);
void ShellInsert(SqList *L, int dk, int *sum1, int *sum2);
void ShellSort(SqList *L);