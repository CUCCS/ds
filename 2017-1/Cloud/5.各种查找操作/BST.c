#include "BST.h"

/* ���ұ�ĳ�ʼ������ */
Status _CreateBST(BiTree *T, TElemType * c) {
	int i;
	for (i = 0; c[i] != -1; i++) {
		InsertBST(T, c[i]);
	}
	return OK;
}

/* ��T���в��ҹؼ���key */
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

/* c����ؼ���key */
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

/*���ұ�ĳ�ʼ�������Ͳ��� */
Status _Search(BiTree T, TElemType * a) {
	//���δ�ҵ��򽫵�ǰ�ؼ�����ӵ���ǰ���ұ��У�����ҵ�����ɾ���ùؼ������ڽ��
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

/* ������������� */
Status PreOrderTraverse(BiTree T, int i) {
	if (T == NULL) {
		return OK;
	}
	if (T) {
		if (i == 0) {	/* ���ʽ��*/
			printf("%d", T->data);
			i++;
		}
		else
			printf(", %d", T->data);
		PreOrderTraverse(T->lchild, i); /* ����������*/
		PreOrderTraverse(T->rchild, i); /* ����������*/
	}
	return 0;
}

/* ɾ��һ����� */
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

/* ��ӡһ����ұ� */
Status _print(BiTree T) {
	static int i = 0;
	PreOrderTraverse(T, i);
	printf("\n");
	return OK;
}