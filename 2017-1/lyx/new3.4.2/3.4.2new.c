#include <stdio.h> 
#include <stdlib.h> 
#define OK 1 //宏常量
#define OVERFLOW -1 //宏常量
#define ERROR 0 //宏常量

typedef int ElemType; 
typedef int Status; 
typedef struct QNode  
{ 
	ElemType data; 
	struct QNode *next; 
}QNode,*QueuePtr; 
typedef struct  
{ 
	QueuePtr front;//队头指针 
	QueuePtr rear;//队尾指针 
}LinkQueue; 

//队列链式表示 

Status InitQueue(LinkQueue *Q) 
{ //队列初始化 
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode)); //动态分配
	if(!Q->front) //若不存在头指针
	{ 
		return OVERFLOW; //溢出
	} 
	Q->front->next = NULL; //初始化 定义头指针指向空
	Q->rear->next = NULL; //初始化 定义尾指针指向空
	return OK; 
} 

Status DeleteQueue(LinkQueue *Q, ElemType *e) 
{ //删除元素 
	QueuePtr p; 
	if (Q->front == Q->rear)  //判断是否是空队列 
	{ 
		return ERROR;//错误
	} 
	p = Q->front->next; //p为要删除的元素 
	(*e) = p->data;//保存将要删除的元素 
	Q->front->next = p->next;//将队头指针后继p->next赋给头结点后继 
	if (Q->rear == p)  //若队尾指针指向p
	{ 
		Q->rear = Q->front;//队列中只有一个元素 
	} 
	free(p); //释放p
	return OK; //成功
} 

Status InsertQueue(LinkQueue *Q, ElemType e) 
{ //插入元素到队列中 
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode)); //动态分配内存
	if (!p) //p不错在
	{ 
		return OVERFLOW;//溢出 
	} 
	p->data = e; //e为要插入的元素
	p->next = NULL; //p尾指针指向空
	Q->rear->next = p;//将p插入尾指针所指向的队尾结点后面 
	Q->rear = p;//尾指针指向新插入的结点 
	return OK; 
} 

Status VisitQueue(LinkQueue Q) 
{//遍历队列中的元素  
	QueuePtr p; //定义p队列
	if (Q.front == Q.rear)//如果头指针为尾指针是空队列.. 
	{ 
		printf("空队列\n"); 
		return ERROR; //错误
	} 
	p = Q.front->next;//p指向头结点 
	while (p)//p不为空时 
	{ 
		printf("%d ", p->data);//输出p指向的结点的值 
		p = p->next;//指针后移 
	} 
	printf("\n"); //换行
	return OK;
} 
int main() 
{ 
	ElemType e; //定义e为一个整数
	LinkQueue p; //定义队列为Q
	InitQueue(&p); //构建并初始化队列Q
	//插入元素
	InsertQueue(&p, 0); 
	InsertQueue(&p, 1); 
	InsertQueue(&p, 2); 
	InsertQueue(&p, 3); 
	InsertQueue(&p, 4); 
	//逐个访问队列Q，并输出
	VisitQueue(p);
	//删除值为e的元素
	DeleteQueue(&p, &e);
	//插入元素5
	InsertQueue(&p, 5); 
	//逐个访问队列Q，并输出
	VisitQueue(p); 
	return 0; 
}

