//�㷨2.12   ��̬������   �αָ꣨ʾ��cur��

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define OK 0
#define ERROR 1
#define OVERFLOW 2

typedef int ElemType;

typedef struct {
	ElemType data;
	int cur;
}component, SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList &spcae);            //��ʼ��

int Malloc_SL(SLinkList &spcae);                //���ط���Ľڵ�����

int LocateElem_SL(SLinkList S, ElemType e);     //���ҵ�һ��Ϊe��Ԫ��

void Free_SL(SLinkList &space, int k);          //���±�Ϊk�Ŀ��нڵ����

int difference(SLinkList &space, int &S);       //�������(A-B)��(B-A),����S���������ͷ��㣩

void Print_L(SLinkList &space, int i);          //�������

int Create_L(SLinkList *space, int n, int &S);  //����Ԫ�ظ���Ϊn���������