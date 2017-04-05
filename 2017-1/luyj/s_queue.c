#include "queue.h"

int main()
{
	int n, n1;
	int i;
	QElemType e = 0;
	LinkQueue q;
	InitQueue(&q);
	srand(time(0));
	n = rand() % 9 + 1;
	for (i = 0; i < n; i++)
	{
		n1 = rand() % 9 + 1;
		EnQueue(&q, n1);
	}
	printf("随机生成队列q:\n");
	QueueTraverse(q);
	printf("\n");
	printf("队列长度(加上头结点)：\n");
	printf("%d", QueueLength(q));
	printf("\n队列q队头元素为：\n");
	GetHead(q, &e);
	printf("%d\n", e);
	printf("删除队头元素，新队列为:\n");
	DeQueue(&q, &e);
	QueueTraverse(q);
	printf("\n");
	if (QueueEmpty(&q) == false)
	{
		printf("目前队列不为空\n");
	}
	printf("清空队列\n");
	{
		ClearQueue(&q);
	}
	if (QueueEmpty(&q) == true)
	{
		printf("目前队列为空\n");
	}

}