#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ListNum 25
void copy(int *a, int *b, int length);
void print_(int *  q, int length, int num1, int num2);
int  make(int *q);
void Sort(int *q, int length);
void InsertSort(int *q, int length);
void ShellInsert(int *q, int dk, int *num1, int *num2, int length);
void ShellSort(int *q, int length);
int Partition(int *q, int length, int low, int high, int *num1, int *num2);
void QSort(int *q, int length, int low, int high, int *num1, int *num2);
void QuickSort(int*q, int length);
int change(int *q, int length, int low, int high);
void SelectSort(int *q, int length);