#include <stdio.h>
#include <stdlib.h>

#include "BiTree.h"

int i = 0;
int length = 0;//���
int testlength = 0;
int width[10] = {0};//���

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

Status MeasureLength(BiTree T){
	if(!T){
		if(testlength > length){
			length = testlength;
		}
		return OK;
	}
	else{
		testlength++;
		MeasureLength(T->lchild);
		MeasureLength(T->rchild);
		testlength--;
	}
	if(testlength > length){
		length = testlength;
	}
	return OK;
}

Status MeasureWidth(BiTree T,int len){
	if(!T){
		return ERROR;
	}
	else{
		width[len] = width[len]+1;
		len++;
	}
	MeasureWidth(T->lchild, len);
	MeasureWidth(T->rchild, len);
	return OK;
}

Status GetWidth(){
	int wi = 0;
	int i;
	for(i = 1;i <= length;i++){
		if(wi<width[i]){
			wi=width[i];
		}
		width[i] = 0;
	}
	printf("�����Ϊ%d\n", wi);
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
	MeasureLength(T);
	printf("������ϵ�һ��������\n�������ĸ߶�Ϊ%d\n",length);
	MeasureWidth(T, 1);
	GetWidth();
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
	MeasureLength(T);
	printf("������ϵڶ���������\n�������ĸ߶�Ϊ%d\n",length);
	MeasureWidth(T, 1);
	GetWidth();
	printf("��������ڶ���������:\n");
	PostOrderTraverse(T);
	printf("\n��������\n");
	MeasureLeaf( T, &count1, &count2);
	printf( "�ö�����Ҷ�ӽڵ�Ϊ%d,��Ҷ�ӽڵ�Ϊ%d\n\n", count1, count2);
	return 0;
}