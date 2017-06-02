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

BSTree InsertBST(BSTree T, int data);  //插入结点
BSTree CreatBST(BSTree T, int array[]); //建立二叉树
bool SearchBST(BSTree T, int key);     //查找二叉树中有无目标结点
void PrePrintBST(BSTree T);            //先序遍历输出二叉树
bool DeleteBST(BSTree *T, int key);    //删除与key相同的结点
bool Delete(BSTree *T);                //删除*T指向的结点
