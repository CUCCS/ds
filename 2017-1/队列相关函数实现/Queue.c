#include "Queue.h"  
#include <malloc.h>  
#include <stdio.h>  
  
/*����һ���ն���*/  
Queue* InitQueue()  
{  
 Queue* pqueue = (Queue*)malloc(sizeof(Queue));  
 if(pqueue!=NULL)  
 {  
    pqueue->front = NULL;  
    pqueue->rear = NULL;  
    pqueue->size = 0;  
  
 }  
 return pqueue;  
 }  
  
/*����һ������*/  
void DestroyQueue(Queue* pqueue)  
{  
    if(IsEmpty(pqueue)!=1)  
    ClearQueue(pqueue);  
  
    free(pqueue);  
}  
  
/*���һ������*/  
void ClearQueue(Queue* pqueue)  
{  
    while(IsEmpty(pqueue)!= 1)  
    {  
        DelQueue(pqueue,NULL);  
      
    }  
}  
/*�ж�һ�������Ƿ�Ϊ��*/  
int IsEmpty(Queue* pqueue)  
{  
    if(pqueue->front==NULL&&pqueue->rear==NULL&& pqueue->size ==0)  
        return 1;  
    else   
        return 0;  
}  
/*����һ�����еĴ�С*/  
int GetSize(Queue* pqueue)  
{  
    return pqueue->size;  
}  
/*���ض�ͷԪ��*/  
PNode GetFront(Queue* pqueue,Item *pitem)  
{  
    if(IsEmpty(pqueue)!=1&& pitem!=NULL)//���в���  
        *pitem = pqueue->front->data;  
    return pqueue->front;  
  
}  
  
/*���ض�βԪ��*/  
PNode GetRear(Queue *pqueue,Item *pitem)  
{  
    if(IsEmpty(pqueue)!=1&& pitem!=NULL)  
    {  
        *pitem = pqueue->rear->data;  
    }  
    return  pqueue->rear;  
  
}  
/*����Ԫ�������*/  
PNode EnQueue(Queue* pqueue,Item item)  
{  
  
    PNode pnode = (PNode)malloc(sizeof(Node));  
  
    if(pnode!=NULL)  
    {  
        pnode->data = item;  
        pnode->next = NULL;  
    if(IsEmpty(pqueue))  
    {  
        pqueue->front = pnode;  
    }  
    else  
    {  
        pqueue->rear->next = pnode;  
    }  
    pqueue->rear = pnode;  
    pqueue->size++;  
  
    }  
    return pnode;  
}  
  
/*��ͷԪ�س���*/  
PNode DelQueue(Queue* pqueue, Item *pitem)  
{  
    PNode pnode = pqueue->front;  
    if(IsEmpty(pqueue)!=1&&pnode!=NULL)  
    {  
        if(pitem!=NULL)  
            *pitem = pnode->data;  
        pqueue->size--;  
        pqueue->front = pnode->next;  
        free(pnode);  
        if(pqueue->size ==0)  
            pqueue->rear =NULL;  
  
  
        }  
      
    return pqueue->front;  
}  
  
/*��������*/  
void QueueTraverse(Queue* pqueue,void (*visit)(PNode))  
{  
  
    PNode pnode = pqueue->front;  
    int i = pqueue->size;  
    while(i--)  
    {  
    visit(pnode);  
    pnode = pnode->next;  
    }  
  
}  