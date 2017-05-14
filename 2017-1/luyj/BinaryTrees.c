#include "BinaryTrees.h"
int i = 0;
int high = 0;
int wide[50] = { 0 };
int swide = 0;

void valInit(int *level, int wide[50], int *count, int *ncounts)
{
	int j;
	*level = 0;
	i = 0;
	*count = 0;
	*ncounts = 0;
	swide = 0;
	for (j = 0; j < 50; j++)
	{
		wide[j] = 0;
	}
}

char AbstractWord(char*s)
{

	char ch = s[i];
	i++;
	return ch;
}



Status CreateBiTree(BiTree *T,char *s) 
{
	char ch;
	ch = AbstractWord(s);
	if (ch == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!T)
		{
			return OVERFLOW;
		}

		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild, s); // ����������
		CreateBiTree(&(*T)->rchild, s);// ����������
							 
	}
	return OK;
}



Status PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	} 
	return OK;
}



Status destoryBiTree(BiTree T)
{
	if (!T)
	{
		return ERROR;
	}
	else
	{
		destoryBiTree(T->lchild);
		destoryBiTree(T->rchild);
		free (T);
	}
}



int Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}



int getHigh(BiTree T)
{
	int high = 0;
	int lhigh;
	int rhigh;
	if (!T)
	{
		return 0;
	}
	else
	{
		
		lhigh = getHigh(T->lchild);
		rhigh = getHigh(T->rchild);
		high = Max(lhigh, rhigh)+1;
		return high;
	}
	
}



int getWide(BiTree T, int level)
{
	if (T == NULL)
	{
		return 0;
	}
	wide[level]++;
	if (swide < wide[level])
	{
		swide = wide[level];
	}
	getWide(T->lchild, level + 1);
	getWide(T->rchild, level + 1);
	return swide;
}



void CountLeaf(BiTree T, int *count,int *ncounts)
{
	if (T)
	{
		(*ncounts)++;
		if ((T->lchild==NULL) && (T->rchild==NULL))
		{
			(*count)++;     // ��Ҷ�ӽ�����
		}
		CountLeaf(T->lchild, count,ncounts);
		CountLeaf(T->rchild, count,ncounts);
	}
}

bool QueueEmpty(LinkQueue*Q)
{
	if (Q->front == Q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Status EnQueue(LinkQueue*Q, BiTNode e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
	{
		return ERROR;
	}
	else
	{
		p->data = e;
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
	}
}

Status DeQueue(LinkQueue*Q, BiTNode*e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	QNode *p = Q->front->next; //ָ���ͷ;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
	{
		return ERROR;
	}
	Q->front->next = NULL;
	return OK;
}


bool isComplete(BiTree T)
{
	if (!T)
	{
		return true;  //�����жϿ���.������ȫ����������,�жϿ���Ϊ��ȫ������;
	}

	int isL = 0; //���Ա��;
	LinkQueue q;
	InitQueue(&q);  //�����ն���;
	BiTree t = T;
	EnQueue(&q, *T);//������������;

	//��ʼ������ȱ���;
	while (QueueEmpty(&q)!=NULL)
	{
		DeQueue(&q,t);
		if (T->lchild != NULL)
		{
			if (t->lchild != NULL)
			{
				/*���isL==1��˵���˽�������Ѿ���û�к��ӻ�ֻ�����ӵĽ�㣬
				��ʱ�ý�㻹�к��ӣ���˵������Ϊ����ȫ��������*/
				if (isL == 1)  
				{
					return false;
				}
				EnQueue(&q, *(t->lchild));
			}
			if (t->rchild != NULL)
			{
				EnQueue(&q, *(t->rchild));
			}
			if (t->lchild == NULL && t->rchild != NULL)
			{
				return false;
			}
			if (t->lchild != NULL&&t->rchild == NULL||t->lchild==NULL&&t->rchild==NULL)
			{
				/*�������ұ���ʱ�����߳��ֽ���
				���Ӳ�Ϊ�յ��Һ���Ϊ�գ��������Һ��Ӷ�Ϊ����isL=1;*/
				isL = 1;  
			}
		}
	}
	return true;
}

//�������ʽ���ʽ;
void printBiTree(BiTree T)
{
	printf("����ʽ���ʽΪ��\n");
	PostOrderTraverse(T);
	printf("\n");
}

void printLeafNumber(BiTree T,int count,int ncounts)
{
	printf("Ҷ�ӽ�����Ϊ:%d\n", count);
	printf("��Ҷ�ӽ�����Ϊ:%d\n", ncounts - count);
}

void printIsComplete(BiTree T)
{
	if (isComplete(T) == true)
	{
		printf("��������ȫ������");
	}
	else
	{
		printf("����������ȫ������");
	}
}
