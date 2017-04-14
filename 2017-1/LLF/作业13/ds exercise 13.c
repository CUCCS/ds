//实现作业13题 链表分解
//说明：
//时间上，Separate函数只遍历一次链表，时间最短
//空间上，为实现循环链表，只重新分配头尾指针即可，空间最小
//头指针存储链表长度
#include <stdio.h>
#include <stdlib.h>

//定义链表
typedef struct node
{
	char data;
	struct node *next;
}*LinkList, Lnode;

//创建链表
void CreateList(LinkList *head, LinkList *tail, char ch)
{
	int n;
	LinkList P;
	if ((P = (LinkList)malloc(sizeof(Lnode))) == NULL)
	{
		exit(1);
	}
	P->data = ch;
	P->next = NULL;
	if (*head == NULL)
	{
		P->next = *head;
		*head = P;
	}
	else
	{
		(*tail)->next = P;
	}
	*tail = P;
	n=GetLength(*head);
	(*head)->data=n;
}

//分解链表
void Separate(LinkList *headA, LinkList *headB, LinkList *tailB)
{
	int count = 0,countA,countB;
	LinkList cA, pA;
	char ch;
	cA = NULL;
	for (pA = *headA; pA != NULL; cA = pA, pA = pA->next)
	{
		ch = pA->data;
		count++;
		if (count % 2 == 0)
		{
			CreateList(headB, tailB, ch);
			cA->next = pA->next;
		}
	}
	countA = GetLength(*headA);
	countB = GetLength(*headB);
	(*headA)->data = countA;
	(*headB)->data = countB;
}

//获取链表长度
int GetLength(LinkList s)//获取并返回链表的长度
{
	LinkList p;
	int count = 0;
	p = s;
	while (p != NULL)
		{
		count++;
		p = p->next;
		}
	return count;
}

//打印链表
void VisitList(LinkList head)
{
	if(head!=NULL)
	printf("%d    ", head->data);
	head = head->next;
	while (head != NULL)
	{
		printf("%c    ", head->data);
		head = head->next;
	}
	printf("\n");
}

//销毁链表
void DestroyList(LinkList *head, LinkList *tail)
{
	LinkList tempPtr;
	while (*head != NULL)
	{
		tempPtr = *head;
		*head = (*head)->next;
		free(tempPtr);
	}
	*head = NULL;
	*tail = NULL;
}


int main(void)
{
	LinkList headA = NULL, tailA = NULL, headB = NULL, tailB = NULL;
	char ch;
	printf("头指针存储链表长度\n");
	printf("以*结束输入：");
	while (1)
	{
		scanf_s(" %c", &ch);
		if (ch == '*')
		{
			break;
		}
		else
		{
			CreateList(&headA, &tailA, ch);
		}
	}
	printf("\n打印当前链表： ");
	VisitList(headA); // 打印分解前的链表 
	if (headA != NULL) // 链表不空的情况对其进行分解 
	{
		Separate(&headA, &headB, &tailB); //对链表进行分解
	}
	else
	{
		printf("headA is empty.\n");
	}
	//打印分解后的链表
	printf("奇数项链表： ");
	VisitList(headA);  
	printf("偶数项链表： ");
	VisitList(headB);
	DestroyList(&headA, &tailA); //销毁链表 
	DestroyList(&headB, &tailB);
	return 0;
}