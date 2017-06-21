#include <stdio.h> 
#include <stdlib.h> 

#define MAXQSIZE 100 
#define MAX_VERTEX_NUM 20    //��󶥵���� 
#define INFINITY -1

typedef int VRType; 
typedef int ElemType;
typedef int InfoType;
typedef int VertexType;
typedef int GraphKind; 

int visited[MAX_VERTEX_NUM ];    //���ʱ�־���飬��ʼֵΪFALSE(0)��һ��ĳ�����㱻���ʣ�������ֵΪTRUE(1). 

//------------ͼ-------------// 
typedef struct ArcCell 
{ // ���Ķ���
	VRType  adj;     // VRType�Ƕ����ϵ���͡�
	// ����Ȩͼ����1��0��ʾ���ڷ�
	// �Դ�Ȩͼ����ΪȨֵ���͡�
	InfoType  *info; // �û������Ϣ��ָ��
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{ // ͼ�Ķ���
	VertexType vexs[MAX_VERTEX_NUM]; // ������Ϣ
	AdjMatrix  arcs;                 // ������Ϣ                     
	int        vexnum, arcnum;       // ������������      
	GraphKind  kind;                 // ͼ�������־             
} Graph;

//-------------����------------ //
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

//---------------------���л�������-----------------\\
//��ʼ������ 
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
//�ж��Ƿ�Ϊ�ն���  
Bool QueueEmpty(LinkQueue *Q)  
{  
	if (Q->front == Q->rear)  
	{  
		return True;  
	}  
	return False;  
}  
//���� 
Status EnQueue(LinkQueue *Q,int e) 
{ 
	QueuePtr p; 
	p = (QueuePtr)malloc(sizeof(QNode));//����priou���ָ��ָ��ոճ����еĽ�㣬����ǰ�Ķ�ͷָ����ָ���; 
	if(!p) 
	{ 
		return ERROR; 
	} 
	p->data = e; 
	p->next = NULL; 
	p->prious = Q->front;//ָ��ǰ�Ķ�ͷָ����ָ��� 
	Q->rear->next  = p; 
	Q->rear = p; 
	return OK; 
} 
//����  
Status DeQueue(LinkQueue *Q, int *e) //�޸Ĺ��ĳ��к����� 
{  
	if (QueueEmpty(Q))  
	{  
		return ERROR;  
	}  
	Q->front = Q->front->next;  
	*e = Q->front->data; //û��free��e�� 
	return OK;  
} 
//----------------ͼ�Ļ�������----------------------- 
//���㸳ֵ 
Status Add(Graph *G, int x, int y) 
{ 
	if(x >= MAX_VERTEX_NUM || y >= MAX_VERTEX_NUM) //��x��y��ֵ����������޶�ֵ�Ǵ���� 
	{ 

		return ERROR; 
	} 
	G -> arcs[x][y].adj = G ->arcs[y][x].adj = 1;  //����ͼ���ڽӾ����ǶԳƵģ�Ϊ����ͼ���㸳ֵ����ֵΪ1 
	return OK; 
} 
//����ͼ���������ʾ���� 
Status CreateGraph(Graph *G) 
{ 
	int i ,j; 
	G -> vexnum = 9;//������ 
	G -> arcnum = 12;//���� 
	for(i = 0; i < G -> vexnum; i++) 
	{ 
		for(j = 0; j < G ->arcnum; j++) 
		{ 
			G -> arcs[i][j].adj = INFINITY;    //��ʼ���ڽӾ�����ÿһ��ֵ��Ϊ���� 
			G->arcs[i][j].info = NULL;
		} 
	} 
	Add(G, 0, 1); Add(G, 0, 2); Add(G, 0, 3); Add(G, 0, 6);
	Add(G, 1, 2); Add(G, 3, 4); Add(G, 3, 5); Add(G, 4, 5); 
	Add(G, 5, 7); Add(G, 6, 7); Add(G, 6, 8); Add(G, 7, 8);  
	//��������ͼ�������ڽӾ���ĶԳ��ԣ���ѹ���洢�ķ�ʽֻ�������������� 
	return OK; 
} 
//���ص�һ���ڽӶ��㣬û�еĻ�����-1  
int FirstAdjVex(Graph G, int i)  
{  
	int k;  
	for (k = 0; k < G.vexnum; k++)  
	{  
		if (G.arcs[i][k].adj == 1) //�ڽӾ���ͬһ����Ϊ1�ĵ㶼�������ڽӵ㣬��0��ʼ��������һ��Ϊ1�ľ����ڽӵ� 
		{  
			return k;  
		}  
	}  
	return -1;  
} 
//������һ���ڽӶ��㣬û�еĻ�����-1  
int NextAdjVex(Graph G, int i, int j)  
{ 
	int k;  
	for (k = j + 1; k < G.vexnum; k++)  
	{ 

		if (G.arcs[i][k].adj == 1)//k��j+1��ʼ����һ��Ϊ1�ľ���������һ���ڽӵ�  
		{ 
			return k; 
		}  
	}  
	return -1;  
} 

Status Print(LinkQueue Q,int start) 
{ 
	int njr[MAX_VERTEX_NUM];//MAX_VERTEX_NUM��������һ���п��Ի���9����Ϊ�˺�����ͨ���ԣ���MAX_VERTEX_NUM���� 
	int i;                   //njr�������洢·�� 
	QueuePtr p; 
	p = Q.rear;//p�Ƕ�β��� 
	for(i=0;i < MAX_VERTEX_NUM; i++) 
	{ 
		njr[i] = -1;//��ʼ��foot���� 
	} 
	njr[0] = p->data;//·�������һ�� 
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
			printf("%d ",njr[i] + 1);//���·�� 
	} 
} 
//���������·�� 
void ShortestPath(Graph G,int a,int b) 
{ 
	int u,v,w; 
	Bool flag = False;//��flag�������˳�whileѭ�����жϣ���Ϊtrue���˳�while 
	LinkQueue Q; 
	for(v = 0; v < G.vexnum; ++v) 
	{ 
		visited[v] = False; //�ȳ�ʼ�����ʱ�־����ΪFALSE 
	} 
	InitQueue(&Q);//��ʼ��һ�����У����洢�ѱ����ʵ�·������Ϊ1��2���������Ķ��㣬���洢���·���Ķ��� 
	EnQueue(&Q,a);//��a������� 
	visited[a] = True;//������a,������ֵΪTRUE����ʾ�Ѿ������� 
	while (!QueueEmpty(&Q))//���в�Ϊ�� 
	{ 
		DeQueue(&Q,&u);//�˺���������ʱ�����ƶ���ͷָ�룬��������ͷ����������ɾ�� 
		for(w = FirstAdjVex(G,u);w >=0;w = NextAdjVex(G, u, w)) //wΪu���ڽӵ㣬ֱ��������bʱforѭ��ֹͣ 
		{ 
			if(w == b)//��w=b����˵����С·���Ѿ��ҵ� 
			{ 
				EnQueue(&Q,w);//�����һ����������� 
				Print(Q,a);//�������·���� 
				flag = True; 
			} 
			if(!visited[w])//��u���ڽӵ�û�б����� 
			{ 

				EnQueue(&Q,w);//��w������� 
				visited[w] = True; 
			} 
		} 
		if(flag) 
		{ 
			break;//����whileѭ�� 
		} 
	} 
} 
//���·�� 

int main() 
{ 
	int i,j; 
	Graph h ; 
	Status pop = 0;
	CreateGraph(&h);//����һ������ͼ�������ڽӾ����ʼ��ͼ
	if(pop == CreateGraph(&h))
	{
		printf("Right!\n");
		printf(">---------------------------------------------<\n");
	}
	printf("ͼ��������������̾���Ϊ:\n"); 
	for(i = 0;i < 9; i++) 
	{ 
		for(j = 0;j < 9;j++) 
		{ 
			if(i != j) 
			{ 
				printf("%d -> %d :",i + 1,j + 1); 
				ShortestPath(h,i,j);//Ѱ�����·�� 
				printf("\n"); 
			} 
		} 
	} 
	return 0; 
} 