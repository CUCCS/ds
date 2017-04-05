#include "Queue.h"

Status InitQueue (LinkQueue *Q)    // ����һ���ն���Q
{
    Q->front = Q->rear =  (QueuePtr *)malloc(STACK_INIT_SIZE * sizeof(QueuePtr)); //Ϊ��ͷ����βָ������ڴ�ռ�
    if (!Q->front) 
	{
        return ERROR;    //�洢����ʧ��
    }
    Q->front->next = NULL;
	printf("���ڹ���һ���ն��С�����\n");
    return OK;
}

Status DestroyQueue (LinkQueue *Q)     //���ٶ���Q��Q���ٴ���
{
	while(Q->front)
	{
		Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
	printf("�����ѱ����١�\n");
	return OK;
}

Status ClearQueue (LinkQueue Q)    //��Q��Ϊ�ն���
{
	DestroyQueue(&Q);
    InitQueue(&Q);
	printf("�����ѱ����\n");
}

Status QueueEmpty (LinkQueue *Q)    //�ж϶����Ƿ�Ϊ��
{
	if (Q->front==Q->rear)
	{
		printf("�����ǿն���\n");
		return OK;
	}
 
}

int QueueLength (LinkQueue *Q)   //����еĳ���
{
	int count = 0;
    //ָ�������ݵĵ�һ�����
    QueuePtr p = Q->front->next;
    while(p)
	{
        count++;
        p = p->next;
    }
    return count;
}

void GetHead(LinkQueue *Q,QElemType e)  //���ض��ж�ͷԪ��
{
	QueuePtr p = (QueuePtr *)malloc(STACK_INIT_SIZE * sizeof(QueuePtr));
    if(Q->front == Q->rear)
	{
        printf("����Ϊ��!\n");
    }
    else
	{
		p = Q->front->next;
		e = p->data;
		printf("��ͷԪ��Ϊ��%d\n",e);

    }
}

Status EnQueue (LinkQueue *Q, QElemType e)  // ����Ԫ��eΪQ���µĶ�βԪ��
{
    QueuePtr p =  (QueuePtr *)malloc(STACK_INIT_SIZE * sizeof(QueuePtr));  //����洢�ռ�

    if(!p) 
	{ 
        return OVERFLOW;   //�洢����ʧ��
    }
    p->data = e;   
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
	printf("%d���   ", e);

    return OK;
}

Status DeQueue (LinkQueue *Q, QElemType *e)  // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ�
{                                                                                //�� e ������ֵ��������OK�����򷵻�ERROR
	QueuePtr p = (QueuePtr *)malloc(STACK_INIT_SIZE * sizeof(QueuePtr));
    if (Q->front == Q->rear) 
	{
        return ERROR;
    }
    p = Q->front->next;
    e = p->data;
    Q->front->next = p->next;
	printf("%d����\t", e);
    if(Q->rear == p) 
	{
        Q->rear = Q->front;
    }
    free (p); 
    return OK;
}

Status QueueTraverse (LinkQueue *Q )
{
	QueuePtr p = Q->front->next;
	if (Q->front == Q->rear)
	{
		printf("����Ϊ��!\n");
		return ERROR;
	}
	else 
	{
		while (p)
		{
			printf("%d\t", p->data);
			p = p->next;
		}
		printf("\n");
		return OK;
	}
}


int main()
{
	LinkQueue  Q;
	int i;
	int n[50];

	srand(time(0));
	int number = rand() % 15+1;

	for (i = 0; i < number; i++)    //���ɶ��������
	{
		n[i] = rand() % 100;
	}

	InitQueue(&Q);  //����һ���ն���

	for(i = 0; i < number; i++)   //��������ɵ��������������
	{
		EnQueue(&Q,n[i]);
	}
	printf("\n");

	printf("���еĳ���Ϊ��%d\n", QueueLength(&Q));  //�����Ԫ�ظ���

	GetHead(&Q, n[0]);

	printf("������Ԫ��Ϊ��");
	QueueTraverse(&Q);

	for (i = 0; i < number; i++)
	{
		DeQueue(&Q,n[i]);
	}
	printf("\n");

	printf("������Ԫ�س����к�");
	QueueEmpty(&Q);

	ClearQueue(Q);
	printf("\n");
	

	return 0;
	

}

