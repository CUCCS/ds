#include "BSTree.h"

Status CreateBST(BSTree *T, ElemType d[], int n) {
	//�������������
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
	// �������������в����ڹؼ��ֵ��� e ������Ԫ��ʱ������Ԫ��ֵΪ e �Ľ�㣬������ true
	// ���򣬲����в��벢����false
	BSTree p, s;
	if (SearchBST(T, e, NULL, &p)) {
		s = (BSTree)malloc(sizeof(BSTNode)); // Ϊ�½�����ռ�
		s->key = e;
		s->lchild = s->rchild = NULL;
		if (!p) {
			*T = s; // ���� s Ϊ�µĸ����
		}
		else if (LT(e, p->key)) {
			p->lchild = s; // ���� *s Ϊ *p ������
		}
		else {
			p->rchild = s; // ���� *s Ϊ *p ���Һ���
		}
		return OK;
	}
	else {
		return ERROR;
	}
}

Status SearchBST(BSTree *T, KeyType kval, BSTree f, BSTree *p) {
	// �ڸ�ָ�� T ��ָ�����������еݹ�ز�����ؼ��ֵ��� kval ������Ԫ��
	// �����ҳɹ����򷵻�ָ�� p ָ�������Ԫ�صĽ�㣬�����غ���ֵΪ true
	// ����������Ҳ��ɹ�������ָ�� p ָ�����·���Ϸ��ʵ����һ����㣬�����غ���ֵΪfalse
	// ָ�� f ָ��ǰ���ʵĽ���˫�ף����ʼ����ֵΪNULL
	if (!*T) { // ���������Ҳ��ɹ�
		*p = f;
		return ERROR;
	}
	else if (EQ(kval,(*T)->key)) {
		*p = *T;
		return OK;   // ���ҳɹ�
	}
	else if (LT(kval, (*T)->key)) { // ���������м�������
		return SearchBST(&(*T)->lchild, kval, *T, p);
	}
	else { // ���������м�������
		return SearchBST(&(*T)->rchild, kval, *T, p);
	}
}

bool EQ(KeyType a, KeyType b) {
	// ��a��b��ȣ�����true�����򷵻�false 
	if (a == b) {
		return true;
	}
	return false;
}

bool LT(KeyType a, KeyType b) {
	// ��aС��b������true�����򷵻�false 
	if (a < b) {
		return true;
	}
	return false;
}

Status DeleteBST(BSTree *T, KeyType kval) {
	// ������������ T �д�����ؼ��ֵ��� kval ������Ԫ�أ���ɾ��������Ԫ�ؽ�㣬
	// �����غ���ֵ OK�����򷵻غ���ֵ ERROR
	if (!(*T)) { // �����ڹؼ��ֵ���kval������Ԫ��
		return ERROR;
	}
	else {
		if (EQ(kval, (*T)->key)) { // �ҵ��ؼ��ֵ���key������Ԫ��
			Delete(T);
			return OK;
		}
		else if (LT(kval, (*T)->key)) { // �������������н��в���
			return DeleteBST(&(*T)->lchild, kval);
		}
		else { // �������������н��в���
			return DeleteBST(&(*T)->rchild, kval);
		}
	}
}

Status Delete(BSTree *p) {
	// �Ӷ�����������ɾ����� p�����ؽ�������������������
	BSTree q, s;
	if (!(*p)->rchild) { // ������Ϊ������ֻ���ؽ�����������
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if (!(*p)->lchild) { // ������Ϊ������ֻ���ؽ�����������
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else {  // ��������������
		q = *p;
		s = (*p)->lchild;
		while (s->rchild) { // s ָ��ɾ����ǰ��
			q = s;
			s = s->rchild;
		}
		(*p)->key = s->key;
		if (q != *p) {
			q->rchild = s->lchild; // �ؽ�*q��������
		}
		else {
			q->lchild = s->lchild; // �ؽ�*q��������
		}
		free(s);
	}
	return OK;
}

Status PreOrderTraverse(BSTree T, FILE *p, Status(*Visit)(ElemType)) {
	//�������������,��ÿ������Ԫ�ص��ú���Visit
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
	// ���Ԫ��
	fprintf(p,"%d", e);
	return OK;
}

Status PrintTree(BSTree T,FILE *p) {
	// ��ӡ������ö�����
	Visit(T->key,p);
	PreOrderTraverse(T->lchild, p,Visit);
	PreOrderTraverse(T->rchild, p,Visit);
	fprintf(p,"\n");
}