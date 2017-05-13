#define MAXQSIZE 100
#define FALSE 0
#define TRUE 1

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
	false,
	true
}bool;

typedef struct ArcCell { // ���Ķ���
	VRType  adj;    // ��1��0��ʾ���ڷ�
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct { // ͼ�Ķ���
	AdjMatrix  arcs;                 // ������Ϣ                     
	int        vexnum, arcnum;       // ������������               
} Graph;

typedef struct QNode {
	ElemType data;
	struct QNode *priou;
	struct QNode *next;
}QNode, LinkList, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//==========���еĻ�������=============// 
Status InitQueue(LinkQueue *Q);  //��ʼ������
Status EnQueue(LinkQueue *Q, ElemType e);  //����
Status DeQueue(LinkQueue *Q, ElemType *e);  //����
bool QueueEmpty(LinkQueue Q);  //�ж��Ƿ�Ϊ�ն���

//==========ͼ�Ļ�������=============// 
int FirstAdjVex(Graph G, int i);  //���ص�һ���ڽӶ��㣬û�еĻ�����-1
int NextAdjVex(Graph G, int i, int j);  //������һ���ڽӶ��㣬û�еĻ�����-1
Status CreateGraph(Graph *G);  //������֪ͼ
Status Add(Graph*G, int x, int y);  //Ϊ�ڽӾ���ֵ
void BFSTraverse(Graph G, int a, int b);  //������ȱ���
Status PrintFoot(LinkQueue Q, int start);  //���·��