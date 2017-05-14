#include <stdio.h>
#include <stdlib.h>
#define NUM 10//�곣��NUMΪ10
typedef char QElmtype;//����QElmtypeΪ�ַ���
typedef int Status;//����StatusΪ����
typedef struct QNode{
	QElmtype data;
	struct QNode *next;
}QNode,*Queueptr;
typedef struct{
	Queueptr front;//��ͷָ��
	Queueptr rear;//��βָ��
}LinkQueue;
typedef enum{
	OK,
	ERROR,
	OVERFLOW
}Status;

Status InitQueue (LinkQueue *Q);//����һ���ն���Q
Status DestoryQueue (LinkQueue *Q);//���ٶ���Q��Q���ٴ���
Status ClearQueue (LinkQueue *Q);//��Q��Ϊ�ն���
Status QueueEmpty (LinkQueue Q);//������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
int QueueLength (LinkQueue Q);//����Q��Ԫ�ظ�������Ϊ���еĳ���
Status GetHead (LinkQueue Q, QElmtype *e);//�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
Status EnQueue (LinkQueue *Q, QElmtype e);//����Ԫ��eΪQ���¶�βԪ�� 
Status DeQueue (LinkQueue *Q, QElmtype *e);//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR��
Status QueueTraverse (LinkQueue Q);//�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص���visit������һ��visitʧ�ܣ������ʧ��
int visit(Queueptr);//���ʲ���ӡÿһ������Ԫ��