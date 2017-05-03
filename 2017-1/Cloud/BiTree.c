//���������ö�������洢
//���������������߶ȵ��㷨���������ĸ߶�Ҳ�ж���������ȣ���
//�������������ȵ��㷨�����������������ָ���������в��н����������ֵ����
//--------------------------------------------------------------------------------
#include "BiTree.h"
int count = 0;
int i = 0; 

Status CreateBiTree(BiTree *T ,TElemType* d){
	if(d[count++] == ' '){
		*T = NULL;
	}else{
		if(!(*T = (BiTNode *)malloc(sizeof(BiTNode)))) {
			exit(1);
		}
		(*T)->data = d[count-1];
		CreateBiTree(&(*T)->lchild,d);
		CreateBiTree(&(*T)->rchild,d);
	}
	return OK;
}
/* ������������� */
int Postorder(BiTree T) {
	if(T  == NULL){
		/*	printf("-");*/
		return OK;
	}
	if(T) {
		Postorder(T->lchild); /* ����������*/
		Postorder(T->rchild); /* ����������*/
		printf("%c",T->data ); /* ���ʽ��*/
	}
	return 0;
}
/* ������������*/
int Depth(BiTree T){ 
	int depthval = 0;
	int depthLeft = 0;
	int depthRight = 0;
	if(!T) {
		depthval = 0;
	} else {
		depthLeft = Depth(T->lchild);
		depthRight= Depth(T->rchild);
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	} 
	return depthval;
}
/* ��������������*/
void  _Width(BiTree T,int* max,int * countperlayer){
	if(T == NULL)
		return ;
	i++;
	countperlayer[i]++;
	if(*max < countperlayer[i])
		*max =  countperlayer[i];
	_Width(T -> lchild,max,countperlayer);
	_Width(T -> rchild,max,countperlayer);
	i--;
}
int Width(BiTree T)
{
	int max = 0;
	int  countperlayer[100] = {0}; /*ÿ��Ľڵ����*/
	_Width(T,&max,countperlayer);
	return max;
}