#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef char ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree, *QElemType;

//���л�������
typedef enum{
    OK,
	ERROR
}Status;
typedef struct QNode {
    QElemType data;
	struct QNode *next;
}QNode, * QueuePtr;
typedef struct {
    QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

//����һ���ն���Q
Status InitQueue(LinkQueue *Q)
{
	Q->front =	Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
	{
		return ERROR;
	}
	Q->front->next = NULL;
	return OK;
}

//������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
Status QueueEmpty(LinkQueue *Q)
{
	if(Q->rear==Q->front)
	{
		return OK;
	}
	return ERROR;
}

//����Ԫ��eΪQ���¶�βԪ��
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QNode *p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
	{
		return ERROR;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
Status DeQueue(LinkQueue *Q, QElemType e )
{
	QNode *p;
	if(Q->front==Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next;
	e = p->data;
	printf("%d was deleted.\n", e);
	Q->front->next = p->next;
	if(Q->rear==p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

//����Q��Ԫ�ظ�������Ϊ���еĳ���
int QueueLength(LinkQueue Q)
{
	int count = 0;
	QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        //printf("%d",p->data);
        p=p->next;
		count++;
     }
	 return count;
}

Status PostOrderTraverse(BiTree T) {
	//��������������ĵݹ��㷨
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
	return OK;
}

int Depth(BiTree T){ // ���ض����������
	int depthval;
	int depthLeft, depthRight;
    if(!T) {
        depthval = 0;
    } else {
        depthLeft = Depth(T->lchild);
        depthRight= Depth(T->rchild);
        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    } 
    return depthval;
}

int Width(BiTree T) {
	// �������������,���ض������Ŀ��
	LinkQueue Q;
	BiTNode *p = T;
	int width = 1; //���������
	int temp = 0; //��һ����
	int last = 0;
	int now = 0; //��ǰ���

	if (!T) {
		return 0;
	}
	InitQueue(&Q); //������������
	EnQueue(&Q, T); //�����ڵ������
	last = 1;
	while (!QueueEmpty(&Q)) {
		temp = last;
		while (temp != 0) {
			DeQueue(&Q, T);
			if (p->lchild) {
				EnQueue(&Q, p->lchild);
			}
			if (p->rchild) {
				EnQueue(&Q, p->rchild);
			}
			temp--;
		}
		now = QueueLength(Q);
		width = now > width ? now : width;
		last = now;
	}
	return ++width;
}

int Count(BiTree T) {
	//����ָ��T��ָ�����������н�����
	int m, n;
	if (!T) {
		return 0;
	}
	if ((!T->lchild) && (!T->rchild)) {
		return 1;
	}
	else {
		m = Count(T->lchild);
		n = Count(T->rchild);
		return m + n + 1;
	}
}

int CountLeaf(BiTree T) {
	// ����ָ��T��ָ������������Ҷ�ӽ�����
	int m, n;
	if (!T) {
		return 0;
	}
	if ((!T->lchild) && (!T->rchild)) {
		return 1;
	}
	else {
		m = CountLeaf(T->lchild);
		n = CountLeaf(T->rchild);
		return m + n;
	}
}

bool Compelete(BiTree T) {
	//�ж��Ƿ�Ϊ��ȫ������
	LinkQueue Q;
	BiTNode *p = T;
	InitQueue(&Q); //������������
	EnQueue(&Q, T);

	while (!QueueEmpty(&Q)) {
		DeQueue(&Q, T);
		if (p->lchild) {
			EnQueue(&Q, p->lchild);
		}
		if (p->rchild) {
			EnQueue(&Q, p->rchild);
		}
		if ((!p->lchild) && p->rchild) {
			return false;
		}
	}
	return true;
}

bool Full(BiTree T) {
	//�ж��Ƿ�Ϊ���������������Ϊk��Ӧ��2^k-1����㣩
	if (pow(2.0, Depth(T)) - 1 == Count(T)) {
		printf("It is a full tree\n");
		return true;
	}
	printf("It is not a full tree\n");
	return false;
}
