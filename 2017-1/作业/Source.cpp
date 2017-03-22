//#include<stdio.h>
////头文件，标准输入输出
//#include<stdlib.h>
////内存分配函数malloc的头文件
//typedef struct LNode
//{
//	int data;//数据
//	struct LNode *next;//指向下一个节点的指针
//
//}LNode,*Linklist;
//void CreatList(Linklist &L, int n);//创建新的线性表的函数
//void MergeList(Linklist &l1, Linklist &L2, Linklist &l3);//实现两个链表相结合形成第三个链表
//void output(Linklist ll, int n);//新形成的线性表的输出
#include "Source.h"


int main()//主函数，即控制函数
{
	Linklist la, lb, lc;//定义三个Linklist变量
	int a, b;//定义两个int变量
	scanf("%d", &a);//输入要创建的第一个线性表的长度
	CreatList(la, a);//调用函数创建第一个线性表
	scanf("%d", &b);//输入第二个线性表的长度
	CreatList(lb, b);//调用函数创建第二个线性表
	MergeList(la,lb,lc);//调用函数实现两个线性表相连
	lc=lc->next;//线性表lc指向下一个节点
	output(lc, a + b);//输出相连后的线性表
	return 0;

}

void CreatList(Linklist &L, int n)
{
	Linklist p;//定义一个Linklist量p来实现对L的操作
	L = (Linklist)malloc(sizeof(LNode));//为L分配内存空间
	L->next = NULL;//让L指向空指针
	for (int i = n; i > 0; i--)//用循环结构逆序输入n个数据元素填充链表
	{
		p = (Linklist)malloc(sizeof(LNode));//为p分配内存
		scanf("%d", &p->data);//输入链表数据元素
		p->next = L->next;//讲对p的操作赋值给L
		L->next = p;//移动指针p到下一个节点
	}

}


void MergeList(Linklist &l1, Linklist &l2, Linklist &l3)
{
	Linklist la, lb, lc, l = NULL;//定义三个Linklist变量来对形参进行操作
	la = l1->next;//让la对形参l1操作
	lb = l2->next;//让lb对形参l2操作
	l3 = lc = l1;//让lc对形参l3操作,先赋值等于第一个线性表l1
	while (la&&lb)//当la和lb都不为空时进行操作
	{
		if (la->data <= lb->data)//如果第一个链表数据较第二个小
		{
			lc->next = la;//将第一个链表数据赋值给lC
			lc = la;
			la = la->next;//移动la到下一个结点
		}
		else//若第二个线性表数据更小
		{
			lc->next = lb; //将第二个链表数据赋值给lc
			lc = lb;
			lb = lb->next;//移动lb到下一个结点
		}
	}
	//最后得到一个两线性表的按从小到大顺序排列的合成线性表
	lc->next = la ? la : lb;

	//判断最终得到的线性表的值跟原来的两表的关系

	free(l);//将第二个线性表占用的内存释放
}

void output(Linklist ll, int n)
{
	int i;
	for (i = n; i > 0; i--)

	{
		printf("%d", ll->data);//循环结构依次输出线性表中的各个数据元素
		ll = ll->next;//操纵结点向后移

	}

}






