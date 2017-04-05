#define MAXQSIZE 100

typedef int QElemType;
typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef enum {
	false,
	true
}bool;
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue *Q); //构造空队列
Status DestoryQueue(LinkQueue *Q); //销毁队列
Status ClearQueue(LinkQueue *Q); //清空队列
bool QueueEmpty(LinkQueue Q); //判断是否为空队列
Status GetHead(LinkQueue Q, QElemType *e); //返回队头元素
Status EnQueue(LinkQueue *Q, QElemType e); //插入新的队尾元素
Status DeQueue(LinkQueue *Q, QElemType *e); //删除队头元素，并用e返回其值
Status QueueTraverse(LinkQueue Q); //遍历队列中的元素,并将其输出

