#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "2.1.h"

void InitList(List *L) {
	L->length = 0;
    L->listsize = LISTSIZE;
}

int equal_fn(ElemType a, ElemType b) {
	return a == b ? 1 : 0;
}

int ListLength(List a) {
	return a.length;
}

void GetElem(List Lb, int i, ElemType *e) {
	*e = Lb.elem[i];
}

int LocateElem(List La, ElemType e, int (*equal)(ElemType, ElemType)) {
	int i;
	for(i = 0; i < ListLength(La); i++) {
		if((*equal)(e, La.elem[i]) == 1) {
			return i;
		}
	}

	return -1;
}

int ListInsert(List *L, int i, ElemType e) {
    ElemType *p, *q;
	if (i < 0 || i > L->length + 1) {  // ����λ�ò��Ϸ�
        return ERROR; // ������Ƶ�fail early and openlyԭ��
    }
    if (L->length >= L->listsize)  { // ��ǰ�洢�ռ�����
        return  OVERFLOW; // ������Ƶķ���״̬��淶
    }
    q = &(L->elem[i-1]);     // q ָʾ����λ��
    for (p = &(L->elem[L->length]); p >= q; --p) {
        *(p+1) = *p;       // ����λ�ü�֮���Ԫ������
    }
    *q = e;       // ����e
    ++L->length;   // ����1
    return OK;
}

void Union(List *la, List lb) {
	int i;
	ElemType e;
	int La_len = ListLength(*la);
	int Lb_len = ListLength(lb);
	
	for(i = 0; i < Lb_len; i++) {
		GetElem(lb, i, &e);
		if(LocateElem(*la, e, &equal_fn) == -1) {
			ListInsert(la, ++La_len, e);
		}
	}
}

void ListTraverse(List L) {
	int i;
	for(i = 0; i < ListLength(L); i++) {
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

int main() {
	List la;
	List lb;
    int i;
    int la_length = 5;
    int lb_length = 6;

	InitList(&la);
	InitList(&lb);

	// ������������
    srand(time(NULL));
    for(i = 0; i < la_length; i++) {
        la.elem[i] = (int)rand() % 1024;
    }
    la.length = la_length;
    for(i = 0; i < lb_length; i++) {
        lb.elem[i] = (int)rand() % 1024;
    }
    lb.length = lb_length;

	ListTraverse(la);
	ListTraverse(lb);

    Union(&la, lb);

	ListTraverse(la);

	return 0;
}
