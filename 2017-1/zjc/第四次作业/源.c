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
void CreatList(ListNode L)  

{
	int i;
	ListNode p;
	 p=L;
	L->next = NULL;
	srand(time(NULL));
	int n = rand() % 10 + 1;
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
	*list1 = (List*)malloc(sizeof(List));
	(*list1)->data = 0;
	(*list1)->next = NULL;
	rear1 = p1 = *list1;
	int len1 = 0;
	int len2 = 0;
	int mark = 1;
	while (p)
	{
		if (mark = 1)
		{
			rear1->next = p;
			rear1 = p;
			(*list1)->data++;
			len1++; mark = 2;
		}
		else
		{
			rear2->next = p;
			rear2 = p;
			(*list2)->data++;
			len2++; mark = 1;
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
int main() {
	printf("数组L为：\n");
	ListNode L, L1, L2;
	int i;
	ListNode p;
	 p=L;
	L->next = NULL;
	srand(time(NULL));
	int n = rand() % 10 + 1;
	for (i = n; i >0; --i)
	{
		p = (List*)malloc(sizeof(List));   
		p->data = rand() % 101;    
		p->next = L->next;      
		L->next = p;
	}
	output(L);
	split(L, &L1, &L2);
	printf("分解后，L1为：\n");
	output2(L1);
	printf("\n");
	printf("分解后，L2为：\n");
	output2(L2);
}
