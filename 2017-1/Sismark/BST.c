#include<stdio.h>
#include<stdlib.h>

//#define DEBUG 0
//#define debug_print if(DEBUG)printf
typedef enum bool{
	false,
	true
} bool;

typedef struct BiTNode {
	int data;
	struct  BiTNode* left;
	struct  BiTNode* right;
}BiTNode, *BiTree;

int LT(int a, int b);
int EQ(int a, int b);
void Delete(BiTree *p);
int DeleteBST(BiTree *T, int kval);

bool SearchBST(BiTree T, int data) {
	if (!T) {
		return false;
	}
	if (T->data == data) {
		return true;
	}
	if (data < T->data) {
		return SearchBST(T->left, data);
	}
	if (data > T->data) {
		return SearchBST(T->right, data);
	}
	return false;
}
int LT(int a,int b) {
	if (a < b) return true;
	else return false;
}
int EQ(int a, int b) {
	if (a == b) return true;
	else return false;
}
BiTree newNode(int data) {
	BiTree temp = (BiTree)malloc(sizeof(BiTNode));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void _InsertBST(BiTree *T, int e) {
	BiTNode* temp = newNode(e);

	if (*T == NULL) {
		*T = temp;
	}
	else {
		if (e > (*T)->data) {
			(*T)->right = temp;
		}
		else if (e < (*T)->data) {
			(*T)->left = temp;
		}
	}
}
void InsertBST(BiTree *T, int e) {
	if (*T == NULL) {
		_InsertBST(T, e);
		return;
	}
	if(e > (*T)->data && (*T)->right){
		InsertBST(&(*T)->right, e);
	}
	else if (e < (*T)->data && (*T)->left) {
		InsertBST(&(*T)->left, e);
	}
	else {
		_InsertBST(T, e);
	}
}
void Delete(BiTree *p) {
	// 从二叉排序树中删除结点 p，
	// 并重接它的左子树或右子树
	BiTree q, s;
	if (!(*p)->right) { // 右子树为空树则只需重接它的左子树
		q = *p;
		*p = (*p)->left;
		q = NULL;
		free(q);
	}
	else if (!(*p)->left) { // 左子树为空树则只需重接它的右子树
		q = *p;
		*p = (*p)->right;
		q = NULL;
		free(q);
	}
	else {  // 左右子树均不空
		q = *p;
		s = (*p)->left;
		while (s->right) { // s 指向被删结点的前驱
			q = s;
			s = s->right;
		}
		(*p)->data = s->data;
		if (q != *p) {
			q->right = s->left; // 重接*q的右子树
		}
		else {
			q->left = s->left; // 重接*q的左子树
		}
		s = NULL;
		free(s);
	}
}
int DeleteBST(BiTree *T, int kval) {
	// 若二叉排序树 T 中存在其关键字等于 kval 的
	// 数据元素，则删除该数据元素结点，并返回
	// 函数值 true，否则返回函数值 false
	if (!(*T)) { // 不存在关键字等于kval的数据元素
		return false;
	}
	else {
		if (kval == (*T)->data) { // 找到关键字等于key的数据元素
			Delete(&(*T));
			return true;
		}
		else if (kval < (*T)->data) { // 继续在左子树中进行查找
			return DeleteBST(&(*T)->left, kval);
		}
		else { // 继续在右子树中进行查找
			return DeleteBST(&(*T)->right, kval);
		}
	}
}
void PreOrderTraverse(BiTree T) {
	printf("%d, ",T->data);
	if (T->left) PreOrderTraverse(T->left);
	if (T->right) PreOrderTraverse(T->right);
}
int main() {
	int i = 0, j = 0;
	int a[] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int b[] = { 13, 8, 5, 20, 6 };
	BiTree T = NULL;
	while (i<12) {
		InsertBST(&T, a[i]);
		i++;
	}
	PreOrderTraverse(T);
	printf("\n");
	while (j < 5) {
		if (SearchBST(T, b[j])) {
			DeleteBST(&T, b[j]);
		}
		else {
			InsertBST(&T, b[j]);
		}
		PreOrderTraverse(T);
		printf("\n");
		j++;
	}
}