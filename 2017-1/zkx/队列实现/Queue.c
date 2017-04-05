#include "Queue.h"

Status InitQueue (LinkQueue *Q)    // 构造一个空队列Q
{
    Q->front = Q->rear =  (QueuePtr *)malloc(STACK_INIT_SIZE * sizeof(QueuePtr)); //为队头，队尾指针分配内存空间
    if (!Q->front) 
	{
        return ERROR;    //存储分配失败
    }
    Q->front->next = NULL;
	printf("正在构造一个空队列。。。\n");
    return OK;
}

Status DestroyQueue (LinkQueue *Q)     //销毁队列Q，Q不再存在
{
	while(Q->front)
	{
		Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
	printf("队列已被销毁。\n");
	return OK;
}

Status ClearQueue (LinkQueue Q)    //将Q清为空队列
{
	DestroyQueue(&Q);
    InitQueue(&Q);
	printf("队列已被清空\n");
}

Status QueueEmpty (LinkQueue *Q)    //判断队列是否为空
{
	if (Q->front==Q->rear)
	{
		printf("队列是空队列\n");
		return OK;
	}
 
}

int QueueLength (LinkQueue *Q)   //求队列的长度
{
	int count = 0;
    //指向存放数据的第一个结点
    QueuePtr p = Q->front->next;
    while(p)
	{
        count++;
        p = p->next;
    }
    return count;
}

void GetHead(LinkQueue *Q,QElemType e)  //返回队列队头元素
{
	QueuePtr p = (QueuePtr *)malloc(STACK_INIT_SIZE * sizeof(QueuePtr));
    if(Q->front == Q->rear)
	{
        printf("队列为空!\n");
    }
    else
	{
		p = Q->front->next;
		e = p->data;
		printf("队头元素为：%d\n",e);

    }
}

Status EnQueue (LinkQueue *Q, QElemType e)  // 插入元素e为Q的新的队尾元素
{
    QueuePtr p =  (QueuePtr *)malloc(STACK_INIT_SIZE * sizeof(QueuePtr));  //分配存储空间

    if(!p) 
	{ 
        return OVERFLOW;   //存储分配失败
    }
    p->data = e;   
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
	printf("%d入队   ", e);

    return OK;
}

Status DeQueue (LinkQueue *Q, QElemType *e)  // 若队列不空，则删除Q的队头元素，
{                                                                                //用 e 返回其值，并返回OK；否则返回ERROR
	QueuePtr p = (QueuePtr *)malloc(STACK_INIT_SIZE * sizeof(QueuePtr));
    if (Q->front == Q->rear) 
	{
        return ERROR;
    }
    p = Q->front->next;
    e = p->data;
    Q->front->next = p->next;
	printf("%d出队\t", e);
    if(Q->rear == p) 
	{
        Q->rear = Q->front;
    }
    free (p); 
    return OK;
}

Status QueueTraverse (LinkQueue *Q )
{
	QueuePtr p = Q->front->next;
	if (Q->front == Q->rear)
	{
		printf("队列为空!\n");
		return ERROR;
	}
	else 
	{
		while (p)
		{
			printf("%d\t", p->data);
			p = p->next;
		}
		printf("\n");
		return OK;
	}
}


int main()
{
	LinkQueue  Q;
	int i;
	int n[50];

	srand(time(0));
	int number = rand() % 15+1;

	for (i = 0; i < number; i++)    //生成队列随机数
	{
		n[i] = rand() % 100;
	}

	InitQueue(&Q);  //构造一个空队列

	for(i = 0; i < number; i++)   //将随机生成的数字依次入队列
	{
		EnQueue(&Q,n[i]);
	}
	printf("\n");

	printf("队列的长度为：%d\n", QueueLength(&Q));  //求队列元素个数

	GetHead(&Q, n[0]);

	printf("队列中元素为：");
	QueueTraverse(&Q);

	for (i = 0; i < number; i++)
	{
		DeQueue(&Q,n[i]);
	}
	printf("\n");

	printf("当所有元素出队列后，");
	QueueEmpty(&Q);

	ClearQueue(Q);
	printf("\n");
	

	return 0;
	

}

