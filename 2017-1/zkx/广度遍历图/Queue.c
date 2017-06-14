#include "Queue.h"

Status InitQueue(LinkQueue *Q)    // ��ʼ��һ������Q
{
	Q->front = Q->rear = (QueuePtr )malloc(MAX_SIZE * sizeof(QueuePtr)); //Ϊ��ͷ����βָ������ڴ�ռ�
	if (!Q->front)
	{
		return ERROR;    //�洢����ʧ��
	}
	Q->front->next = Q->rear->next = NULL;
	return OK;
}

bool QueueEmpty(LinkQueue Q)    //�ж϶����Ƿ�Ϊ��
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;

}

Status EnQueue(LinkQueue *Q, ElemType e)  // ����Ԫ��eΪQ���µĶ�βԪ��
{
	QueuePtr p = (QueuePtr )malloc(MAX_SIZE * sizeof(QueuePtr));  //����洢�ռ�

	if (!p)
	{
		return OVERFLOW;   //�洢����ʧ��
	}
	p->data = e;
	p->next = NULL;
	p->priou = Q->front;    //�����µĶ�β���ʱ������priou���ָ��ָ��ոճ����еĽ��
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, ElemType *e)  //������ʱ�����ƶ���ͷָ�룬��������ͷ����������ɾ����
{                                                                                
	if (QueueEmpty(*Q)) 
	{
		return ERROR;
	}
	Q->front = Q->front->next;
	*e = Q->front->data;
	return OK;

}