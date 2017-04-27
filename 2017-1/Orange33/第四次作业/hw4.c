#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;   

typedef struct  LNode
{
	ElemType data;
	struct LNode *next;   

}LNode, *LinkList; 

void CreateList(LinkList L, int n)  //创建线性链表
{
	int i;
	LNode* p = L;
	L->next = NULL;  
	srand(time(NULL));    
	for (i = n; i >0 ; --i)
	{
		p = (LNode*)malloc(sizeof(LNode));   //分配空间
		p->data = rand() % 50+1;    //随机生成数据
		p->next = L->next;      //插入到表头
		L->next = p;
	}
};

void TraverseList_L1(LinkList L)   //遍历输出单链表
{
	LNode *p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void TraverseList_L2(LinkList L)   //遍历输出循环链表
{
	LNode *p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
		if (p == L->next)
		{
			break;
		}
	}
}

void change(LinkList list,LinkList *list1, LinkList *list2)//拆分原线性链表为两个循环链表
{
	LNode*p, *p1, *p2;     //用于遍历list,list1,list2的三个指向节点的指针
	LNode*rear1, *rear2;   //尾指针
	int count = 0;
	*list1 = (LNode*)malloc(sizeof(LNode));  
	(*list1)->data = 0;
	(*list1)->next = NULL;
	rear1 = p1 = *list1;
	*list2 = (LNode*)malloc(sizeof(LNode));  //分配存储空间
	(*list2)->data = 0;
	(*list2)->next = NULL;
	rear2 = p2 = *list2; 
	for (p = list->next; p != NULL; p = p->next)
	{
		count++;
		if (count % 2)          //控制奇数项
		{
			rear1->next = p;
			rear1 = p;
			(*list1)->data++;     //长度增加1
			printf("\n元素：%d，序号为奇数，分配给list1 ", rear1->data);
		}
		else
		{
			rear2->next = p;
			rear2 = p;
			(*list2)->data++;     //长度增加1
			printf("\n元素：%d，序号为偶数，分配给list2 ", rear2->data);
		}
	}
	rear1->next = p1->next;
	rear2->next = p2->next;
}

int main()
{
	int n;
	LinkList L, La, Lb;
	srand(time(0));
	n = rand() % 20 + 1 ;//随机生成链表元素
	L = (LinkList)malloc(sizeof(LNode));
	CreateList(L, n);  //创建L
	printf("L:");         //输出L
	TraverseList_L1(L);
	printf("\n");
	change(L, &La, &Lb);
	printf("\n\n拆分结果：\n\n");//La，Lb是循环链表，通过函数实现只输出一次
	printf("序号为奇数的元素放入La\n");
	printf("La元素个数：%d\nLa:", La->data);
	TraverseList_L2(La);
	printf("\n序号为偶数的元素放入Lb\n");
	printf("Lb元素个数：%d\nLb:", Lb->data);     
	TraverseList_L2(Lb);
	return 0;
}

//查找算法时间复杂度都是O(1)，所用时间最少，空间最小