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
	Queueptr front;//��ͷָ��
	Queueptr rear;//��βָ��
	}Linkqueue;
status Init(Linkqueue *q);//��ʼ������һ���ն���
status Destory(Linkqueue *q);//���ٶ���q q���ڴ���
status Clearqueue(Linkqueue *q);//���������
status Queueempty(Linkqueue  q);//������Ϊ��  ����1 ���򷵻�0
status Queuelength(Linkqueue q);//���ض��еĳ���
status Gethead(Linkqueue q, QElmtype *e);//�����в��� ����e 1 ���򷵻�0
status Enqueue(Linkqueue *q, QElmtype e);//����Ԫ��e��q
status Dequeue(Linkqueue *q, QElmtype *e);//�����в��� ɾ����ͷԪ�� ����e������ֵ ����1  ���򷵻�0
status Queuetraverse(Linkqueue q);//�Ӷ�ͷ����β���ε��ú���visit() ,һ��visit()ʧ�������ʧ��
int visit(Queueptr);//���ʲ���ӡÿһ������Ԫ��