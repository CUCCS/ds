#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct  LNode
{
	int data;
	struct LNode *next;   
}LNode, *LinkList;     //�ṹ��Ľ���

LinkList CreateList(LinkList *L,int n);
void List_L1(LinkList *L);
void List_L2(LinkList *L);
void SeperateList(LinkList list, LinkList *list1, LinkList *list2);

LinkList CreateList(LinkList *L,int n)  //��������
{
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�
    LNode *temp = *L;
	int i;
	(*L)->data = 0;
	(*L)->next = NULL;         //�Ƚ���һ����ͷ���ĵ�����
	srand(time(NULL)); 
	printf("�����������:\n");
	for (i = 0; i < n ; i++)
	{
		temp = (LNode*)malloc(sizeof(LNode));   //����ռ�
		temp->data = rand() % 50+1;            //�����������
		temp->next = (*L)->next;              //���뵽��ͷ
		(*L)->next = temp;
	}
};

void List_L1(LinkList *L)   //�������������
{
	LNode *p = (*L)->next;
	while (p)
	{
		printf("%d ", p->data);   //������������Ԫ��
		p = p->next;
	}
}

void List_L2(LinkList *L)   //�������ѭ������
{
	LNode *p = (*L)->next;
	int count = (*L)->data;
	p = (*L)->next;
	while (count)
	{
		printf("%d ", p->data);    //�����ֺ������Ԫ��
		p = p->next;
		count--;
		if (p == (*L)->next)      //��ֹ����
		{
			break;
		}
	}
}

void SeperateList(LinkList list,LinkList *list1, LinkList *list2)    //���ԭ��������Ϊ����ѭ������
{
	LNode*p, *p1, *p2;     //���ڱ���list,list1,list2������ָ��ڵ��ָ��
	LNode*rear1, *rear2;   //βָ��
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
		if (count % 2)          //����������
		{
			rear1->next = p;
			rear1 = p;
			(*list1)->data++;     //��������1
			printf("\n��ǰΪ��%d������������list1  ", rear1->data);    //�����list1��list2
		}
		else
		{
			rear2->next = p;
			rear2 = p;
			(*list2)->data++;     //��������1
			printf("\n��ǰΪ��%d��ż��������list2  ", rear2->data);      //�����list1��list2
		}
	}
	rear1->next = p1->next;
	rear2->next = p2->next;
	free(list);         //�ͷ�ͷָ��
}

int main()
{
	int n;
	LinkList L, La, Lb;
	srand(time(NULL));
	n =  rand() % 20 + 1 ;
	L = (LinkList)malloc(sizeof(LNode));
	printf("��������L���ݣ�\n");
	CreateList(&L, n);                       //����L
	La = (LNode*)malloc(sizeof(LNode));  
	Lb = (LNode*)malloc(sizeof(LNode));     //����洢�ռ�
	printf("L:");                           //���L
	List_L1(&L);
	printf("\n");
	SeperateList(L, &La, &Lb);
	printf("\n\n��L��ֳ�����ѭ������\n\n");   //La,LbΪѭ������ֻ���һ��
	printf("���Ϊ������Ԫ�ط���La\n");
	printf("LaԪ�ظ�����%d\n", La->data);
	printf("La:");                            //���La
	List_L2(&La);
	printf("\n");
	printf("���Ϊż����Ԫ�ط���Lb\n");
	printf("LbԪ�ظ���:%d\n", Lb->data);
	printf("Lb:");                            //���Lb
	List_L2(&Lb);
	return 0;
}

//��βָ��rear����ʾ��ѭ������
//����ҿ�ʼ�����ն˽�㶼����ʵ��
//Ϊ�˽�ʡʱ��Ϳռ䣬���迪���¿ռ䣬ֻ����ԭ���������Ͻ��в���
//����ʱ�䶼��O(1)��������ʱ�����٣��ռ�����