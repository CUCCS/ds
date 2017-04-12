#include <stdio.h> 
#include <stdlib.h> 
#define OK 1 //�곣��
#define OVERFLOW -1 //�곣��
#define ERROR 0 //�곣��

typedef int ElemType; 
typedef int Status; 
typedef struct QNode  
{ 
	ElemType data; 
	struct QNode *next; 
}QNode,*QueuePtr; 
typedef struct  
{ 
	QueuePtr front;//��ͷָ�� 
	QueuePtr rear;//��βָ�� 
}LinkQueue; 

//������ʽ��ʾ 

Status InitQueue(LinkQueue *Q) 
{ //���г�ʼ�� 
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode)); //��̬����
	if(!Q->front) //��������ͷָ��
	{ 
		return OVERFLOW; //���
	} 
	Q->front->next = NULL; //��ʼ�� ����ͷָ��ָ���
	Q->rear->next = NULL; //��ʼ�� ����βָ��ָ���
	return OK; 
} 

Status DeleteQueue(LinkQueue *Q, ElemType *e) 
{ //ɾ��Ԫ�� 
	QueuePtr p; 
	if (Q->front == Q->rear)  //�ж��Ƿ��ǿն��� 
	{ 
		return ERROR;//����
	} 
	p = Q->front->next; //pΪҪɾ����Ԫ�� 
	(*e) = p->data;//���潫Ҫɾ����Ԫ�� 
	Q->front->next = p->next;//����ͷָ����p->next����ͷ����� 
	if (Q->rear == p)  //����βָ��ָ��p
	{ 
		Q->rear = Q->front;//������ֻ��һ��Ԫ�� 
	} 
	free(p); //�ͷ�p
	return OK; //�ɹ�
} 

Status InsertQueue(LinkQueue *Q, ElemType e) 
{ //����Ԫ�ص������� 
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode)); //��̬�����ڴ�
	if (!p) //p������
	{ 
		return OVERFLOW;//��� 
	} 
	p->data = e; //eΪҪ�����Ԫ��
	p->next = NULL; //pβָ��ָ���
	Q->rear->next = p;//��p����βָ����ָ��Ķ�β������ 
	Q->rear = p;//βָ��ָ���²���Ľ�� 
	return OK; 
} 

Status VisitQueue(LinkQueue Q) 
{//���������е�Ԫ��  
	QueuePtr p; //����p����
	if (Q.front == Q.rear)//���ͷָ��Ϊβָ���ǿն���.. 
	{ 
		printf("�ն���\n"); 
		return ERROR; //����
	} 
	p = Q.front->next;//pָ��ͷ��� 
	while (p)//p��Ϊ��ʱ 
	{ 
		printf("%d ", p->data);//���pָ��Ľ���ֵ 
		p = p->next;//ָ����� 
	} 
	printf("\n"); //����
	return OK;
} 
int main() 
{ 
	ElemType e; //����eΪһ������
	LinkQueue p; //�������ΪQ
	InitQueue(&p); //��������ʼ������Q
	//����Ԫ��
	InsertQueue(&p, 0); 
	InsertQueue(&p, 1); 
	InsertQueue(&p, 2); 
	InsertQueue(&p, 3); 
	InsertQueue(&p, 4); 
	//������ʶ���Q�������
	VisitQueue(p);
	//ɾ��ֵΪe��Ԫ��
	DeleteQueue(&p, &e);
	//����Ԫ��5
	InsertQueue(&p, 5); 
	//������ʶ���Q�������
	VisitQueue(p); 
	return 0; 
}

