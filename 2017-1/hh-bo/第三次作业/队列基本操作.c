//
//  main.c
//  Queue
//
//  Created by Huhongbo on 2017/4/5.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ok 1
#define error 0
#define overflow -1
typedef int Status;
typedef int ElemType;

/*单链队列的链式存储结构*/
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
    QueuePtr front; //队头指针
    QueuePtr rear;  //队尾指针
}LinkQueue;

/*基本操作函数的原型说明*/
Status InitQueue(LinkQueue *Q); //构造一个空队列
Status DestroyQueue(LinkQueue *Q);  //销毁队列Q
Status EnQueue(LinkQueue *Q,ElemType e);    //插入元素e作队尾
Status DeQueue(LinkQueue *Q,ElemType *e);   //若队列不空，删除队头元素，用e返回
Status ClearQueue(LinkQueue *Q);//清空队列Q
Status QueueEmpty(LinkQueue Q);//若Q为空队列，则返回TRUE，否则FALSE
Status GetHead(LinkQueue Q,ElemType *e);//用e返回Q的队头元素
Status QueueTraverse(LinkQueue Q,void(*visit)(ElemType));//从队头到队尾依次调用函数visit()
int QueueLength(LinkQueue Q);//求队列长度

/*基本操作函数的实现*/
Status InitQueue(LinkQueue *Q)
{
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        exit(overflow); //存储分配失败
    Q->front->next=NULL;
    return ok;
}

Status DestroyQueue(LinkQueue *Q)
{
    while(Q->front)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return ok;
}

Status EnQueue(LinkQueue *Q,ElemType e)
{
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p)
        exit(overflow); //存储分配失败
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return ok;
}

Status DeQueue(LinkQueue *Q,ElemType *e)
{
    QueuePtr p;
    if(Q->front==Q->rear)
        return error;   //若队列为空，则返回错误
    p=Q->front->next;
    e=&p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return ok;
}
Status ClearQueue(LinkQueue *Q)
{
    QueuePtr p,q;
    Q->rear=Q->front;
    p=Q->front->next;
    Q->front->next=NULL;//只留下头结点
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    return ok;
}
Status QueueLength(LinkQueue Q)
{
    int i=0;
    QueuePtr p;
    p=Q.front;
    while(Q.rear!=p)
    {
        i++;
        p=p->next;
    }
    return i;  
}
Status GetHead(LinkQueue Q,ElemType *e)
{
    QueuePtr p;
    if(Q.front==Q.rear)
        return error;
    p=Q.front->next;
    e=&p->data;
    return ok;
}
Status QueueTraverse(LinkQueue Q,void(*visit)(ElemType))
{
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return  ok;
}
Status QueueEmpty(LinkQueue Q)
{
    if(Q.front->next==NULL)//注意不要把链式队列的判空条件与循环队列混淆
        return 1;
    else
        return 0;
}

/*主函数*/
int main()
{
    LinkQueue Q;
    InitQueue(&Q);
    
    int i,n;
    ElemType e;
    
    printf("please input the sequence's length :  ");
    scanf("%d",&n);
    printf("\nThe sequence of enqueue is \n");
    for(i=0;i<n;i++)
    {
        EnQueue(&Q,2*i);
        printf("%d ",2*i);
    }
    printf("\n\n");
    
    printf("The sequence of dequeue is \n");
    for(i=0;i<n;i++)
    {
        DeQueue(&Q,&e);
        printf("%d ",e);
    }
    printf("\n\n");
    
    printf("Destroy queue! \n");
    DestroyQueue(&Q);
    
    return 0;
}
