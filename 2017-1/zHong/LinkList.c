#include"LinkList.h"
#include<stdlib.h>

#define MAX 100

void scan(ElemType *p){
	scanf_s("%d",p);
}
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
//�½�����Ϊn�ĵ�����L��������ÿ������ʹ��func����������
void print(const ElemType n){
	printf("%2d ",n);
}
void TraverseList_L(const LinkList L,void(*func)(ElemType)){
	LNode *p = L->next;
	while (p){
		func(p->data);
		p = p->next;
	}
}
//����������L��������ÿ������ִ��func����

void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc){
	LNode *pa = La->next, *pb = Lb->next, *pc;
	(*Lc) = pc = La;//��La��ͷ�ڵ���ΪLc��ͷ�ڵ�

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
//�鲢����������La,Lb��Lc��