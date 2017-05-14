#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define OK 1
#define OVERFLOW -2
#define TRUE 1
#define LEN 5

typedef int ElemType;


typedef struct  LNode
{
	ElemType elem;
	struct LNode* next;

}LNode, *LinkList;

void scan(ElemType *p)   //�½������������
{

	scanf_s("%d", p);

}

void print(const ElemType n)
{

	printf("%2d ", n);

}


void CreateList_L(LinkList L, int n, void(*func)(ElemType*))  //�������������ο���dsĿ¼���û�TheMasterOfMagic�Ĵ���
{


	int i;

	LNode* p;

	L->next = NULL;



	for (i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(LNode));
		func(&p->elem);
		p->next = L->next;
		L->next = p;


	}

	printf("�������\n");
	printf("\n");
}

void MergeList(LinkList La, LinkList Lb, LinkList *Lc)    //�ϲ��������ο��α�2.12�㷨�޸Ķ���
{
	LNode *pa, *pb, *pc;
	pa = La->next; pb = Lb->next;
	(*Lc) = pc = La;
	while (pa&&pb)
	{
		if (pa->elem <= pb->elem)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	printf("pa��pb��������һ��Ϊ�գ�ѭ����ֹ\n");
	printf("\n");
	pc->next = pa ? pa : pb;
	free(Lb);
}

/*����������*/
void TraverseList_L(const LinkList L, void(*func)(ElemType)) {

	LNode *p = L->next;

	while (p) {

		func(p->elem);

		p = p->next;

	}

}


int test1_iter(int k) {

	static int b = 20;

	return b -= k;

}

void test1(ElemType *p)
{

	*p = test1_iter(rand() % 5 + 1);     //���������������

}

int test2_iter(int k)
{

	static int b = 20;

	return b -= k;

}

void test2(ElemType *p)
{

	*p = test2_iter(rand() % 5 + 1);

}

int main()
{
	LinkList La;
	LinkList Lb;
	LinkList Lc;
	srand(time(0));
	La = (LinkList)malloc(sizeof(LNode));
	printf("��ʼ����������La\n");
	CreateList_L(La, LEN + rand() % 5, test1);
	Lb = (LinkList)malloc(sizeof(LNode));
	printf("��ʼ����������Lb\n");
	CreateList_L(Lb, LEN + rand() % 5, test2);
	printf("\nLa������:");
	TraverseList_L(La, print);
	printf("\n");
	printf("Lb������:");
	TraverseList_L(Lb, print);
	printf("\n\n");

	MergeList(La, Lb, &Lc);
	printf("�ϲ����Lc:");
	TraverseList_L(Lc, print);
	printf("\n\n");
	return 0;
}
