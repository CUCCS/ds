#include <stdio.h>
#include <malloc.h>

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum
{
	TRUE,
	FALSE
}bool;


/*=========图的数组存储结构=========*/
#define MAX_VERTEX_NUM 10 
#define VRType int 
#define InfoType int
#define VertexType int
#define INFINITY -1

typedef struct ArcCell
{
	VRType adj;
	InfoType *info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum; //图的顶点数和弧数;
}MGraph;


/*=========队列的双链存储结构=========*/
#define QElemType int

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
	struct QNode *pre;
}QNode, *QueuePtr;

typedef struct LinkQueue
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/*=========队列的基本操作=========*/
Status InitQueue(LinkQueue *Q);
Status EnQueue(LinkQueue*Q, QElemType e);
Status DeQueue(LinkQueue*Q, QElemType*e);
bool QueueEmpty(LinkQueue*Q);
Status DestroyQueue(LinkQueue*Q);

/*=========图的基本操作=========*/
bool LocateVex(MGraph *g, int v, int *i);
Status CreateUDN(MGraph *G);
int FirstAdjVex(MGraph *G, int u);
int NextAdjvex(MGraph *G, int u, int w);
Status BFSTraverse(MGraph*G, LinkQueue *Q, int a, int b);
Status print(LinkQueue *Q, int a); 
Status InsertArc(MGraph *G, int v1, int v2);


