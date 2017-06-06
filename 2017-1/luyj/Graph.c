#include "Graph.h"


/*=========���еĻ�������=========*/
Status InitQueue(LinkQueue *q)
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)
	{
		return ERROR;
	}
	q->front->next = q->rear->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue*q, QElemType e)
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
		p->pre = q->front;
		q->rear->next = p;
		q->rear = p;
	}
}

Status DeQueue(LinkQueue*q, QElemType*e)
{
	if (q->front == q->rear)
	{
		return ERROR;
	}
	q->front = q->front->next;
	*e = q->front->data;
	return OK;
}

bool QueueEmpty(LinkQueue*q)
{
	if (q->front == q->rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status DestroyQueue(LinkQueue*q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	return OK;
}
/*=========ͼ�Ļ�������=========*/

Status InsertArc(MGraph *g,int v1,int v2)
{
	int i = 0;
	int j = 0;
	if (LocateVex(g, v1, &i) == TRUE && LocateVex(g, v2, &j) == TRUE)
	{
		g->arcs[i][j].adj = 1;//����֮�������ߣ���ֵΪ1;
		g->arcs[j][i] = g->arcs[i][j];
	}
}
bool LocateVex(MGraph *g,int v,int *i)
{
	int m;
	for (m = 0; m <= g->vexnum; m++)
	{
		if (g->vexs[m]==v)
		{
			*i = m;
			return TRUE;
		}
	}
	return FALSE;
}

//����ͼ
Status CreateUDN(MGraph *g)
{
	int i;
	int j;
	//��������ֱ�Ӹ�ֵ��
	g->vexnum = 9;
	g->arcnum = 12;
	for (i = 1; i <= g->vexnum; i++)
	{
		g->vexs[i] = i;//������������;
	}
	for (i = 0; i <= g->vexnum; i++)//��ʼ���ڽӾ���;
	{
		for (j = 0; j <= g->vexnum; j++)
		{
			g->arcs[i][j].adj = INFINITY;
			g->arcs[i][j].info = NULL;
		}
	}
	//�����ڽӾ���;
		InsertArc(g, 1, 2);
		InsertArc(g, 1, 3);
		InsertArc(g, 1, 4);
		InsertArc(g, 1, 7);
		InsertArc(g, 2, 3);
		InsertArc(g, 4, 5);
		InsertArc(g, 4, 6);
		InsertArc(g, 5, 6);
		InsertArc(g, 6, 8);
		InsertArc(g, 7, 8);
		InsertArc(g, 7, 9);
		InsertArc(g, 8, 9);

		return OK;
}

//�ҳ���һ���ڽӵ�
int FirstAdjVex(MGraph *g, int u)
{
	int i;
	for (i = 1; i <= g->vexnum; i++)
	{
		if (g->arcs[u][i].adj == 1)
		{
			return i;
		}
	}
	return -1;
}

//�ҳ���һ���ڽӵ�
int NextAdjvex(MGraph *g, int u, int w)
{
	int i;
	for (i = w + 1; i <= g->vexnum; i++)
	{
		if (g->arcs[u][i].adj == 1)
		{
			return i;
		}
	}
	return -1;
}
//������ȱ���ͼ,������a,b������·��;
Status BFSTraverse(MGraph*g, LinkQueue *q,int a,int b)
{
	
	int v;
	int u = 0;
	int w = 0;
	int m = 0;
	int n = 0;
	bool visited[MAX_VERTEX_NUM];
	for (v = 1; v <= g->vexnum; v++)
	{
		visited[v] = FALSE;  //������飬���ͼ���ѷ��ʵĵ�
	}
	
	EnQueue(q, a); //a�������;
	while (QueueEmpty(q)!= TRUE)
	{
		DeQueue(q, &u);
		for (w = FirstAdjVex(g, u); w >=0; w = NextAdjvex(g, u, w))
		{
			if (visited[w] == FALSE)//�ж�w�Ƿ��Ѿ����ʹ�
			{
				visited[w] = TRUE;
				EnQueue(q, w); 
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

Status print(LinkQueue *q,int a)
{
	if (q->rear->data == a)
	{
		printf("%d->%d\n", a, a);
		return OK;
	}

	int i = 0;
	int j;
	int num[MAX_VERTEX_NUM] = { 0 };
	while (q->rear->data!=a)//�����������
	{
		num[i] = q->rear->data;
		q->rear = q->rear->pre;
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


