//广大度优先遍历求示例无向图中两点间最短距离（用邻接矩阵）
#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100//最大存储
#define MAX_VERTEX 20//图顶点数

typedef struct node//定义图
{
	int data;//顶点存储数据
	struct node *next;
}node, *vexnode;

typedef struct
{
	vexnode ad[MAXSIZE];//静态分配数组存储信息
}Graph;//图的构成

//定义辅助队列数组用来存储路径信息
struct queue
{
	int vertex;//顶点
	int pre_num;//第几层
}queue[MAXSIZE];

int front, rear;

void print(int front)//用于打印队列数组
{
	while (front != 0)
	{
		int b = front;
		front = queue[front].pre_num;
		queue[b].pre_num = -1;//访问过后标记为-1
	}
	front = 0;//front置0
	while (front<MAXSIZE)
	{
		if (queue[front].pre_num == -1)//输出路径
		{
			printf("%d ", queue[front].vertex + 1);
		}
		front++;
	}
}

//创建图
void CreateGraph(Graph **g, int array[][MAXSIZE])//头插法初始化邻接矩阵
{
	(*g) = (Graph *)malloc(sizeof(Graph));
	for (int i = 0; i<MAX_VERTEX; i++)
	{
		(*g)->ad[i] = NULL;//分别初始化结构体指针
	}
	int c = 0;
	node *p;
	int j;
	for (int i = 0; i<MAX_VERTEX; i++)
	{//分行
		for (j = 0; j<MAX_VERTEX; j++)
		{//分段
			if (array[i][j] != 0)//如果是通路分配内存并存储
			{
				p = (node *)malloc(sizeof(node));//分配内存
				p->data = j;
				p->next = (*g)->ad[i];
				(*g)->ad[i] = p;//头插法构建邻接矩阵
			}
		}
	}
}

//广度优先遍历查找最短路径
void shortest_path(Graph *g, int v, int u, int *visited)
{
	node *p;
	int m;
	int find = 0;//find为flag，标记是否找到
	rear++;
	for (int a = 0; a < MAXSIZE; a++)//初始化队列
	{
		queue[a].vertex = 0;
		queue[a].pre_num = 0;
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
			find = 1;//find标识已找到
			print(front);
			return;//返回
		}
		p = g->ad[m];//起点后面跟的数据
		while (p != NULL)
		{//广度优先遍历
			if (visited[p->data] == 0)//如果没有访问过
			{
				visited[p->data] = 1;//标识已访问
				rear++;
				queue[rear].vertex = p->data;
				queue[rear].pre_num = front;
			}
			p = p->next;//遍历下一个
		}
	}
}
int main()
{
	int graph_array[][MAXSIZE] = {

	{0,1,1,1,0,0,1,0,0},
	{1,0,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0,0},
	{1,0,0,0,1,1,0,0,0},
	{0,0,0,1,0,1,0,0,0},
	{0,0,0,1,1,0,0,1,0},
	{1,0,0,0,0,0,0,1,1},
	{0,0,0,0,0,1,1,0,1},
	{0,0,0,0,0,0,1,1,0}
		
	};
	
	Graph *g;
	CreateGraph(&g, graph_array);
	for (int i = 0; i < 9; i++)
	{
		
		for (int j = i+1; j < 9; j++)
		{
				front = -1;//初始化front 
				rear = -1;//初始化rear 
				int visited[MAXSIZE] = { 0 };//初始化 visit
				printf("%d<->%d： ", i + 1, j + 1);//输出 
				shortest_path(g, i, j, visited);//求最短路径 
				printf("\n");
			
		}
		printf("\n");
	}
	for (int i = 0; i < MAX_VERTEX; i++)
	{	//释放内存
		node *p;
		node *q;
		p = g->ad[i];
		while (p != NULL)//当p不为空时 
		{
			q = p;//令q=p 
			p = p->next;//p指向下一个数据 
			free(q);//释放q的内存 
		}
	}
	return 0;
}