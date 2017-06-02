//参考jackcily的作业
#include <stdio.h>
#include <malloc.h>

#define Max 100  //矩阵最大容量
#define Maxnum 10 //已知图点数

//图的邻接矩阵存储
typedef struct Node
{
	int num;//存储顶点
	struct Node *next;
}Node,*vertexnode;
typedef struct 
{
	vertexnode a[Max];
}Graph;
//设置队列用于存储通过路径顶点的信息
struct queue
{
	int vertex;//顶点
	int c_num;//层数
}queue[Max];
int front, rear;//定义全局变量用来计数遍历过的顶点
void print(int front);//打印队列数组
void CreateGraph(Graph **g, int array[][Max], int k);//初始化邻接矩阵
void shortest_path(Graph *g, int i, int j, int *visit);//求最短路径