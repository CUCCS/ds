#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

/*���*/
#define XOR(a,b) ((a)&&!(b) || (b)&&!(a))

/*������Щ����ĸСд�ĺͺ���ͬ���ĺ�*/
/*���ڼ򻯶�Ӧ�����ĵ��ù���*/
#define isQueueEmpty(Q) (IsQueueEmpty((Q),&global_isQueueEmpty),global_isQueueEmpty)
#define enQueue(Q,data) EnQueue(&(Q),(data))
#define deQueue(Q,data) (DeQueue(&(Q),&global_deQueue),global_deQueue)
#define sizeOfQueue(Q) (SizeOfQueue(Q,&global_sizeOfQueue),global_sizeOfQueue)
#define getHead(Q) (GetHead(Q,&global_getHead),global_getHead)
#define clearQueue(Q) ClearQueue(&(Q))

#define DEBUG 1
#define debug_print(...) if(DEBUG)printf(__VA_ARGS__)

/*����check��ͷ�ĺ������ں�����ڴ����������*/
/*���ڲ����쳣ʱ��ӡ�����Ϣ*/
#define checkQIllegal(Q) if(XOR((Q).rear,(Q).head)){ debug_print("Q is broken , return ERROR \n");return ERROR;}
#define checkQEmpty(Q) if(isQueueEmpty(Q)){debug_print("Q is empty , return ERROR \n");return ERROR;}
#define checkEmpty(var,var_name) if(!(var)){debug_print("%s is empty , return ERROR \n",var_name);return ERROR;}

typedef int Elemtype;

typedef struct _Node {
	Elemtype data;
	struct _Node* prev;
	struct _Node* next;
}Node;
typedef struct _Queue {
	Node * head;
	Node* rear;
}Queue;
typedef enum _bool { false, true } bool;

bool global_isQueueEmpty;
Elemtype global_deQueue;
int global_sizeOfQueue;
Elemtype global_getHead;

Status InitQueue(Queue*);
Status IsQueueEmpty(Queue, bool*);
Status EnQueue(Queue*, const Elemtype);
Status DeQueue(Queue*, Elemtype *);
Status SizeOfQueue(const Queue, int*);
Status TraverseQueue(const Queue);
Status GetHead(const Queue, Elemtype*);
Status ClearQueue(Queue*);