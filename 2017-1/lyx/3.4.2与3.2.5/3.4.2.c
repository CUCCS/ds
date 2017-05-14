#include"3.4.2.h"
Status InitQueue (LinkQueue *Q)
{//构造一个空队列Q
	Q->rear = (Queueptr)malloc(sizeof(QNode));//动态分配内存
	if(!Q->rear){//分配失败
		return OVERFLOW;//报错
	}
	Q->front = Q->rear;//使队头指针与队尾指针相等
	Q->rear->next = NULL;//使指向下一元素指针为零
	return OK;
}//InitQueue
Status DestoryQueue (LinkQueue *Q)
{//销毁队列Q，Q不再存在
	while(Q->front){//当队首指针存在时
		Q->rear = Q->front->next;//队尾指针等于队首指针的下一个，即没有中间指针
		free(Q->front);//清空
		Q->front = Q->rear;//使队首等于队尾
	}
	return OK;
}//DestoryQueue
Status ClearQueue (LinkQueue *Q)
{//将Q清为空队列
	Queueptr temp = Q->front->next;//temp为队首指针指向的下一个
	Queueptr th;
	while(temp){
		th = temp;
		temp = temp->next;//指向下一个
		free(th);//清空th的内存
	}
	temp = NULL;//使temp为空
	Q->front = Q->rear = NULL;//使队首队尾均为零
	return OK;
}//ClearQueue
Status QueueEmpty (LinkQueue *Q)
{//若队列Q为空队列，则返回TRUE，否则返回FALSE
	if(Q->front == Q->rear){//若队首等于队尾
		return OK;
	}
	else{
		return ERROR;//报错
	}
}//QueueEmpty
int QueueLength (LinkQueue *Q)
{//返回Q的元素个数，即为队列的长度
	Q->front=Q->front->next;//指向下一个
	int num=0;//num为队列长度，设为零
	while(Q->front)//存在队头指针
	{
		num++;//num自加
		Q->front=Q->front->next;//队头指针指向下一个	
	}
	return num;//返回num值
}//QueueLength
Status GetHead (LinkQueue *Q, QElmtype *e)
{//若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
	if(Q->front == Q->rear){//队头队尾相等
		return ERROR;//报错
	}
	*e=Q->front->next->data;//e为下一个的值
	return OK;
}
Status EnQueue (LinkQueue *Q, QElmtype e)
{//插入元素e为Q的新队尾元素 
	Queueptr p = (Queueptr)malloc(sizeof(QNode));//动态分配p内存
	if(!Q){//Q不存在
		return ERROR;//报错
	}
	p->data = e;//e为值
	p->next = NULL;//指向下一个的指针为空
	Q->rear->next = p;//p为队尾指针指向的下一个
	Q->rear = p;//队尾指针为p
	return OK;
}//EnQueue
Status DeQueue (LinkQueue *Q, QElmtype *e)
{//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR；
	if(Q->front == Q->rear){//队头指针队尾指针相等，即队列为空
		return ERROR;//报错
	}
	Queueptr p = Q->front->next;//p为队头指针指向的下一个
	*e = p->data;//e为p指的值
	Q->front->next = p->next;//队首指针指的下一个为p指向的下一个
	if(Q->rear == p){//队尾指针为p
		Q->rear = Q->front;//队头等于队尾指针
	}
	free(p);//清空p的内存
	return OK;
}//DeQueue
Status QueueTraverse (LinkQueue *Q)
{//从队头到队尾依次对队列Q中每个元素调用visit（）。一旦visit失败，则操作失败
	Q->front = Q->front->next;//队首指针指向下一个
	while(visit(Q->front))//成功执行visit的函数
	{
		Q->front = Q->front->next;//队首指针指向下一个
	}
	printf("\n");//换行
	return OK;
}//QueueTraverse
int visit(Queueptr p)
{//访问并打印每一个队列元素
	if(NULL != p){//p不为空
		char x = p->data;//x为p的值
		printf("%c",x);//输出
		return OK;
	}
	return ERROR;//报错
}//visit

int main()
{
	LinkQueue q;//定义q队列
	InitQueue (*q);//构造空队列q
	QElmtype x[NUM] = {'q','w','e','r','t','y','u','i','o','p'};//输入数组
	QElmtype e;
	for(int i=0;i<NUM;i++)//循环输入队列
	{
		EnQueue (*q, x[i]);//插入为最后一个元素
	}
	printf("生成的队列为：");
	QueueTraverse(*q);//遍历输出队列
	printf("\n");
	printf("队列长度为：%d\n",QueueLength(*q));//输出队列长度
	if(GetHead(*q,*e)){//e返回队头元素
		printf("队列不为空，队头为：%c",e);
	}
	else{
		printf("队列为空");
	}
	while(!QueueEmpty(*q))//q不为空
	{
		DeQueue(*q,*e);//删除一个元素
		printf("删除的元素是%c\n",e);
		printf("删除后的队列");
		QueueTraverse(*q);//遍历输出队列
	}
	printf("队列长度为%d\n",QueueLength(*q));//输出队列长度
	DestoryQueue(*q);//销毁队列
	printf("销毁队列\n");
	return 0;
}
