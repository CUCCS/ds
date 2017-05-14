#include"Tree.h"
BiTNode* CreateBiTree(BiTNode *T,char *p){
	static char *ch=(char *)malloc(sizeof(char));
	ch=p;
	//scanf_s("%c",&ch);
	//getchar();
    if(*ch == '0') {
        T = NULL;
	}
	else {
		T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!T){
			printf("OVERFLOW"); 
			exit(1);
	}
		T->data = *ch;    // 生成根结点
		T->lchild= CreateBiTree(T->lchild,++ch);   // 构造左子树
		T->rchild= CreateBiTree(T->rchild,++ch);   //` 构造右子树
    }
	return T;
}
void Preorder(BiTNode *T) { // 先序遍历二叉树 
	if(T) {
      Preorder(T->lchild); // 遍历左子树
      Preorder(T->rchild); // 遍历右子树
	  printf("%c ",T->data);
   }
}