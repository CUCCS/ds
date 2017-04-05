#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define OVERFLOW -1
#define ERROR 0

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
//队列初始化
Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
	{
		return OVERFLOW;
	}
    Q->front->next = NULL;
    Q->rear->next = NULL;
    return OK;
}
//删除元素
Status DeleteQueue(LinkQueue *Q, ElemType *e)
{
	  QueuePtr p;
    if (Q->front == Q->rear) 
	{
			return ERROR;//判断是否是空队列
	}
    p = Q->front->next; //将要删除的对头结点暂存给p
    (*e) = p->data;//保存将要删除结点的值
    Q->front->next = p->next;//将元队列头后继p->bext赋给头结点后继
    if (Q->rear == p) 
	{
			Q->rear = Q->front;//删除元素之前，队列中只有一个元素。
	}
    free(p);
    return OK;
}
//插入元素到队列中
Status InsertQueue(LinkQueue *Q, ElemType e)
{
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if (!p)
	{
			return OVERFLOW;
	}
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;//将p插入尾指针所指向的队尾结点后面
    Q->rear = p;//尾指针指向新插入的结点
    return OK;
}
//遍历队列中的元素
Status VisitQueue(LinkQueue Q)
{
	QueuePtr p;
    if (Q.front == Q.rear)//如果是空队列..
    {
       printf("空队列\n") ;
        return ERROR;
    }
    p = Q.front->next;//p指向队头结点
    while (p)//p不为空时
    {
           printf("%d ", p->data);//输出p指向的结点的值
            p = p->next;//指针后移
    }
   printf("\n");
    return OK;
}

int main()
{
	ElemType e;
    LinkQueue Q;
    InitQueue(&Q);
    InsertQueue(&Q, 1);
    InsertQueue(&Q, 2);
    InsertQueue(&Q, 3);
    InsertQueue(&Q, 4);
    InsertQueue(&Q, 5);
    VisitQueue(Q);
    DeleteQueue(&Q, &e);
    InsertQueue(&Q, 6);
    VisitQueue(Q);
    getchar();
    return 0;
}