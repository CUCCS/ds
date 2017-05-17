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

//----------------ͼ�Ļ�������-----------------------

//���㸳ֵ
Status Add(Graph *G, int x, int y)
{
	if (x >= MAX_VERTEX_NUM || y >= MAX_VERTEX_NUM)
	{
		return ERROR;
	}
	G->arcs[x][y].adj = G->arcs[y][x].adj = 1;  //����ͼ���ڽӾ����ǶԳƵģ�Ϊ����ͼ���㸳ֵ����ֵΪ1
	return OK;
}
//����ͼ���������ʾ����
Status CreateGraph(Graph *G)
{
	int i, j;
	G->vexnum = 9;//������
	G->arcnum = 12;//����

	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->arcnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;    //��ʼ���ڽӾ���
		}
	}
	Add(G, 0, 1); Add(G, 0, 2); Add(G, 0, 3); Add(G, 0, 6); //Add����Ϊ�ظ��ģ���һ����������װ�������
	Add(G, 1, 2); Add(G, 3, 4); Add(G, 3, 5); Add(G, 4, 5); //��������ͼ�������ڽӾ���ĶԳ��ԣ���ѹ���洢�ķ�ʽֻ��������������
	Add(G, 5, 7); Add(G, 6, 7); Add(G, 6, 8); Add(G, 7, 8);

	return OK;
}
//���ص�һ���ڽӶ��㣬���򷵻�-1 
int FirstAdjVex(Graph G, int i)
{
	int k;
	for (k = 0; k < G.vexnum; k++)
	{
		if (G.arcs[i][k].adj == 1) //�ڽӾ���ͬһ����Ϊ1�ĵ㶼�������ڽӵ㣬��0��ʼ��������һ��Ϊ1�ľ����ڽӵ�
		{
			return k;
		}
	}
	return -1;
}
//������һ���ڽӶ��㣬���򷵻�-1 
int NextAdjVex(Graph G, int i, int j)
{
	int k;
	for (k = j + 1; k < G.vexnum; k++)
	{
		if (G.arcs[i][k].adj == 1)//k��j+1��ʼ����һ��Ϊ1�ľ���������һ���ڽӵ� 
		{
			return k;
		}
	}
	return -1;
}
//���������·��
void ShortestPath(Graph G, int a, int b)
{
	int u, v, w;
	bool flag = false;
	LinkQueue Q;
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = false; //�ȳ�ʼ�����ʱ�־����ΪFALSE
	}
	InitQueue(&Q);
	EnQueue(&Q, a);
	visited[a] = true;//������a,������ֵΪTRUE����ʾ�Ѿ�������
	while (!QueueEmpty(Q))
	{
		DeQueue(&Q, &u);
		for (w = FirstAdjVex(G, u);w >= 0;w = NextAdjVex(G, u, w)) //wΪu���ڽӵ㣬ֱ��������bʱforѭ��ֹͣ
		{
			if (w == b)//�ҵ���С·�����
			{
				EnQueue(&Q, w);
				PrintFoot(Q, a);
				flag = true;
			}
			if (!visited[w])//��u���ڽӵ�û�б�����
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

//���·��
Status PrintFoot(LinkQueue Q, int start)
{
	int foot[MAX_VERTEX_NUM];
	int i;
	QueuePtr p;
	p = Q.rear;
	for (i = 0;i < MAX_VERTEX_NUM; i++)
	{
		foot[i] = -1;//��ʼ��foot����
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
			printf("%d ", foot[i] + 1);//���·��
	}
}

//---------------------���л�������-----------------
//��ʼ������
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
//�ж��Ƿ�Ϊ�ն��� 
bool QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}
//����
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
//���� 
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
	CreateGraph(&h);//����һ������ͼ�������ڽӾ����ʼ��ͼ

	for (i = 0;i < 9; i++)
	{
		for (j = 0;j < 9;j++)
		{
			if (i != j)
			{
				printf("%d -> %d :", i + 1, j + 1);
				ShortestPath(h, i, j);//Ѱ�����·��
				printf("\n");
			}
		}
	}
	return 0;
}
