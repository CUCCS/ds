//运用队列和图的基本操作（图通过邻接矩阵存储）实现最短路径及打印

#include <stdio.h>
#include <malloc.h>

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;

typedef enum{
	TRUE,
	FALSE
}bool;


/*=========队列的双链存储结构=========*/
#define QElemType int

typedef struct QNode{
	QElemType data;
	struct QNode *next;
	struct QNode *pre;
}QNode, *QueuePtr;

typedef struct LinkQueue{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


/*=========队列的基本操作=========*/
Status InitQueue(LinkQueue *q){
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front){
		return ERROR;
	}
	q->front->next = q->rear->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue*q, QElemType e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p){
		return ERROR;
	}
	else{
		p->data = e;
		p->next = NULL;
		p->pre = q->front;
		q->rear->next = p;
		q->rear = p;
	}
}

Status DeQueue(LinkQueue*q, QElemType*e){
	if (q->front == q->rear){
		return ERROR;
	}
	q->front = q->front->next;
	*e = q->front->data;
	return OK;
}

bool QueueEmpty(LinkQueue*q){
	if (q->front == q->rear){
		return TRUE;
	}
	else{
		return FALSE;
	}
}

Status DestroyQueue(LinkQueue*q){
	while (q->front){
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	return OK;
}

/*=========图的数组存储结构=========*/
#define MAX_VERTEX_NUM 10 
#define VRType int  //数据类型
#define InfoType int
#define VertexType int
#define INFINITY -1//弧不存在

typedef struct ArcCell{
	VRType adj;//用来标记两点间是否有弧
	InfoType *info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum; //图的顶点数和弧数
}MGraph;

/*=========图的基本操作=========*/
bool LocateVex(MGraph *g, int v, int *i){
	int m;
	for (m = 0; m <= g->vexnum; m++){
		if (g->vexs[m] == v){
			*i = m;
			return TRUE;
		}
	}
	return FALSE;
}//传入一个图，要定位v，用i返回v的位置（下标）

Status InsertArc(MGraph *g, int v1, int v2){
	int i = 0;
	int j = 0;
	if (LocateVex(g, v1, &i) == TRUE && LocateVex(g, v2, &j) == TRUE){
		g->arcs[i][j].adj = 1;//两点之间有连线，弧值为1;
		g->arcs[j][i] = g->arcs[i][j];//无向图
	}
}

Status CreateUDN(MGraph *g){
	int i;
	int j;
	//根据用例直接赋值。
	g->vexnum = 9;//顶点个数
	g->arcnum = 12;//弧的个数
	for (i = 1; i <= g->vexnum; i++){
		g->vexs[i] = i;
	}
	for (i = 0; i <= g->vexnum; i++){//初始化邻接矩阵;
		for (j = 0; j <= g->vexnum; j++){
			g->arcs[i][j].adj = INFINITY;//将弧的情况初始化为不存在
			g->arcs[i][j].info = NULL;
		}
	}
	//构建邻接矩阵;
	InsertArc(g, 1, 2);
	InsertArc(g, 1, 3);
	InsertArc(g, 1, 4);
	InsertArc(g, 1, 7);
	InsertArc(g, 2, 3);
	InsertArc(g, 4, 5);
	InsertArc(g, 4, 6);
	InsertArc(g, 5, 6);
	InsertArc(g, 6, 8);
	InsertArc(g, 7, 8);
	InsertArc(g, 7, 9);
	InsertArc(g, 8, 9);

	return OK;
}//构建图

int FirstAdjVex(MGraph *g, int u){
	int i;
	for (i = 1; i <= g->vexnum; i++){
		if (g->arcs[u][i].adj == 1){
			return i;
		}
	}
	return -1;
}//找出第一个邻接点

int NextAdjvex(MGraph *g, int u, int w){
	int i;
	for (i = w + 1; i <= g->vexnum; i++){
		if (g->arcs[u][i].adj == 1){
			return i;
		}
	}
	return -1;
}//找出下一个邻接点

Status BFSTraverse(MGraph*g, LinkQueue *q, int a, int b)
{

	int v;
	int u = 0;
	int w = 0;
	int m = 0;
	int n = 0;
	bool visited[MAX_VERTEX_NUM];
	for (v = 1; v <= g->vexnum; v++){
		visited[v] = FALSE;  //图中未访问的点记为false
	}

	EnQueue(q, a); 
	while (！QueueEmpty(q)){
		DeQueue(q, &u);
		for (w = FirstAdjVex(g, u); w >= 0; w = NextAdjvex(g, u, w)){
			if (！visited[w]){
				visited[w] = TRUE;
				EnQueue(q, w);
			}//判断w是否已经访问过，未访问则访问，并将其入队
			if (w == b){
				break;
			}
		}
		if (w == b){
			break;
		}
	}
}//广度优先遍历图,求两点a,b间的最短路径;

Status print(LinkQueue *q, int a){
	if (q->rear->data == a){
		printf("%d->%d\n", a, a);
		return OK;
	}

	int i = 0;
	int j;
	int num[MAX_VERTEX_NUM] = { 0 };
	while (q->rear->data != a){
		num[i] = q->rear->data;
		q->rear = q->rear->pre;
		i++;
	}//倒序进入数组，起到类似栈的作用，为简便使用队列
	printf("%d", a);
	for (j = i - 1; j >= 0; j--)
	{
		printf("->%d", num[j]);
	}


	printf("\n");
	return OK;
}
