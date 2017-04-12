#include <stdio.h>
#include <stdlib.h>

#include "3-4QUEEN.h"

int main(){
	LinkQueue a;
	QElemType e;
	int len;

	a.front = a.rear = (QueuePtr)malloc(sizeof(QNode));
	InitQueue(a);
	TraverseQueue(a);
	len=QueueLength(a);
	printf("此时队列长度为 %d\n\n", len);

	printf("将数字3加入队列中\n");
	EnQueue(&a, 3);
	TraverseQueue(a);
	len=QueueLength(a);
	printf("此时队列长度为 %d\n\n", len);

	printf("将数字18加入队列中\n");
	EnQueue(&a, 18);
	TraverseQueue(a);
	len=QueueLength(a);
	printf("此时队列长度为 %d\n\n", len);

	GetHead(a, &e);

	DeQueue(&a, &e);
	printf("此时队列不为空，删除队头元素%d\n",e);
	TraverseQueue(a);
	printf("\n");

	GetHead(a, &e);

	DeQueue(&a, &e);
	printf("此时队列不为空，删除队头元素%d\n",e);
	TraverseQueue(a);
	printf("\n");

	CleanQueue(a);
	return 0;
}