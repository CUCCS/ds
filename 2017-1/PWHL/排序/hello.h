//�ο�jackcily��ҵ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Maxsize 25
void copy(int *a, int *b, int n);
void print(int *p, int n, int sum1, int sum2);//��ӡ����
int Make(int *p);//�����������
void insertSort(int *p, int n);//ֱ�Ӳ�������
void ShellSort(int *p, int n);   //ϣ�������㷨
void ShellInsert(int *q, int d, int *sum1, int *sum2, int n);
void BubbleSort(int *p, int n);//ð������
int Partition(int *q, int n, int low, int high, int *sum1, int *sum2);//��������
void QSort(int *q, int n, int low, int high, int *sum1, int *sum2);//��������
void QuickSort(int *q, int n);
int change(int *q, int n, int low, int high);
void SelectSort(int *p, int n);//��ѡ������

