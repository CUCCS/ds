#include <stdio.h>
#include <stdlib.h>
typedef enum status
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef enum { // ���岼������ֵ
	false,
	true
}bool;
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool SearchBST(BiTree T, int key, BiTree f, BiTree *p);
bool InsertBST(BiTree *T, int e);
Status CreatBST(BiTree *T, int a[], int n);
bool Delete(BiTree *T);
bool DeleteBST(BiTree *T, int key);
bool print(int data, FILE*pfile);
int preOrderTraverse(BiTree T, FILE*pfile);
int PreOrderTraverse(BiTree T);
#pragma once
