#include "Queen.h"
int main()
 {
	Linkqueue  q;
	Init(&q);
	QElmtype x[NUM] = { 'a','b','c','d','e','f','h','i','j','k' };
	QElmtype e;
	int i;
	for (i = 0; i < NUM; i++)
		 {
		Enqueue(&q, x[i]);
		}
	printf("   1.������ɵĶ���Ϊ\n");
	Queuetraverse(q);
	printf("\n   2.���еĳ���Ϊ %d\n\n", Queuelength(q));
	printf("   3.�ж϶����Ƿ�Ϊ�ղ����ض�ͷԪ��\n\n");
	if (Gethead(q, &e))
		 {
		printf("   ���в�Ϊ�գ���ջ��Ԫ��Ϊ%c\n", e);
		}
	printf("\n   4.����ɾ������\n\n");
	while (!Queueempty(q))
		 {
		Dequeue(&q, &e);
		printf("   ��ɾ����Ԫ��Ϊ%c\n", e);
		printf("   ɾ����Ķ���Ϊ\n");
		Queuetraverse(q);
		}
	printf("\n   5.���еĳ���Ϊ %d\n\n", Queuelength(q));
	printf("   6.���ٶ���\n");
	Destory(&q);
	return 0;
	}
//��ʼ������һ���ն���  �ɹ�����1 ���򷵻�0
status Init(Linkqueue *q)
 {//��һ��ͷԪ���ǲ������ݵ�
	q->rear = (Queueptr)malloc(sizeof(Qnode));
	if (!q->rear)
		 {
		return 0;
		}
	q->front = q->rear;
	q->rear->next = NULL;
	return 1;
	}
status Destory(Linkqueue *q)//���ٶ���q q���ڴ���
 {
	while (q->front)
		 {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
		}
	return 1;
	}
status Clearqueue(Linkqueue *q)//���������
 {
	Queueptr  temp = q->front->next;
	Queueptr th;
	while (temp)
		{
		th = temp;
		temp = temp->next;
		free(th);
		}//ֻ������ͷ��β
	temp = NULL;
	q->front = q->rear = NULL;//ͷβָ���Ϊ��  ����������Ҫ��ʼ��  ��Ϊ�Ѿ���ȫ�ͷ���
	return 1;
	}
//������Ϊ��  ����1 ���򷵻�0
status Queueempty(Linkqueue  q)
 {
	if (q.front == q.rear)
		 {
		return 1;
		}
	return 0;
	}
//���ض��еĳ���  �����ͷ�ĳ���
status Queuelength(Linkqueue q)
 {
	q.front = q.front->next;
	int num = 0;
	while (q.front)
		 {
		num++;
		q.front = q.front->next;
		}
	return num;
	}
//�����в��� ����e 1 ���򷵻�0
status Gethead(Linkqueue q, QElmtype *e)
 {
	if (q.front == q.rear)
		 {
		return 0;
		}
	*e = q.front->next->data;
	return 1;
	}
//����Ԫ��e��q  ʧ�ܷ���0 ���򷵻�1
status Enqueue(Linkqueue *q, QElmtype e)
 {
	Queueptr p = (Queueptr)malloc(sizeof(Qnode));
	if (!p)
		 {
		return 0;
		}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;//ע�ⵥ������ķ���
	q->rear = p;
	return 1;
	}
//�����в��� ɾ����ͷԪ�� ����e������ֵ ����1  ���򷵻�0
status Dequeue(Linkqueue *q, QElmtype *e)
 {
	if (q->front == q->rear)
		 {
		return 0;
		}
	Queueptr p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
		 {
		q->rear = q->front;
		}
	free(p);
	return 1;
	}
//�Ӷ�ͷ����β���ε��ú���visit() ,һ��visit()ʧ�������ʧ��
status Queuetraverse(Linkqueue q)
 {
	q.front = q.front->next;
	while (visit(q.front))
		 {
		q.front = q.front->next;
		}
	printf("\n");
	return 1;
	}
int visit(Queueptr p)
{
	if (NULL != p)
		 {
		char x = p->data;
		printf("   %c ", x);
		return 1;
		}
	return 0;
	}