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
	printf("������ɶ���q:\n");
	QueueTraverse(q);
	printf("\n");
	printf("���г���(����ͷ���)��\n");
	printf("%d", QueueLength(q));
	printf("\n����q��ͷԪ��Ϊ��\n");
	GetHead(q, &e);
	printf("%d\n", e);
	printf("ɾ����ͷԪ�أ��¶���Ϊ:\n");
	DeQueue(&q, &e);
	QueueTraverse(q);
	printf("\n");
	if (QueueEmpty(&q) == false)
	{
		printf("Ŀǰ���в�Ϊ��\n");
	}
	printf("��ն���\n");
	{
		ClearQueue(&q);
	}
	if (QueueEmpty(&q) == true)
	{
		printf("Ŀǰ����Ϊ��\n");
	}

}