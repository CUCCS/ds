#include<stdio.h>
#include<stdlib.h>
typedef char  ElemType;
typedef int status;
#define num 20
int number = 0;//����һ��ȫ�ֱ���  ���ڸ�ֵʱ�ļ���
//���������
typedef struct  BiTree
{
	ElemType  date;
	struct  BiTree *lChild;
	struct  BiTree * rChild;
}  BitNode, *BiTree;
status CreatBiTree(BiTree *t, char *x);//������������
void  VisitHouxu(BiTree t);//��������