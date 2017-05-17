#include <stdio.h> 
#include <stdlib.h> 

//-----图的数组存储表示--------// 
#define MAX_VERTEX_NUM 20    //最大顶点个数 
#define INFINITY -1

typedef int VRType; 
typedef int ElemType;
typedef int InfoType;
typedef int VertexType;
typedef int GraphKind; 

int visited[MAX_VERTEX_NUM ];    //访问标志数组，初始值为FALSE(0)，一旦某个顶点被访问，则令其值为TRUE(1). 

typedef struct ArcCell 
{ // 弧的定义
    VRType  adj;     // VRType是顶点关系类型。
                     // 对无权图，用1或0表示相邻否；
                     // 对带权图，则为权值类型。
    InfoType  *info; // 该弧相关信息的指针
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{ // 图的定义
    VertexType vexs[MAX_VERTEX_NUM]; // 顶点信息
    AdjMatrix  arcs;                 // 弧的信息                     
    int        vexnum, arcnum;       // 顶点数，弧数      
    GraphKind  kind;                 // 图的种类标志             
} Graph;

//-------------队列------------ //
#define MAXQSIZE 100 
typedef struct QNode 
{ 
	int data; 
	struct QNode *prious; 
	struct QNode *next; 
}QNode,LinkList,*QueuePtr; 

typedef struct 
{ 
	QueuePtr front; 
	QueuePtr rear; 
}LinkQueue; 

typedef enum 
{ 
	OK, 
	ERROR, 
	OVERFLOW 
}Status; 

typedef enum 
{ 
	False, 
	True 
}Bool; 
Status InitQueue (LinkQueue *Q);
Bool QueueEmpty(LinkQueue *Q) ;
Status EnQueue(LinkQueue *Q,int e);
Status DeQueue(LinkQueue *Q, int *e);
Status Add(Graph *G, int x, int y) ;
Status CreateGraph(Graph *G) ;
int FirstAdjVex(Graph G, int i)  ;
int NextAdjVex(Graph G, int i, int j) ;
Status PrintFoot(LinkQueue Q,int start) ;
void ShortestPath(Graph G,int a,int b) ;

//---------------------队列基本操作-----------------\\
//初始化队列 
Status InitQueue (LinkQueue *Q) 
{ 
	Q->front = Q->rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));  
	if(!(Q->front)) 
	{ 
		return ERROR; 
	} 
	Q->front->next = Q->rear->next = NULL; 
	return OK; 
} 
//判断是否为空队列  
Bool QueueEmpty(LinkQueue *Q)  
{  
	if (Q->front == Q->rear)  
	{  
		return True;  
	}  
	return False;  
}  
//入列 
Status EnQueue(LinkQueue *Q,int e) 
{ 
	QueuePtr p; 
	p = (QueuePtr)malloc(sizeof(QNode));//令其priou域的指针指向刚刚出队列的结点，即当前的队头指针所指结点; 
	if(!p) 
	{ 
		return ERROR; 
	} 
	p->data = e; 
	p->next = NULL; 
	p->prious = Q->front;//指向当前的队头指针所指结点 
	Q->rear->next  = p; 
	Q->rear = p; 
	return OK; 
} 
//出列  
Status DeQueue(LinkQueue *Q, int *e) //修改过的出列函数， 
{  
	if (QueueEmpty(Q))  
	{  
		return ERROR;  
	}  
	Q->front = Q->front->next;  
	*e = Q->front->data; //没有free（e） 
	return OK;  
} 
//----------------图的基本操作----------------------- 
//顶点赋值 
Status Add(Graph *G, int x, int y) 
{ 
	if(x >= MAX_VERTEX_NUM || y >= MAX_VERTEX_NUM) //若x、y的值超过了最大限定值是错误的 
	{ 

		return ERROR; 
	} 
	G -> arcs[x][y].adj = G ->arcs[y][x].adj = 1;  //无向图的邻接矩阵是对称的，为无向图顶点赋值，赋值为1 
	return OK; 
} 
//构建图（用数组表示法） 
Status CreateGraph(Graph *G) 
{ 
	int i ,j; 
	G -> vexnum = 9;//顶点数 
	G -> arcnum = 12;//弧数 
	for(i = 0; i < G -> vexnum; i++) 
	{ 
		for(j = 0; j < G ->arcnum; j++) 
		{ 
			G -> arcs[i][j].adj = INFINITY;    //初始化邻接矩阵，让每一个值都为无穷 
			G->arcs[i][j].info = NULL;
		} 
	} 
	Add(G, 0, 1); Add(G, 0, 2); Add(G, 0, 3); Add(G, 0, 6);
	Add(G, 1, 2); Add(G, 3, 4); Add(G, 3, 5); Add(G, 4, 5); 
	Add(G, 5, 7); Add(G, 6, 7); Add(G, 6, 8); Add(G, 7, 8);  
	//对于无向图，利用邻接矩阵的对称性，用压缩存储的方式只存入矩阵的上三角 
	return OK; 
} 
//返回第一个邻接顶点，没有的话返回-1  
int FirstAdjVex(Graph G, int i)  
{  
	int k;  
	for (k = 0; k < G.vexnum; k++)  
	{  
		if (G.arcs[i][k].adj == 1) //邻接矩阵同一行中为1的点都是它的邻接点，从0开始遍历，第一个为1的就是邻接点 
		{  
			return k;  
		}  
	}  
	return -1;  
} 
//返回下一个邻接顶点，没有的话返回-1  
int NextAdjVex(Graph G, int i, int j)  
{ 
	int k;  
	for (k = j + 1; k < G.vexnum; k++)  
	{ 

		if (G.arcs[i][k].adj == 1)//k从j+1开始，下一个为1的就是它的下一个邻接点  
		{ 
			return k; 
		}  
	}  
	return -1;  
} 

Status Print(LinkQueue Q,int start) 
{ 
	int njr[MAX_VERTEX_NUM];//MAX_VERTEX_NUM可以在这一题中可以换成9，但为了函数的通用性，用MAX_VERTEX_NUM更好 
	int i;                   //njr数组来存储路径 
	QueuePtr p; 
	p = Q.rear;//p是队尾结点 
	for(i=0;i < MAX_VERTEX_NUM; i++) 
	{ 
		njr[i] = -1;//初始化foot数组 
	} 
	njr[0] = p->data;//路径的最后一个 
	p = p->prious; 
	for(i = 1;p->data != start; i++) 
	{ 
		njr[i] = p->data; 
		p = p->prious; 
	} 
	njr[i] = start;//foot[i] = p->data; 
	for(;i >= 0; i--) 
	{ 
		if(njr[i] >= 0) 
			printf("%d ",njr[i] + 1);//输出路径 
	} 
} 
//广度优先求路径 
void ShortestPath(Graph G,int a,int b) 
{ 
	int u,v,w; 
	Bool flag = False;//用flag来进行退出while循环的判断，若为true则退出while 
	LinkQueue Q; 
	for(v = 0; v < G.vexnum; ++v) 
	{ 
		visited[v] = False; //先初始化访问标志数组为FALSE 
	} 
	InitQueue(&Q);//初始化一个队列，来存储已被访问的路径长度为1，2，。。。的顶点，即存储最短路径的顶点 
	EnQueue(&Q,a);//将a进入队列 
	visited[a] = True;//访问了a,则将它赋值为TRUE，表示已经被访问 
	while (!QueueEmpty(&Q))//队列不为空 
	{ 
		DeQueue(&Q,&u);//此函数出队列时，仅移动队头指针，而不将队头结点从链表中删除 
		for(w = FirstAdjVex(G,u);w >=0;w = NextAdjVex(G, u, w)) //w为u的邻接点，直到遍历到b时for循环停止 
		{ 
			if(w == b)//若w=b，则说明最小路径已经找到 
			{ 
				EnQueue(&Q,w);//把最后一个结点进入队列 
				Print(Q,a);//可以输出路径了 
				flag = True; 
			} 
			if(!visited[w])//若u的邻接点没有被访问 
			{ 

				EnQueue(&Q,w);//让w进入队列 
				visited[w] = True; 
			} 
		} 
		if(flag) 
		{ 
			break;//跳出while循环 
		} 
	} 
} 
//输出路径 

int main() 
{ 
	int i,j; 
	Graph h ; 
	CreateGraph(&h);//构建一个无向图，并用邻接矩阵初始化图 
	printf("图中任意两点间的最短距离为:\n"); 
	for(i = 0;i < 9; i++) 
	{ 
		for(j = 0;j < 9;j++) 
		{ 
			if(i != j) 
			{ 
				printf("%d -> %d :",i + 1,j + 1); 
				ShortestPath(h,i,j);//寻找最短路径 
				printf("\n"); 
			} 
		} 
	} 
	return 0; 
} 