/* 单链队列——队列的链式存储结构 */
typedef struct QNode
{
	QElemType data;           //数据域
	struct QNode *next;       //指针域
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front,rear;      //队头、队尾指针
}LinkQueue;

/* 链队列的基本操作*/
void InitQueue(LinkQueue *Q)
{   //构造一个空队列Q
	Q->front=Q->rear=malloc(sizeof(QNode));   //动态分配空间
	if(!Q->front)						      
		exit(OVERFLOW);
	Q->front->next=NULL;                      //空队列
}

void DestroyQueue(LinkQueue *Q)
{   //销毁队列Q(无论空否均可)
	while(Q->front)                           //释放元素空间 
	{
		Q->rear=Q->front->next;               
		free(Q->front);                       
		Q->front=Q->rear;                     
	}
}

void ClearQueue(LinkQueue *Q)
{   //将Q清为空队列
	QueuePtr p,q;
	Q->rear=Q->front;
	p=Q->front->next;        //p指向队头元素
	Q->front->next=NULL;     //删除队头元素
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
}

Status QueueEmpty(LinkQueue Q)
{   //若Q为空队列，则返回TRUE，否则返回FALSE
	if(Q.front->next==NULL)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q)
{   //求队列的长度
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(Q.rear!=p)     //当p指针的值与队尾不同时，继续执行
	{
		i++;
		p=p->next;       //指向下一数据
	}
	return i;
}

Status GetHead_Q(LinkQueue Q,QElemType *e)
{   //若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
	QueuePtr p;
	if(Q.front==Q.rear)    //空队列
		return ERROR;
	p=Q.front->next;       //p指向队头元素
	*e=p->data;            //用e返回队头元素的数据
	return OK;
}

void EnQueue(LinkQueue *Q,QElemType e)
{   //插入元素e为Q的新的队尾元素
	QueuePtr p=malloc(sizeof(QNode));
	if(!p)                 //存储分配失败
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{   //若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	free(p);
	return OK;
}

void QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
{   //从队头到队尾依次对队列Q中每个元素调用函数vi()
	QueuePtr p;
	p=Q.front->next;
	while(p)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");
}
