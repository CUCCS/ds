#include<stdio.h>
#include<stdlib.h>
typedef char  ElemType;
typedef int status;
#define num 30
int number = 0;//定义一个全局变量  用于赋值时的计数
			   //定义二叉树
typedef struct  BiTree
{
	ElemType  date;
	struct  BiTree *lChild;
	struct  BiTree * rChild;
}  BitNode, *BiTree;
status CreatBiTree(BiTree *t, char *x);//先序创立二叉树
void  VisitHouxu(BiTree t);//后续遍历