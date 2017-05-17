#include <stdio.h>
#include <stdlib.h>

#include"graph.h"
#include"queue.h"

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef enum
{
	false,
	true
}bool;

//----------------图的基本操作-----------------------

//顶点赋值
Status Add(Graph *G, int x, int y)
{
	if (x >= MAX_VERTEX_NUM || y >= MAX_VERTEX_NUM)
	{
		return ERROR;
	}
	G->arcs[x][y].adj = G->arcs[y][x].adj = 1;  //无向图的邻接矩阵是对称的，为无向图顶点赋值，赋值为1
	return OK;
}
//构建图（用数组表示法）
Status CreateGraph(Graph *G)
{
	int i, j;
	G->vexnum = 9;//顶点数
	G->arcnum = 12;//弧数

	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->arcnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;    //初始化邻接矩阵
		}
	}
	Add(G, 0, 1); Add(G, 0, 2); Add(G, 0, 3); Add(G, 0, 6); //Add操作为重复的，用一个函数来包装这个操作
	Add(G, 1, 2); Add(G, 3, 4); Add(G, 3, 5); Add(G, 4, 5); //对于无向图，利用邻接矩阵的对称性，用压缩存储的方式只存入矩阵的上三角
	Add(G, 5, 7); Add(G, 6, 7); Add(G, 6, 8); Add(G, 7, 8);

	return OK;
}
//返回第一个邻接顶点，否则返回-1 
int FirstAdjVex(Graph G, int i)
{
	int k;
	for (k = 0; k < G.vexnum; k++)
	{
		if (G.arcs[i][k].adj == 1) //邻接矩阵同一行中为1的点都是它的邻接点，从0开始遍历，第一个为1的就是邻接点
		{
			return k;
		}
	}
	return -1;
}
//返回下一个邻接顶点，否则返回-1 
int NextAdjVex(Graph G, int i, int j)
{
	int k;
	for (k = j + 1; k < G.vexnum; k++)
	{
		if (G.arcs[i][k].adj == 1)//k从j+1开始，下一个为1的就是它的下一个邻接点 
		{
			return k;
		}
	}
	return -1;
}
//广度优先求路径
void ShortestPath(Graph G, int a, int b)
{
	int u, v, w;
	bool flag = false;
	LinkQueue Q;
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = false; //先初始化访问标志数组为FALSE
	}
	InitQueue(&Q);
	EnQueue(&Q, a);
	visited[a] = true;//访问了a,则将它赋值为TRUE，表示已经被访问
	while (!QueueEmpty(Q))
	{
		DeQueue(&Q, &u);
		for (w = FirstAdjVex(G, u);w >= 0;w = NextAdjVex(G, u, w)) //w为u的邻接点，直到遍历到b时for循环停止
		{
			if (w == b)//找到最小路径输出
			{
				EnQueue(&Q, w);
				PrintFoot(Q, a);
				flag = true;
			}
			if (!visited[w])//若u的邻接点没有被访问
			{
				EnQueue(&Q, w);
				visited[w] = true;
			}
		}

		if (flag)
		{
			break;
		}
	}
}

//输出路径
Status PrintFoot(LinkQueue Q, int start)
{
	int foot[MAX_VERTEX_NUM];
	int i;
	QueuePtr p;
	p = Q.rear;
	for (i = 0;i < MAX_VERTEX_NUM; i++)
	{
		foot[i] = -1;//初始化foot数组
	}
	foot[0] = p->data;
	p = p->prious;
	for (i = 1;p->data != start; i++)
	{
		foot[i] = p->data;
		p = p->prious;
	}
	foot[i] = start;//foot[i] = p->data;
	for (;i >= 0; i--)
	{
		if (foot[i] >= 0)
			printf("%d ", foot[i] + 1);//输出路径
	}
}

//---------------------队列基本操作-----------------
//初始化队列
Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));
	if (!(Q->front))
	{
		return ERROR;
	}
	Q->front->next = Q->rear->next = NULL;
	return OK;
}
//判断是否为空队列 
bool QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}
//入列
Status EnQueue(LinkQueue *Q, int e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
	{
		return ERROR;
	}
	p->data = e;
	p->next = NULL;
	p->prious = Q->front;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
//出列 
Status DeQueue(LinkQueue *Q, int *e)
{
	if (QueueEmpty(*Q))
	{
		return ERROR;
	}
	Q->front = Q->front->next;
	*e = Q->front->data; 
	return OK;
}





int main()
{
	int i, j;
	Graph h;
	CreateGraph(&h);//构建一个无向图，并用邻接矩阵初始化图

	for (i = 0;i < 9; i++)
	{
		for (j = 0;j < 9;j++)
		{
			if (i != j)
			{
				printf("%d -> %d :", i + 1, j + 1);
				ShortestPath(h, i, j);//寻找最短路径
				printf("\n");
			}
		}
	}
	return 0;
}
