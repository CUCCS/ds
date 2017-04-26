#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct List
{
	int data;
	struct List *next;
}List;

List* CreatList(int n)//创建一个已知长度的链表，头结点的数据初始化为表长n，并返回头结点
{
	List *head, *p, *q;
	head = (List*)malloc(sizeof(List));
	head->data=n;
	head->next = NULL;
	srand(time(NULL));
	int a,i;
	for (i = 0;i < n;i++)
	{
		a = rand() % 10;
		p = (List*)malloc(sizeof(List));
		p->data = a;
		if (head->next == NULL)
		{
			head->next = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}
	p->next = NULL;
	return head;
}
void PrintList(List *s)//打印链表数据
{
	List *p;
	int num = s->data;
	p = s->next;
	for(num;num>0;num--)
	{
		printf("%3d", p->data);
		p=p->next;
	}
	printf("\n");
}
int GetLength(List *s)//获取并返回链表的长度
{
	List *p;
	int count = 0;
	p = s->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}
List* SeparateList(List *s)//分解链表，将奇数位元素与偶数位元素分别存储在两个链表中
{
	int count,count1,count2;
	count = count1 = count2 = 0;
	List*p,*head,*q,*r;
	head = (List*)malloc(sizeof(List));
	head->next = NULL;
	q = s->next;
	p = s;
	while (p != NULL&&q!=NULL)
	{
		p->next = q->next;
		if(head->next==NULL)
		{
			head->next = q;
			r = q;
			p = q->next;
			q = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			p = q->next;
			if (p != NULL)
				q = p->next;
			else
				q = NULL;
		}
		
	}
	count1 = GetLength(s);
	count2 = GetLength(head);
	s->data = count1;
	head->data = count2;
	return head;
}


int main()
{
	int n;
	srand(time(NULL));
	do
	{
		n = rand() % 10;
	} while (n < 5);
	List *list;
	printf("Creat a list:");
	list = CreatList(n);
	PrintList(list);
	List*list2;
	list2=SeparateList(list);
	printf("The length of the list1 is:%d\n", list->data);
	printf("Print list1:");
	PrintList(list);
	printf("The length of the list2 is:%d\n", list2->data);
	printf("Print list2:");
	PrintList(list2);
	return 0;
}