//ʵ����ҵ13�� ����ֽ�
//˵����
//ʱ���ϣ�Separate����ֻ����һ������ʱ�����
//�ռ��ϣ�Ϊʵ��ѭ������ֻ���·���ͷβָ�뼴�ɣ��ռ���С
//ͷָ��洢������
#include <stdio.h>
#include <stdlib.h>

//��������
typedef struct node
{
	char data;
	struct node *next;
}*LinkList, Lnode;

//��������
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

//�ֽ�����
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

//��ȡ������
int GetLength(LinkList s)//��ȡ����������ĳ���
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

//��ӡ����
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

//��������
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
	printf("ͷָ��洢������\n");
	printf("��*�������룺");
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
	printf("\n��ӡ��ǰ���� ");
	VisitList(headA); // ��ӡ�ֽ�ǰ������ 
	if (headA != NULL) // �����յ����������зֽ� 
	{
		Separate(&headA, &headB, &tailB); //��������зֽ�
	}
	else
	{
		printf("headA is empty.\n");
	}
	//��ӡ�ֽ�������
	printf("���������� ");
	VisitList(headA);  
	printf("ż�������� ");
	VisitList(headB);
	DestroyList(&headA, &tailA); //�������� 
	DestroyList(&headB, &tailB);
	return 0;
}