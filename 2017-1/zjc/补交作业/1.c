#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct list{
	int data;
	struct list *next;
};
void input(struct list *head, int number)
{
	printf("输入相应的链表：\n");
	int i;
	struct list *temp;
	struct list *end;
	end = head;
	for (i = 0; i != number; i++)
	{
		temp = (struct list *)malloc(sizeof(struct list));
		srand((unsigned)time(NULL));
		temp->data = (rand() *i) % 101;
		printf("%d  ", temp->data);
		end->next = temp;
		temp->next = NULL;
		end = temp;
	}
	printf("\n");
}
void sort(struct list *l1, struct list *l2)
{
	struct list *p1, *p2, *temp;
	p1 = l1;
	p2 = l2->next;
	while (p1->next&&p2)
	{
		if (p1->next->data > p2->data)
		{
			temp = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p2 = temp;
		}
		else
			p1 = p1->next;
	}
	if (p2)
		p1->next = p2;
}
void output(struct list *head)
{
	printf("输出Lc：\n");
	while (head->next)
	{
		printf("%d  ", head->next->data);
		head = head->next;
	}
}
int main()
{
	int num;
	struct list *h1, *h2;
	h1 = (struct list*)malloc(sizeof(struct list));
	h2 = (struct list*)malloc(sizeof(struct list));
	h1->next = NULL;
	h2->next = NULL;
	printf("输入La的长度：\n");
	srand((unsigned)time(NULL));
	num = rand() % 11;
	printf("%d\n", num);
	input(h1, num);
	printf("输入Lb的长度:\n");
	num = rand() % 11;
	printf("%d\n", num);
	input(h2, num);
	sort(h1, h2);
	output(h1);
	return 0;
}
