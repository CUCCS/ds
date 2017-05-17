#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define MAX_VERTEX_NUM 100
#define INFINITY INT_MAX    //表示两个顶点不相连，值为无穷
#define Visit(x) {visited[x]=true;}


bool visited[MAX_VERTEX_NUM];

typedef int VRType;

typedef struct ArcCell   // 弧的定义
{ 
	VRType  adj;     // VRType是顶点关系类型。
					 // 对无权图，用1或0表示相邻否；
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct   // 图的定义
{ 
	AdjMatrix  arcs;                 // 弧的信息                     
	int   vexnum, arcnum;       // 顶点数，弧数                
} Graph;

Status CreateGraph(Graph *G);  //构建一个无向图

Status Connect(Graph*G, int x, int y);  //为邻接矩阵赋值,建立顶点之间的连接关系

void BFSTraverse(Graph G, int a, int b);  //广度优先遍历图

ElemType FirstAdjVex(Graph G, int i);  //返回顶点i的第一个邻接顶点

ElemType NextAdjVex(Graph G, int i, int j);  //返回顶点i的下一个邻接顶点

Status Show(LinkQueue Q, int start);  //输出两个顶点间的最短路径

Status Print();  //打印最后结果

