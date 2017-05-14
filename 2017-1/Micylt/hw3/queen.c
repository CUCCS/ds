//有头尾指针的链式映像实现的单向队列的所有基本操作
#include <stdio.h>
#include <string.h>

typedef int QElemType;

typedef enum 
{
	false,
	true,
}bool;
typedef enum 
{
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct QNode 
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct LinkQueue 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


Status InitQueue(LinkQueue q) //初始化队列
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front) 
	{
		exit(OVERFLOW);
	}
	q.front->next = NULL;
	printf("初始化完毕\n");
	return OK;
}
Status DestroyQueue(LinkQueue q) //销毁队列
{
	while (q.front) 
	{
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}
	return OK;
}
Status EnQueue(LinkQueue *q, QElemType e) //向队列插入元素
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) 
	{
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear->data = p->data;
	q->rear = p;
	return OK;
}
bool QueueEmpty(LinkQueue q) 
{
	if (q.front == q.rear) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
Status DeQueue(LinkQueue *q, QElemType *e) //删除队头元素
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (q->front == q->rear) 
	{
		return ERROR;
	}
	p = q->front;
	*e = p->data;
	q->front = q->front->next;
	if (q->rear == p) 
	{
		q->rear = q->front;
	}
	free(p);
	return OK;
}
Status CleanQueue(LinkQueue q) //清空队列
{
	QueuePtr p;
	QueuePtr next;
	if (QueueEmpty(q))
	{
		printf("将队列清空为空对列\n");
		return OK;
	}
	else 
	{
		for (p = q.front; p; p = next) 
		{
			next = p->next;
			free(p);
			p = next;
		}
	}
	printf("将队列清空为空对列\n");
	return OK;
}
int QueueLength(LinkQueue q)  //求队列长度
{
	QueuePtr p;
	QueuePtr next;
	int length = 0;
	p = q.front;
	while (p != q.rear) 
	{
		p = p->next;
		length++;
	}
	return length;
}
Status GetHead(LinkQueue q, QElemType *e) //求队头元素
{
	*e = q.front->data;
	printf("此时队头元素为%d\n", *e);
	return OK;
}
Status TraverseQueue(LinkQueue q)  //遍历队列
{
	QueuePtr p;
	printf("开始遍历:\n");
	if (QueueEmpty(q))
	{
		printf("此时队列里不存在元素\n");
		return OK;
	}
	p = q.front;
	while (p != q.rear) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main() 
{
	LinkQueue a;
	QElemType e;
	int len;
	int n;
	int num;
	int flag = 1;
	a.front = a.rear = (QueuePtr)malloc(sizeof(QNode));
	do
	{


	printf("----------队列基本操作如下:---------\n");
	printf("-----------1.初始化队列-------------\n");
	printf("-----------2.向队列中插入元素-------\n");
	printf("-----------3.求队列长度-------------\n");
	printf("-----------4.删除队头元素(空队列无效)\n");
	printf("-----------5.遍历队列---------------\n");
	printf("-----------6.退出-------------------\n");
	printf("请选择您的操作：");
	scanf("%d",&n);
	switch (n)
	{
	case 1:
			InitQueue(a);
			TraverseQueue(a);
			len = QueueLength(a);
			printf("此时队列长度为 %d\n\n", len);
			break;
	case 2:
			
			printf("请输入要插入的元素：");
			scanf("%d", &num);
			EnQueue(&a, num);
			TraverseQueue(a);
			len = QueueLength(a);
			printf("此时队列长度为 %d\n\n", len);
			break;

	case 3:
		    len = QueueLength(a);
			printf("此时队列长度为 %d\n\n", len);
			break;

	case 4:
			GetHead(a, &e);
			DeQueue(&a, &e);
			printf("此时队列不为空，删除队头元素%d\n", e);
			TraverseQueue(a);
			printf("\n");
			break;
	case 5:
		  TraverseQueue(a);
		  break;
	default:
		flag = 0;
		break;
	}
} while (flag==1);
	return 0;
}