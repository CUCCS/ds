#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef int KeyType;
typedef int InfoType;
#define maxsize 20
#define len 10
#define LT(a,b) ((a)<(b))
typedef struct
{
	KeyType key;
	InfoType otherinfo;
}RedType;
typedef struct
{
	RedType r[maxsize + 1];
	int length;
}SqList;
void swap(SqList*L, int i, int j);
void ShellSort(SqList*L);
void InsertSort(SqList*L);
void BubbleSort(SqList*L);
void QuickSort(SqList*L);
void QSort(SqList*L, int low, int high, int*count1, int*count2);
int Partition(SqList*L, int low, int high, int*count1, int*count2);
void SelectSort(SqList*L);
