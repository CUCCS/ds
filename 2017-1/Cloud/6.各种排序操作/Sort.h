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
/* 打印数组 */
Status  PrintArray(ElemeyType *a, int l, int move_count, int compare_count);

/* 直接插入排序 */
Status InsSort(ElemeyType *r, int length, int *move_count, int *compare_count);

/* 一趟希尔插入排序 */
void ShellInsert(ElemeyType *r, int length, int delta, int *move_count, int *compare_count);

/* 希尔排序 */
void ShellSort(ElemeyType *r, int length, int *move_count, int *compare_count);

/* 冒泡排序 */
void BubbleSort(ElemeyType *r, int length, int *move_count, int *compare_count);

/* 快速排序 */
void QKSort(ElemeyType *r, int low, int high, int *move_count, int *compare_count);

/* 一趟快速排序 */
int QKPass(ElemeyType *r, int left, int right, int *move_count, int *compare_count);

/* 选择排序 */
void SelectSort(ElemeyType *r, int length, int *move_count, int *compare_count);

#endif
