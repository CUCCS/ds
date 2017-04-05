#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

typedef int QElemType;
typedef enum 
{
   OK ,
   OVERFLOW,
   ERROR
} Status;

typedef enum
{ 
	false,
	true
}bool;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}*QueuePtr,QNode;
typedef struct LinkQueue
{
	QueuePtr front, rear;//队头，队尾指针
}LinkQueue;

Status InitQueue(LinkQueue *Q)
{//初始化一个队列
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)//生成头结点失败
		return OVERFLOW;
	Q->front->next = NULL;
	return OK;
}
Status DestoryQueue(LinkQueue *Q)
{ //销毁队列
	while (Q->front)
	{
		Q->rear = Q->front->next;//Q.rear指向Q.front的下一个结点
		free(Q->front);//释放Q.front所指结点
		Q->front = Q->rear;//Q.front指向Q.front的下一个结点
	}
	return OK;
}
Status ClearQueue(LinkQueue *Q)
{ //将队列清为空
	DestoryQueue(Q);//销毁队列
	InitQueue(Q);//重新构造队列
	return OK;
}
bool QueueEmpty(LinkQueue Q)
{ //判断队列是否为空
	if (Q.front->next == NULL)
		return true;
	else return false;
}
int QueueLength(LinkQueue Q)
{ //求队列的长度
	int i = 0;//计数器清0
	QueuePtr p = Q.front;//p指向结点
	while (Q.rear != p)//p所指向的不是尾结点
	{
		i++;//计数器加1
		p = p->next;
	}
	return i;
}
Status GetHead(LinkQueue Q, QElemType *e)
{
	QueuePtr p;
	if (Q.front == Q.rear) return ERROR;
	p = Q.front->next;//p指向队头结点
	*e = p->data;//将队头元素的值赋给e
	return OK;
}
Status EnQueue(LinkQueue *Q, QElemType e)
{ //插入元素e为队列Q的新的队尾元素
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	//动态生成新结点
	if (!p)
		exit(OVERFLOW);
	p->data = e;//将e的值赋给新结点
	p->next = NULL;//新结点的指针为空
	Q->rear->next = p;//原队尾结点的指针域为指向新结点
	Q->rear = p;//尾指针指向新结点
	return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e)
{ //若队列不为空，删除Q的队头元素，用e返回其值
	QueuePtr p;
	if (Q->front == Q->rear)//队列为空
		return ERROR;
	p = Q->front->next;//p指向队头结点
	*e = p->data;//队头元素赋给e
	Q->front->next = p->next;//头结点指向下一个结点
	if (Q->rear == p)//如果删除的队尾结点
		Q->rear = Q->front;//修改队尾指针指向头结点
	free(p);
	return OK;
}
Status QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{ //对队头到队尾依次对队列中每个元素调用函数visit()
	QueuePtr p = Q.front->next;
	while (p)
	{
		visit(p->data);//对p所指元素调用visit()
		p = p->next;
	}
	printf("\n");
	return OK;
}
Status print(QElemType e)
{
	printf("%2d", e);
	printf("  ");
	return OK;
}


int main()
{
	int i, k,s,cha;
	QElemType d;
	LinkQueue q;
	InitQueue(&q);//构造一个空栈
	srand((unsigned)time(NULL));
	s = rand() % 21+1;
	for (i = 1; i <= s; i++)
	{
		EnQueue(&q, rand()%101);
	}
	printf("构建了一个空栈\n");
	printf("栈的元素为:");
	QueueTraverse(q, print);
	k = QueueEmpty(q);
	printf("判断栈是否为空:");
	if (k == 0)
		printf(" 不为空\n");
	else
		printf(" 为空\n");
	k = GetHead(q, &d);
	printf("此时队头元素为: %d\n", d);
	printf("删除这个队头元素\n");
	DeQueue(&q, &d);
	k = GetHead(q, &d);
	printf("删除后新的队头元素为：%d\n", d);
	printf("此时队列的长度为%d\n", QueueLength(q));
	cha = rand() % 101;
	EnQueue(&q, cha);
	printf("插入一个新的元素：%d\n", cha);
	printf("此时栈的元素为:");
	QueueTraverse(q, print);
	ClearQueue(&q);
	printf("清空队列后q.front=%u,q.rear=%u,q.front->next=%u", q.front, q.rear, q.front->next);
	QueueTraverse(q, print);
	k = QueueEmpty(q);
	printf("判断栈是否为空:");
	if (k == 0)
		printf(" 不为空\n");
	else
		printf(" 为空\n");
	DestoryQueue(&q);
	printf("销毁队列后,q.front=%u,q.rear=%u\n", q.front, q.rear);
}
