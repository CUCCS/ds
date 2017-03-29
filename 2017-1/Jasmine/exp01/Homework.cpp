#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct list
{
	int data;
	struct list *next;
}List;
List *Creat(int n)//创造一条已知长度的有序链表
{
	List *head, *next, *present;
	int a;
	head = (List*)malloc(sizeof(List));
	head->next = NULL;
	present = head;
	next = NULL;
	for (int i = 0;i < n;i++)
	{
		a = rand() % 20;
		next = (List*)malloc(sizeof(List));
		next->data = a;
		present->next = next;
		present = next;
	}
	present->next = NULL;
	return head;
}
List* MergeList(List *LA, List *LB)//采用尾插法建表的链表归并 算法 (A，B为递增链表，C要求为单调不减链表)
{
	List *pc = NULL;
	List *pa = LA->next;
	List *pb = LB->next;
	List *LC;
	LC = LA;
	LC->next = NULL;
	pc = LC;
	free(LB);
	//LB=NULL;

	while (pa != NULL && pb != NULL)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;

			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;

			pc = pb;
			pb = pb->next;
		}
		pc->next = NULL;
	}

	if (pa == NULL)
	{
		pc->next = pb;

	}
	else
	{
		pc->next = pa;
	}
	return LC;
}
void Print(List *head)
{
	List *p;
	p = head->next;
	while (p != 0)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	srand((unsigned)time(NULL));
	List *head1, *head2, *head3;
	int len1, len2;
	printf("随机生成线性表LA的长度：");
	len1 = rand() % 5;
	head1 = Creat(len1);

	Print(head1);

	printf("随机生成线性表LB的长度：");
	len2 = rand() % 10;
	head2 = Creat(len2);
	Print(head2);




	head3 = MergeList(head1, head2);
	Print(head3);


	return 0;

}