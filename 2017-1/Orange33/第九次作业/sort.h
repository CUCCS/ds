#pragma once
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
     

void InsertSort(int *array, int n, int *comp, int *mov); //ֱ�Ӳ�������			   
void ShellSort(int *array, int n, int *comp, int *mov);  //ϣ������
void BubbleSort(int *array, int n, int *comp, int *mov); //��������								  
void QuickSort(int *array, int left, int right, int count, int *comp, int *mov);//��������	  
void SelectSort(int * array, int n, int *comp, int *mov);//��ѡ������
void input(int *a, int n);         //������ɲ�������
void output(int *a, int n );       //��ӡ�����������
void outTime(int comp, int mov);   //�������
void originArray(int* dest, int* source, int n);//��ʼ���鱣��

