#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100//最大存储
#define MAXNUM 10//已知图点数
typedef struct node
{
	int number;//存储顶点
	struct node *next;//指针
}node, *vertexnode;//基本图元素
typedef struct
{
	vertexnode ad[MAXSIZE];//静态分配数组存储信息
}Graph;//图的构成
struct queue//设置队列，用于存储可通路径顶点的信息
{
	int vertex;//顶点
	int pre_num;//第几层
}queue[MAXSIZE];
int  front, rear;
void  print(int front);//用于打印队列数组
void CreateGraph(Graph **g, int array[][MAXSIZE], int k);//头插法初始化邻接矩阵
void shortest_path(Graph *g, int v, int u, int *visited);//求最短路径