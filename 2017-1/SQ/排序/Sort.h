#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int KeyType; // �ؼ�������

typedef enum { // ��������ֵ
	ERROR,
	OK
}Status;

typedef enum { // ���岼������ֵ
	FALSE,
	TRUE
}bool;

typedef struct RecordType { // ��¼�ṹ
	KeyType key;
} RecordType;

//==================ֱ�Ӳ�������==================//
Status InsSort(RecordType **r, int length, int *compare, int *move);

//==================ϣ������==================//
Status ShellInsert(RecordType **r, int length, int delta, int *compare, int *move);
Status ShellSort(RecordType **r, int length, int *compare, int *move);

//==================ð������==================//
Status BubbleSort(RecordType **r, int length, int *compare, int *move);

//==================��������==================//
Status QKSort(RecordType *r, int low, int high, int *compare, int *move);
int QKPass(RecordType **r, int left, int right, int *compare, int *move);

//==================��ѡ������==================//
Status SelectSort(RecordType **r, int length, int *compare, int *move);

//==================������==================//
Status HeapAdjust(RecordType **r, int s, int m, int *compare, int *move);
Status HeapSort(RecordType **r, int length, int *compare, int *move);

//==================�鲢����==================//
Status Merge(RecordType **r, RecordType **r1, int i, int m, int n, int *compare, int *move);
Status MSort(RecordType **r, RecordType **r1, int s, int t, int *compare, int *move);
Status MergeSort(RecordType **r, int length, int *compare, int *move);

//==================������Ĳ���==================//
bool Empty(RecordType **r);
int CreateTest(RecordType **r);
Status Fresh(RecordType **r, int n, RecordType **p, int *compare, int *move);
Status Sort(RecordType **r, int n, int *compare, int *move);

//==================�������==================//
Status PrintCase(RecordType **r, int n);
Status PrintNum(int *compare, int *move);
Status Print(RecordType **r, int n, int *compare, int *move);