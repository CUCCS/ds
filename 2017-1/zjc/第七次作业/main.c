#include<stdio.h>  
#include<stdlib.h> 
#include <malloc.h>  

#define INFINITY INT_MAX //最大值为无穷
#define MAX_VERTEX_NUM 20 //最大顶点数

typedef enum {
	DG,DN,UGD,UDN
}GraphKind;//{有向图，有向网，无向图，无向网}

typedef int VRType, InfoType;

typedef struct ArcCell {
	VRType adj;//VRType是顶点关系类型，对无权图，用1或0
	            //表示相邻否；对有权图，则为权值类型
	InfoType *info;//该弧相关信息的指针
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	AdjMatrix  arcs;                 // 邻接矩阵                      
	int        vexnum, arcnum;       // 图的当前顶点数和弧数  
}Graph;

typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;

Status CreateGraph(Graph *G) {
	//采用邻接矩阵法表示法，构建已知的图
	G->vexnum = 9;   //该图的顶点数 
	G->arcnum = 12;  //该图的弧数
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = INFINITY;  //初始化邻接矩阵,INFINITY表示不相邻 
		}
	}//初始化图
	//相邻的顶点赋值
	Add(G, 0, 1); Add(G, 0, 2); Add(G, 0, 3); Add(G, 0, 6);
	Add(G, 1, 2); Add(G, 3, 4); Add(G, 3, 5); Add(G, 4, 5);
	Add(G, 5, 7); Add(G, 6, 7); Add(G, 6, 8); Add(G, 7, 8);
	//表示0-1,0-2.。。。。。相邻
	return OK;
}

Status Add(Graph*G, int x, int y) {
	//构造邻接矩阵，相邻赋值为1 
	if (x >= MAX_VERTEX_NUM || y >= MAX_VERTEX_NUM) {
		return ERROR;//当超出了图的范围，就返回ERROR
	}
	G->arcs[x][y].adj = G->arcs[y][x].adj = 1;//无向图两边邻接都为1，且当两个连结时，给弧赋值
	return OK;
}
/*-------------图的生成------------------*/

typedef int ElemType;

#define MAXQSIZE 100 //最大的容量

typedef struct QNode {
	ElemType data;
	struct QNode *priou;//节点的上一个节点
	struct QNode *next;//节点的下一个节点
}QNode, LinkList, *QueuePtr;

typedef struct {
	QueuePtr front;//前面的
	QueuePtr rear;//后面的
}LinkQueue;

Status InitQueue(LinkQueue *Q) {
	//队列的初始化
	Q->front = Q->rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));
	if (!(Q->front)) {
		return ERROR;
	}
	Q->front->next = Q->rear->next = NULL;//使队列为空
	return OK;
}

Status EnQueue(LinkQueue *Q, ElemType e) {
	//入队列的操作
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		return ERROR;
	}
	p->data = e;//储存到队列里的数据
	p->next = NULL;//下一个节点为空
	p->priou = Q->front;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, ElemType *e) {
	//出队列操作
	if (QueueEmpty(*Q)) {
		//队列为空时停止操作并返回ERROR
		return ERROR;
	}
	Q->front = Q->front->next;//头结点指向它的下一个节点
	*e = Q->front->data;
	return OK;
}

typedef enum {
	false,
	true
}bool;

bool QueueEmpty(LinkQueue Q) {
	//判断这是不是一个空队列
	if (Q.front == Q.rear) {
		return true;//头结点和后一个节点为同一个，那么这个队列为空
	}
	return false;//否则队列不为空
}

int FirstAdjVex(Graph G, int i) {
	//返回第一个邻接顶点，没有的话返回-1 
	for (int k = 0; k < G.vexnum; k++) {
		if (G.arcs[i][k].adj == 1) {
			return k;//如果是邻接节点，返回这个邻接的节点
		}
	}
	return -1;
}

int NextAdjVex(Graph G, int i, int j) {
	//返回下一个邻接顶点，没有的话返回-1 
	for (int k = j + 1; k < G.vexnum; k++) {
		if (G.arcs[i][k].adj == 1) {
			return k;
		}
	}
	return -1;
}
/*----------------队列的操作------------*/
#define FALSE 0 
#define TRUE 1 

int visited[MAX_VERTEX_NUM];

void BFSTraverse(Graph G, int a, int b) {
	//按广度优先的非递归遍历图G。使用辅助队列Q和访问标志数组visited.
	LinkQueue Q;  //辅助队列 
	for (int v = 0; v < G.vexnum; ++v) {
		visited[v] = FALSE;  //初始化访问标志 
	}
	InitQueue(&Q); // 置空的辅助队列Q 
	EnQueue(&Q, a); //起点入列 
	visited[a] = TRUE;
	bool flag = false;
	int u, w;
	while (!QueueEmpty(Q)) //队列不为空时执行
	{
		DeQueue(&Q, &u);//出队列操作
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
		{
			//依次将相邻顶点入列 
			if (w == b) {
				EnQueue(&Q, w);    //入队列操作
				PrintFoot(Q, a);  //输出路径 
				flag = true;
				break;
			}//if
			if (!visited[w]) {
				//w为u的未访问的邻接顶点
				EnQueue(&Q, w);   //入队列				
				visited[w] = true;
			}//if
		}//for
		if (flag) {
			break;
		}//if
	}//while
}//BFSTraverse
/*---------图的遍历--------------*/

Status PrintFoot(LinkQueue Q, int start) {
	//输出最短路径
	int foot[MAX_VERTEX_NUM];///最大顶点数
	int i;
	QueuePtr p;//定义一个队列
	p = Q.rear;//p指向队尾节点
	for (i = 0; i < MAX_VERTEX_NUM; i++) {
		foot[i] = -1;
	}//队列的初始化
	foot[0] = p->data;
	p = p->priou;
	for (i = 1; p->data != start; i++) {
		foot[i] = p->data;
		p = p->priou;
	}
	foot[i] = p->data;
	for (; i >= 0; i--) {
		//倒序输出 
		if (foot[i] >= 0) {
			printf("%d ", foot[i] + 1);
		}
	}
}

int main()
{
	Graph G;
	CreateGraph(&G);//创建一个图图，并且初始化它1
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (j != i) {
				printf("%d<->%d:", i + 1, j + 1);
				BFSTraverse(G, i, j);//广度遍历
				printf("\n");
			}//if
		}//for j
	}//for i
	return 0;
}