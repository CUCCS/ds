#include<stdio.h>
#include "Queue.h"
int main() {
	int _queueLen;
	QElemType _e;
	LinkQueue lk;
	printf("���г�ʼ��...\n");
	InitQueue(&lk);
	printf("�������У�");
	TraverseQueue(lk);
	printf("\n�����µ�Ԫ�� 2\n�������У�");
	EnQueue(&lk, 2);
	TraverseQueue(lk);
	printf("\n�����µ�Ԫ�� 4\n�������У�");
	EnQueue(&lk, 4);
	TraverseQueue(lk);
	printf("\n�����µ�Ԫ�� 6\n�������У�");
	EnQueue(&lk, 6);
	TraverseQueue(lk);

	GetHead(&lk, &_e);
	_queueLen = QueueLength(&lk);
	printf("\n*��ǰͷ�ڵ�Ϊ %d �����г���Ϊ %d \n", _e, _queueLen);
	DeQueue(&lk, &_e);
	printf("\nɾ����ͷԪ�� %d \n�������У�", _e);
	TraverseQueue(lk);

	GetHead(&lk, &_e);
	_queueLen = QueueLength(&lk);
	printf("\n*��ǰͷ�ڵ�Ϊ %d �����г���Ϊ %d \n", _e, _queueLen);
	ClearQueue(&lk);
	printf("\n��ն���...\n�������У�");
	TraverseQueue(lk);
	DestroyQueue(&lk);
	return 0;
}