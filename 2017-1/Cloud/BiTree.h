//���������ö�������洢
//���������������߶ȵ��㷨���������ĸ߶�Ҳ�ж���������ȣ���
//�������������ȵ��㷨�����������������ָ���������в��н����������ֵ����
//--------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#define  MAX_TREE_SIZE  100      // ���������������
#define TElemType char 
extern int count ;
typedef enum{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef struct BiTNode { // ���ṹ
	TElemType      data;
    struct BiTNode  *lchild, *rchild; // ���Һ���ָ��
} BiTNode, *BiTree;

Status CreateBiTree(BiTree *T ,TElemType* d);
int Postorder(BiTree T);
int Depth(BiTree T);
int Width(BiTree T);
