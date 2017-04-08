//#include<stdio.h>
//#include<time.h>
//#include <stdlib.h>
//#define MAXSIZE 1000
//
//typedef struct LNode{
//	int data;
//	struct LNode *next;
//}LNode,*LinkList;
//LNode  *Create()  //����ֵ: �������ָ��
//{
//
//}
//LinkList MergeList_L(LinkList La,LinkList Lb)//�ϲ�
//{
//	LinkList   pa,pb,pc,Lc; 
//	Lc=(LinkList)malloc(sizeof(LNode)); 
//	Lc-> data=La-> data+Lb-> data; 
//	pa=La-> next; 
//	pb=Lb-> next; 
//	Lc=pc=La; 
//	while(pa&&pb) 
//	{ 
//		if(pa-> data <=pb-> data) 
//		{ 
//			pc-> next=pa;pc=pa;pa=pa->next; 
//		} 
//		else 
//		{pc-> next=pb;pc=pb;pb=pb-> next;} 
//	} 
//	pc-> next=pa?pa:pb; 
//	free(Lb); 
//	return   Lc; 
//} 
//int PrintLinkList(LinkList L) //��ӡ���� 
//{ 
//	LinkList   q; 
//	q=L; 
//	if(q!=NULL) 
//	{
//		q=q-> next; 
//		do 
//		{ 
//			printf( "%d ",q-> data); 
//			q=q-> next; 
//		} 
//		while(q!=NULL); 
//		printf( "\n "); 
//	} 
//	return 0; 
//} 
//int main()
//{
//	LinkList L1=Create();
//	LinkList L2=Create();
//	LinkList L3;
//	L3=MergeList_L(L1,L2);                           
//	PrintLinkList(L3);  
//
//	return 0;
//
//
//}

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#include<malloc.h>

typedef struct LNode{

	int data;

	struct LNode *next;

}LNode,*LinkList;

void CreateList(LinkList &L,int n)

{

	LinkList p;

	L=(LinkList)malloc(sizeof(LNode));

	L->next=NULL;//�ȳ�ʼΪ��

	printf("�밴˳�����������ֵ\n");

	srand((unsigned) time(NULL));

	for(int i=n;i>0;--i)

	{

		p=(LinkList)malloc(sizeof(LNode));

		p->data=rand()%101;

		printf("%d ",&p->data);

		p->next=L->next;

		L->next=p;

	}

}

void PrintList(LinkList L)

{

	LinkList p;

	p=L->next;

	while(p)

	{

		printf("%d ",p->data);

		p=p->next;

	}

	printf("\n");

}

LinkList MergeList_L(LinkList La,LinkList Lb)//�ϲ�
{
	LinkList   pa,pb,pc,Lc; 
	Lc=(LinkList)malloc(sizeof(LNode)); 
	Lc-> data=La-> data+Lb-> data; 
	pa=La-> next; 
	pb=Lb-> next; 
	Lc=pc=La; 
	while(pa&&pb) 
	{ 
		if(pa-> data <=pb-> data) 
		{ 
			pc-> next=pa;pc=pa;pa=pa->next; 
		} 
		else 
		{pc-> next=pb;pc=pb;pb=pb-> next;} 
	} 
	pc-> next=pa?pa:pb; 
	free(Lb); 
	return   Lc; 
} 
void main()

{

	LinkList La,Lb,Lc;
	int length1;
	int length2;
	printf("����La�ĳ���Ϊ��");
	scanf("%d",&length1);

	printf("����La������Ϊ��");
	CreateList(La,length1);

	printf("����Lb�ĳ���Ϊ��");
	scanf("%d",&length2);

	printf("����Lb������Ϊ��");
	CreateList(Lb,length2);

	 Lc=MergeList_L(La,Lb);

	printf("����Lc�ĺϲ����Ϊ��");

	PrintList(Lc);

} 