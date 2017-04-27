#include <stdio.h>
#include <stdlib.h>

#include "BiTree.h"

int i = 0;

Status CreateBiTree(BiTree *T,char *c){
	char ch;
	ch = c[i];
	i++;
	if(ch == '#'){
		*T = NULL;
	}
	else{
		if(!(*T = (BiTNode * )malloc(sizeof(BiTNode)))){
			exit(OVERFLOW);
		}
		(*T)->data = ch;
		CreateBiTree( &(*T)->lchild,c);
		CreateBiTree( &(*T)->rchild,c);
	}
	return OK;
}

Status PostOrderTraverse(BiTree T){
	if(T){
	PostOrderTraverse( T->lchild);
	PostOrderTraverse( T->rchild);
	printf( "%c", T->data);
	}
	return OK;
}

int main(){
	char c[30]="ABDG###EH##I#K##C#F##";
	char c1[30]="ABD#F###CE###";
	BiTree T=NULL;
	printf("开始创建第一个二叉数 : ABDG###EH##I#K##C#F##\n");
	CreateBiTree( &T, c);
	printf("创建完毕第一个二叉树\n");
	printf("后序遍历第一个二叉树:\n");
	PostOrderTraverse(T);
	printf("\n遍历结束\n\n");

	i=0;
	printf("开始创建第二个二叉数 : ABD#F###CE###\n");
	CreateBiTree( &T, c);
	printf("创建完毕第二个二叉树\n");
	printf("后序遍历第二个二叉树:\n");
	PostOrderTraverse(T);
	printf("\n遍历结束\n\n");
	return 0;
}