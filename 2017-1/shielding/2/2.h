//˵����
//ʱ�临�Ӷȣ�
//ParitySequence�����ڽ�list��������ֽ������ѭ������ʱ��ֻ����һ��ѭ������һ�����Ա�
//��ʱ�临�Ӷ�ԼΪO(n)(����ĳ���)����ʱ��ʱ�临�Ӷ�ӦΪ��С��
//�ռ临�Ӷȣ�
//�ڴ�������ѭ������(list1,list2)ʱ��ֻ�ֱ����¶�̬������һ��ͷ��㡣
//��������ѭ������Ĺ��̣����ֽ�list�Ĺ��̣�list1,list2��ͷ�����������㣬û�����·���ռ䣬����ֱ�ӽ�nextָ��ָ��list��Ӧ��㡣

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;


//���������
Status output(LinkList L){
	LinkList p = L;
	if (!p->next){
		return ERROR;
	}
	while (p->next)
	{
		p = p->next;
		printf("%d\n", p->data);
	}
	return OK;
}

//���ѭ���������һ�����ڣ�
Status output1(LinkList L)
{
	LinkList p = L, m = L;
	if (!p->next)
	{
		return ERROR;
	}
	while (p->next!=m)
	{
		p = p->next;
		printf("%d\n", p->data);
	}
	return OK;
}

//����һ��������������һ�������Ϊָ��list������
void CreateList_L(LinkList L, int n)
{
	L->data = (int)rand() % 1024;
	L->next = NULL;
	LinkList p;
	int i;
	for (i = 0; i < n - 1; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = (int)rand() % 1024;
		p->next = L->next;
		L->next = p;
		L = L->next;
	}
}

//�����Ե�������ż�Էֽ�Ϊ����ѭ������
void ParitySequence(LinkList list, LinkList list1, LinkList list2)
{

	LNode*p1 = list1;
	LNode*p2 = list2;
	LNode*p = list;
	list1->data = 0;
	list2->data = 0;
	while (p != NULL)
	{
		p1->next = p;
		p1 = p1->next;
		list1->data++;
		p = p->next;
		if (p != NULL)
		{
			p2->next = p;
			p2 = p2->next;
			list2->data++;
			p = p->next;
		}
	}
	p1->next = list1;
	p2->next = list2;
}