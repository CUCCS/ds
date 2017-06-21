#include "Graph.h"

Status CreateGraph(Graph *G)
{
	int i, j, k;  //计数标志
	G->vexnum = 9;  //已知图有9个顶点
	G->arcnum = 12;  //已知图有12条弧
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = INT_MAX;   //初始化邻接矩阵，所有顶点不相连
		}
	}
	
	return OK;
}
Status Connect(Graph*G, int a, int b)
{
	G->arcs[a][b].adj = G->arcs[b][a].adj = 1;  //相连的顶点值为1，无向图双向设置
	return OK;
}

void BFSTraverse(Graph G, int a, int b)
{
	int u, v, w;
	bool flag=false;
	LinkQueue Q;  
	for (v = 0; v < G.vexnum; ++v) 
	{
		visited[v] = false;  //初始化访问标志
	}
	InitQueue(&Q);      // 置空队列Q
	EnQueue(&Q, a);   //a入列
	visited[a] = true;
	while (!QueueEmpty(Q)) 
	{
		DeQueue(&Q, &u);      //队头元素出队并置为u
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) //w为u的尚未访问的邻接顶点
		{
			if (w == b)   //如果w和b的值相等
			{
				EnQueue(&Q, w);  // w入队列
				Show(Q, a);  //输出最短路径                             
				flag = true;
				break;                                                           
			}
			if (!visited[w])
			{
				EnQueue(&Q, w);
				Visit(w);
			}
		}
		if (flag)
		{
			break;
		}
	}

}
	

ElemType FirstAdjVex(Graph G, int i)
{
	int j;
	for (j = 0; j < G.vexnum; j++) 
	{
		if (G.arcs[i][j].adj == 1) 
		{
			return j;
		}
	}
	return -1;
}
ElemType NextAdjVex(Graph G, int i, int j)
{
	int k;
	for (k = j+1; k < G.vexnum; k++)
	{
		if (G.arcs[i][k].adj == 1)
		{
			return k;
		}
	}
	return -1;
}

Status Show(LinkQueue Q, int start)
{
	int path[MAX_VERTEX_NUM];
	int i;
	QueuePtr p;
	p = Q.rear;    //p指针指向队列的尾部
	for (i = 0; i < MAX_VERTEX_NUM; i++)   //初始化数组
	{
		path[i] = -1;
	}
	/*path[0] = p->data;
	p = p->priou;*/
	for (i = 0; p->data != start; i++)
	{
		path[i] = p->data;
		p = p->priou;
	}
	path[i] = p->data;    //从队尾依次向前赋值

	for (; i >= 0; i--)      //从队尾倒序输出
	{
		if (path[i] >= 0)
		{
			printf("%d ", path[i] + 1);   //从0开始所以最后结果要+1（顶点为1,2,3.....)
		}
	}
	return OK;
}

Status Print(Graph G)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (j != i)
			{
				printf("%d<->%d:", i + 1, j + 1);   //计数从0开始
				BFSTraverse(G, i, j);
				printf("\n");
			}
		}
	}
}
