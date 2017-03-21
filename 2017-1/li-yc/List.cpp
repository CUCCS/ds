#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void creatList(LinkList &L,int n){
	int i;
	int number=20;
	LinkList p=NULL;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=n;i>0;i--){
		p=(LinkList)malloc(sizeof(LNode));
		number=number-(rand()%n+1);
		p->data=number;
		p->next=L->next;
		L->next=p;
	}
	printf("���������\n");
}

void Traverse(LinkList &L){
	LinkList a=L;
	a=a->next;
	while(a){
		printf("%d",a->data);
		printf(" ");
		a=a->next;
	}
	printf("\n");
	printf("�������");
}

void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc){
	printf("��ʼ�鲢����La��Lb\n");
	LinkList pa, pb, pc;
	pa=pb=pc=NULL;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb){
		if(pa->data<=pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa ? pa : pb;
	free(Lb);
	printf("�鲢�������\n");
}