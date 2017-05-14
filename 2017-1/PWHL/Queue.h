#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
typedef char QElemType;
typedef int Status;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct Queue
{
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

Status InitQueue(LinkQueue *Q);//����ն���
Status DestroyQueue(LinkQueue *Q);//���ٶ���Q
Status ClearQueue(LinkQueue *Q);//��ն���
Status QueueEmpty(LinkQueue Q);//������Ϊ�գ�����TRUE�����򷵻�FALSE
int QueueLength(LinkQueue Q);//����г���
Status GetHead(LinkQueue Q, QElemType *e);//�����в��գ���e����Q�Ķ�ͷԪ�أ�������OK �����򷵻�ERROR
Status EnQueue(LinkQueue *Q, QElemType e);//����Ԫ��eΪQ���µĶ�βԪ��
Status DeQueue(LinkQueue *Q, QElemType *e);//�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
Status QueueTraverse(LinkQueue Q);// �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi().
int visit(Queueptr);//���ʲ���ӡÿһ������Ԫ��
