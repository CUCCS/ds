#include "hw.h"
void print(int front)//打印队列数组
{
	int k = front;
	int j;
	do
	{
		j = k;
		k = queue[k].c_num;//找上一层顶点
		queue[j].c_num = -1;//将访问过的顶点标注为-1
	} while (k != 0);
	k = 0;
	while (k < Max)
	{
		if (queue[k].c_num == -1)
		{
			printf("%d ", queue[k].vertex + 1);
		}
		k++;
	}
}
//初始化邻接矩阵
void CreateGraph(Graph **g, int array[][Max], int k)//使用**g方便改变g的内存
{
	(*g) = (Graph *)malloc(sizeof(Graph));//分配内存
	int i, j;
	for (i = 0; i < k; i++)
	{
		(*g)->a[i] = NULL;//初始化结构体指针
	}
	Node *p;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (array[i][j] != 0)//如果是通路
			{
				p = (Node*)malloc(sizeof(Node));
				p->num = j;
				p->next = (*g)->a[i];
				(*g)->a[i] = p;
			}
		}
	}
}
//求最短路径
void shortest_path(Graph *g, int i, int j, int *visit)
{
	Node *p;
	int  m;
	int find = 0;
	rear++;
	int n;
	//初始化队列
	for (n = 0; n < Max; n++)
	{
		queue[n].vertex = 0;
		queue[n].c_num = 0;
	}
	queue[rear].vertex = i;//起点
	queue[rear].c_num = -1;//标记该点
	visit[i] = 1;//把该点设置为已经访问过
	while (front != rear && !find)
	{
		front++;
		m = queue[front].vertex;//从队列中依次搜索起点
		if (m == j)//如果找到终点
		{
			find = 1;
			print(front);
			return;
		}
		p = g->a[m];//起点后面的数据
		while (p != NULL)
		{
			//广度优先遍历
			if (visit[p->num] == 0)
			{
				visit[p->num] = 1;
				rear++;
				queue[rear].vertex = p->num;
				queue[rear].c_num = front;
			}
			p = p->next;
		}
	}
}
int main()
{
	int Array[][Max] = {
		{ 1,1,1 ,1,0,0, 1,0,0 },
		{ 1,1,1 ,0,0,0, 0,0,0 },
		{ 1,1,1, 0,0,0, 0,0,0 },
		{ 1,0,0, 1,1,1, 0,0,0 },
		{ 0,0,0, 1,1,1, 0,0,0 },
		{ 0,0,0, 1,1,1, 0,1,0 },
		{ 1,0,0, 0,0,0, 1,1,1 },
		{ 0,0,0 ,0,0,1, 1,1,1 },
        { 0,0,0 ,0,0,0, 1,1,1 }
	};
	Graph *g;
	CreateGraph(&g, Array, Maxnum);
	int i, j;
	for (i = 0; i < 9; i++)
	{
		printf("\n");
		for (j = 0; j < 9; j++)
		{
			if (i == j)
			{

			}
			else
			{
				front = rear = -1;
				int visit[Max] = { 0 };
				printf("%d<->%d  ", i + 1, j + 1);
				shortest_path(g, i, j, visit);
				printf("\n");
			}
		}
	}
	for (i = 0; i < Maxnum; i++)
	{
		Node *p, *q;
		p = g->a[i];
		while (p != NULL)
		{
			q = p;
			p = p->next;
			free(q);
		}
	}
	return 0;
}