#include <stdio.h>
#include <malloc.h>
#define INFINITY -1
#define MXAVERTEX_NUM 10//��󶥵����
#define VRType int 
#define VertexType int 
#define InfoType int
#define QElemType int
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef enum
{
	true,
	false
}bool;
//-------ͼ���ڽӾ���洢-----------//
typedef struct Arcell
{
	VRType adj;//�����ϵ��1��0
	InfoType *info;//�������Ϣ��ָ��
}Arcell, AdjMatrix[MXAVERTEX_NUM][MXAVERTEX_NUM];
typedef struct
{
	VertexType vexs[MXAVERTEX_NUM];    //��������
	AdjMatrix arcs;       //�ڽӾ���
	int vexnum, arcnum;     //ͼ�ĵ�ǰ����ͻ���
}MGraph;
//--------����---------//
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
	struct QNode *pre;
}QNode, *QueuePtr;
typedef struct LinkQueue
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
/*=========���еĻ�������=========*/
Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
	{
		return ERROR;
	}
	Q->front->next = Q->rear->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue*Q, QElemType e)
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
		p->pre = Q->front;
		Q->rear->next = p;
		Q->rear = p;
		return OK;
	}
}

Status DeQueue(LinkQueue*Q, QElemType*e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	Q->front = Q->front->next;
	*e = Q->front->data;
	return OK;
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

Status DestroyQueue(LinkQueue*Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
/*=========ͼ�Ļ�������=========*/

int LocateVex(MGraph *G, int v1)//���ض���v1��λ��
{
	int i;
	int n = -1;
	
	for (i = 0; i <= G->vexnum; i++)
	{
		if (G->vexs[i] == v1)
		{
			n= i;
			break;
		}
	}
	if (n != -1)
	{
		return n;
	}
	return 0;
}
Status InsertArc(MGraph *G, int v1, int v2)//v1��v2����ӻ�
{
	int i, j;
	i = LocateVex(G, v1);
	j= LocateVex(G, v2);
	if (i != 0 && j != 0)
	{
		G->arcs[i][j].adj = 1;//����֮�������ߣ���ֵΪ1;
		G->arcs[j][i] = G->arcs[i][j];
		return OK;
	}
	else
	{
		return ERROR;
	}
}
//����ͼ
Status CreateUDN(MGraph *G)
{
	int i;
	int j;
	//��������ֱ�Ӹ�ֵ��
	G->vexnum = 9;
	G->arcnum = 12;
	for (i = 1; i <= G->vexnum; i++)
	{
		G->vexs[i] = i;//������������;
	}
	for (i = 0; i <= G->vexnum; i++)//��ʼ���ڽӾ���;
	{
		for (j = 0; j <= G->vexnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;
			G->arcs[i][j].info = NULL;
		}
	}
	//�����ڽӾ���;
	InsertArc(G, 1, 2);
	InsertArc(G, 1, 3);
	InsertArc(G, 1, 4);
	InsertArc(G, 1, 7);
	InsertArc(G, 2, 3);
	InsertArc(G, 4, 5);
	InsertArc(G, 4, 6);
	InsertArc(G, 5, 6);
	InsertArc(G, 6, 8);
	InsertArc(G, 7, 8);
	InsertArc(G, 7, 9);
	InsertArc(G, 8, 9);

	return OK;
}

//�ҳ���һ���ڽӵ�
int FirstAdjVex(MGraph *G, int u)
{
	int i;
	for (i = 1; i <= G->vexnum; i++)
	{
		if (G->arcs[u][i].adj == 1)
		{
			return i;
		}
	}
	return -1;
}

//�ҳ���һ���ڽӵ�
int NextAdjvex(MGraph *G, int u, int w)
{
	int i;
	for (i = w + 1; i <= G->vexnum; i++)
	{
		if (G->arcs[u][i].adj == 1)
		{
			return i;
		}
	}
	return -1;
}
//������ȱ���ͼ,������a,b������·��;
Status BFSTraverse(MGraph*G, LinkQueue *Q, int a, int b)
{

	int v;
	int u = 0;
	int w = 0;
	int m = 0;
	int n = 0;
	bool visited[MXAVERTEX_NUM];
	for (v = 1; v <= G->vexnum; v++)
	{
		visited[v] = false;  //������飬���ͼ���ѷ��ʵĵ�
	}

	EnQueue(Q, a); //a�������;
	while (QueueEmpty(Q) != true)
	{
		DeQueue(Q, &u);
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjvex(G, u, w))
		{
			if (visited[w] == false)//�ж�w�Ƿ��Ѿ����ʹ�
			{
				visited[w] = true;
				EnQueue(Q, w);
			}
			if (w == b)
			{
				break;
			}
		}
		if (w == b)
		{
			break;
		}
	}
	return OK;
}

Status print(LinkQueue *Q, int a)
{
	if (Q->rear->data == a)
	{
		printf("%d->%d\n", a, a);
		return OK;
	}

	int i = 0;
	int j;
	int num[MXAVERTEX_NUM] = { 0 };
	while (Q->rear->data != a)//�����������
	{
		num[i] = Q->rear->data;
		Q->rear = Q->rear->pre;
		i++;
	}
	printf("%d", a);
	for (j = i - 1; j >= 0; j--)
	{
		printf("->%d", num[j]);
	}


	printf("\n");
	return OK;
}

int main()
{
	int i, j;
	MGraph Graph;
	CreateUDN(&Graph);
	for (i = 1; i <= Graph.vexnum; i++)
	{
		for (j = 1; j <= Graph.vexnum; j++)
		{
			LinkQueue Q;
			InitQueue(&Q);
			printf("%d<->%d:  ", i, j);
			BFSTraverse(&Graph, &Q, i, j);
			print(&Q, i);
			DestroyQueue(&Q);

		}
	}
}