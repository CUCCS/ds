#include "Graph.h"


/*=========队列的基本操作=========*/
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
/*=========图的基本操作=========*/

Status InsertArc(MGraph *g,int v1,int v2)
{
	int i = 0;
	int j = 0;
	if (LocateVex(g, v1, &i) == TRUE && LocateVex(g, v2, &j) == TRUE)
	{
		g->arcs[i][j].adj = 1;//两点之间有连线，弧值为1;
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

//构建图
Status CreateUDN(MGraph *g)
{
	int i;
	int j;
	//根据用例直接赋值。
	g->vexnum = 9;
	g->arcnum = 12;
	for (i = 1; i <= g->vexnum; i++)
	{
		g->vexs[i] = i;//构建顶点向量;
	}
	for (i = 0; i <= g->vexnum; i++)//初始化邻接矩阵;
	{
		for (j = 0; j <= g->vexnum; j++)
		{
			g->arcs[i][j].adj = INFINITY;
			g->arcs[i][j].info = NULL;
		}
	}
	//构建邻接矩阵;
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

//找出第一个邻接点
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

//找出下一个邻接点
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
//广度优先遍历图,求两点a,b间的最短路径;
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
		visited[v] = FALSE;  //标记数组，标记图中已访问的点
	}
	
	EnQueue(q, a); //a先入队列;
	while (QueueEmpty(q)!= TRUE)
	{
		DeQueue(q, &u);
		for (w = FirstAdjVex(g, u); w >=0; w = NextAdjvex(g, u, w))
		{
			if (visited[w] == FALSE)//判断w是否已经访问过
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
	while (q->rear->data!=a)//倒序进入数组
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


