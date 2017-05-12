#include<stdio.h>
#include<stdlib.h>

typedef int QElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
typedef enum{
	OK,
	ERROR,
	OVERFLOW
}Status;

Status InitQueue (LinkQueue*Q);
Status DestroyQueue (LinkQueue Q);
Status EnQueue (LinkQueue *Q,QElemType e);
Status DeQueue (LinkQueue Q,QElemType *e);
Status CreateQueue(LinkQueue*L,int n);
Status Travel(LinkQueue Q);
Status backTravel(QueuePtr,QueuePtr);
Status ClearQueue(LinkQueue Q);
Status GetHead (LinkQueue Q,QElemType e);
int QueueEmpty(QueuePtr,QueuePtr);
int GetLength (LinkQueue Q);


Status InitQueue (LinkQueue*Q)
{
	Q->front = NULL;
	Q->rear = NULL;
	return OK;
}
Status DestroyQueue (LinkQueue*Q)
{
	QueuePtr temp;
	while(Q->front)
	{
		temp = Q->front ->next;
		free(Q->front);
		Q->front = temp;
	}
	return OK;
}
Status EnQueue (LinkQueue *Q,QElemType e)
{	
	QueuePtr p = (QueuePtr) malloc (sizeof(QNode));
	if (!p) 
		return OVERFLOW;
	p->data = e;
	p ->next = NULL;
	if(Q->front!=NULL)
	{
		Q->rear->next = p;
	}
	else
	{
		Q->front=p;
	}
	Q->rear = p;
	return OK;
}
Status DeQueue (LinkQueue*Q,QElemType *e)
{
	QueuePtr p;
	if (Q->front == NULL)
	{
		return ERROR;
	}
	p= Q->front;
	*e = p->data;
	Q->front = p->next;
	free(p);
	return OK;
}
Status Travel(LinkQueue Q)
{
	QueuePtr p = Q.front;
	printf("\n正向遍历:\n");
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
//已知队尾元素，反向遍历到队首
Status backTravel(QueuePtr start,QueuePtr end)
{
	if(start!=end)
	{
		backTravel(start->next,end);
	}
	printf("%d ",start->data);
	return OK;
}
Status CreateQueue(LinkQueue*L,int n)
{
	printf("\n输入数据:");
	QueuePtr p = NULL;
	int i ;
	L->front = NULL;
	for(i=0;i<n;i++){
		p = (QueuePtr)malloc(sizeof(QNode));
		scanf("%d",&p->data);
		if(i==0)L->rear=p;
		p->next = L->front;
		L->front = p;
	}
	return OK;
}
int QueueEmpty(QueuePtr start,QueuePtr end)
{
	if(start ==end)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int GetLength (LinkQueue Q)
{
	QueuePtr p;
	int n=0;
	p = Q.front;
	while(p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}
Status GetHead (LinkQueue Q,QElemType e)
{
	if(!QueueEmpty)
	{
		e = Q.front->data;
		return OK;
	}
	else
	{
		return ERROR;
	}
}
Status ClearQueue(LinkQueue *Q)
{
	QueuePtr p,q;
	Q->rear = Q->front;
	p = Q->front;
	Q->front = NULL;
	while(p)
	{
		q = p;
		p=p->next;
		free(q);
	}
	return OK;
}
int main ()
{
	LinkQueue Q={0,0};
	int n;
	QElemType e=7,s;
	InitQueue (&Q);
	printf("请输入数据个数:");
	scanf("%d",&n);

	CreateQueue(&Q,n);
	printf("\n输出长度:%d\n", GetLength(Q));

	Travel(Q);
	printf("反向遍历:\n");
	backTravel(Q.front,Q.rear);

	printf("\n");
	EnQueue (&Q,e);

	Travel(Q);
	printf("反向遍历:\n");
	backTravel(Q.front,Q.rear);

	DestroyQueue(&Q);
	return 0;
}