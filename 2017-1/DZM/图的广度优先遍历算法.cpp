#include "stdio.h"
#define MAX_VERTEX_NUM 20
#include "conio.h"
#include "stdlib.h"

typedef char VertexType;
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	int info;
}ArcNode;  //表结点类型

typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM]; //头结点

typedef struct
{
	AdjList vertices;  //邻接表
	int vexnum,arcnum;
}ALGraph;

typedef struct Qnode
{   //链队结点的类型
	int data;
	struct Qnode *next;
}Qnode,*QueuePtr;

typedef struct
{   //链队指针类型
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

int visited[MAX_VERTEX_NUM];

int LocateVex(ALGraph G,char u)
{
	int i;
	for (i=0;i<G.vexnum;i++)
	{ 
		if(u==G.vertices[i].data) 
			return i; 
	}
	if (i==G.vexnum) {printf("Error u!\n");exit(1);}
	return 0;
}

void InitQueue(LinkQueue &Q)
{ 
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(Qnode));
	if(!Q.front) exit(1); //存储分配失败
	Q.front->next=NULL;
}

void EnQueue(LinkQueue &Q,int e)
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(Qnode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}

int QueueEmpty(LinkQueue &Q)
{
	return(Q.front==Q.rear? 1:0);
}

void DeQueue(LinkQueue &Q,int &e)
{ QueuePtr p;
if(QueueEmpty(Q))
{
	printf("\n Queue is free!");
	exit(1);
}//if
p=Q.front->next;
e=p->data;
Q.front->next=p->next;
if(Q.front->next==NULL) Q.rear=Q.front;
free(p);
}

void CreateALGraph_adjlist(ALGraph &G)
{    
	int i,j,k,w; 
	char v1,v2,enter;
	ArcNode *p;
	printf("Input vexnum & arcnum:\n");
	scanf("%d",&G.vexnum);
	scanf("%d",&G.arcnum);
	printf("Input Vertices(以回车隔开各个数据):\n");
	for (i=0;i<G.vexnum;i++)
	{     scanf("%c%c",&enter,&G.vertices[i].data);//注意点，解说
	G.vertices[i].firstarc=NULL;
	}//for

	printf("Input Arcs(v1,v2,w)以回车分开各个数据:\n");
	for (k=0;k<G.arcnum;k++)
	{
		scanf("%c%c",&enter,&v1);
		scanf("%c%c",&enter,&v2);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;  
		p->nextarc=G.vertices[i].firstarc; //前插法,即每次都插入到头结点的后面
		G.vertices[i].firstarc=p;
		printf("Next\n");
	}//for     
	return;
}//CreateALGraph_adjlist

void BFSTraverse(ALGraph &G)
{
	LinkQueue Q;
	for(int v=0;v<G.vexnum;++v) visited[v]=false;
	InitQueue(Q);
	for(int v=0;v<G.vexnum;++v)
		if(!visited[v])
		{
			EnQueue(Q,v);
			while(!QueueEmpty(Q))
			{
				int u;      
				DeQueue(Q,u);
				visited[u]=true;
				printf("->%c",G.vertices[u].data);//visit一下
				for(ArcNode *w=G.vertices[u].firstarc;w;w=w->nextarc)
					if(!visited[w->adjvex]) EnQueue(Q,w->adjvex);
			}//while
		}//if
}//BFSTraverse

int main()
{
	ALGraph G;
	CreateALGraph_adjlist(G);
	BFSTraverse(G);
}