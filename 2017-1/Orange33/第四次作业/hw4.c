#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;   

typedef struct  LNode
{
	ElemType data;
	struct LNode *next;   

}LNode, *LinkList; 

void CreateList(LinkList L, int n)  //������������
{
	int i;
	LNode* p = L;
	L->next = NULL;  
	srand(time(NULL));    
	for (i = n; i >0 ; --i)
	{
		p = (LNode*)malloc(sizeof(LNode));   //����ռ�
		p->data = rand() % 50+1;    //�����������
		p->next = L->next;      //���뵽��ͷ
		L->next = p;
	}
};

void TraverseList_L1(LinkList L)   //�������������
{
	LNode *p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void TraverseList_L2(LinkList L)   //�������ѭ������
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

void change(LinkList list,LinkList *list1, LinkList *list2)//���ԭ��������Ϊ����ѭ������
{
	LNode*p, *p1, *p2;     //���ڱ���list,list1,list2������ָ��ڵ��ָ��
	LNode*rear1, *rear2;   //βָ��
	int count = 0;
	*list1 = (LNode*)malloc(sizeof(LNode));  
	(*list1)->data = 0;
	(*list1)->next = NULL;
	rear1 = p1 = *list1;
	*list2 = (LNode*)malloc(sizeof(LNode));  //����洢�ռ�
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
			printf("\nԪ�أ�%d�����Ϊ�����������list1 ", rear1->data);
		}
		else
		{
			rear2->next = p;
			rear2 = p;
			(*list2)->data++;     //��������1
			printf("\nԪ�أ�%d�����Ϊż���������list2 ", rear2->data);
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
	n = rand() % 20 + 1 ;//�����������Ԫ��
	L = (LinkList)malloc(sizeof(LNode));
	CreateList(L, n);  //����L
	printf("L:");         //���L
	TraverseList_L1(L);
	printf("\n");
	change(L, &La, &Lb);
	printf("\n\n��ֽ����\n\n");//La��Lb��ѭ������ͨ������ʵ��ֻ���һ��
	printf("���Ϊ������Ԫ�ط���La\n");
	printf("LaԪ�ظ�����%d\nLa:", La->data);
	TraverseList_L2(La);
	printf("\n���Ϊż����Ԫ�ط���Lb\n");
	printf("LbԪ�ظ�����%d\nLb:", Lb->data);     
	TraverseList_L2(Lb);
	return 0;
}

//�����㷨ʱ�临�Ӷȶ���O(1)������ʱ�����٣��ռ���С