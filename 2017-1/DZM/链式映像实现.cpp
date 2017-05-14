/* �������С������е���ʽ�洢�ṹ */
typedef struct QNode
{
	QElemType data;           //������
	struct QNode *next;       //ָ����
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front,rear;      //��ͷ����βָ��
}LinkQueue;

/* �����еĻ�������*/
void InitQueue(LinkQueue *Q)
{   //����һ���ն���Q
	Q->front=Q->rear=malloc(sizeof(QNode));   //��̬����ռ�
	if(!Q->front)						      
		exit(OVERFLOW);
	Q->front->next=NULL;                      //�ն���
}

void DestroyQueue(LinkQueue *Q)
{   //���ٶ���Q(���ۿշ����)
	while(Q->front)                           //�ͷ�Ԫ�ؿռ� 
	{
		Q->rear=Q->front->next;               
		free(Q->front);                       
		Q->front=Q->rear;                     
	}
}

void ClearQueue(LinkQueue *Q)
{   //��Q��Ϊ�ն���
	QueuePtr p,q;
	Q->rear=Q->front;
	p=Q->front->next;        //pָ���ͷԪ��
	Q->front->next=NULL;     //ɾ����ͷԪ��
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
}

Status QueueEmpty(LinkQueue Q)
{   //��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
	if(Q.front->next==NULL)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q)
{   //����еĳ���
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(Q.rear!=p)     //��pָ���ֵ���β��ͬʱ������ִ��
	{
		i++;
		p=p->next;       //ָ����һ����
	}
	return i;
}

Status GetHead_Q(LinkQueue Q,QElemType *e)
{   //�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
	QueuePtr p;
	if(Q.front==Q.rear)    //�ն���
		return ERROR;
	p=Q.front->next;       //pָ���ͷԪ��
	*e=p->data;            //��e���ض�ͷԪ�ص�����
	return OK;
}

void EnQueue(LinkQueue *Q,QElemType e)
{   //����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p=malloc(sizeof(QNode));
	if(!p)                 //�洢����ʧ��
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{   //�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	free(p);
	return OK;
}

void QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
{   //�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()
	QueuePtr p;
	p=Q.front->next;
	while(p)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");
}
