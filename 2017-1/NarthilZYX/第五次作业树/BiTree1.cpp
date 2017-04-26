#include "BiTree.h"

char c[] = "ABC  DE G  F   ";
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

int main(){
	BiTree Tree = NULL;
	int flag;

	flag = CreateBiTree(&Tree);
	if (!flag) {
		printf("Tree creating succeeded!\n");
		printf("The original input: %s\n", c);
		printf("The postorder traverse: ");
		PostOrderTraverse(Tree);
		printf("\n");
	}
	else {
		printf("Tree creating failed!\n");
	}

	return 0;
}