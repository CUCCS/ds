//#include<stdio.h>
////头文件，标准输入输出
//#include<stdlib.h>
////内存分配函数malloc的头文件
//typedef struct LNode
//{
//	int data;//数据
//	struct LNode *next;//指向下一个节点的指针
//
//}LNode, *Linklist;
//Linklist CreatList(LNode *L, int n);//创建新的线性表的函数
//Linklist MergeList(LNode *l1, LNode  *L2, LNode *l3);//实现两个链表相结合形成第三个链表
//void output(LNode *ll, int n);
#include "Source.h";


int main()
{
	Linklist la = NULL, lb = NULL, lc = NULL;//定义三个Linklist变量
	//srand((unsigned)time(NULL));
	int a, b;
	a = rand() % 101;
	/*scanf("%d", &a);*/
	la = CreatList(la, a);//调用函数创建第一个线性表
    b= rand() % 101;
	/*scanf("%d", &b);*/
	lb = CreatList(lb, b);
	lc = MergeList(la, lb, lc);//调用函数实现两个线性表相连
							   //lc = lc->next;
	output(lc, a + b);
	return 0;

}

Linklist CreatList(LNode *L, int n)
{
	LNode * p = NULL;
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; i--)
	{
	/*	
		p->data = rand() % 101;*/
		p = (LNode *)malloc(sizeof(LNode));
	/*	scanf("%d", &p->data);*/
		p->data = rand() % 101; 
		p->next = L->next;
		L->next = p;
	}
	return L;
}


Linklist MergeList(LNode *l1, LNode *l2, LNode *l3)
{
	LNode * la = NULL;
	LNode * lb = NULL;
	LNode * lc = NULL;
	la = l1->next;
	lb = l2->next;
	l3 = lc = l1;
	while (la&&lb)//当la和lb都不为空时进行操作
	{
		if (la->data <= lb->data)
		{
			lc->next = la;
			lc = la;
			la = la->next;
		}
		else
		{
			lc->next = lb;
			lc = lb;
			lb = lb->next;
		}
	}
	lc->next = (la ? la : lb);

	if (l2 != NULL)
		free(l2);//将第二个线性表占用的内存释放

	return l3;
}

void output(LNode *ll, int n)
{
	int i;
	LNode *p = ll->next;
	for (i = n; i > 0; i--)

	{
		printf("%d", p->data);
		p = p->next;
	}

}