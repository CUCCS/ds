#include "13.h"
int main()
{
	Lnode *p = ListCreat();//制造要初始化的线性链表   使用了尾插法进行插入
	print_list(p);
	Lnode *p1;
	Lnode *p2;
	ApartList(p, &p1, &p2);//将链表进行拆分 只需要进行一次拆分 节省了循环的时间
	printf("拆分后的第一个链表\n");
	print_circle_list(p1);//输出第一个循环的数组
	printf("拆分后的第二个链表\n");
	print_circle_list(p2);//输出第二个循环的数组
	destory(&p1);//销毁第一个循环数组
	destory(&p2);//销毁第二个循环的数组
	return 0;
}
//初始化一个链表 尾插法
Lnode * ListCreat()
{
	int i;
	int num;
	printf("请输入初始的线性链表的长度\n");
	scanf_s("%d", &num);
	Lnode *L;
	L = (Lnode *)malloc(sizeof(Lnode));   //申请头结点空间  
	L->data = 1;
	L->next = NULL;                  //初始化一个空链表  
	Lnode *r;
	r = L;                          //r始终指向终端结点，开始时指向头结点 
	for (i = 2; i <= num; i++)
	{
		Lnode *p;
		p = (Lnode *)malloc(sizeof(Lnode));
		p->data = i;                     //结点数据域赋值   
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L;
}
//将线性链表整个拆开 拆成两个循环链表
int ApartList(Lnode *t,Lnode **px, Lnode **py)
{//尾插法
	Lnode *p1;
	Lnode *p2;
	Lnode *temp1;
	Lnode *temp2;
	Lnode *temp;
	Lnode *p;
	p = t;
	p1 = (Lnode *)malloc(sizeof(Lnode));   //申请头结点空间  
	p1->next = NULL;
	p2 = (Lnode *)malloc(sizeof(Lnode));   //申请头结点空间
	temp1 = p1;
	temp2 = p2; 
	p2->next = NULL; 
	while (NULL != p)
	{
		temp = p;
		p = p->next;
		if (temp->data % 2 != 0)//如果是奇数
		{	 
			temp->next= temp1->next;//temp1移动用于最后首尾相连
			temp1->next = temp;
			temp1 = temp;
		}
		else
		{
			temp->next = temp2->next;//temp2移动
			temp2->next = temp;
			temp2 = temp;
		}
	}//当拆分完成的时候
	p1->data = (temp1->data + 1) / 2;
	p2->data = temp2->data / 2;
	temp1->next = p1;
	temp2->next = p2;
	*px = p1;
	*py = p2;
	return 0;
}
//打印初始单链表
int print_list(Lnode *p)
{
	printf("初始的链表为：\n");
	do
	{
		printf("%d ", p->data);
		p = p->next;
	}while (p!= NULL);
	printf("\n");
	return 1;
}
//打印循环单链表
int print_circle_list(Lnode *p)
{
	Lnode *t;
	printf("链表长度为 %d  \n", p->data);
    t = p;
	p = p->next;
	printf("元素为： ");
	do
	{
		printf("%d ", p->data);
		p = p->next;
	} while (p != t);
	printf("\n\n");
	return 1;
}
//销毁链表
int destory(Lnode **p)
{
	Lnode *t;	
	int i;
	int k = (*p)->data+1;
	for (i = 0; i < k; i++)
	{
    t = *p;
	(*p) = (*p)->next;
	free(t);
	}
	return 1;
}