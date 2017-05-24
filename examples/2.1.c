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
	if (i < 0 || i > L->length + 1) {  // 插入位置不合法
        return ERROR; // 程序设计的fail early and openly原则
    }
    if (L->length >= L->listsize)  { // 当前存储空间已满
        return  OVERFLOW; // 程序设计的返回状态码规范
    }
    q = &(L->elem[i-1]);     // q 指示插入位置
    for (p = &(L->elem[L->length]); p >= q; --p) {
        *(p+1) = *p;       // 插入位置及之后的元素右移
    }
    *q = e;       // 插入e
    ++L->length;   // 表长增1
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

	// 产生测试数据
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
