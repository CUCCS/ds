#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int QElemType;
typedef enum {
	false,
	true,
}bool;
typedef enum {
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct QNode {
	QElemType data;
	struct QNode *next;
	struct QNode *prious;
}QNode, *QueuePtr;
typedef struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/*���ڶ��е���ز���*/
Status InitQueue(LinkQueue q);//��ʼ������
Status EnQueue(LinkQueue *q,QElemType e);//����һ�����
bool QueueEmpty(LinkQueue q);//�������Ƿ�Ϊ��
Status DeQueue(LinkQueue *q,QElemType *e);//ɾ��һ�����
Status TraverseQueue(LinkQueue q);//��������