#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tree.h"

//==========���еĻ�������=============//
Status InitQueue(LinkQueue *Q)  {
	//����ն���
	Q->front = Q->rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));
	if (!(Q->front)) {
		return ERROR;
	}
	Q->front->next = NULL;
	Q->rear->next = NULL;
	return OK;
};

bool QueueEmpty(LinkQueue Q) {
	//�ж��Ƿ�Ϊ�ն���
	if (Q.front == Q.rear) {
		return true;
	}
	return false;
};

Status EnQueue(LinkQueue *Q, QElemType e) {
	//�����µĶ�βԪ��
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
	//ɾ����ͷԪ�أ�����e������ֵ
	QueuePtr p = NULL;
	if (QueueEmpty(*Q)) {
		printf("���󣡿ն���!\n");
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
	//���ض��е�Ԫ�ظ���
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

int Depth(BiTree T) {
	// ���ض���������� 
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
	// �������������,���ض������Ŀ��
	LinkQueue Q;
	BiTNode *p = T;
	int width = 1; //���������
	int temp = 0; //��һ����
	int last = 0;
	int now = 0; //��ǰ���

	if (!T) {
		return 0;
	}
	InitQueue(&Q); //������������
	EnQueue(&Q, T); //�����ڵ������
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
	//�ж��Ƿ�Ϊ��ȫ������
	LinkQueue Q;
	BiTNode *p = T;
	InitQueue(&Q); //������������
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

	int depth; //���Ӷ�����ʱ����һ���ж�
	depth = Depth(T);
	if ((Count(T) - CountLeaf(T)) == pow(2, depth - 1)) {
		return true; //�������һ�㣬�����Ľ�㶼�ﵽ���ֵ
	}
	else {
		return false;
	}
	return true;
}

int Count(BiTree T) {
	//����ָ��T��ָ�����������н�����
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
	// ����ָ��T��ָ������������Ҷ�ӽ�����
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
	//�ж��Ƿ�Ϊ���������������Ϊk��Ӧ��2^k-1����㣩
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

//==========����һ�����ַ�������ʽ���� ������ ������������һ�ö�����=============// 
char c[] = "ABC  DE G  F   ";
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
	printf("The depth of the tree is %d\n", Depth(T));
	printf("The width of the tree is %d\n", Width(T));
}

int main() {
	BiTree Tree = NULL;
	int flag;
	int length;

	//==========����һ=============// 
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

	//==========������=============// 
	char p1[10] = "ABDFCE"; //��������
	char p2[10] = "DFBAEC"; //��������

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

	//==========��������һ=============// 
	strcpy(p1, "ABCDEFGHK"); //�����µ���������
	strcpy(p2, "BDCAEHGKF"); //�����µ���������
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

	//==========����������=============// 
	strcpy(p1, "ABCDEFG"); //�����µ���������
	strcpy(p2, "CBDAFEG"); //�����µ���������

    //==========��������������ȫ����=============// 
	//strcpy(p1, "ABDEFGC"); //�����µ���������
	//strcpy(p2, "DBFEGAC"); //�����µ���������

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