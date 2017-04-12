#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef int datatype;
typedef enum {
    OK,
    OVERFLOW,
    ERROR
} Status;
typedef struct Queuenode {
    datatype data;
    struct Queuenode *next;
} Qnode;

typedef struct link_queue {
    Qnode *front;
    Qnode *rear;
} Linkqueue;

Status InitQueue(Linkqueue *q);//初始化队列
Status DestoryQueue(Linkqueue *q);//销毁已经存在的队列
bool QueueEmpty(Linkqueue *q);//判断队列为空，因为不是用数组来存储队列，而是用堆来管理队。
datatype Queuelength(Linkqueue q);//获取队列长度
Status EnQueue(Linkqueue *q, datatype x);//入队
datatype DeQueue(Linkqueue *q);//出队
datatype QueueFront(Linkqueue *q);//取头指针

Status InitQueue(Linkqueue *q)//初始化队列
{
    q->front = q->rear = (Qnode *) malloc(sizeof(Qnode));
    if (!q->front) {
        return OVERFLOW;
    }
    q->front = q->rear = NULL;
    return OK;
}

Status DestoryQueue(Linkqueue *q)//销毁已经存在的队列
{
    while (q->front) {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    return OK;
}

bool QueueEmpty(Linkqueue *q)//判断队列为空，因为不是用数组来存储队列，而是用堆来管理队。
{
    if ((q->front == NULL) && (q->rear == NULL))
        return true;
    return false;
}

Status ClearQueue(Linkqueue *q)//清空一个队列
{
    DestoryQueue(q);
    InitQueue(q);
    return OK;
}

datatype Queuelength(Linkqueue q)//获取队列长度
{
    int length = 0;
    Queuenode *pqueue;
    pqueue = q.front;
    while (q.rear != pqueue) {
        length++;
        pqueue = pqueue->next;
    }
    return length;
}

Status EnQueue(Linkqueue *q, datatype x)//入队
{
    Qnode *p;
    p = (Qnode *) malloc(sizeof(Qnode));


    if (!p) {
        exit(OVERFLOW);
    }

    p->data = x;
    p->next = NULL;

    //队列为空的情况
    if (QueueEmpty(q)) {
        q->front = q->rear = p;
    }
    else {
        q->rear->next = p;
        q->rear = p;
    }
    return OK;
}

datatype DeQueue(Linkqueue *q)//出队
{
    datatype x;
    Qnode *p;



    p = q->front;
    x = p->data;
    q->front = p->next;

    if (q->rear == p) {
        q->rear = NULL;
    }

    free(p);
    return x;
}

datatype QueueFront(Linkqueue *q)//取头指针
{
    if (QueueEmpty(q)) {
        printf("queue is empty");
    }
    return (q->front->data);
}

int main() {
    datatype i, k = 0, length, e, c;
    Linkqueue q;
    srand(time(NULL));
    length = rand() % 10 + 3;
    for (i = 0; i < length; i++) {
        k = k + 2;
        e = rand() % k;
        EnQueue(&q, e);
    }
    for (i = 0; i < length; i++) {
        c = DeQueue(&q);
        printf("%d ", c);
    }
    ClearQueue(&q);
    return 0;
}