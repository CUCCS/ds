#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct  LNode
{
	int data;
	struct LNode *next;   
}LNode, *LinkList;     //结构体的建立

LinkList CreateList(LinkList *L,int n);
void List_L1(LinkList *L);
void List_L2(LinkList *L);
void SeperateList(LinkList list, LinkList *list1, LinkList *list2);

LinkList CreateList(LinkList *L,int n)  //创建链表
{
	//逆位序输入n个元素的值，建立带表头结点的单链线性表
    LNode *temp = *L;
	int i;
	(*L)->data = 0;
	(*L)->next = NULL;         //先建立一个带头结点的单链表
	srand(time(NULL)); 
	printf("产生随机数据:\n");
	for (i = 0; i < n ; i++)
	{
		temp = (LNode*)malloc(sizeof(LNode));   //分配空间
		temp->data = rand() % 50+1;            //随机生成数据
		temp->next = (*L)->next;              //插入到表头
		(*L)->next = temp;
	}
};

void List_L1(LinkList *L)   //遍历输出单链表
{
	LNode *p = (*L)->next;
	while (p)
	{
		printf("%d ", p->data);   //输出随机的链表元素
		p = p->next;
	}
}

void List_L2(LinkList *L)   //遍历输出循环链表
{
	LNode *p = (*L)->next;
	int count = (*L)->data;
	p = (*L)->next;
	while (count)
	{
		printf("%d ", p->data);    //输出拆分后的链表元素
		p = p->next;
		count--;
		if (p == (*L)->next)      //终止条件
		{
			break;
		}
	}
}

void SeperateList(LinkList list,LinkList *list1, LinkList *list2)    //拆分原线性链表为两个循环链表
{
	LNode*p, *p1, *p2;     //用于遍历list,list1,list2的三个指向节点的指针
	LNode*rear1, *rear2;   //尾指针
	int count = 0; 
	(*list1)->data = 0;
	(*list1)->next = NULL;
	rear1 = p1 = *list1;
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
			printf("\n当前为：%d，奇数项，分配给list1  ", rear1->data);    //分配给list1和list2
		}
		else
		{
			rear2->next = p;
			rear2 = p;
			(*list2)->data++;     //长度增加1
			printf("\n当前为：%d，偶数项，分配给list2  ", rear2->data);      //分配给list1和list2
		}
	}
	rear1->next = p1->next;
	rear2->next = p2->next;
	free(list);         //释放头指针
}

int main()
{
	int n;
	LinkList L, La, Lb;
	srand(time(NULL));
	n =  rand() % 20 + 1 ;
	L = (LinkList)malloc(sizeof(LNode));
	printf("输入待拆分L数据：\n");
	CreateList(&L, n);                       //创建L
	La = (LNode*)malloc(sizeof(LNode));  
	Lb = (LNode*)malloc(sizeof(LNode));     //分配存储空间
	printf("L:");                           //输出L
	List_L1(&L);
	printf("\n");
	SeperateList(L, &La, &Lb);
	printf("\n\n将L拆分成两个循环链表\n\n");   //La,Lb为循环链表，只输出一次
	printf("序号为奇数的元素放入La\n");
	printf("La元素个数：%d\n", La->data);
	printf("La:");                            //输出La
	List_L2(&La);
	printf("\n");
	printf("序号为偶数的元素放入Lb\n");
	printf("Lb元素个数:%d\n", Lb->data);
	printf("Lb:");                            //输出Lb
	List_L2(&Lb);
	return 0;
}

//用尾指针rear来表示单循环链表
//则查找开始结点和终端结点都容易实现
//为了节省时间和空间，无需开辟新空间，只需在原来的链表上进行操作
//查找时间都是O(1)。故所用时间最少，空间最少