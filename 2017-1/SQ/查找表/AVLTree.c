#include "AVLTree.h"

Status CreateAVLT(AVLTree *T, ElemType d[], int n) {
	// �������ƽ����
	int i;
	bool taller = false;
	for (i = 0; i < n; i++) {
		InsertAVLT(T, d[i], &taller); 
	}
	if (!T) {
		return OK;
	}
	return ERROR;
}

Status SearchAVLT(AVLTree *T, KeyType kval, AVLTree f, AVLTree *p) {
	// �ڸ�ָ�� T ��ָ�������еݹ�ز�����ؼ��ֵ��� kval ������Ԫ��
	// �����ҳɹ����򷵻�ָ�� p ָ�������Ԫ�صĽ�㣬�����غ���ֵΪ true
	// ����������Ҳ��ɹ�������ָ�� p ָ�����·���Ϸ��ʵ����һ����㣬�����غ���ֵΪfalse
	// ָ�� f ָ��ǰ���ʵĽ���˫�ף����ʼ����ֵΪNULL
	if (!*T) { // ���������Ҳ��ɹ�
		*p = f;
		return ERROR;
	}
	else if (EQ(kval, (*T)->key)) {
		*p = *T;
		return OK;   // ���ҳɹ�
	}
	else if (LT(kval, (*T)->key)) { // ���������м�������
		return SearchAVLT(&(*T)->lchild, kval, *T, p);
	}
	else { // ���������м�������
		return SearchAVLT(&(*T)->rchild, kval, *T, p);
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

Status InsertAVLT(AVLTree *T, ElemType e, bool *taller) {
	// ����ƽ��Ķ���������T�в����ں�e��ȵĽ�㣬�����һ������Ԫ��Ϊe���½�㣬�����سɹ�
	// ��������ʹ����������ʧȥƽ�⣬����ƽ����ת������������taller��ӦT�������
	if (!(*T)) {
		*T = (AVLTree)malloc(sizeof(AVLTNode));
		(*T)->key = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = true;
	}
	else {
		if (EQ(e, (*T)->key)) {
			*taller = false;
			return ERROR;
		}
		if (LT(e, (*T)->key)) {
			if (InsertAVLT(&(*T)->lchild, e, taller)) {
				return ERROR;
			}
			if (*taller) {
				switch ((*T)->bf) {
				case LH:
					LeftBalance(T);
					*taller = false;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = true;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = false;
					break;
				}
			}	
		}
		else {
			if (InsertAVLT(&(*T)->rchild, e, taller)) {
				return ERROR;
			}
			if (*taller) {
				switch ((*T)->bf) {
				case LH:
					(*T)->bf = EH;
					*taller = false;
					break;
				case EH:
					(*T)->bf = RH;
					*taller = true;
					break;
				case RH:
					RightBalance(T);
					*taller = false;
					break;
				}
			}
		}
	}
	return OK;
}

Status L_Rotate(AVLTree *T) {
	// ����ָ�� *T Ϊ���Ķ�����������������������֮�� T ָ���µĸ��ڵ�
	AVLTree rc;
	rc = (*T)->rchild;
	(*T)->rchild = rc->lchild;
	rc->lchild = (*T);
	(*T) = rc;
	return OK;
}

Status R_Rotate(AVLTree *T) {
	// ����ָ�� *T Ϊ���Ķ�����������������������֮�� T ָ���µĸ��ڵ�
	AVLTree lc;
	lc = (*T)->lchild;
	(*T)->lchild = lc->rchild;
	lc->rchild = (*T);
	(*T) = lc;
	return OK;
}

Status LeftBalance(AVLTree *T) {
	// ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת�����㷨����ʱTָ���µĸ��ڵ�
	AVLTree lc, rc;
	lc = (*T)->lchild;
	rc = NULL;
	if (lc) {
		switch (lc->bf) {
		case LH:
			(*T)->bf = lc->bf = EH;
			R_Rotate(T);
			break;
		case RH:
			rc = lc->rchild;
			switch (rc->bf) {
			case LH:
				(*T)->bf = RH;
				lc->bf = EH;
				break;
			case EH:
				(*T)->bf = lc->bf = EH;
				break;
			case RH:
				(*T)->bf = EH;
				lc->bf = LH;
				break;
			}
			rc->bf = EH;
			L_Rotate(&(*T)->lchild);
			R_Rotate(T);
			break;
		}
		return OK;
	}
	return ERROR;
}

Status RightBalance(AVLTree *T) {
	// ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת�����㷨����ʱTָ���µĸ��ڵ�
	AVLTree lc, rc;
	rc = (*T)->rchild;
	lc = NULL;
	if (rc) {
		switch (rc->bf) {
		case RH:
			(*T)->bf = rc->bf = EH;
			L_Rotate(T);
			break;
		case LH:
			lc = rc->lchild;
			switch (lc->bf) {
			case LH:
				(*T)->bf = EH;
				rc->bf = RH;
				break;
			case EH:
				(*T)->bf = rc->bf = EH;
				break;
			case RH:
				(*T)->bf = LH;
				rc->bf = EH;
				break;
			}
			lc->bf = EH;
			R_Rotate(&(*T)->rchild);
			L_Rotate(T);
			break;
		}
		return OK;
	}
	return ERROR;
}

Status PreOrderTraverse(AVLTree T, FILE *p, Status(*Visit)(ElemType)) {
	// �������������,��ÿ������Ԫ�ص��ú���Visit
	if (T) {
		fprintf(p, ", ");
		Visit(T->key, p);
		PreOrderTraverse(T->lchild, p, Visit);
		PreOrderTraverse(T->rchild, p, Visit);
		return OK;
	}
	return ERROR;
}

Status Visit(ElemType e, FILE *p) {
	// ���Ԫ��
	fprintf(p, "%d", e);
	return OK;
}

Status PrintTree(AVLTree T, FILE *p) {
	// ��ӡ������ö�����
	Visit(T->key, p);
	PreOrderTraverse(T->lchild, p, Visit);
	PreOrderTraverse(T->rchild, p, Visit);
	fprintf(p, "\n");
}

//===============���²ο�����(ɾ������)=============//
// ����˵����*TΪ�����е����������ĸ����
// bfChildΪ*T��ɾ�����ǰ��ƽ������
Status DelLeftCase(AVLTree *T, int bfChild)
{
	// ��bfΪ-1��1��Ϊ0�����ߺ���Ϊ��ʱ˵�������߽���     
	if ((!(*T)->lchild) || (EH != bfChild && EH == (*T)->lchild->bf)) {
		switch ((*T)->bf) { // ���������߽���
		case EH:
			(*T)->bf = RH;
			break;
		case LH:
			(*T)->bf = EH;
			break;
		case RH:        // ԭ���������Ƚϸ�   
			RightBalance(T);
			break;
		}
		return OK;
	}
	else {
		return ERROR;
	}
}

Status DelRightCase(AVLTree *T, int bfChild)
{
	// ��bfΪLH��RH��ΪEH�����ߺ���Ϊ��ʱ˵�������߽���
	if ((!(*T)->rchild) || (EH != bfChild && EH == (*T)->rchild->bf)) {
		switch ((*T)->bf) { // ���������߽���
		case EH:
			(*T)->bf = LH;
			break;
		case RH:
			(*T)->bf = EH;
			break;
		case LH:    //ԭ���������Ƚϸ�    
			LeftBalance(T);
			break;
		}
		return OK;
	}
	else {
		return ERROR;
	}
}

AVLTree DeleteNode(AVLTree *T, KeyType key)
{
	// �ݹ��ҵ�Ԫ��ֵΪkey��Ԫ�أ�ɾ����Ԫ�أ�������ǰ������ƽ��
	// �����ݹ�ʱ���������õݹ����������ƽ��ֱ�����ڵ�
	int bfChild = 0;
	if (*T) {
		if (LT(key, (*T)->key)) { // ��ǰԪ�ش��ڴ�ɾ��Ԫ��
			bfChild = (*T)->lchild->bf;
			(*T)->lchild = DeleteNode(&(*T)->lchild, key); // �������������н��в���
			DelLeftCase(T, bfChild);
		}
		else if (LT((*T)->key, key)) { // ��ǰԪ��С�ڴ�ɾ��Ԫ��
			bfChild = (*T)->rchild->bf;
			(*T)->rchild = DeleteNode(&(*T)->rchild, key); // �������������н��в���
			DelRightCase(T, bfChild);
		}
		else // ��ǰ�ڵ����Ҫɾ���Ľڵ�
		{
			if ((*T)->lchild)        // *T����Ҷ�ӽ�㲢�Ҿ���ֱ��ǰ��
			{
				AVLTree farRight, temp;
				// AVLTree farRight = GofarRight((*T)->lchild);
				// ����http://www.cs.usfca.edu/~galles/visualization/RedBlack.html
				// �˹��������ݣ�����̬ͼ����ʾ�Ʋ��farRight��ָ��
				temp = (*T)->lchild->rchild; 
				while (temp) {
					farRight = temp;
					temp = temp->rchild;
				}
				(*T)->key = farRight->key; // ����Ԫ��ֵ
				// ����ȷ����ɾ���Ľڵ�Ϊ��ǰ�ڵ����������ĳһ���ڵ�
				(*T)->lchild = DeleteNode(&(*T)->lchild, farRight->key); // ɾ��Ԫ��ֵΪkey�Ľڵ�
				DelLeftCase(T, bfChild); // ������ƽ�����
			}
			else if ((*T)->rchild)    // *T����Ҷ�ӽ�㲢�Ҿ���ֱ�Ӻ���
			{
				AVLTree farLeft, temp;
				// AVLTree farLeft = GofarLeft((*T)->rchild);
				// ����http://www.cs.usfca.edu/~galles/visualization/RedBlack.html
				// �˹��������ݣ�����̬ͼ����ʾ�Ʋ��farLeft��ָ��
				temp = (*T)->rchild->lchild;
				while(temp){
					farLeft = temp;
					temp = temp->lchild;
				}
				(*T)->key = farLeft->key; // ����Ԫ��ֵ
				(*T)->rchild = DeleteNode(&(*T)->rchild, farLeft->key); // ɾ��Ԫ��ֵΪkey�Ľڵ�
				DelRightCase(T, bfChild); // ������ƽ�����
			}
			else             // *T��Ҷ�ӽ��
			{
				free(*T);
				*T = NULL;
			}
		}
	}
	return (*T); // �����˷���NULL�������ĵ�ǰ�ڵ�
}