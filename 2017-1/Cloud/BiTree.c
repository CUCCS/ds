#include "BiTree.h"
TElemType count = 0;
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
int Postorder(BiTree T) { // 先序遍历二叉树 
	if(T  == NULL){
	/*	printf("-");*/
		return OK;
	}
	if(T) {
		Postorder(T->lchild); // 遍历左子树
		Postorder(T->rchild); // 遍历右子树
		printf("%c",T->data );   // 访问结点
	}
	return 0;
}