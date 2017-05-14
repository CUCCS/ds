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
	printf("��ʼ������һ�������� : ABDG###EH##I#K##C#F##\n");
	CreateBiTree( &T, c);
	printf("������ϵ�һ��������\n");
	printf("���������һ��������:\n");
	PostOrderTraverse(T);
	printf("\n��������\n\n");

	i=0;
	printf("��ʼ�����ڶ��������� : ABD#F###CE###\n");
	CreateBiTree( &T, c);
	printf("������ϵڶ���������\n");
	printf("��������ڶ���������:\n");
	PostOrderTraverse(T);
	printf("\n��������\n\n");
	return 0;
}