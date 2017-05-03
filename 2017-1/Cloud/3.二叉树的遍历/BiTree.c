#include "BiTree.h"
int count = 0;
/* 建立一个二叉树 */
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
void  _Width(BiTree T,int* max,int * countperlayer,int i){
	if(T == NULL)
		return ;
	i++;
	countperlayer[i]++;
	if(*max < countperlayer[i])
		*max =  countperlayer[i];
	_Width(T -> lchild,max,countperlayer,i);
	_Width(T -> rchild,max,countperlayer,i);
	i--;
}

int Width(BiTree T)
{
	int max = 0;/* 记录当前每层的最大节点个数 */
	int  countperlayer[100] = {0}; /* 每层的节点个数 */
	static int i = 0;/*标记层数*/
	_Width(T,&max,countperlayer,i);
	return max;
}//zz友情协助^-^

/* 计算二叉树中所有叶子结点个数 */
int CountLeafNode(BiTree T) {

	if(!T) return 0;
	if( (!T->lchild) && (!T->rchild )) { 
		return 1;
	} else {
		return CountLeafNode(T->lchild) + CountLeafNode(T->rchild);   
	} 
}

/* 求二叉树中所有结点个数 */
int CountAllNode (BiTree T) {
	if (!T) return 0;
	if (!T->lchild && !T->rchild) {
		return 1;
	} else {
		return  CountAllNode(T->lchild) + CountAllNode(T->rchild) + 1 ;   
	}
} 

/* 计算二叉树中所有非叶子结点个数 */
int CountNonLeafNode(BiTree T){
	return CountAllNode(T) - CountLeafNode(T);
}