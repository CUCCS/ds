#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tree.h"

//==========队列的基本操作=============//
Status InitQueue(LinkQueue *Q)  {
	//构造空队列
	Q->front = Q->rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));
	if (!(Q->front)) {
		return ERROR;
	}
	Q->front->next = NULL;
	Q->rear->next = NULL;
	return OK;
};

bool QueueEmpty(LinkQueue Q) {
	//判断是否为空队列
	if (Q.front == Q.rear) {
		return true;
	}
	return false;
};

Status EnQueue(LinkQueue *Q, QElemType e) {
	//插入新的队尾元素
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		return ERROR;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
};

Status DeQueue(LinkQueue *Q, QElemType *e) {
	//删除队头元素，并用e返回其值
	QueuePtr p = NULL;
	if (QueueEmpty(*Q)) {
		printf("错误！空队列!\n");
		return ERROR;
	}
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) {
		Q->rear = Q->front;
	}
	free(p);
	return OK;
};

int QueueLength(LinkQueue Q) {
	//返回队列的元素个数
	QueuePtr p;
	int i = 0;
	p = Q.front->next;
	if (QueueEmpty(Q)) {
		return 0;
	}
	while (p) {
		p = p->next;
		i++;
	}
	return i;
};

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

int Depth(BiTree T) {
	// 返回二叉树的深度 
	int depthval, depthLeft, depthRight;
	if (!T) {
		depthval = 0;
	}
	else {
		depthLeft = Depth(T->lchild);
		depthRight = Depth(T->rchild);
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	}
	return depthval;
}

int Width(BiTree T) {
	// 层序遍历二叉树,返回二叉树的宽度
	LinkQueue Q;
	BiTNode *p = T;
	int width = 1; //二叉树宽度
	int temp = 0; //上一层宽度
	int last = 0;
	int now = 0; //当前宽度

	if (!T) {
		return 0;
	}
	InitQueue(&Q); //建立工作队列
	EnQueue(&Q, T); //将根节点入队列
	last = 1;
	while (!QueueEmpty(Q)) {
		temp = last;
		while (temp != 0) {
			DeQueue(&Q, &p);
			if (p->lchild) {
				EnQueue(&Q, p->lchild);
			}
			if (p->rchild) {
				EnQueue(&Q, p->rchild);
			}
			temp--;
		}
		now = QueueLength(Q);
		width = now > width ? now : width;
		last = now;
	}
	return width;
}

bool Compelete(BiTree T) {
	//判断是否为完全二叉树
	LinkQueue Q;
	BiTNode *p = T;
	InitQueue(&Q); //建立工作队列
	EnQueue(&Q, T);

	while (!QueueEmpty(Q)) {
		DeQueue(&Q, &p);
		if (p->lchild) {
			EnQueue(&Q, p->lchild);
		}
		if (p->rchild) {
			EnQueue(&Q, p->rchild);
		}
		if ((!p->lchild) && p->rchild) {
			return false;
		}
	}

	int depth; //左孩子都存在时，进一步判断
	depth = Depth(T);
	if ((Count(T) - CountLeaf(T)) == pow(2, depth - 1)) {
		return true; //除了最后一层，其余层的结点都达到最大值
	}
	else {
		return false;
	}
	return true;
}

int Count(BiTree T) {
	//返回指针T所指二叉树中所有结点个数
	int m, n;
	if (!T) {
		return 0;
	}
	if ((!T->lchild) && (!T->rchild)) {
		return 1;
	}
	else {
		m = Count(T->lchild);
		n = Count(T->rchild);
		return m + n + 1;
	}
}

int CountLeaf(BiTree T) {
	// 返回指针T所指二叉树中所有叶子结点个数
	int m, n;
	if (!T) {
		return 0;
	}
	if ((!T->lchild) && (!T->rchild)) {
		return 1;
	}
	else {
		m = CountLeaf(T->lchild);
		n = CountLeaf(T->rchild);
		return m + n;
	}
}

bool Full(BiTree T) {
	//判断是否为满树（若树的深度为k，应有2^k-1个结点）
	if (pow(2, Depth(T)) - 1 == Count(T)) {
		printf("It is a full tree\n");
		return true;
	}
	printf("It is not a full tree\n");
	return false;
}

Status CountNode(BiTree T) {
	int total, leaf;
	if (T) {
		total = Count(T);
		leaf = CountLeaf(T);
		printf("The number of node is:%d\n", total);
		printf("The number of leaves is:%d\n", leaf);
		printf("The number of node(except leaves) is:%d - %d = %d\n", total, leaf, total - leaf);
		return OK;
	}
	return ERROR;
}

//==========方法一，以字符串的形式“根 左子树 右子树”定义一棵二叉树=============// 
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
	printf("The depth of the tree is %d\n", Depth(T));
	printf("The width of the tree is %d\n", Width(T));
}

int main() {
	BiTree Tree = NULL;
	int flag;
	int length;

	//==========方法一=============// 
	flag = CreateBiTree(&Tree);
	printf("---------------Test One---------------\n");
	if (!flag) {
		printf("Created tree succeeded!\n");
		printf("The original input: %s\n", c);
		printf("The postorder traverse: ");
		PostOrderTraverse(Tree);
		printf("\n");
		printf("The depth of the tree is %d\n", Depth(Tree));
		printf("The width of the tree is %d\n", Width(Tree));
		if (Compelete(Tree)) {
			printf("It is a compeleted tree\n");
		}
		else{
			printf("It is not a compeleted tree\n");
		}
		Full(Tree);
		CountNode(Tree);
	}
	else {
		printf("Created tree failed!\n");
	}

	//==========方法二=============// 
	char p1[10] = "ABDFCE"; //先序序列
	char p2[10] = "DFBAEC"; //中序序列

	length = Getlength(p1);
	flag = CrtBT(&Tree, p1, p2, 0, 0, length);
	printf("\n---------------Test Two---------------\n");
	if (!flag) {
		print(p1, p2, Tree);
		if (Compelete(Tree)) {
			printf("It is a compeleted tree\n");
		}
		else {
			printf("It is not a compeleted tree\n");
		}
		Full(Tree);
		CountNode(Tree);
	}
	else {
		printf("Created tree failed!\n");
	}

	//==========新增用例一=============// 
	strcpy(p1, "ABCDEFGHK"); //构建新的先序序列
	strcpy(p2, "BDCAEHGKF"); //构建新的中序序列
	length = Getlength(p1);
	flag = CrtBT(&Tree, p1, p2, 0, 0, length);
	printf("\n---------------Test Three---------------\n");
	if (!flag) {
		print(p1, p2, Tree);
		if (Compelete(Tree)) {
			printf("It is a compeleted tree\n");
		}
		else {
			printf("It is not a compeleted tree\n");
		}
		Full(Tree);
		CountNode(Tree);
	}
	else {
		printf("Created tree failed!\n");
	}

	//==========新增用例二=============// 
	strcpy(p1, "ABCDEFG"); //构建新的先序序列
	strcpy(p2, "CBDAFEG"); //构建新的中序序列

    //==========新增用例（非完全树）=============// 
	//strcpy(p1, "ABDEFGC"); //构建新的先序序列
	//strcpy(p2, "DBFEGAC"); //构建新的中序序列

	length = Getlength(p1);
	flag = CrtBT(&Tree, p1, p2, 0, 0, length);
	printf("\n---------------Test Four---------------\n");
	if (!flag) {
		print(p1, p2, Tree);
		if (Compelete(Tree)) {
			printf("It is a compeleted tree\n");
		}
		else {
			printf("It is not a compeleted tree\n");
		}
		Full(Tree);
		CountNode(Tree);
	}
	else {
		printf("Created tree failed!\n");
	}

	return 0;
}