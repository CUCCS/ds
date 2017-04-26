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
int Postorder(BiTree T) { // ������������� 
	if(T  == NULL){
	/*	printf("-");*/
		return OK;
	}
	if(T) {
		Postorder(T->lchild); // ����������
		Postorder(T->rchild); // ����������
		printf("%c",T->data );   // ���ʽ��
	}
	return 0;
}