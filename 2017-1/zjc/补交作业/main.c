#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct List
{
	int data;
	struct List *next;
}List, *ListNode;
void output(ListNode L)
{
	List *p = L->next;
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
void CreatList(ListNode L,int n)  

{
	int i;
	ListNode p;
	 p=L;
	L->next = NULL;
	srand(time(NULL));
	for (i = n; i >0; --i)
	{
		p = (List*)malloc(sizeof(List));   
		p->data = rand() % 101;    
		p->next = L->next;      
		L->next = p;
	}
};

void split(ListNode list, ListNode *list1, ListNode *list2)
{
	List *p, *p1, *p2;
	List *rear1, *rear2;
	int n=0;
	*list1 = (List*)malloc(sizeof(List));
	(*list1)->data = 0;
	(*list1)->next = NULL;
	rear1 = p1 = *list1;
	*list2 = (List*)malloc(sizeof(List));     //����洢�ռ� 
	(*list2)->data = 0; 
	(*list2)->next = NULL; 
	rear2 = p2 = *list2; 
	for(p=list->next;p!=NULL;p=p->next)
	{
		n++;
		if (n%2)
		{
			rear1->next = p;
			rear1 = p;
			(*list1)->data++;
			
		}
		else
		{
			rear2->next = p;
			rear2 = p;
			(*list2)->data++;
		}
	}
	rear1->next = p1->next;
	rear2->next = p2->next;
}
void output2(ListNode L)
{
	List *p = L->next;
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
int main() 
{ 
	int n; 
	ListNode L, La, Lb; 
	srand(time(0)); 
	n =  rand() % 20 + 1 ; 
	L = (ListNode)malloc(sizeof(List)); 
	printf("��������L���ݣ�\n"); 
	CreatList(L,n);  //����L 
	printf("L:");         //���L 
	output(L); 
	split(L, &La, &Lb); 
	printf("\n\n--------��L��ֳ�����ѭ������--------\n"); 
	printf("���Ϊ������Ԫ�ط���La\n"); 
 	printf("LaԪ�ظ�����%d\n", La->data); 
	printf("La:");         //���La 
	output(La); 
	printf("\n"); 
	printf("���Ϊż����Ԫ�ط���Lb\n"); 
	printf("LbԪ�ظ�����%d\n", Lb->data); 
	printf("Lb:");         //���Lb 
	output2(Lb); 
	printf("\n\n"); 
	return 0; 
}
