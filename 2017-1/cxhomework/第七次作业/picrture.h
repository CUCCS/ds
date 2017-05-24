#define MAXQSIZE 100
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

int visited[MAX_VERTEX_NUM];

typedef int VRType;
typedef int ElemType;

typedef enum {
	OK,
	ERROR,
	OVERFLOW
	
}Status;

typedef enum {
	False,
	True
	
}Bool;

typedef struct ArcCell { // 弧的定义
 VRType  adj;    // 用1或0表示相邻否；
	
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	
		typedef struct { // 图的定义
		AdjMatrix  arcs;                 // 弧的信息                     
		int vexnum, arcnum;       // 顶点数，弧数               
		
	} Graph;
	
		typedef struct QNode {
		ElemType data;
		struct QNode *priou;
		struct QNode *next;
		
	}QNode, DuLinkList, *QueuePtr;
	
		typedef struct {
		QueuePtr front;
		QueuePtr rear;
		
	}LinkQueue;
	
		//队列的基本操作// 
		Status InitQueue(LinkQueue *Q) {
		Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
		Q->front->next = Q->rear->next = NULL;
		return OK;
			}//初始化队列
	Status EnQueue(LinkQueue *Q, ElemType e) {
		QueuePtr p;
		p = (QueuePtr)malloc(sizeof(QNode));
		p->data = e;
		p->next = NULL;
		p->priou = Q->front;
		Q->rear->next = p;
		Q->rear = p;
		return OK;
		
	}//入列
	Status DeQueue(LinkQueue *Q, ElemType *e) {
		Q->front = Q->front->next;
		*e = Q->front->data;
		return OK;
		
	}//出列
	Bool QueueEmpty(LinkQueue Q) {
		if (Q.front == Q.rear) {
			return True;
			
		}
		return False;
		
	}; //判断是否为空队列
	
		//图的基本操作// 
		int FirstAdjVex(Graph G, int i);  //返回第一个邻接顶点，没有的话返回-1
	int NextAdjVex(Graph G, int i, int j);  //返回下一个邻接顶点，没有的话返回-1
	Status CreateGraph(Graph *G);  //构建已知图
	Status Add(Graph*G, int x, int y);  //为邻接矩阵赋值
	void BFSTraverse(Graph G, int a, int b);  //广度优先遍历
	Status PrintFoot(LinkQueue Q, int start);  //输出路径