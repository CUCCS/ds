#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define NULL 0
#define LEN sizeof(struct LNode)

//定义单链线性表
typedef struct LNode
{
	int data;
   struct LNode *next;
}LNode,*LinkList;

//定义枚举类型 设置返回值
typedef enum {
	OK,
	ERROR
}Status;

//创建单链线性表
Status CreateList_L(LinkList &L, int n)//逆位序输入n个元素的值，建立带表头结点的单链线性表L。
{
	int i;
	srand((unsigned)time(NULL));//用时间做种

	if (n < 0)//若个数不合法，报错
	{
		return ERROR;
	}
    LinkList p;
	L = (LinkList)malloc(LEN);
	L->next = NULL;//先建立一个带头结点的单链表
	for ( i = n; i > 0; --i)
	{
		p= (LinkList)malloc(LEN);//生成新结点;
		p->data=(int)rand()%2000;//随机生成元素值
		p->next = L->next;
		L->next = p;//插入到表头
	}
	
	return OK;

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
	p = head->next;
	if (p != NULL)        //如果不是空链表，就输出链表中所有节点  
	{
		do
		{
			printf("%d ",p->data);//输出数据
			p = p->next;     //移到下一个节点  
		} while (p != NULL);
	}
	printf("\n");
}//Print_L

int main(int argc,char* argv[])
{
	srand((unsigned)time(NULL));//用时间做种

	int n ;
	n=(int)rand() % 20;//随机生成个数

	LinkList La,Lb,Lc;//定义链表
	CreateList_L(La, n);//创建
	CreateList_L(Lb, n);//创建
	MergeList_L(La, Lb, Lc);//插入
	
	Print_L(Lc);//打印

	return 0;
}
