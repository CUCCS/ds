#include "link.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	//int choice, data, d = 0;
	LinkQueue Q, q;
	int a[10], b[10];
	int i;
	int d = 0, n;
	if (InitQueue(&Q) == 1)
	{
		printf("Succeed in initializing the link queue Q\n");
	}
	else
	{
		printf("Fail to initializing the link queue Q\n");
	}

	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100 + 1;

	}
	for (int i = 0; i < 10; i++)
	{
		EnQueue(&Q, a[i]);
	}
	printf("Traversing Q:");
	QueueTraverse(Q);




	printf("\nThe length of Q is %d\n", QueueLength(Q));
	GetHead(Q, &d);
	printf("Fetching the Q's head number:%d \n", d);

	n = rand() % 10 + 1;
	printf("\nSelecting %d ги0<n<=10)number(s) in random to make them be poped\n", n);
	for (i = 0; i < n; i++)
	{
		DeQueue(&Q, &a[i]);
	}
	if (QueueEmpty(Q))
	{
		printf("After poping, Q is empty \n");
	}
	else
	{
		printf("After poping ,Q is not empty\n");
		printf("The length of Q is %d\n", QueueLength(Q));
		printf("Traversing Q:");
		QueueTraverse(Q);
		GetHead(Q, &d);
		printf("\nFetching the head number %d in Q\n\n", d);



		if (ClearQueue(&Q))
		{
			printf("Clearing Q\n");
		}
		if (QueueEmpty(Q))
		{
			printf("Q is empty\n");
		}
		else
		{
			printf("Q is not empty\n");
		}
	}

	printf("--------------------------------------------------------------------");
	printf("\nMaking another link queue 'q' to conduct the step of Destory \n");

	if (InitQueue(&q) == 1)
	{
		printf("Succeed in initializing the link queue q\n");
	}
	else
	{
		printf("Fail to initializing the link queue q\n");
	}

	for (int i = 0; i < 10; i++)
	{
		b[i] = rand() % 100 + 1;

	}

	for (int i = 0; i < 10; i++)
	{
		EnQueue(&q, b[i]);
	}
	printf("Traversing q");
	QueueTraverse(q);
	if (DestroyQueue(&q))
	{
		printf("\nSucceed in destorying q");
	}
	printf("\n");
	return 0;
}

