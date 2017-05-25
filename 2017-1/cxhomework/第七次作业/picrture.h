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

typedef struct ArcCell { // ���Ķ���
 VRType  adj;    // ��1��0��ʾ���ڷ�
	
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	
		typedef struct { // ͼ�Ķ���
		AdjMatrix  arcs;                 // ������Ϣ                     
		int vexnum, arcnum;       // ������������               
		
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
	
		//���еĻ�������// 
		Status InitQueue(LinkQueue *Q) {
		Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
		Q->front->next = Q->rear->next = NULL;
		return OK;
			}//��ʼ������
	Status EnQueue(LinkQueue *Q, ElemType e) {
		QueuePtr p;
		p = (QueuePtr)malloc(sizeof(QNode));
		p->data = e;
		p->next = NULL;
		p->priou = Q->front;
		Q->rear->next = p;
		Q->rear = p;
		return OK;
		
	}//����
	Status DeQueue(LinkQueue *Q, ElemType *e) {
		Q->front = Q->front->next;
		*e = Q->front->data;
		return OK;
		
	}//����
	Bool QueueEmpty(LinkQueue Q) {
		if (Q.front == Q.rear) {
			return True;
			
		}
		return False;
		
	}; //�ж��Ƿ�Ϊ�ն���
	
		//ͼ�Ļ�������// 
		int FirstAdjVex(Graph G, int i);  //���ص�һ���ڽӶ��㣬û�еĻ�����-1
	int NextAdjVex(Graph G, int i, int j);  //������һ���ڽӶ��㣬û�еĻ�����-1
	Status CreateGraph(Graph *G);  //������֪ͼ
	Status Add(Graph*G, int x, int y);  //Ϊ�ڽӾ���ֵ
	void BFSTraverse(Graph G, int a, int b);  //������ȱ���
	Status PrintFoot(LinkQueue Q, int start);  //���·��