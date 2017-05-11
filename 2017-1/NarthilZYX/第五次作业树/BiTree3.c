#include "BiTree.h"

//test1
char c[] = "ABDG   EH  I K  C F  ";
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

//test2
int Search(char ino[], char p);
Status CrtBT(BiTree *T, char pre[], char ino[], int ps, int is, int n);
void print(char *pre, char *in, BiTree T);

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

int main(){
	BiTree Tree = NULL;
	int flag;
	//test1
	printf("Teat1 is as followed.\n");
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
	printf("\n");

	//test2
	int k;
	char p1[] = "ABDFCE";
	char p2[] = "DFBAEC";

	k = Getlength(p1);
	flag = CrtBT(&Tree, p1, p2, 0, 0, k);
	printf("Test2 is as followed.\n");
	if (!flag) {
		printf("Tree creating succeeded!\n");
	    printf("Preorder input: %s\n", p1);
	    printf("Inorder input: %s\n", p2);
	   printf("The postorder traverse: ");
	   PostOrderTraverse(Tree);
	   printf("\n");
	}
	else {
		printf("Created tree failed!\n");
	}
	
	return 0;
}