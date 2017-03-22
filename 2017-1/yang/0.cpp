#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

void CreateList_L(LinkList&L, int n)
{
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0; i<n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
void MergeList_L(LinkList&La, LinkList&Lb, LinkList&Lc)
{
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
    pc = La;
	Lc = La;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
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
	pc->next = pa ? pa : pb;
	free(Lb);
}
int main()
{
	LinkList La, Lb, Lc,p1;
	int n, m;
	cin >>n >> m;
	CreateList_L(La,  n);
	CreateList_L(Lb, m);
	p1 = La;
	MergeList_L(La, Lb, Lc);
	while (p1->next!=NULL)
	{
		p1 = p1->next;
		cout << p1->data << " ";
		
	}

}