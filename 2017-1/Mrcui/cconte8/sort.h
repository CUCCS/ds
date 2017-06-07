#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insert_sort(int a[], int n);//直接插入排序
void shell_sort(int a[], int n);//希尔排序
void bubble_sort(int a[], int n);//起泡排序
void quick_sort(int a[], int left, int right, int *movecount, int *comcount);//快速排序
void select_sort(int array[], int arrayCount);//简单选择排序
void copyarray(int a[], int b[], int n);//恢复随机序列
