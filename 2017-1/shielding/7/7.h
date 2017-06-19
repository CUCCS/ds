//���ö��к�ͼ�Ļ���������ͼͨ���ڽӾ���洢��ʵ�����·������ӡ

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


/*=========���е�˫���洢�ṹ=========*/
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


/*=========���еĻ�������=========*/
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

/*=========ͼ������洢�ṹ=========*/
#define MAX_VERTEX_NUM 10 
#define VRType int  //��������
#define InfoType int
#define VertexType int
#define INFINITY -1//��������

typedef struct ArcCell{
	VRType adj;//�������������Ƿ��л�
	InfoType *info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum; //ͼ�Ķ������ͻ���
}MGraph;

/*=========ͼ�Ļ�������=========*/
bool LocateVex(MGraph *g, int v, int *i){
	int m;
	for (m = 0; m <= g->vexnum; m++){
		if (g->vexs[m] == v){
			*i = m;
			return TRUE;
		}
	}
	return FALSE;
}//����һ��ͼ��Ҫ��λv����i����v��λ�ã��±꣩

Status InsertArc(MGraph *g, int v1, int v2){
	int i = 0;
	int j = 0;
	if (LocateVex(g, v1, &i) == TRUE && LocateVex(g, v2, &j) == TRUE){
		g->arcs[i][j].adj = 1;//����֮�������ߣ���ֵΪ1;
		g->arcs[j][i] = g->arcs[i][j];//����ͼ
	}
}

Status CreateUDN(MGraph *g){
	int i;
	int j;
	//��������ֱ�Ӹ�ֵ��
	g->vexnum = 9;//�������
	g->arcnum = 12;//���ĸ���
	for (i = 1; i <= g->vexnum; i++){
		g->vexs[i] = i;
	}
	for (i = 0; i <= g->vexnum; i++){//��ʼ���ڽӾ���;
		for (j = 0; j <= g->vexnum; j++){
			g->arcs[i][j].adj = INFINITY;//�����������ʼ��Ϊ������
			g->arcs[i][j].info = NULL;
		}
	}
	//�����ڽӾ���;
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
}//����ͼ

int FirstAdjVex(MGraph *g, int u){
	int i;
	for (i = 1; i <= g->vexnum; i++){
		if (g->arcs[u][i].adj == 1){
			return i;
		}
	}
	return -1;
}//�ҳ���һ���ڽӵ�

int NextAdjvex(MGraph *g, int u, int w){
	int i;
	for (i = w + 1; i <= g->vexnum; i++){
		if (g->arcs[u][i].adj == 1){
			return i;
		}
	}
	return -1;
}//�ҳ���һ���ڽӵ�

Status BFSTraverse(MGraph*g, LinkQueue *q, int a, int b)
{

	int v;
	int u = 0;
	int w = 0;
	int m = 0;
	int n = 0;
	bool visited[MAX_VERTEX_NUM];
	for (v = 1; v <= g->vexnum; v++){
		visited[v] = FALSE;  //ͼ��δ���ʵĵ��Ϊfalse
	}

	EnQueue(q, a); 
	while (��QueueEmpty(q)){
		DeQueue(q, &u);
		for (w = FirstAdjVex(g, u); w >= 0; w = NextAdjvex(g, u, w)){
			if (��visited[w]){
				visited[w] = TRUE;
				EnQueue(q, w);
			}//�ж�w�Ƿ��Ѿ����ʹ���δ��������ʣ����������
			if (w == b){
				break;
			}
		}
		if (w == b){
			break;
		}
	}
}//������ȱ���ͼ,������a,b������·��;

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
	}//����������飬������ջ�����ã�Ϊ���ʹ�ö���
	printf("%d", a);
	for (j = i - 1; j >= 0; j--)
	{
		printf("->%d", num[j]);
	}


	printf("\n");
	return OK;
}
