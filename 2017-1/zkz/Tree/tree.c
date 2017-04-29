#include <stdlib.h>
#include "tree.h"

#define EMPTY '#'

/*===�ַ������===*/
/*�ֶ���ȡ�Ӵ�*/
char* substr(char* source, int begin, int end) {
		int size = end - begin + 1;
		if (size <= 0) {
			return "";
		}
		char* result = (char*)malloc((size + 1) * sizeof(char));
		result[size] = '\0';
		--size;
		for (; size >= 0; --size) {
			result[size] = source[begin + size - 1];
		}
		return result;
}
/*�ֶ��ָ��ַ���*/
void divideString(char* source, char delim, char** pDes1, char** pDes2) {
	 
		char* p = source;
		int size1, sizeS = strlen(source);
		while (*(p++) != delim);
		size1 = p - source - 1;
		*pDes1 = substr(source, 1, size1);
		*pDes2 = substr(source, size1 + 2, sizeS);
}

inline Node* newNode() {
	 
		Node* p = (Node*)malloc(sizeof(Node));
		p->parent = p->left = p->right = NULL;
		p->data = 0;
		return p;
}
void InitializeTree(Tree* pT) {
	 
		*pT = newNode();
}
void _ShowTree(const Tree root , int*null) {
	printf("%c",root->data);
}
void _TraverseTree(const Tree root, Order order, void func(const Tree,int*) , int* p) {
	 
		/*���root��Ϊ�� , �����order��˳�����root*/
		if (root) {
			if (order == pre)func(root,p);
			_TraverseTree(root->left, order,func,p);
			if (order == in)func(root,p);
			_TraverseTree(root->right, order,func,p);
			if (order == post)func(root,p);
		}
}
/*����������*/
/*root : �������Ķ�����*/
/*order : ����˳��(pre , in , post , all �ֱ�Ϊǰ�����򡢺�������˳��)*/
void TraverseTree(const Tree root, Order order , void func(const Tree , int*) , int* p) {
	_TraverseTree(root, order, func,p);
}
void Show(const Tree root, Order order) {
	if (order == all) {
		Show(root, pre);
		Show(root, in);
		Show(root, post);
		return;
	}
	debug_print("%s�������0x%p : ", order == pre ? "ǰ" : order == in ? "��" : "��", root);
	TraverseTree(root, order, _ShowTree, NULL);
	debug_print("\n");
}
inline int getDepth(const Tree t) {
	 
		int depth = 1;
		Node* p = t;
		while (p->parent) {
			++depth;
			p = p->parent;
		}
		return depth;
}
/*ɾ����������Ϊc�Ľڵ�*/
void DeleteSpecialNode(Tree *pRoot, Elemtype c) {
	 
		if ((*pRoot)->left) {
			if ((*pRoot)->left->data == c) {
				free((*pRoot)->left);
				(*pRoot)->left = NULL;
			}
			else {
				DeleteSpecialNode(&(*pRoot)->left, c);
			}
		}
		if ((*pRoot)->right) {
			if ((*pRoot)->right->data == c) {
				free((*pRoot)->right);
				(*pRoot)->right = NULL;
			}
			else {
				DeleteSpecialNode(&(*pRoot)->right, c);
			}
		}
}
/*����һ�������������н���������*/
Tree newBinaryTree(char* str) {
	 
		Node* current;
		Tree tree;
		InitializeTree(&tree);
		/*����ǿ��ַ�����ʲô������*/
		if (strlen(str) == 0) {
			return tree;
		}
		debug_print("�ԡ�%s��Ϊ����ǰ������", str);
		debug_print("��0x%p������������\n", tree);
		tree->data = str[0];
		current = tree;
		while (*++str != '\0') {
			if (current->left == NULL) {
				current->left = newNode();
				current->left->parent = current;
				current->left->data = *str;
				if (*str != EMPTY) {
					current = current->left;
				}
			}/*end if current->left == NULL*/
			else if (current->right == NULL) {
				current->right = newNode();
				current->right->parent = current;
				current->right->data = *str;
				if (*str != EMPTY) {
					current = current->right;
				}
			}/*end if current->left == NULL*/
			else {
				current = current->parent;
				--str;
			}
		}/*end while*/
		 /*ȥ������Ϊ�ո��Ҷ�ڵ�*/
		DeleteSpecialNode(&tree, EMPTY);
		return tree;
}
/*����һ��������������������һ�����������������н���������*/
Tree _newBinaryTree2(char* pre, char* in) {
	 
		Tree tree = newNode();
		int len = strlen(pre);
		char * p = in;
		char* leftPre, *leftIn, *rightPre, *rightIn;
		if (strlen(pre) == 1 && strlen(in) == 1) {
			tree->data = *pre;
			return tree;
		}
		tree->data = pre[0];
		divideString(in, pre[0], &leftIn, &rightIn);
		/*��������*/
		if (strlen(leftIn)) {
			leftPre = substr(pre, 2, strlen(leftIn) + 1);
			tree->left = _newBinaryTree2(leftPre, leftIn);
			tree->left->parent = tree;
		}
		/*��������*/
		if (strlen(rightIn)) {
			rightPre = substr(pre, strlen(pre) - strlen(rightIn) + 1, strlen(pre));
			tree->right = _newBinaryTree2(rightPre, rightIn);
			tree->right->parent = tree;
		}

		return tree;
}
Tree newBinaryTree2(char*pre, char* in) {
	Tree tree = _newBinaryTree2(pre, in);
	debug_print("�ԡ�%s���롾%s����0x%p������������\n", pre, in, tree);
	return tree;
}
/*������������������*/
void _CalculateDepth(const Tree t , int* pDepth){
	int depth = getDepth(t);
	if (depth > *pDepth) {
		*pDepth = depth;
	}
}
void _CalculateWidth(const Tree t , int*width) {
	width[getDepth(t) - 1] += 1;
}
void CalculateDepthAndWidth(const Tree t, int* pD, int * pW) {
	*pD = 0;
	TraverseTree(t, pre, _CalculateDepth,pD);
	int * width = (int*)malloc(*pD * sizeof(int));
	/*��ʼ��Ϊȫ0����*/
	for (int i = 0; i < *pD; ++i) { width[i] = 0; }
	TraverseTree(t, pre, _CalculateWidth, width);
	*pW = 0;
	for (int i = 0; i < *pD; ++i) {
		if (width[i] > *pW) *pW = width[i];
	}
	debug_print("������0x%p��������� , ����ֱ�Ϊ %d �� %d \n",t,*pD,*pW);
	free(width);
}
/*ͳ�ƶ�����������Ҷ���Ҷ�ڵ�ĸ���*/
void _CountLeave(const Tree t, int* p) {
	//printf("It's %c , its left is %c , its right is %c \n",t->data,t->left ? t->left->data : '0' , t->right ? t->right->data : '0');
	if (t->left == NULL && t->right == NULL) {
		*p += 1;
	}
}
void CountLeaves(const Tree t, int* pLeaf) {
	*pLeaf = 0;
	TraverseTree(t, pre, _CountLeave, pLeaf);
	debug_print("��0x%p��Ҷ�ڵ����Ϊ%d \n", t, *pLeaf);
}
void _CountBranch(const Tree t, int*p) {
	if (t->left != NULL || t->right != NULL) {
		*p += 1;
	}
}
void CountBranches(const Tree t, int* pBranch) {
	*pBranch = 0;
	TraverseTree(t, pre, _CountBranch, pBranch);
	debug_print("��0x%p�з�Ҷ�ڵ����Ϊ%d \n", t, *pBranch);
}
/*���׶���*/
typedef struct _QueueNode {
	Elemtype data;
	struct _QueueNode * prev;
	struct _QueueNode * next;
}QueueNode;
typedef struct _Queue {
	QueueNode* head, *rear;
}Queue;
QueueNode* newQueueNode() {
	QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
	p->data = 0; p->next = p->prev = NULL;
	return p;
}
Queue newQueue() {
	Queue q;
	q.head = q.rear = NULL;
	return q;
}
int isEmpty(Queue* pQ) {
	if (pQ->head && !pQ->rear || pQ->rear && !pQ->head) {
		printf("What the f**k is this s**t ???");
		exit(-1);
	}
	return pQ->head == NULL;
}
void enQueue(Queue* pQ, Elemtype d) {
	QueueNode* p = newQueueNode();
	p->data = d;
	if (isEmpty(pQ)) {
		pQ->head = pQ->rear = p;
	}
	else {
		pQ->rear->next = p;
		pQ->rear = p;
	}
}
Elemtype deQueue(Queue* pQ) {
	QueueNode* p = pQ->head;
	Elemtype d = p->data;
	if (isEmpty(pQ)) {
		pQ->head = pQ->rear = NULL;
	}
	else {
		pQ->head = pQ->head->next;
	}
	free(p);
	return d;
}
/*�ж��Ƿ�Ϊ��ȫ������*/
int _isCompleteBinaryTree(const Tree t, int *p , int num) {
	if (!t) { return 1; }
	else if (num > *p) { return 0; }
	else {
		return _isCompleteBinaryTree(t->left, p, num * 2) * _isCompleteBinaryTree(t->right, p, num * 2 + 1);
	}
}
void _Count(const Tree t, int *p) {
	*p += 1;
}
int isCompleteBinaryTree(const Tree t) {
	int mount = 0;
	TraverseTree(t, pre, _Count, &mount);
	return _isCompleteBinaryTree(t, &mount , 1);
}