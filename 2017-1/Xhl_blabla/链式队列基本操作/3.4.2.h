//单项队列的基本操作
//队尾插入 队头删除
#include <stdio.h>
#include <stdlib.h>
#define NUM 10
typedef char QElmtype;
typedef int status;
typedef struct Qnode
{
	QElmtype  data;
	struct Qnode *next;
}Qnode, *Queueptr;
typedef struct
{
	Queueptr front;//队头指针
	Queueptr rear;//队尾指针
}Linkqueue;
status Init(Linkqueue *q);//初始化构造一个空队列
status Destory(Linkqueue *q);//销毁队列q q不在存在
status Clearqueue(Linkqueue *q);//将队列清空
status Queueempty(Linkqueue  q);//若队列为空  返回1 否则返回0
status Queuelength(Linkqueue q);//返回队列的长度
status Gethead(Linkqueue q, QElmtype *e);//若队列不空 返回e 1 否则返回0
status Enqueue(Linkqueue *q, QElmtype e);//插入元素e进q
status Dequeue(Linkqueue *q, QElmtype *e);//若队列不空 删除队头元素 并用e返回其值 返回1  否则返回0
status Queuetraverse(Linkqueue q);//从队头到队尾依次调用函数visit() ,一旦visit()失败则操作失败
int visit(Queueptr);//访问并打印每一个队列元素