#include "BST.h"

/* 查找表的初始化建立 */
Status _CreateBST(BiTree *T, TElemType * c) {
	int i;
	for (i = 0; c[i] != -1; i++) {
		InsertBST(T, c[i]);
	}
	return OK;
}

/* 在T树中查找关键字key */
Status SearchBST(BiTree T, TElemType key, BiTree f, BiTree * p) {
	if (!T) {
		*p = f;
		return FALSE;
	}
	else if (key == T->data) {
		*p = T;
		return TRUE;
	}
	else if (key < (*T).data) {
		return SearchBST((*T).lchild, key, T, p);
	}
	else {
		return SearchBST((*T).rchild, key, T, p);
	}
}

/* c插入关键字key */
Status InsertBST(BiTree *T, TElemType key) {
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p)) {
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = NULL;
		s->rchild = NULL;
		s->parent = NULL;
		if (!p) {
			*T = s;
		}
		else if (key < p->data) {
			p->lchild = s;
			s->parent = p;
		}
		else {
			p->rchild = s;
			s->parent = p;
		}
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*查找表的初始化建立和查找 */
Status _Search(BiTree T, TElemType * a) {
	//如果未找到则将当前关键字添加到当前查找表中，如果找到，则删除该关键字所在结点
	BiTree p, f = NULL;
	int i;
	for (i = 0; a[i] != -1; i++) {
		if (SearchBST(T, a[i], f, &p)) {
			Delete(p, f);
		}
		else {
			InsertBST(&T, a[i]);
		}
		_print(T);
	}
	return OK;
}

/* 先序遍历二叉树 */
Status PreOrderTraverse(BiTree T, int i) {
	if (T == NULL) {
		return OK;
	}
	if (T) {
		if (i == 0) {	/* 访问结点*/
			printf("%d", T->data);
			i++;
		}
		else
			printf(", %d", T->data);
		PreOrderTraverse(T->lchild, i); /* 遍历左子树*/
		PreOrderTraverse(T->rchild, i); /* 遍历右子树*/
	}
	return 0;
}

/* 删除一个结点 */
Status Delete(BiTree  p, BiTree f) {
	BiTree q, s;
	q = p;
	if (!p->rchild) {
		if (p->parent->rchild == p) {
			p->parent->rchild = p->lchild;
		}
		else {
			p->parent->lchild = p->lchild;
		}
		free(q);
	}
	else if (!p->lchild) {
		if (p->parent->rchild == p) {
			p->parent->rchild = p->rchild;
		}
		else {
			p->parent->lchild = p->rchild;
		}
		free(q);
	}
	else {
		s = p->lchild;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q != p) {
			q->rchild = s->lchild;
		}
		else {
			q->lchild = s->lchild;
		}
		free(s);
	}
	return OK;
}

/* 打印一遍查找表 */
Status _print(BiTree T) {
	static int i = 0;
	PreOrderTraverse(T, i);
	printf("\n");
	return OK;
}