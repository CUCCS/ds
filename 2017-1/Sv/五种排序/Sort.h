#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int RecordType;
void Print(RecordType r[], int length);
void InsSort(RecordType r[], int length,int *a,int *b);
void ShellInsert(RecordType r[], int length, int delta,int *,int *);
void ShellSort(RecordType r[], int length,int *,int *);
void Copy(RecordType a[], RecordType b[], int c);
void BubbleSort(RecordType r[], int length, int *, int *);
void QKSort(RecordType r[], int low, int high,int *,int *);
void SelectSort(RecordType r[], int length, int *, int *);
