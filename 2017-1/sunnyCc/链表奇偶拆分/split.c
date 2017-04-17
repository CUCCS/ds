#include "split.h"
void CreateList(LinkList *L, int n)
{
	LNode* p = *L;
	int i;

	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;//初始化链表

	srand((unsigned int)time(NULL));
	printf("随机产生数据\n");
	for (i = 0; i<n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->data = rand() % 100 + 1;
		printf("%d ", p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
	printf("\n");
}
void Split(LinkList list, LinkList list1, LinkList list2)
{

	LNode *temp1, *temp, *p1, *p2;
	int count = 0;
	list1->data = 0;
	list1->next = NULL;
	list2->data = 0;
	list2->next = NULL;
	temp1 = temp = list->next;
	p1 = list1;
	p2 = list2;

	while (temp)
	{
		if (count % 2)//操作奇数项
		{
			temp1 = temp->next;
			if (list1->next == NULL)
			{
				temp->next = list1->next;
				list1->next = temp;
			}
			else
			{
				temp->next = p1->next;
				p1->next = temp;
			}
			p1 = temp;
			list1->data++;//储存链表的长度加1
			count++;
		}
		else
		{
			temp1 = temp->next;
			if (list2->next == NULL)
			{
				temp->next = list2->next;
				list2->next = temp;
			}
			else
			{
				temp->next = p2->next;
				p2->next = temp;
			}
			p2 = temp;
			list2->data++;
			count++;
		}
		temp = temp1;
	}
	p1->next = list1;
	p2->next = list2;
	free(list);
}
void Traverse(LinkList head)
{
	LNode *temp;
	int count = head->data;
	temp = head->next;
	printf("该链表中的数据有;\n");
	while (count)
	{
		printf("%d ", temp->data);
		temp = temp->next;
		count--;
	}
	printf("\n");

}