#include<stdio.h>
#include<stdlib.h>
typedef char  ElemType;
typedef int status;
#define num 30
#define width_num 10
int number = 0;//����һ��ȫ�ֱ���  ���ڸ�ֵʱ�ļ���
			   //���������
typedef struct  BiTree
{
	ElemType  date;
	struct  BiTree *lChild;
	struct  BiTree * rChild;
}  BitNode, *BiTree;
int TreeDeep(BiTree T);//�����������
status CreatBiTree(BiTree *t, char *x);//������������
void  VisitHouxu(BiTree t);//��������