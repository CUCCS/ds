#include<stdio.h>
#include<stdlib.h>

#define INFINITY 65535//最大值 无穷大
#define MAX 20//最大顶点个数
#define OVERFLOW -1

#define DEBUG 0
#define debug_print if(DEBUG)printf


typedef int VRType;
typedef int InfoType;
typedef int VertexType;
typedef int Status;

enum { OK, ERROR };
enum{ FALSE =0,  TRUE =1 };
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef struct ArcCell {
	VRType adj;//表示相邻否 无权图用1或0
	InfoType *info;//该弧相关信息的指针
}ArcCell, AdjMatrix[MAX][MAX];
typedef struct {
	VertexType vexs[MAX];//顶点向量
	AdjMatrix arcs;//邻接矩阵
	int vexnum, arcnum;//当前顶点数 弧数
	GraphKind kind;//图的种类
}MGraph;
int LocateVex(MGraph G, int u)
{//返回顶点u的位置
	int i;
	//printf("u=%d ",u);
	if (u < G.vexnum) {
		for (i = 0; i < G.vexnum; i++) {
			//printf("vexs[%d] = %d\n", i, G.vexs[i]);
			if (G.vexs[i] == u) {
				//printf("位置=%d\n", i);
				return i;
			}
		}
	}
	else {
		//printf("错误位置%d\n",u);
		return -1;
	}
}
void Build(MGraph *G, int v1, int v2) {
	int i = LocateVex(*G, v1);//返回v1的位置为i
	int j = LocateVex(*G, v2);//返回v2的位置为j
	G->arcs[i][j].adj = 1;//弧<v1,v2>的权值
	G->arcs[j][i].adj = G->arcs[i][j].adj;//矩阵对称
	//printf("<v1=%d,v2=%d>  ",v1,v2);
	//printf("G->arcs[%d][%d].adj=%d\n",i,j,G->arcs[i][j].adj);
}
int CreateUDN(MGraph *G) {
	//int IncInfo;
	int v1=0, v2=0;
	G->vexnum = 9;//顶点数
	G->arcnum = 12;//弧数
	for (int i = 0; i < G->vexnum; ++i) G->vexs[i] = i; 
	for (int i = 0; i < G->vexnum; ++i) {
		for (int j = 0; j < G->vexnum; ++j) {
			G->arcs[i][j].adj = -1;
			G->arcs[i][j].info = NULL;
		}
	}
	Build(G, 0, 1); Build(G, 0, 2); Build(G, 0, 3); Build(G, 0, 6);
	Build(G, 1, 2); Build(G, 3, 4); Build(G, 3, 5); Build(G, 4, 5);
	Build(G, 5, 7); Build(G, 6, 7); Build(G, 6, 8); Build(G, 7, 8);
	return OK;
}
//队列
typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
	struct QNode *priou;
}QNode, *Queueptr;

typedef struct {
	Queueptr front;
	Queueptr rear;
	Queueptr lastOut;
}LinkQueue;

Status InitQueue(LinkQueue *Q) {//构造空队列Q
	debug_print(__FUNCTION__" \n");
	Q->lastOut = NULL;
	Q->front = Q->rear = NULL;
	return OK;
}

int QueueEmpty(LinkQueue Q) {
	if (Q.front == NULL && Q.rear == NULL) return TRUE;
	else return FALSE;
}
void showQueue(LinkQueue *Q) {
	QNode* p = Q->front;
	if (p == NULL)printf("(empty)");
	while (p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
Status DeQueue(LinkQueue *Q, QElemType *e) {//不删除队头元素用e返回值
	*e = Q->front->data;
	debug_print(__FUNCTION__" %d\n", *e);
	if (QueueEmpty(*Q)) {
		printf("Error : %s\n", __LINE__);
		exit(-1);
	}
	Q->lastOut = Q->front;
	Q->front = Q->front->next;
	if (Q->front == NULL)Q->rear = NULL;
	//if (Q->front != Q->rear) {
	//	QNode* temp = Q->front;
	//	Q->front = Q->front->next;
	//	free(temp);
	//}
	//else {
	//	free(Q->front);
	//	Q->front = Q->rear;
	//}

	if(DEBUG)showQueue(Q);
	return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e) {//插入e为队尾元素
	debug_print(__FUNCTION__" %d\n",e);
	Queueptr p;
	p = (Queueptr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e; 
	p->next = NULL;
	p->priou = Q->lastOut;
	
	if (!QueueEmpty(*Q)) {
		Q->rear->next = p;
		Q->rear = p;
	}
	else {
		Q->front = p;
		Q->rear = p;
	}

	if(DEBUG)showQueue(Q);
	return OK;
}
int FirstAdjvex(MGraph G, int v)
{//返回v的第一个邻接顶点
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[v][i].adj > 0&&v!=i)  return i; 
	}
	return -1;
}

int NextAdjVex(MGraph G, int v, int w) {//返回V的相对于W的下一个邻接顶点  
	for (int i =w+1; i < G.vexnum; i++) {
		if (G.arcs[v][i].adj > 0) return i;
	}
	return -1;
}

void showList(QNode* p) {
	if (p) {
		showList(p->priou);
		printf("%d ", p->data);
	}
}
void BFSTraverse(MGraph G,int start,int end) {//广度优先遍历图
	debug_print(__FUNCTION__"\n");
	int visited[MAX];
	int v;
	for ( v = 0; v < G.vexnum; v++)  visited[v] = FALSE;
	LinkQueue Q;
	InitQueue(&Q);
	v = start;
		if (!visited[v]) {//顶点v尚未访问
			visited[v] = TRUE;
			EnQueue(&Q, v);//v入队列
			while (!QueueEmpty(Q)) {
				DeQueue(&Q, &v);//队头元素出队列并赋值为u
				//debug_print("开始访问%d的邻节点\n",v);
				for (int w = FirstAdjvex(G, v); w != -1; w = NextAdjVex(G,v, w)) {
					//debug_print("当前邻节点是%d\n", w);
					if (!visited[w]) {
						visited[w] = TRUE;
						EnQueue(&Q, w);//相邻顶点入队列
						if (w == end)break;
					}
				}//end for
				if (Q.rear->data == end)break;
			}//end while
		}
	showList(Q.rear);
}
int main() {
	MGraph G;
	CreateUDN(&G);
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			if (i != j) {
				printf("%d<->%d:", i, j);
				BFSTraverse(G, i, j);
				printf("\n");
			}
		}
	}
	return 0;
}