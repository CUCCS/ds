#include "3.4.2.h"
int main()
{
	Linkqueue  q;
	Init(&q);
	QElmtype x[NUM] = {'a','b','c','d','e','f','h','i','j','k'};
	QElmtype e;
	int i;
	for (i = 0; i < NUM; i++)
	{
		Enqueue(&q, x[i]);
	}
	printf("   1.插入完成的队列为\n");
	Queuetraverse(q);
	printf("\n   2.队列的长度为 %d\n\n", Queuelength(q));
	printf("   3.判断队列是否为空并返回队头元素\n\n");
	if (Gethead(q, &e))
	{
		printf("   队列不为空，且栈顶元素为%c\n", e);
	}
	printf("\n   4.依次删除队列\n\n");
	while (!Queueempty(q))
	{
		Dequeue(&q, &e);
		printf("   被删除的元素为%c\n", e);
		printf("   删除后的队列为\n");
		Queuetraverse(q);
	}
	printf("\n   5.队列的长度为 %d\n\n", Queuelength(q));
	printf("   6.销毁队列\n");
	Destory(&q);
	return 0;
}
//初始化构造一个空队列  成功返回1 否则返回0
status Init(Linkqueue *q)
{//第一个头元素是不存数据的
	q->rear = (Queueptr)malloc(sizeof(Qnode));
	if (!q->rear)
	{
		return 0;
	}
	q->front = q->rear;
	q->rear->next = NULL;
	return 1;
}
status Destory(Linkqueue *q)//销毁队列q q不在存在
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	return 1;
}
status Clearqueue(Linkqueue *q)//将队列清空
{
	Queueptr  temp = q->front->next;
	Queueptr th;
	while (temp)
	{
		th = temp;
		temp = temp->next;
		free(th);
	}//只保留队头队尾
	temp = NULL;
	q->front = q->rear = NULL;//头尾指针均为空  但是再用需要初始化  因为已经完全释放了
	return 1;
}
//若队列为空  返回1 否则返回0
status Queueempty(Linkqueue  q)
{
	if (q.front == q.rear)
	{
		return 1;
	}
	return 0;
}
//返回队列的长度  不算队头的长度
status Queuelength(Linkqueue q)
{
	q.front = q.front->next;
	int num = 0;
	while (q.front)
	{
		num++;
		q.front = q.front->next;
	}
	return num;
}
//若队列不空 返回e 1 否则返回0
status Gethead(Linkqueue q, QElmtype *e)
{
	if (q.front == q.rear)
	{
		return 0;
	}
	*e = q.front->next->data;
	return 1;
}
//插入元素e进q  失败返回0 否则返回1
status Enqueue(Linkqueue *q, QElmtype e)
{
	Queueptr p = (Queueptr)malloc(sizeof(Qnode));
	if (!p)
	{
		return 0;
	}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;//注意单向链表的方向
	q->rear = p;
	return 1;
}
//若队列不空 删除队头元素 并用e返回其值 返回1  否则返回0
status Dequeue(Linkqueue *q, QElmtype *e)
{
	if (q->front == q->rear)
	{
		return 0;
	}
	Queueptr p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;
	}
	free(p);
	return 1;
}
//从队头到队尾依次调用函数visit() ,一旦visit()失败则操作失败
status Queuetraverse(Linkqueue q)
{
	q.front = q.front->next;
	while (visit(q.front))
	{
		q.front = q.front->next;
	}
	printf("\n");
	return 1;
}
int visit(Queueptr p)
{
	if (NULL != p)
	{
		char x = p->data;
		printf("   %c ", x);
		return 1;
	}
	return 0;
}