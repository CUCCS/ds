#include <stdio.h>
#include <time.h>
#include <malloc.h>
typedef int KeyType;
typedef int OtherType;

typedef enum
{
	FALSE,
	TRUE
}Bool;

typedef struct
{
	KeyType key;
	OtherType data;
}RecordType;

void ShellInsert(RecordType *r, int length, int delta, int *cmp_count, int *mov_count);
int QKPass(RecordType *r, int left, int right, int *cmp_count, int *mov_count);
Bool LT(KeyType a, KeyType b);
void InsSort(RecordType *r, int length, int *cmp_count, int *mov_count);
void ShellSort(RecordType *r, int length, int *cmp_count, int *mov_count);
void ShellInsert(RecordType *r, int length, int delta, int *cmp_count, int *mov_count);
void BubbleSort(RecordType *r, int length, int *cmp_count, int *mov_count);
void QKSort(RecordType *r, int low, int high, int *cmp_count, int *mov_count);
int QKPass(RecordType *r, int left, int right, int *cmp_count, int *mov_count);

void SelectSort(RecordType *r, int length, int *cmp_count, int *mov_count);
void print(RecordType *r, int length, int cmp_count, int mov_count);
void Inital(RecordType *counts, RecordType *count, int length, int *cmp_count, int *mov_count);
