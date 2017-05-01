#include <stdio.h>
#include <stdlib.h>

#include "BiTree.h"

int i = 0;
int length = 0;
int testlength = 0;
int width[10] = {0};

Status CreateBiTree(BiTree *T,char *c){
	char ch;
	ch = c[i];
	i++;
	if(ch == '#'){
		*T = NULL;
	}
	else{
		testlength++;
		width[testlength]=width[testlength]+1;
		if(!(*T = (BiTNode * )malloc(sizeof(BiTNode)))){
			exit(OVERFLOW);
		}
		(*T)->data = ch;
		CreateBiTree( &(*T)->lchild,c);
		CreateBiTree( &(*T)->rchild,c);
		testlength--;
	}
	if(testlength > length){
		length = testlength;
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

Status MeasureWidth(){
	int w = 0;
	int i;
	for(i = 1;i <= length;i++){
		if(w < width[i]){
			w = width[i];
		}
		width[i] = 0;
	}
	printf("�ö����������Ϊ%d\n", w);
	return OK;
}

Status MeasureLeaf(BiTree T,int *count1,int *count2){
	if(T){
		if(T->lchild == NULL&&T->rchild == NULL){
			*(count1) = *(count1)+1;
		}
		else{
			*(count2) = *(count2)+1;
		}
		MeasureLeaf(T->lchild, count1, count2);
		MeasureLeaf(T->rchild, count1, count2);
	}
	return OK;
}

int main(){
	int count1=0;
	int count2=0;
	char c[30]="ABDG###EH##I#K##C#F##";
	char c1[30]="ABD#F###CE###";
	BiTree T=NULL;
	printf("��ʼ������һ�������� : ABDG###EH##I#K##C#F##\n");
	CreateBiTree( &T, c);
	printf("������ϵ�һ��������\n�������ĸ߶�Ϊ%d\n",length);
	MeasureWidth();
	printf("���������һ��������:\n");
	PostOrderTraverse(T);
	printf("\n��������\n");
	MeasureLeaf( T, &count1, &count2);
	printf( "�ö�����Ҷ�ӽڵ�Ϊ%d,��Ҷ�ӽڵ�Ϊ%d\n\n", count1, count2);

	i=0;
	length=0;
	testlength=0;
	count1=0;
	count2=0;
	printf("��ʼ�����ڶ��������� : ABD#F###CE###\n");
	CreateBiTree( &T, c1);
	printf("������ϵڶ���������\n�������ĸ߶�Ϊ%d\n",length);
	MeasureWidth();
	printf("��������ڶ���������:\n");
	PostOrderTraverse(T);
	printf("\n��������\n");
	MeasureLeaf( T, &count1, &count2);
	printf( "�ö�����Ҷ�ӽڵ�Ϊ%d,��Ҷ�ӽڵ�Ϊ%d\n\n", count1, count2);
	return 0;
}