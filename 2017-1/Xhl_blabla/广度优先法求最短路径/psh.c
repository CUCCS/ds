#include "psh.h"
void  print(int front)
{
	int k = front, j;
	do
	{
		j = k;
		k = queue[k].pre_num;//循环寻找上一个点
		queue[j].pre_num = -1;//访问过后标记
	} while (k != 0);
	k = 0;
	while (k<MAXSIZE)
	{
		if (queue[k].pre_num == -1)//如果是路径就输出
		{
			printf("%d ", queue[k].vertex + 1);
		}
		k++;
	}
}
void CreateGraph(Graph **g, int array[][MAXSIZE], int k)//k是初始化的数值大小
{
	(*g) = (Graph *)malloc(sizeof(Graph));//分配内存
	for (int i = 0; i<k; i++)
	{
		(*g)->ad[i] = NULL;//初始化结构体指针
	}
	int  c = 0;
	node *p;
	int i;
	int j;
	for (i = 0; i<k; i++)
	{
		for (j = 0; j<k; j++)
		{
			if (array[i][j] != 0)//如果是通路分配内存并存储
			{
				p = (node *)malloc(sizeof(node));//分配内存
				p->number = j;
				p->next = (*g)->ad[i];
				(*g)->ad[i] = p;//头插法构建邻接矩阵
			}
		}
	}
}
void shortest_path(Graph *g, int v, int u, int *visited)
{
	node *p;
	int m;
	int find = 0;
	rear++;
	int nn;
	for (nn = 0; nn < MAXSIZE; nn++)//初始化队列
	{
		queue[nn].vertex = 0;
		queue[nn].pre_num = 0;
	}
	queue[rear].vertex = v;//起点
	queue[rear].pre_num = -1;//标记该点
	visited[v] = 1;//把该点设为已经访问过
	while (front != rear && !find)
	{
		front++;
		m = queue[front].vertex;//搜索的起点从队列依次搜索
		if (m == u)//如果找到了终点
		{
			find = 1;
			print(front);
			return;
		}
		p = g->ad[m];//起点后面跟的数据  
		while (p != NULL)
		{//广度优先遍历
			if (visited[p->number] == 0)//如果没有访问过
			{
				visited[p->number] = 1;
				rear++;
				queue[rear].vertex = p->number;
				queue[rear].pre_num = front;
			}
			p = p->next;
		}
	}
}
int main()
{//用二维数组存储用例邻接矩阵的信息
	int graph_array[][MAXSIZE] = {
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
	CreateGraph(&g, graph_array, MAXNUM);//初始化临接矩阵
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
				front = -1, rear = -1;
				int visited[MAXSIZE] = { 0 };//初始化 visit
				printf("%d<->%d    ", i + 1, j + 1);
				shortest_path(g, i, j, visited);
				printf("\n");
			}
		}
	}
	//释放堆上的内存
	for (i = 0; i < MAXNUM; i++)
	{
		node *p;
		node *q;
		p = g->ad[i];
		while (p != NULL)
		{
			q = p;
			p = p->next;
			free(q);	
		}
	}
	return 0;
}



