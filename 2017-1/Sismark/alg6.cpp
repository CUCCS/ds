#include<stdio.h>
#include<stdlib.h>

#define isLeaf(node) ((node)->left==NULL&&(node)->right==NULL)

int i = 0;//��������i��
int a[10] = { 0 };//���ʮ�� ÿ���ʼ��Ϊ0���
int max = 0;//�����

typedef char ElemType;
typedef int Status;

typedef struct Node {
	ElemType data;
	struct  Node* left;
	struct  Node* right;
	struct  Node* parent;
}Node, *Tree;

Node* _newNode() {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = 0;
	p->left = p->parent = p->right = NULL;
	return p;
}

void _DeleteAllLeave(Tree *pt) {
	if (isLeaf((*pt)->left)) {
		free((*pt)->left);
		(*pt)->left = NULL;
	}
	if (isLeaf((*pt)->right)) {
		free((*pt)->right);
		(*pt)->right = NULL;
	}
	if ((*pt)->left) _DeleteAllLeave(&(*pt)->left);
	if ((*pt)->right) _DeleteAllLeave(&(*pt)->right);
}

Tree newBinaryTree(char *str) {
	if (*str == '\0') return NULL;
	Tree t = _newNode();
	t->data = *str;
	Node*current = t;//current��ʾ��ǰ�ڵ�
	for (char *ch = str + 1; *ch != '\0'; ch++) {
		Node* p = _newNode();
		p->data = *ch;
		if (current->left == NULL) {
			current->left = p;
			p->parent = current;
			if (*ch != '#') current = p;
		}
		else {
			if (current->right == NULL) {
				current->right = p;
				p->parent = current;
				if (*ch != '#') current = p;
			}
			else {
				current = current->parent;
				ch -= 1;
			}
		}
	}
	_DeleteAllLeave(&t);
	return t;
}
void Traverse(Tree t) {
	printf("%c", t->data);
	if (t->left) Traverse(t->left);
	if (t->right) Traverse(t->right);
}
int Depth(Tree t) {
	if (t == NULL) return 0;
	int depth1, depth2;
	depth1 = Depth(t->left) + 1;
	depth2 = Depth(t->right) + 1;
	if (depth1 > depth2) return depth1;
	else return depth2;
}

int Width(Tree t) {
	if (t == NULL) return 0;
	a[i]++;//��i���ȼ�һ
	if (max < a[i]) max = a[i];
	i++;//������һ
	Width(t->left);
	Width(t->right);
	i--;//����t���ڵĲ�
	return max;
}
int main() {
	int m = rand() % 2;
	Tree t;
	//char str[] = "ABC##DE#G##F###";
	char str[] = "ABDG###EH##I#K##C#F##";
	t = newBinaryTree(str);
	printf("����������:");
	Traverse(t);
	printf("\ndepth=%d\n", Depth(t));
	printf("width=%d\n", Width(t));
	return 0;
}
