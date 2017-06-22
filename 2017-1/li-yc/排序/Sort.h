#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20

typedef enum {
	false,
	true,
}bool;
typedef enum {
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct {
	int r[MAXSIZE];
	int length;
}SqList;

Status InsertSort(SqList *a, int *ctime, int *mtime);
Status ShellInsert(SqList *a, int dk, int *ctime, int *mtime);
Status BubbleSort(SqList *a, int *ctime, int *mtime);
Status QKSort(SqList *a, int low, int high, int *ctime, int *mtime);
int QKPass(SqList *a, int left, int right, int *ctime, int *mtime);
Status SelectSort(SqList *a, int *ctime, int *mtime);
Status Traverse(SqList a);
Status InitTestArrary(SqList *a, SqList *a1, int *ctime, int *mtime);