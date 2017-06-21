#include "Graph.h"

Status CreateGraph(Graph *G)
{
	int i, j, k;  //������־
	G->vexnum = 9;  //��֪ͼ��9������
	G->arcnum = 12;  //��֪ͼ��12����
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = INT_MAX;   //��ʼ���ڽӾ������ж��㲻����
		}
	}
	
	return OK;
}
Status Connect(Graph*G, int a, int b)
{
	G->arcs[a][b].adj = G->arcs[b][a].adj = 1;  //�����Ķ���ֵΪ1������ͼ˫������
	return OK;
}

void BFSTraverse(Graph G, int a, int b)
{
	int u, v, w;
	bool flag=false;
	LinkQueue Q;  
	for (v = 0; v < G.vexnum; ++v) 
	{
		visited[v] = false;  //��ʼ�����ʱ�־
	}
	InitQueue(&Q);      // �ÿն���Q
	EnQueue(&Q, a);   //a����
	visited[a] = true;
	while (!QueueEmpty(Q)) 
	{
		DeQueue(&Q, &u);      //��ͷԪ�س��Ӳ���Ϊu
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) //wΪu����δ���ʵ��ڽӶ���
		{
			if (w == b)   //���w��b��ֵ���
			{
				EnQueue(&Q, w);  // w�����
				Show(Q, a);  //������·��                             
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
	p = Q.rear;    //pָ��ָ����е�β��
	for (i = 0; i < MAX_VERTEX_NUM; i++)   //��ʼ������
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
	path[i] = p->data;    //�Ӷ�β������ǰ��ֵ

	for (; i >= 0; i--)      //�Ӷ�β�������
	{
		if (path[i] >= 0)
		{
			printf("%d ", path[i] + 1);   //��0��ʼ���������Ҫ+1������Ϊ1,2,3.....)
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
				printf("%d<->%d:", i + 1, j + 1);   //������0��ʼ
				BFSTraverse(G, i, j);
				printf("\n");
			}
		}
	}
}
