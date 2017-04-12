#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define QElemType int 

typedef struct QNode 
{ 
	QElemType data; 
	struct QNode *next; 
}QNode, *QueuePtr; 

typedef struct 
{ 
	QueuePtr front; 
	QueuePtr rear;
}LinkQueue; 

typedef enum 
{ 
	OK, 
	ERROR, 
	OVERFLOW 
}Status; 

Status InitQueue(LinkQueue *Q) //����ն���
{ 
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode)); 
	if (!Q->front) 
	{ 
		return ERROR; 
	} 
	Q->front->next = NULL; 
	return OK; 
} 

Status DestroyQueue(LinkQueue*Q) //���ٶ���
{ 
	while (Q->front) 
	{ 

		Q->rear = Q->front->next; 
		free(Q->front); 
		Q->front = Q->rear; 
	} 
	return OK; 
} 

Status EnQueue(LinkQueue*Q, QElemType e) // ����Ԫ��eΪQ���µĶ�βԪ�� 
{ 
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode)); 
	if (!p) 
	{ 
		return ERROR; 
	} 
	else 
	{ 
		p->data = e; 
		p->next = NULL; 

		Q->rear->next = p; 
		Q->rear = p; 
	} 
} 

Status DeQueue(LinkQueue*Q, QElemType*e)  // �����в��գ���ɾ��Q�Ķ�ͷԪ��
{ 
	if (Q->front == Q->rear) 
	{ 
		return ERROR; 
	} 
	QNode *p= Q->front->next; 
	*e = p->data; 
	Q->front->next = p->next; 
	if (Q->rear == p) 
	{ 
		Q->rear = Q->front; 

	} 
	free(p); 
	return OK; 
} 

int QueueEmpty(LinkQueue*Q) //�ж϶����Ƿ�Ϊ��
{ 
	if (Q->front == Q->rear) 
	{ 
		return 1; 
	} 
	else 
	{ 
		return 0; 
	}
} 

Status ClearQueue(LinkQueue*Q) //��ն���
{ 
	QElemType e; 
	if (QueueEmpty(Q)) 
	{ 
		return ERROR; 
	} 

	while (!QueueEmpty(Q)) 
	{ 
		DeQueue(Q,&e); 
	} 
} 

int QueueLength(LinkQueue Q) //����г���
{ 
	int i = 0; 
	while (!QueueEmpty(&Q)) 
	{ 
		Q.front = Q.front->next; 
		i++; 
	} 
} 

Status GetHead(LinkQueue Q, QElemType *e) //���ض���ͷԪ�� 
{ 
	if (QueueEmpty(&Q) == 1) 
	{ 
		return ERROR; 
	} 
	else 
	{ 
		QNode *p = Q.front->next; 
		*e = p->data; 
		return OK; 
	} 
} 

Status QueueTraverse(LinkQueue Q) //��������
{ 
	if (QueueEmpty(&Q)) 
	{ 
		printf("ERROR"); 
	} 
	else 
	{ 
		QNode*p = Q.front->next; 
		while (p != Q.rear) 
		{ 
			printf("%d", p->data); 
			p = p->next; 
		} 
		return OK; 
	} 
}

int main() 
{ 
	int n, n1; 
	int i; 
	QElemType e = 0; 
	LinkQueue q; 
	InitQueue(&q); 
	srand(time(0)); 
	n = rand() % 9 + 1; //���������
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
	if (!QueueEmpty(&q) ) 
	{ 
		printf("Ŀǰ���в�Ϊ��\n"); 
	} 
	printf("��ն���\n"); 
	{ 
		ClearQueue(&q); 
	} 
	if (QueueEmpty(&q)) 
	{ 
		printf("Ŀǰ����Ϊ��\n"); 
	}
}