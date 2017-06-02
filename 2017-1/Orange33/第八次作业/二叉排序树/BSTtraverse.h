#pragma once
#include<stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
	int data;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

typedef enum {
	false,
	true
}bool;

BSTree InsertBST(BSTree T, int data);  //������
BSTree CreatBST(BSTree T, int array[]); //����������
bool SearchBST(BSTree T, int key);     //���Ҷ�����������Ŀ����
void PrePrintBST(BSTree T);            //����������������
bool DeleteBST(BSTree *T, int key);    //ɾ����key��ͬ�Ľ��
bool Delete(BSTree *T);                //ɾ��*Tָ��Ľ��
