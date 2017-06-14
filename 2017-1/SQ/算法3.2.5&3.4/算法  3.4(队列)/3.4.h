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
Status InitQueue(LinkQueue *Q); //����ն���
Status DestoryQueue(LinkQueue *Q); //���ٶ���
Status ClearQueue(LinkQueue *Q); //��ն���
bool QueueEmpty(LinkQueue Q); //�ж��Ƿ�Ϊ�ն���
Status GetHead(LinkQueue Q, QElemType *e); //���ض�ͷԪ��
Status EnQueue(LinkQueue *Q, QElemType e); //�����µĶ�βԪ��
Status DeQueue(LinkQueue *Q, QElemType *e); //ɾ����ͷԪ�أ�����e������ֵ
Status QueueTraverse(LinkQueue Q); //���������е�Ԫ��,���������

