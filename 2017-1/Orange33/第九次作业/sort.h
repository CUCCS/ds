#pragma once
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
     

void InsertSort(int *array, int n, int *comp, int *mov); //直接插入排序			   
void ShellSort(int *array, int n, int *comp, int *mov);  //希尔排序
void BubbleSort(int *array, int n, int *comp, int *mov); //起泡排序								  
void QuickSort(int *array, int left, int right, int count, int *comp, int *mov);//快速排序	  
void SelectSort(int * array, int n, int *comp, int *mov);//简单选择排序
void input(int *a, int n);         //随机生成测试数据
void output(int *a, int n );       //打印输出测试数据
void outTime(int comp, int mov);   //输出次数
void originArray(int* dest, int* source, int n);//初始数组保存

