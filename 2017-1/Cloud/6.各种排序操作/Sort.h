#pragma once
#ifndef SORT_H
#define SORT_H
#include<stdio.h>
#define ElemeyType int 
#define len  5
typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum {
	FALSE,
	TRUE
}bool;
/* ��ӡ���� */
Status  PrintArray(ElemeyType *a, int l, int move_count, int compare_count);

/* ֱ�Ӳ������� */
Status InsSort(ElemeyType *r, int length, int *move_count, int *compare_count);

/* һ��ϣ���������� */
void ShellInsert(ElemeyType *r, int length, int delta, int *move_count, int *compare_count);

/* ϣ������ */
void ShellSort(ElemeyType *r, int length, int *move_count, int *compare_count);

/* ð������ */
void BubbleSort(ElemeyType *r, int length, int *move_count, int *compare_count);

/* �������� */
void QKSort(ElemeyType *r, int low, int high, int *move_count, int *compare_count);

/* һ�˿������� */
int QKPass(ElemeyType *r, int left, int right, int *move_count, int *compare_count);

/* ѡ������ */
void SelectSort(ElemeyType *r, int length, int *move_count, int *compare_count);

#endif
