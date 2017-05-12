#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;   //定义指针指向下一节点
    int data;   //定义链表的值
	int listsize;   //定义链表长度
}Node,*List;

void Merge(List &La,List &Lb,List &Lc)  //合并链表
{
	Node *pa,*pb,*pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La; //用La的头结点作为Lc的头结点
	while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;  //使Lc下一节点等于La中的pa节点的值
			pc = pa;    //将pa的地址给pc，实现pc节点后移
			pa = pa->next;  //pa节点的后移
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;  //若pa为非空指针就把pa的赋值给pc->next，否则把pb的值赋给pc->next
	                          //插入剩余段
	free(Lb);
}

List getList(int a[], int len)  //初始化链表
{
    Node *head = (Node*)malloc(sizeof(Node));   //头结点初始化
    Node *p = head;  //定义p为头结点
    head->next = NULL; 
    for(int i=0; i<len; i++)  //将数组中的数据写入链表
    {
        Node *n = (Node*)malloc(sizeof(Node));
        n->data = a[i];
        p->next = n;
        p = n;
    }
    p->next = NULL;
    return head;
}

void print(List a) //打印链表
{
    if(!a) return;
    Node *p = a->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

void main()
{
    int a[] = {1, 2, 3, 4};  //定义链表a,b中的数据
    int b[] = {0, 1, 9};
	
    List la = getList(a, 4);  //初始化链表
    List lb = getList(b, 3);
	List lc = NULL;

	printf("链表La中的数据：\n");
    print(la);
	printf("链表Lb中的数据：\n");
    print(lb);
    Merge(la, lb, lc);
	printf("链表合并后的数据：\n");
	print(lc);
	system("pause");
}