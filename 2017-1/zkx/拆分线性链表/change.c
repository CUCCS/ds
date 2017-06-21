#include "change.h"

void CreateList(LinkList L, int n)  //����ԭ��������
{
	int i;
	LNode* p = L;
	L->next = NULL;  
	srand(time(NULL));    
	for (i = 0; i <n ; i++)
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

void change(LinkList list,LinkList *list1, LinkList *list2)    //���ԭ��������Ϊ����ѭ������
{
	LNode*p;     //���ڱ���list,list1,list2������ָ��ڵ��ָ��
	LNode*rear1, *rear2;   //βָ��
	int count = 0;
	*list1 = (LNode*)malloc(sizeof(LNode));  
	(*list1)->data = 0;
	(*list1)->next = NULL;
	rear1  = *list1;

	*list2 = (LNode*)malloc(sizeof(LNode));     //����洢�ռ�
	(*list2)->data = 0;
	(*list2)->next = NULL;
	rear2 = *list2; 

	for (p = list->next; p != NULL; p = p->next)
	{
		count++;
		if (count % 2)          //����������
		{
			rear1->next = p;
			rear1 = p;
			(*list1)->data++;     //��������1
			printf("\n��ǰΪ��%d������������list1  ", rear1->data);
		}
		else
		{
			rear2->next = p;
			rear2 = p;
			(*list2)->data++;     //��������1
			printf("\n��ǰΪ��%d��ż��������list2  ", rear2->data);
		}
	}
	rear1->next = (*list1)->next;
	rear2->next = (*list2)->next;
}

int main()
{
	int n;
	LinkList L, La, Lb;
	srand(time(0));
	n =  rand() % 20 + 1 ;
	L = (LinkList)malloc(sizeof(LNode));

	printf("��������L���ݣ�\n");
	CreateList(L, n);  //����L
	printf("L:");         //���L
	TraverseList_L1(L);
	printf("\n");

	change(L, &La, &Lb);
	printf("\n\n--------��L��ֳ�����ѭ������--------\n\n");

	printf("\n(ע������La��Lb��ѭ��������ͨ������ʵ��ֻ���һ�Ρ�)\n\n");

	printf("���Ϊ������Ԫ�ط���La\n");
	printf("LaԪ�ظ�����%d\n", La->data);
	printf("La:");         //���La
	TraverseList_L2(La);
	printf("\n");

	printf("���Ϊż����Ԫ�ط���Lb\n");
	printf("LbԪ�ظ�����%d\n", Lb->data);
	printf("Lb:");         //���Lb
	TraverseList_L2(Lb);
	printf("\n\n");
	return 0;

}
/*��βָ��rear����ʾ��ѭ������
����ҿ�ʼ���a1���ն˽��an���ܷ��㣬
���ǵĴ洢λ�÷ֱ���(rear->next)->next��rear��
��Ȼ������ʱ�䶼��O(1)��������ʱ�����٣��ռ�����*/