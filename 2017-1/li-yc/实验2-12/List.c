#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include"List.h"

void creatList(LinkList L,int n){
	printf("\nCreatList:\n");
	printf("开始创建长度为%d的单链表\n",n);

	int i;
	int number=20;
	LinkList p;
	p=NULL;

	L->next=NULL;

	for(i=n;i>0;i--){
		p=(LinkList)malloc(sizeof(LNode));
		number=number-(rand()%n+1);
		p->data=number;
		p->next=L->next;
		L->next=p;
	}
	printf("链表创建完毕\n");
}

void Traverse(LinkList L){
	LinkList a=L;
	a=a->next;
	while(a){
		printf("%d",a->data);
		printf(" ");
		a=a->next;
	}
	printf("\n");
	printf("遍历完成");
}

void MergeList(LinkList La,LinkList Lb,LinkList Lc){
	printf("MergeList\n");
	printf("开始归并链表La和Lb\n");
	LinkList pa, pb, pc;

	pa=pb=pc=NULL;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;

	while(pa&&pb){
		printf("pa与pb都不为空链表,循环继续执行\n");
		printf("pa->data(%d)%spb->data(%d),所以\n",pa->data,pa->data<=pb->data ? "<=" : ">",pb->data);
		if(pa->data<=pb->data){
			printf("pc->next=pa(%x),pc=pa(%x),pa=pa->next(%x)\n",pa,pa,pa->next);
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else{
			printf("pc->next=pa(%x),pc=pa(%x),pb=pb->next(%x)\n",pb,pb,pa->next);
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	printf("pa与pb中至少有一个为空，循环终止\n");
	pc->next=pa ? pa : pb;
	free(Lb);
	printf("释放链表Lb\n");
	printf("归并链表结束\n");
}