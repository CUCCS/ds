#include <stdio.h>
#include <stdlib.h>

#include "3-4QUENE.h"

int main(){
	LinkQueue a;
	QElemType e;
	int len;

	a.front = a.rear = (QueuePtr)malloc(sizeof(QNode));
	InitQueue(a);
	TraverseQueue(a);
	len=QueueLength(a);
	printf("��ʱ���г���Ϊ %d\n\n", len);

	printf("������3���������\n");
	EnQueue(&a, 3);
	TraverseQueue(a);
	len=QueueLength(a);
	printf("��ʱ���г���Ϊ %d\n\n", len);

	printf("������18���������\n");
	EnQueue(&a, 18);
	TraverseQueue(a);
	len=QueueLength(a);
	printf("��ʱ���г���Ϊ %d\n\n", len);

	GetHead(a, &e);

	DeQueue(&a, &e);
	printf("��ʱ���в�Ϊ�գ�ɾ����ͷԪ��%d\n",e);
	TraverseQueue(a);
	printf("\n");

	GetHead(a, &e);

	DeQueue(&a, &e);
	printf("��ʱ���в�Ϊ�գ�ɾ����ͷԪ��%d\n",e);
	TraverseQueue(a);
	printf("\n");

	CleanQueue(a);
	return 0;
}
//������