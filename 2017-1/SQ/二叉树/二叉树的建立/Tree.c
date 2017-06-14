#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

//==========����һ�����ַ�������ʽ���� ������ ������������һ�ö�����=============// 
char c[] = "ABC DFE  G  H   ";
int i = 0;

Status CreateBiTree(BiTree *T) {
	char ch = c[i];   //�����ַ���

	if (ch == ' ') {
		*T = NULL;
		i++;
	}
	else {
		if (!((*T) = (BiTree)malloc(sizeof(BiTNode)))) {
			return OVERFLOW;
		}
		(*T)->data = ch;               // ���ɸ����
		i++;
		CreateBiTree(&(*T)->lchild);   // ����������
		CreateBiTree(&(*T)->rchild);   // ����������
	}
	return OK;
}

//==========���������ɶ�������������������н���=============// 
int Search(char ino[], char p) {
	//��ino[]��Ѱ���ַ�p���ҵ��򷵻�λ�ã����򷵻�-1
	int i;
	for (i = 0; ino[i] != '\0'; i++) {
		if (ino[i] == p) {
			return i;
		}
	}
	return -1;
}

int Getlength(char *p) {
	//��ȡ�ַ����ĳ���
	int i;
	for (i = 0; p[i] != '\0'; i++);
	return i;
}

Status CrtBT(BiTree *T, char pre[], char ino[], int ps, int is, int n) {
	// ��֪pre[ps...ps+n-1]Ϊ���������������У� ino[is...is+n-1]Ϊ����������������
	// ���㷨�ɴ��������й����������  
	int k;
	if (n == 0) {
		*T = NULL;
	}
	else {
		k = Search(ino, pre[ps]); // �����������в�ѯpre[ps]��ino�еĵڼ���λ��
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
	//����������һϵ�������Ϊһ������
	printf("Created tree succeeded!\n");
	printf("Preorder input: %s\n", pre);
	printf("Inorder input: %s\n", in);
	printf("The postorder traverse: ");
	PostOrderTraverse(T);
	printf("\n");
}

//==========�������Ļ�������=============// 
Status PostOrderTraverse(BiTree T) {
	//��������������ĵݹ��㷨
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

	//==========����һ=============// 
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

	//==========������=============// 
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