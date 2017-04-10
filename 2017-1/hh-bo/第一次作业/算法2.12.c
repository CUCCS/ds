#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int data;
	struct list *next;
}List;
List *Creat(int m[],int n)
{
	List *head, *next, *present;
	int a;
	head = (List*)malloc(sizeof(List));
	head->next = NULL;
	present = head;
	next = NULL;
	for (int i = 0;i < n;i++)
	{
		a=m[i];
		next = (List*)malloc(sizeof(List));
		next->data = a;
		present->next = next;
		present = next;
	}
	present->next = NULL;
	return head;
}
List* MergeList(List *LA, List *LB)
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
	List *head1, *head2, *head3;
	int a[4] = { 3,5,8,11 };
	int b[7] = { 2,6,8,9,11,15,20 };
	printf("线性表LA：");
	head1 = Creat(a,4);
	Print(head1);

	printf("线性表LB：");
	head2 = Creat(b,7);
	Print(head2);



	
	head3=MergeList(head1, head2);
	Print(head3);


	return 0;

}
