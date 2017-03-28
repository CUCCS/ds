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

void scan(ElemType *p)   //新建输入输出函数
{

	scanf_s("%d", p);

}

void print(const ElemType n)
{

	printf("%2d ", n);

}


void CreateList_L(LinkList L, int n, void(*func)(ElemType*))  //创建单链表代码参考了ds目录下用户TheMasterOfMagic的代码
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

	printf("创建完毕\n");
	printf("\n");
}

void MergeList(LinkList La, LinkList Lb, LinkList *Lc)    //合并链表代码参考课本2.12算法修改而来
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
	printf("pa与pb中至少有一个为空，循环中止\n");
	printf("\n");
	pc->next = pa ? pa : pb;
	free(Lb);
}

/*遍历单链表*/
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

	*p = test1_iter(rand() % 5 + 1);     //随机产生测试数据

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
	printf("开始创建单链表La\n");
	CreateList_L(La, LEN + rand() % 5, test1);
	Lb = (LinkList)malloc(sizeof(LNode));
	printf("开始创建单链表Lb\n");
	CreateList_L(Lb, LEN + rand() % 5, test2);
	printf("\nLa内数据:");
	TraverseList_L(La, print);
	printf("\n");
	printf("Lb内数据:");
	TraverseList_L(Lb, print);
	printf("\n\n");

	MergeList(La, Lb, &Lc);
	printf("合并后的Lc:");
	TraverseList_L(Lc, print);
	printf("\n\n");
	return 0;
}
