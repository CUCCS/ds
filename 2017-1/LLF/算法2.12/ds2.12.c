#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#define LEN sizeof(struct LNode)

//定义单链线性表
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

//对链表中数据进行非递减排序
LNode* SelectSort(LNode *L)
{
	LNode *p, *q, *small;
	int temp;

	for (p = L->next; p->next != NULL; p = p->next)    /*每次循环都找出一个最小值，将最小值交换到第一位，然后将指针向后移动一位*/
	{
		small = p;
		for (q = p->next; q; q = q->next)    /*由前向后遍历，找出最小的节点*/
		{
			if (q->data < small->data)
				small = q;
		}
		if (small != p)
		{
			temp = p->data;
			p->data = small->data;
			small->data = temp;
		}
	}
	return L;
}
	


//创建单链线性表
LNode* CreateList_L( int n)//逆位序输入n个元素的值，建立带表头结点的单链线性表L。
{
	LNode * L;
	int i;


	if (n < 0)//若个数不合法，报错
	{
		exit(0);
	}
	LNode * p;
	L = (LNode *)malloc(LEN);
	L->next = NULL;//先建立一个带头结点的单链表
	for (i = n; i > 0; --i)
	{
		p = (LNode *)malloc(LEN);//生成新结点;
		p->data = (int)rand() % 2000;//随机生成元素值
		p->next = L->next;
		L->next = p;//插入到表头
	}
	
	return SelectSort(L);

}//CreateList_L


 //已知单链线性表la和lb的元素按值非递减排列。
 //归并la和lb得到新的单链线性表lc，lc的元素也按值非递减排列。
LNode* MergeList_L(LNode * La, LNode * Lb, LNode * Lc)
{
	struct LNode *pa, *pb, *pc;
	pa = La->next;
	pb = Lb->next;
	pc = La;
	Lc = pc;//用la的头结点作为lc的头结点
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
	free(Lb);     //释放lb的头结点
	return Lc;
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
			printf("%d ", p->data);//输出数据
			p = p->next;     //移到下一个节点  
		} while (p != NULL);
	}
	printf("\n");
}//Print_L

int main(int argc, char* argv[])
{
	srand((unsigned)time(NULL));//用时间做种

	int n;
	n = (int)rand() % 20;//随机生成个数

	LNode * La, *Lb, *Lc;//定义链表

	La = CreateList_L(n);
	printf("La:  ");
	Print_L(La);//打印La

	Lb = CreateList_L(n);
	printf("Lb:  ");
	Print_L(Lb);//打印Lb

	Lc = NULL;

	Lc=MergeList_L(La, Lb, Lc);//插入
	printf("Lc:  ");
	Print_L(Lc);//打印lc

	return 0;
}