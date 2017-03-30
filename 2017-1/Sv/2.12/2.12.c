#include<stdio.h>
#include<stdlib.h>
#include "2.12.h"
//算法2.12：有序链表合并
void MergeList_L(LinkList La, LinkList Lb, LinkList Lc) {
	LinkList pa = La->next, pb = Lb->next;
	LinkList pc = La = Lc;//La头节点作为Lc头节点
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}//pa所指结点链接至pc所指节点之后
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}//pb所指结点连接至pc所指节点之后
	}//pa，pb其中一个为假（空值）时，停止循环
	pc->next = pa ? pa : pb;//插入剩余段
	free(Lb);//释放Lb头节点
}//Mergel_L
//新建单链表
void CreateList_L(LinkList L, int n) {
	//L = (LinkList)malloc(sizeof(LNode));
	//srand(time(0));
	L->next = NULL;
	int i; LinkList p;
	printf("列表元素:\n");
	for (i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));//生成新结点
		p->data = rand() % 10 + 1;
		printf("%d ", p->data);
		//scanf_s("%d", &p->data);//输入元素值
		p->next = L->next; L->next = p;//插入到表头
	}
	printf("\n");
}//CreatList_L
//遍历输出：
void PRINT(LinkList L)
{
	LinkList p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void order(LinkList L, int n) {
	int *p = (int *)malloc(n*sizeof(int));
	LinkList l = (LinkList)malloc(sizeof(LNode));
	l = L;
	for (int i = 0; i < n; i++) {
		p[i] = l->data;
		l = l->next;
	}
	for (int i= 0; i< n; i++)
	{
		for (int j= 0; i+ j< n- 1; j++)
		{
			if (p[j]>p[j+ 1])
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	l = L;
	for (int i = 0; i < n; i++) {
		l->data=p[i];
		l = l->next;
	}
}


