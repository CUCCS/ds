#include<stdio.h>
#include<malloc.h>
#define NULL 0
#define LEN sizeof(struct LNode)

//定义单链线性表
typedef struct LNode
{
	int data;
   struct LNode *next;
}LNode,*LinkList;

//创建单链线性表
void CreateList_L(LinkList &L, int n)//逆位序输入n个元素的值，建立带表头结点的单链线性表L。
{
	struct LNode *p;
	L = (LinkList)malloc(LEN);
	L->next = NULL;//先建立一个带头结点的单链表
	for (int i = n; i > 0; --i)
	{
		p= (LinkList)malloc(LEN);//生成新结点;
		scanf_s("%d", p->data);//输入元素值
		p->next = L->next;
		L->next = p;//插入到表头
	}

}//CreateList_L

//已知单链线性表la和lb的元素按值非递减排列。
//归并la和lb得到新的单链线性表lc，lc的元素也按值非递减排列。
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
	struct LNode *pa, *pb, *pc;
	pa = La->next;
	pb = Lb->next;
	pc = La; Lc = pc;//用la的头结点作为lc的头结点
	while (pa&&pb)
	{
		if (pa->data <= pb->data) //将pa所指结点链接到pc所指结点之后
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else       //将pb所指结点链接到pc所指结点之后
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb; //插入剩余段
	free(Lb);               //释放lb的头结点
}//MergeList_L

//输出结点
void Print_L(struct LNode *head)
{
	struct LNode *p;
	p = head;
	if (head != NULL)        //如果不是空链表，就输出链表中所有节点  
	{
		
		do
		{
			printf("%d ",p->data);//输出数据
			p = p->next;     //移到下一个节点  
		} while (p != NULL);
	}
}//Print_L

int main()
{
	LinkList La, Lb, Lc;
	CreateList_L(La, 3);
	CreateList_L(Lb, 3);
	MergeList_L(La, Lb, Lc);
	Print_L(La);

	return 0;
}