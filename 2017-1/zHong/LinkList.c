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

/*算法2.11	新建单链表*/
void CreateList_L(LinkList L, int n, void(*func)(ElemType*)){
	DEBUG && printf("\nCreateList_L\n");
	DEBUG && printf("开始创建长度为%d的单链表\n",n);
	int i;
	LNode* p;

	L->next = NULL;
	DEBUG && printf("L->next=NULL\n");

	for (i = 0; i < n; ++i){
		DEBUG && printf("创建第%d个节点\n",i+1);
		p = (LinkList)malloc(sizeof(LNode));
		DEBUG && printf("使用malloc函数为指针p分配了空间，p=%X\n",p);
		func(&p->data);
		DEBUG && printf("p->data=%d\n",p->data);
		p->next = L->next;
		DEBUG && printf("p->next=L->next(%X)\n",L->next);
		L->next = p;
		DEBUG && printf("L->next=p(%X)\n",p);
	}//end for
	DEBUG && printf("end CreateList_L\n");
};//CraeteList_L
/*算法2.12	归并两个单链表*/
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc){
	DEBUG && printf("MergeList_L\n");
	LNode *pa = La->next, *pb = Lb->next, *pc;
	(*Lc) = pc = La;//用La的头节点作为Lc的头节点
	DEBUG && printf("pa=La->next(%X),pb=Lb->next(%X), Lc=pc=La(%X)\n",La->next,Lb->next,La);

	while (pa&&pb){
		DEBUG && printf("pa与pb均不为空，循环继续\n");
		DEBUG && printf("pa->data(%d)%spb->data(%d),所以\n",pa->data,pa->data <= pb->data ? "<=" : ">",pb->data);
		if (pa->data <= pb->data){
			DEBUG && printf("pc->next=pa(%X),pc=pa(%X)，pa=pa->next(%X)\n",pa,pa,pa->next);
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else{
			DEBUG && printf("pc->next=pb(%X),pc=pb(%X)，pb=pb->next(%X)\n", pb, pb, pb->next);
			pc->next = pb; pc = pb; pb = pb->next;
		}//end if else
	}//end while
	DEBUG && printf("pa与pb中至少有一个为空，循环中止\n");
	pc->next = pa ? pa : pb;
	DEBUG && printf("%s为空，所以pc->next=%s(%X)\n", pa ? "pb" : "pa", pa ? "pa" : "pb", pa ? pa : pb);
	free(Lb);
	DEBUG && printf("释放Lb\n");
}
/*遍历单链表*/
void TraverseList_L(const LinkList L, void(*func)(ElemType)){
	LNode *p = L->next;
	while (p){
		func(p->data);
		p = p->next;
	}
}