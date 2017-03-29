#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include"List.h"

void creatList(LinkList &L,int n){
	printf("\nCreatList:\n");
	printf("��ʼ��������Ϊ%d�ĵ�����\n",n);

	int i;
	int number=20;
	LinkList p=NULL;

	L->next=NULL;
	printf("L->next=NULL\n");

	for(i=n;i>0;i--){
		printf("������%d���ڵ�\n",i);
		p=(LinkList)malloc(sizeof(LNode));
		printf("ʹ��malloc����Ϊָ��p�����˿ռ�,p=%x\n",p);
		number=number-(rand()%n+1);
		p->data=number;
		printf("p->data=%d\n",p->data);
		p->next=L->next;
		printf("p->next=L->next(%x)\n",p);
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
	printf("MergeList\n");
	printf("��ʼ�鲢����La��Lb\n");
	LinkList pa, pb, pc;

	pa=pb=pc=NULL;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	printf("pa=La->next(%x),pb=Lb->next(%x),Lc=pc=La(%x)\n",La->next,Lb->next,La);

	while(pa&&pb){
		printf("pa��pb����Ϊ������,ѭ������ִ��\n");
		printf("pa->data(%d)%spb->data(%d),����\n",pa->data,pa->data<=pb->data ? "<=" : ">",pb->data);
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
	printf("pa��pb��������һ��Ϊ�գ�ѭ����ֹ\n");
	pc->next=pa ? pa : pb;
	free(Lb);
	printf("�ͷ�����Lb\n");
	printf("�鲢�������\n");
}