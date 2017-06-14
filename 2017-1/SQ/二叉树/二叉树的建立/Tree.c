#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

//==========方法一，以字符串的形式“根 左子树 右子树”定义一棵二叉树=============// 
char c[] = "ABC DFE  G  H   ";
int i = 0;

Status CreateBiTree(BiTree *T) {
	char ch = c[i];   //遍历字符串

	if (ch == ' ') {
		*T = NULL;
		i++;
	}
	else {
		if (!((*T) = (BiTree)malloc(sizeof(BiTNode)))) {
			return OVERFLOW;
		}
		(*T)->data = ch;               // 生成根结点
		i++;
		CreateBiTree(&(*T)->lchild);   // 构造左子树
		CreateBiTree(&(*T)->rchild);   // 构造右子树
	}
	return OK;
}

//==========方法二，由二叉树的先序和中序序列建树=============// 
int Search(char ino[], char p) {
	//在ino[]中寻找字符p，找到则返回位置，否则返回-1
	int i;
	for (i = 0; ino[i] != '\0'; i++) {
		if (ino[i] == p) {
			return i;
		}
	}
	return -1;
}

int Getlength(char *p) {
	//获取字符串的长度
	int i;
	for (i = 0; p[i] != '\0'; i++);
	return i;
}

Status CrtBT(BiTree *T, char pre[], char ino[], int ps, int is, int n) {
	// 已知pre[ps...ps+n-1]为二叉树的先序序列， ino[is...is+n-1]为二叉树的中序序列
	// 本算法由此两个序列构造二叉链表  
	int k;
	if (n == 0) {
		*T = NULL;
	}
	else {
		k = Search(ino, pre[ps]); // 在中序序列中查询pre[ps]在ino中的第几个位置
		if (k == -1) {
			*T = NULL;
		}
		else {
			if (!((*T) = (BiTree)malloc(sizeof(BiTNode)))) {
				return OVERFLOW;
			}
			(*T)->data = pre[ps];
			if (k == is) {
				(*T)->lchild = NULL;
			}
			else {
				CrtBT(&(*T)->lchild, pre, ino, ps + 1, is, k - is);
			}
			if (k == is + n - 1) {
				(*T)->rchild = NULL;
			}
			else {
				CrtBT(&(*T)->rchild, pre, ino, ps + 1 + (k - is), k + 1, n - (k - is) - 1);
			}
		}
	}
	return OK;
}

void print(char *pre, char *in, BiTree T) {
	//将方法二的一系列输出合为一个函数
	printf("Created tree succeeded!\n");
	printf("Preorder input: %s\n", pre);
	printf("Inorder input: %s\n", in);
	printf("The postorder traverse: ");
	PostOrderTraverse(T);
	printf("\n");
}

//==========二叉树的基本操作=============// 
Status PostOrderTraverse(BiTree T) {
	//后序遍历二叉树的递归算法
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
	return OK;
}

int main(){
	BiTree Tree = NULL;
	int flag;

	//==========方法一=============// 
	flag = CreateBiTree(&Tree);
	printf("---------------Test one---------------\n");
	if (!flag) {
		printf("Created tree succeeded!\n");
		printf("The original input: %s\n", c);
		printf("The postorder traverse: ");
		PostOrderTraverse(Tree);
		printf("\n");
	}
	else {
		printf("Created tree failed!\n");
	}

	//==========方法二=============// 
	int k;
	char p1[] = "ABDFCE";
	char p2[] = "DFBAEC";

	k = Getlength(p1);
	flag = CrtBT(&Tree, p1, p2, 0, 0, k);
	printf("\n---------------Test two---------------\n");
	if (!flag) {
		print(p1, p2, Tree);
	}
	else {
		printf("Created tree failed!\n");
	}

	return 0;
}