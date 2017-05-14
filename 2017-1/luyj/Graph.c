#include "Graph.h"


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

Status LocateVex(MGraph *G,int v1,int v2)
{
	int i;
	int j;
	int m = 0;
	int n = 0;
	for (i = 0; i <= G->vexnum; i++)
	{
		if (G->vexs[i]==v1)
		{
			m = i;
			break;
		}
	}
	for (j = 0; j <= G->vexnum; j++)
	{
		if (G->vexs[j] == v2)
		{
			n = j;
			break;
		}
	}
	G->arcs[i][j].adj = 1;//����֮�������ߣ���ֵΪ1;
	G->arcs[j][i] = G->arcs[i][j];
	return OK;
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
		LocateVex(G, 1, 2);
		LocateVex(G, 1, 3);
		LocateVex(G, 1, 4);
		LocateVex(G, 1, 7);
		LocateVex(G, 2, 3);
		LocateVex(G, 4, 5);
		LocateVex(G, 4, 6);
		LocateVex(G, 5, 6);
		LocateVex(G, 6, 8);
		LocateVex(G, 7, 8);
		LocateVex(G, 7, 9);
		LocateVex(G, 8, 9);

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
Status BFSTraverse(MGraph*G, LinkQueue *Q,int a,int b)
{
	
	int v;
	int u = 0;
	int w = 0;
	int m = 0;
	int n = 0;
	bool visited[MAX_VERTEX_NUM];
	for (v = 1; v <= G->vexnum; v++)
	{
		visited[v] = false;  //������飬���ͼ���ѷ��ʵĵ�
	}
	
	EnQueue(Q, a); //a�������;
	while (QueueEmpty(Q)!= true)
	{
		DeQueue(Q, &u);
		for (w = FirstAdjVex(G, u); w >=0; w = NextAdjvex(G, u, w))
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
}

Status print(LinkQueue *Q,int a)
{
	if (Q->rear->data == a)
	{
		printf("%d->%d\n", a, a);
		return OK;
	}

	int i = 0;
	int j;
	int num[MAX_VERTEX_NUM] = { 0 };
	while (Q->rear->data!=a)//�����������
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


