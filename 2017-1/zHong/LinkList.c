#include"LinkList.h"
#include<stdlib.h>

#define MAX 100

void scan(ElemType *p){
	scanf_s("%d",p);
}
void print(const ElemType n){
	printf("%2d ", n);
}

/*算法2.11	新建单链表*/
void CreateList_L(LinkList L, int n, void(*func)(ElemType*)){
	int i;
	LNode* p;

	L->next = NULL;

	for (i = 0; i < n; ++i){
		p = (LinkList)malloc(sizeof(LNode));
		func(&p->data);
		p->next = L->next;
		L->next = p;
	}
};//CraeteList_L
/*算法2.12	归并两个单链表*/
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc){
	LNode *pa = La->next, *pb = Lb->next, *pc;
	(*Lc) = pc = La;//用La的头节点作为Lc的头节点

	while (pa&&pb){
		if (pa->data <= pb->data){
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else{
			pc->next = pb; pc = pb; pb = pb->next;
		}//end if else
	}//end while

	pc->next = pa ? pa : pb;
	free(Lb);
}
/*遍历单链表*/
void TraverseList_L(const LinkList L, void(*func)(ElemType)){
	LNode *p = L->next;
	while (p){
		func(p->data);
		p = p->next;
	}
}