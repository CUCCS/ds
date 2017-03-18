#include"LinkList.h"
#include<stdlib.h>

#define MAX 100
#define DEBUG 1

void scan(ElemType *p){
	scanf_s("%d",p);
}
void print(const ElemType n){
	printf("%2d ", n);
}

/*�㷨2.11	�½�������*/
void CreateList_L(LinkList L, int n, void(*func)(ElemType*)){
	DEBUG && printf("\nCreateList_L\n");
	DEBUG && printf("��ʼ��������Ϊ%d�ĵ�����\n",n);
	int i;
	LNode* p;

	L->next = NULL;
	DEBUG && printf("L->next=NULL\n");

	for (i = 0; i < n; ++i){
		DEBUG && printf("������%d���ڵ�\n",i+1);
		p = (LinkList)malloc(sizeof(LNode));
		DEBUG && printf("ʹ��malloc����Ϊָ��p�����˿ռ䣬p=%X\n",p);
		func(&p->data);
		DEBUG && printf("p->data=%d\n",p->data);
		p->next = L->next;
		DEBUG && printf("p->next=L->next(%X)\n",L->next);
		L->next = p;
		DEBUG && printf("L->next=p(%X)\n",p);
	}//end for
	DEBUG && printf("end CreateList_L\n");
};//CraeteList_L
/*�㷨2.12	�鲢����������*/
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc){
	DEBUG && printf("MergeList_L\n");
	LNode *pa = La->next, *pb = Lb->next, *pc;
	(*Lc) = pc = La;//��La��ͷ�ڵ���ΪLc��ͷ�ڵ�
	DEBUG && printf("pa=La->next(%X),pb=Lb->next(%X), Lc=pc=La(%X)\n",La->next,Lb->next,La);

	while (pa&&pb){
		DEBUG && printf("pa��pb����Ϊ�գ�ѭ������\n");
		DEBUG && printf("pa->data(%d)%spb->data(%d),����\n",pa->data,pa->data <= pb->data ? "<=" : ">",pb->data);
		if (pa->data <= pb->data){
			DEBUG && printf("pc->next=pa(%X),pc=pa(%X)��pa=pa->next(%X)\n",pa,pa,pa->next);
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else{
			DEBUG && printf("pc->next=pb(%X),pc=pb(%X)��pb=pb->next(%X)\n", pb, pb, pb->next);
			pc->next = pb; pc = pb; pb = pb->next;
		}//end if else
	}//end while
	DEBUG && printf("pa��pb��������һ��Ϊ�գ�ѭ����ֹ\n");
	pc->next = pa ? pa : pb;
	DEBUG && printf("%sΪ�գ�����pc->next=%s(%X)\n", pa ? "pb" : "pa", pa ? "pa" : "pb", pa ? pa : pb);
	free(Lb);
	DEBUG && printf("�ͷ�Lb\n");
}
/*����������*/
void TraverseList_L(const LinkList L, void(*func)(ElemType)){
	LNode *p = L->next;
	while (p){
		func(p->data);
		p = p->next;
	}
}