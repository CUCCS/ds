#include <stdio.h>
#include <malloc.h>

#define MAXQSIZE 100       //最大值
#define MAX_VERTEX_NUM 20  //最大顶点数
#define INFINITY 10000000  //最大值
#define	OK 1
int visited[MAX_VERTEX_NUM];//访问标志数组


typedef struct ArcCell // 弧的定义
{
	int  adj;    // 用1或0表示是否相邻
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct// 图的定义
{
	AdjMatrix  arcs;            // 弧的信息                     
	int vexnum, arcnum;       // 顶点数，弧数    
} Graph;

typedef struct QNode
{
	int data;
	struct QNode *priou;
	struct QNode *next;
}QNode, LinkList, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//队列基本操作

int InitQueue(LinkQueue *Q)//初始化队列
{
	Q->front = Q->rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));//分配队列空间
	if (!(Q->front))
	{
		return 0;
	}
	Q->front->next = Q->rear->next = NULL;
	return OK;
}

int EnQueue(LinkQueue *Q, int e)//入队列
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
	{
		return 0;
	}
	p->data = e;
	p->next = NULL;
	p->priou = Q->front;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

int QueueEmpty(LinkQueue Q)//判断队列是否为空
{
	if (Q.front == Q.rear)
	{
		return 1;
	}
	return 0;
};

int DeQueue(LinkQueue *Q, int *e)//出队列
{
	if (QueueEmpty(*Q)) //队列为空
	{
		return 0;
	}
	Q->front = Q->front->next;
	*e = Q->front->data;
	return OK;
}

//图的操作

int FirstAdjVex(Graph G, int i)//返回第一个邻接顶点，若无则返回-1
{
	int k;
	for (k = 0; k < G.vexnum; k++)
	{
		if (G.arcs[i][k].adj == 1)
		{
			return k;
		}
	}
	return -1;
}

int NextAdjVex(Graph G, int i, int j)//返回下一个邻接顶点，若无则返回-1
{
	int k;
	for (k = j + 1; k < G.vexnum; k++)
	{
		if (G.arcs[i][k].adj == 1)
		{
			return k;
		}
	}
	return -1;
}

int Add(Graph*G, int x, int y) ////构造邻接矩阵并赋值
{
	if (x >= MAX_VERTEX_NUM || y >= MAX_VERTEX_NUM)
	{
		return 0;
	}
	G->arcs[x][y].adj = G->arcs[y][x].adj = 1;//相邻则赋值为1
	return OK;
}

int CreateGraph(Graph *G) //构建已知图
{
	int i, j;
	G->vexnum = 9;   //顶点
	G->arcnum = 12;  //边
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;  //初始化邻接矩阵,INFINITY表示不相邻
		}
	}
	//初始化图,相邻顶点赋值
	Add(G, 0, 1); Add(G, 0, 2); Add(G, 0, 3); Add(G, 0, 6);
	Add(G, 1, 2); Add(G, 3, 4); Add(G, 3, 5); Add(G, 4, 5);
	Add(G, 5, 7); Add(G, 6, 7); Add(G, 6, 8); Add(G, 7, 8);
	return OK;
}

void PrintFoot(LinkQueue Q, int start)//输出顶点间最短路径
{
	int i;
	int foot[MAX_VERTEX_NUM];
	QueuePtr p;
	p = Q.rear;
	for (i = 0; i < MAX_VERTEX_NUM; i++)
	{
		foot[i] = -1;
	}
	foot[0] = p->data;
	p = p->priou;
	for (i = 1; p->data != start; i++)
	{
		foot[i] = p->data;
		p = p->priou;
	}
	foot[i] = p->data;
	for (; i >= 0; i--) //倒序输出
	{
		if (foot[i] >= 0)
		{
			printf("%d ", foot[i] + 1);
		}
	}
}

void BFSTraverse(Graph G, int a, int b) //广度优先遍历
{
	LinkQueue Q;  //辅助队列Q
	int i = 0;
	int flag = 0;

	for (int j = 0; j < G.vexnum; ++j)
	{
		visited[j] = 0;  //初始化访问标志
	}
	InitQueue(&Q);  // 初始化辅助队列Q
	EnQueue(&Q, a);  //起点入队列
	visited[a] = 1;
	while (!QueueEmpty(Q)) //队列不为空
	{
		DeQueue(&Q, &i);
		for (int k = FirstAdjVex(G, i); k >= 0; k = NextAdjVex(G, i, k))//相邻顶点入队列
		{
			if (k == b)
			{
				EnQueue(&Q, k);
				PrintFoot(Q, a);  //输出顶点间最短路径
				flag = 1;
				break;
			}
			if (!visited[k])
			{
				EnQueue(&Q, k);
				visited[k] = 1;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

void main()
{
	int i, j;
	Graph G;
	CreateGraph(&G);
	printf("各顶点间最短路径依次为:\n\n");
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j != i)
			{
				printf("%d<->%d:", i + 1, j + 1);
				BFSTraverse(G, i, j);
				printf("\n");
			}
		}
	}
}