#include"BSTree.h"
int max = 0;


bool EQ(KeyType kval, KeyType data) //比较两个数是否相等 相等返回1否则返回0
{
	if (kval == data) {
		return true;
	}
	else {
		return false;
	}
}

bool LT(KeyType kval, KeyType data)  //比较kval是否小于data 若是则返回1 否则返回0
{
	if ( kval < data) {
		return true;
	}
	else {
		return false;
	}
}

Status preOrderTraverse(BiTree T)  //先序遍历排序二叉树
{
	fp = fopen("BSTOutput.txt", "a");//以读方式打开文件.
	if (T) 
	{
		printf("%d", T->data);
		fprintf(fp, "%d", T->data);  //将数据写入文件
		if (T->data != max) 
		{
			printf(", ");
			fprintf(fp, ", ");
		}
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);
		return OK;
	}
	else {
		return ERROR;
	}

}

bool SearchBST(BiTree T, KeyType kval, BiTree f, BiTree *p) //排序二叉树的查找
{
	if (!T) {
		*p = f;
		return false;
	}
	else if (EQ(kval, T->data)) {   //查找成功就结束
		*p = T;
		return true;
	}
	else if (LT(kval, T->data)) {  //小于查左孩子
		return SearchBST(T->lchild, kval, T, p);
	}
	else {
		return SearchBST(T->rchild, kval, T, p);  //大于查右孩子
	}
}

bool InsertBST(BiTree *T, KeyType e, BiTree p) //二叉树的插入
{  
	BiTree s = NULL;
	if (max < e) 
{
		max = e;
	}
	if (!(s = (BiTNode *)malloc(sizeof(BiTNode)))) {
		exit(OVERFLOW);
	}
	if (!(p = (BiTNode *)malloc(sizeof(BiTNode)))) {
		exit(OVERFLOW);
	}
	if (!SearchBST(*T, e, NULL, &p)) {
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p) {
			*T = s;
		}
		else if (LT(e, p->data)) {
			p->lchild = s;
		}
		else {
			p->rchild = s;
		}
		return true;
	}
	else {
		return false;
	}
}

Status Delete(BiTree *p) {  //二叉树的删除
	BiTree q = NULL;
	BiTree s = NULL;
	if (!(*p)->rchild) {
		q = *p;
		(*p) = (*p)->lchild;
	}
	else if (!(*p)->lchild) {
		q = *p;
		(*p) = (*p)->rchild;
	}
	else {
		q = *p;
		s = (*p)->lchild;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != (*p)) {
			q->rchild = s->lchild;
		}
		else {
			q->rchild = s->lchild;
		}
	}
	return OK;
}

bool DeleteBST(BiTree *T, KeyType kval) {
	if (!T) {
		return false;
	}
	else {
		if (EQ(kval, (*T)->data)) {
			Delete(T);
			return true;
		}
		else if (LT(kval, (*T)->data)) {
			return DeleteBST(&(*T)->lchild, kval);
		}
		else {
			return DeleteBST(&(*T)->rchild, kval);
		}
	}
}