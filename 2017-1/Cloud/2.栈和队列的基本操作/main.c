#include<stdio.h>
#include "Queue.h"
int main() {
	int _queueLen;
	QElemType _e;
	LinkQueue lk;
	printf("队列初始化...\n");
	InitQueue(&lk);
	printf("遍历队列：");
	TraverseQueue(lk);
	printf("\n插入新的元素 2\n遍历队列：");
	EnQueue(&lk, 2);
	TraverseQueue(lk);
	printf("\n插入新的元素 4\n遍历队列：");
	EnQueue(&lk, 4);
	TraverseQueue(lk);
	printf("\n插入新的元素 6\n遍历队列：");
	EnQueue(&lk, 6);
	TraverseQueue(lk);

	GetHead(&lk, &_e);
	_queueLen = QueueLength(&lk);
	printf("\n*当前头节点为 %d ，队列长度为 %d \n", _e, _queueLen);
	DeQueue(&lk, &_e);
	printf("\n删除队头元素 %d \n遍历队列：", _e);
	TraverseQueue(lk);

	GetHead(&lk, &_e);
	_queueLen = QueueLength(&lk);
	printf("\n*当前头节点为 %d ，队列长度为 %d \n", _e, _queueLen);
	ClearQueue(&lk);
	printf("\n清空队列...\n遍历队列：");
	TraverseQueue(lk);
	DestroyQueue(&lk);
	return 0;
}