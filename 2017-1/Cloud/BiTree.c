//二叉树采用二叉链表存储
//计算整个二叉树高度的算法（二叉树的高度也叫二叉树的深度）。
//计算二叉树最大宽度的算法（二叉树的最大宽度是指二叉树所有层中结点个数的最大值）。
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
/* 先序遍历二叉树 */
int Postorder(BiTree T) {
	if(T  == NULL){
		/*	printf("-");*/
		return OK;
	}
	if(T) {
		Postorder(T->lchild); /* 遍历左子树*/
		Postorder(T->rchild); /* 遍历右子树*/
		printf("%c",T->data ); /* 访问结点*/
	}
	return 0;
}
/* 求二叉树的深度*/
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
/* 求二叉树的最大宽度*/
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
	int  countperlayer[100] = {0}; /*每层的节点个数*/
	_Width(T,&max,countperlayer);
	return max;
}