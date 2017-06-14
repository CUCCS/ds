#include "BSTree.h"

Status CreateBST(BSTree *T, ElemType d[], int n) {
	//构造二叉排序树
	int i;
	for (i = 0; i < n; i++) {
		InsertBST(T, d[i]);
	}
	if (!T) {
		return OK;
	}
	return ERROR;
}

Status InsertBST(BSTree *T, ElemType e) {
	// 当二叉排序树中不存在关键字等于 e 的数据元素时，插入元素值为 e 的结点，并返回 true
	// 否则，不进行插入并返回false
	BSTree p, s;
	if (SearchBST(T, e, NULL, &p)) {
		s = (BSTree)malloc(sizeof(BSTNode)); // 为新结点分配空间
		s->key = e;
		s->lchild = s->rchild = NULL;
		if (!p) {
			*T = s; // 插入 s 为新的根结点
		}
		else if (LT(e, p->key)) {
			p->lchild = s; // 插入 *s 为 *p 的左孩子
		}
		else {
			p->rchild = s; // 插入 *s 为 *p 的右孩子
		}
		return OK;
	}
	else {
		return ERROR;
	}
}

Status SearchBST(BSTree *T, KeyType kval, BSTree f, BSTree *p) {
	// 在根指针 T 所指二叉排序树中递归地查找其关键字等于 kval 的数据元素
	// 若查找成功，则返回指针 p 指向该数据元素的结点，并返回函数值为 true
	// 否则表明查找不成功，返回指针 p 指向查找路径上访问的最后一个结点，并返回函数值为false
	// 指针 f 指向当前访问的结点的双亲，其初始调用值为NULL
	if (!*T) { // 空树，查找不成功
		*p = f;
		return ERROR;
	}
	else if (EQ(kval,(*T)->key)) {
		*p = *T;
		return OK;   // 查找成功
	}
	else if (LT(kval, (*T)->key)) { // 在左子树中继续查找
		return SearchBST(&(*T)->lchild, kval, *T, p);
	}
	else { // 在右子树中继续查找
		return SearchBST(&(*T)->rchild, kval, *T, p);
	}
}

bool EQ(KeyType a, KeyType b) {
	// 若a与b相等，返回true，否则返回false 
	if (a == b) {
		return true;
	}
	return false;
}

bool LT(KeyType a, KeyType b) {
	// 若a小于b，返回true，否则返回false 
	if (a < b) {
		return true;
	}
	return false;
}

Status DeleteBST(BSTree *T, KeyType kval) {
	// 若二叉排序树 T 中存在其关键字等于 kval 的数据元素，则删除该数据元素结点，
	// 并返回函数值 OK，否则返回函数值 ERROR
	if (!(*T)) { // 不存在关键字等于kval的数据元素
		return ERROR;
	}
	else {
		if (EQ(kval, (*T)->key)) { // 找到关键字等于key的数据元素
			Delete(T);
			return OK;
		}
		else if (LT(kval, (*T)->key)) { // 继续在左子树中进行查找
			return DeleteBST(&(*T)->lchild, kval);
		}
		else { // 继续在右子树中进行查找
			return DeleteBST(&(*T)->rchild, kval);
		}
	}
}

Status Delete(BSTree *p) {
	// 从二叉排序树中删除结点 p，并重接它的左子树或右子树
	BSTree q, s;
	if (!(*p)->rchild) { // 右子树为空树则只需重接它的左子树
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if (!(*p)->lchild) { // 左子树为空树则只需重接它的右子树
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else {  // 左右子树均不空
		q = *p;
		s = (*p)->lchild;
		while (s->rchild) { // s 指向被删结点的前驱
			q = s;
			s = s->rchild;
		}
		(*p)->key = s->key;
		if (q != *p) {
			q->rchild = s->lchild; // 重接*q的右子树
		}
		else {
			q->lchild = s->lchild; // 重接*q的左子树
		}
		free(s);
	}
	return OK;
}

Status PreOrderTraverse(BSTree T, FILE *p, Status(*Visit)(ElemType)) {
	//先序遍历二叉树,对每个数据元素调用函数Visit
	if (T) {
		fprintf(p,", ");
		Visit(T->key,p);
		PreOrderTraverse(T->lchild, p,Visit);
		PreOrderTraverse(T->rchild, p,Visit);
		return OK;
	}
	return ERROR;
}

Status Visit(ElemType e,FILE *p) {
	// 输出元素
	fprintf(p,"%d", e);
	return OK;
}

Status PrintTree(BSTree T,FILE *p) {
	// 打印输出整棵二叉树
	Visit(T->key,p);
	PreOrderTraverse(T->lchild, p,Visit);
	PreOrderTraverse(T->rchild, p,Visit);
	fprintf(p,"\n");
}