#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100//最大存储
#define MAX_VERTEX_NUM 20//图点数
typedef struct node//基本图元素
{
	int number;//存储顶点
	struct node *next;//指针
}node, *vexnode;
typedef struct
{
	vexnode ad[MAXSIZE];//静态分配数组存储信息
}Graph;//图的构成
struct queue//设置队列，用于存储可通路径顶点的信息
{
	int vertex;//顶点
	int pre_num;//第几层
}queue[MAXSIZE];
int front, rear;
void print(int front)//用于打印队列数组
{
	while (front != 0)
	{
		int b = front;//保证不会出现歧义，新设一个变量b
		front = queue[front].pre_num;//循环寻找上一个点
		queue[b].pre_num = -1;//访问过后标记为-1
	}
	front = 0;//将front置为0
	while (front<MAXSIZE)//保证不溢出数据
	{
		if (queue[front].pre_num == -1)//如果是路径就输出
		{
			printf("%d ", queue[front].vertex + 1);//输出路径
		}
		front++;//往下进行
	}
}//print
void CreateGraph(Graph **g, int array[][MAXSIZE])//头插法初始化邻接矩阵
{
	(*g) = (Graph *)malloc(sizeof(Graph));//分配内存
	for (int i = 0; i<MAX_VERTEX_NUM; i++)
	{
		(*g)->ad[i] = NULL;//分别初始化结构体指针
	}
	int c = 0;
	node *p;
	int j;
	for (int i = 0; i<MAX_VERTEX_NUM; i++)
	{//分行
		for (j = 0; j<MAX_VERTEX_NUM; j++)
		{//分段
			if (array[i][j] != 0)//如果是通路分配内存并存储
			{
				p = (node *)malloc(sizeof(node));//分配内存
				p->number = j;
				p->next = (*g)->ad[i];
				(*g)->ad[i] = p;//头插法构建邻接矩阵
			}
		}
	}
}//CreateGraph
void shortest_path(Graph *g, int v, int u, int *visited)//求最短路径
{
	node *p;
	int m;
	int find = 0;//find为标识
	rear++;//rear自加
	for (int a = 0; a < MAXSIZE; a++)//初始化队列
	{
		queue[a].vertex = 0;//顶点
		queue[a].pre_num = 0;//第几行
	}
	queue[rear].vertex = v;//起点
	queue[rear].pre_num = -1;//标记该点
	visited[v] = 1;//把该点设为已经访问过
	while (front != rear && !find)//首不是尾
	{
		front++;//front自加
		m = queue[front].vertex;//搜索的起点从队列依次搜索
		if (m == u)//如果找到了终点
		{
			find = 1;//find置为1
			print(front);//输出front
			return;//返回
		}
		p = g->ad[m];//起点后面跟的数据
		while (p != NULL)
		{//广度优先遍历
			if (visited[p->number] == 0)//如果没有访问过
			{
				visited[p->number] = 1;//置为1
				rear++;//rear自加
				queue[rear].vertex = p->number;//顶点
				queue[rear].pre_num = front;//行
			}
			p = p->next;//指向下一个，继续遍历
		}
	}
}//shortest_path