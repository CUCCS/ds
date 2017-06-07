#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20
typedef int KeyType;
typedef int InfoType;

typedef struct
{
	KeyType key;                   //�ؼ�����
	InfoType otherinfo;          //����������
}RecordType;                       //��¼����

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

Status InsertSort(RecordType *r, int length, int *compare, int *move);      //ֱ�Ӳ�������

Status ShellSort(RecordType *r, int length, int *compare, int *move);   //ϣ������

Status BubbleSort(RecordType *r, int length, int *compare, int *move);   //��������

Status _QuickSort(RecordType*r, int length, int *compare, int* move);

Status QuickSort(RecordType*arr, int length, int *compare, int* move);  //��������

Status _SelectSort(RecordType *r, int length, int *compare, int *move);

Status SelectSort(RecordType *r, int length, int *compare, int *move);   //��ѡ������

void input(RecordType*r, int length);   //���ɲ�������

void Print(RecordType *r, int length);   //�����������

void Showtimes(int *compare, int *move);   //����ƶ������ͱȽϴ���

void CopyArr(RecordType* dest, const RecordType* source, int length);  //��������Ŀ��������ڽ���ͬһ�����ݶ��ֲ�ͬ������
