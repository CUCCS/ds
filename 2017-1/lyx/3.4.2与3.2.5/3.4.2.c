#include"3.4.2.h"
Status InitQueue (LinkQueue *Q)
{//����һ���ն���Q
	Q->rear = (Queueptr)malloc(sizeof(QNode));//��̬�����ڴ�
	if(!Q->rear){//����ʧ��
		return OVERFLOW;//����
	}
	Q->front = Q->rear;//ʹ��ͷָ�����βָ�����
	Q->rear->next = NULL;//ʹָ����һԪ��ָ��Ϊ��
	return OK;
}//InitQueue
Status DestoryQueue (LinkQueue *Q)
{//���ٶ���Q��Q���ٴ���
	while(Q->front){//������ָ�����ʱ
		Q->rear = Q->front->next;//��βָ����ڶ���ָ�����һ������û���м�ָ��
		free(Q->front);//���
		Q->front = Q->rear;//ʹ���׵��ڶ�β
	}
	return OK;
}//DestoryQueue
Status ClearQueue (LinkQueue *Q)
{//��Q��Ϊ�ն���
	Queueptr temp = Q->front->next;//tempΪ����ָ��ָ�����һ��
	Queueptr th;
	while(temp){
		th = temp;
		temp = temp->next;//ָ����һ��
		free(th);//���th���ڴ�
	}
	temp = NULL;//ʹtempΪ��
	Q->front = Q->rear = NULL;//ʹ���׶�β��Ϊ��
	return OK;
}//ClearQueue
Status QueueEmpty (LinkQueue *Q)
{//������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
	if(Q->front == Q->rear){//�����׵��ڶ�β
		return OK;
	}
	else{
		return ERROR;//����
	}
}//QueueEmpty
int QueueLength (LinkQueue *Q)
{//����Q��Ԫ�ظ�������Ϊ���еĳ���
	Q->front=Q->front->next;//ָ����һ��
	int num=0;//numΪ���г��ȣ���Ϊ��
	while(Q->front)//���ڶ�ͷָ��
	{
		num++;//num�Լ�
		Q->front=Q->front->next;//��ͷָ��ָ����һ��	
	}
	return num;//����numֵ
}//QueueLength
Status GetHead (LinkQueue *Q, QElmtype *e)
{//�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
	if(Q->front == Q->rear){//��ͷ��β���
		return ERROR;//����
	}
	*e=Q->front->next->data;//eΪ��һ����ֵ
	return OK;
}
Status EnQueue (LinkQueue *Q, QElmtype e)
{//����Ԫ��eΪQ���¶�βԪ�� 
	Queueptr p = (Queueptr)malloc(sizeof(QNode));//��̬����p�ڴ�
	if(!Q){//Q������
		return ERROR;//����
	}
	p->data = e;//eΪֵ
	p->next = NULL;//ָ����һ����ָ��Ϊ��
	Q->rear->next = p;//pΪ��βָ��ָ�����һ��
	Q->rear = p;//��βָ��Ϊp
	return OK;
}//EnQueue
Status DeQueue (LinkQueue *Q, QElmtype *e)
{//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR��
	if(Q->front == Q->rear){//��ͷָ���βָ����ȣ�������Ϊ��
		return ERROR;//����
	}
	Queueptr p = Q->front->next;//pΪ��ͷָ��ָ�����һ��
	*e = p->data;//eΪpָ��ֵ
	Q->front->next = p->next;//����ָ��ָ����һ��Ϊpָ�����һ��
	if(Q->rear == p){//��βָ��Ϊp
		Q->rear = Q->front;//��ͷ���ڶ�βָ��
	}
	free(p);//���p���ڴ�
	return OK;
}//DeQueue
Status QueueTraverse (LinkQueue *Q)
{//�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص���visit������һ��visitʧ�ܣ������ʧ��
	Q->front = Q->front->next;//����ָ��ָ����һ��
	while(visit(Q->front))//�ɹ�ִ��visit�ĺ���
	{
		Q->front = Q->front->next;//����ָ��ָ����һ��
	}
	printf("\n");//����
	return OK;
}//QueueTraverse
int visit(Queueptr p)
{//���ʲ���ӡÿһ������Ԫ��
	if(NULL != p){//p��Ϊ��
		char x = p->data;//xΪp��ֵ
		printf("%c",x);//���
		return OK;
	}
	return ERROR;//����
}//visit

int main()
{
	LinkQueue q;//����q����
	InitQueue (*q);//����ն���q
	QElmtype x[NUM] = {'q','w','e','r','t','y','u','i','o','p'};//��������
	QElmtype e;
	for(int i=0;i<NUM;i++)//ѭ���������
	{
		EnQueue (*q, x[i]);//����Ϊ���һ��Ԫ��
	}
	printf("���ɵĶ���Ϊ��");
	QueueTraverse(*q);//�����������
	printf("\n");
	printf("���г���Ϊ��%d\n",QueueLength(*q));//������г���
	if(GetHead(*q,*e)){//e���ض�ͷԪ��
		printf("���в�Ϊ�գ���ͷΪ��%c",e);
	}
	else{
		printf("����Ϊ��");
	}
	while(!QueueEmpty(*q))//q��Ϊ��
	{
		DeQueue(*q,*e);//ɾ��һ��Ԫ��
		printf("ɾ����Ԫ����%c\n",e);
		printf("ɾ����Ķ���");
		QueueTraverse(*q);//�����������
	}
	printf("���г���Ϊ%d\n",QueueLength(*q));//������г���
	DestoryQueue(*q);//���ٶ���
	printf("���ٶ���\n");
	return 0;
}
