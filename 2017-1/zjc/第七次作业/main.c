#include<stdio.h>  
#include<stdlib.h> 
#include <malloc.h>  

#define INFINITY INT_MAX //���ֵΪ����
#define MAX_VERTEX_NUM 20 //��󶥵���

typedef enum {
	DG,DN,UGD,UDN
}GraphKind;//{����ͼ��������������ͼ��������}

typedef int VRType, InfoType;

typedef struct ArcCell {
	VRType adj;//VRType�Ƕ����ϵ���ͣ�����Ȩͼ����1��0
	            //��ʾ���ڷ񣻶���Ȩͼ����ΪȨֵ����
	InfoType *info;//�û������Ϣ��ָ��
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	AdjMatrix  arcs;                 // �ڽӾ���                      
	int        vexnum, arcnum;       // ͼ�ĵ�ǰ�������ͻ���  
}Graph;

typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;

Status CreateGraph(Graph *G) {
	//�����ڽӾ��󷨱�ʾ����������֪��ͼ
	G->vexnum = 9;   //��ͼ�Ķ����� 
	G->arcnum = 12;  //��ͼ�Ļ���
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = INFINITY;  //��ʼ���ڽӾ���,INFINITY��ʾ������ 
		}
	}//��ʼ��ͼ
	//���ڵĶ��㸳ֵ
	Add(G, 0, 1); Add(G, 0, 2); Add(G, 0, 3); Add(G, 0, 6);
	Add(G, 1, 2); Add(G, 3, 4); Add(G, 3, 5); Add(G, 4, 5);
	Add(G, 5, 7); Add(G, 6, 7); Add(G, 6, 8); Add(G, 7, 8);
	//��ʾ0-1,0-2.��������������
	return OK;
}

Status Add(Graph*G, int x, int y) {
	//�����ڽӾ������ڸ�ֵΪ1 
	if (x >= MAX_VERTEX_NUM || y >= MAX_VERTEX_NUM) {
		return ERROR;//��������ͼ�ķ�Χ���ͷ���ERROR
	}
	G->arcs[x][y].adj = G->arcs[y][x].adj = 1;//����ͼ�����ڽӶ�Ϊ1���ҵ���������ʱ��������ֵ
	return OK;
}
/*-------------ͼ������------------------*/

typedef int ElemType;

#define MAXQSIZE 100 //��������

typedef struct QNode {
	ElemType data;
	struct QNode *priou;//�ڵ����һ���ڵ�
	struct QNode *next;//�ڵ����һ���ڵ�
}QNode, LinkList, *QueuePtr;

typedef struct {
	QueuePtr front;//ǰ���
	QueuePtr rear;//�����
}LinkQueue;

Status InitQueue(LinkQueue *Q) {
	//���еĳ�ʼ��
	Q->front = Q->rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));
	if (!(Q->front)) {
		return ERROR;
	}
	Q->front->next = Q->rear->next = NULL;//ʹ����Ϊ��
	return OK;
}

Status EnQueue(LinkQueue *Q, ElemType e) {
	//����еĲ���
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		return ERROR;
	}
	p->data = e;//���浽�����������
	p->next = NULL;//��һ���ڵ�Ϊ��
	p->priou = Q->front;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, ElemType *e) {
	//�����в���
	if (QueueEmpty(*Q)) {
		//����Ϊ��ʱֹͣ����������ERROR
		return ERROR;
	}
	Q->front = Q->front->next;//ͷ���ָ��������һ���ڵ�
	*e = Q->front->data;
	return OK;
}

typedef enum {
	false,
	true
}bool;

bool QueueEmpty(LinkQueue Q) {
	//�ж����ǲ���һ���ն���
	if (Q.front == Q.rear) {
		return true;//ͷ���ͺ�һ���ڵ�Ϊͬһ������ô�������Ϊ��
	}
	return false;//������в�Ϊ��
}

int FirstAdjVex(Graph G, int i) {
	//���ص�һ���ڽӶ��㣬û�еĻ�����-1 
	for (int k = 0; k < G.vexnum; k++) {
		if (G.arcs[i][k].adj == 1) {
			return k;//������ڽӽڵ㣬��������ڽӵĽڵ�
		}
	}
	return -1;
}

int NextAdjVex(Graph G, int i, int j) {
	//������һ���ڽӶ��㣬û�еĻ�����-1 
	for (int k = j + 1; k < G.vexnum; k++) {
		if (G.arcs[i][k].adj == 1) {
			return k;
		}
	}
	return -1;
}
/*----------------���еĲ���------------*/
#define FALSE 0 
#define TRUE 1 

int visited[MAX_VERTEX_NUM];

void BFSTraverse(Graph G, int a, int b) {
	//��������ȵķǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited.
	LinkQueue Q;  //�������� 
	for (int v = 0; v < G.vexnum; ++v) {
		visited[v] = FALSE;  //��ʼ�����ʱ�־ 
	}
	InitQueue(&Q); // �ÿյĸ�������Q 
	EnQueue(&Q, a); //������� 
	visited[a] = TRUE;
	bool flag = false;
	int u, w;
	while (!QueueEmpty(Q)) //���в�Ϊ��ʱִ��
	{
		DeQueue(&Q, &u);//�����в���
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
		{
			//���ν����ڶ������� 
			if (w == b) {
				EnQueue(&Q, w);    //����в���
				PrintFoot(Q, a);  //���·�� 
				flag = true;
				break;
			}//if
			if (!visited[w]) {
				//wΪu��δ���ʵ��ڽӶ���
				EnQueue(&Q, w);   //�����				
				visited[w] = true;
			}//if
		}//for
		if (flag) {
			break;
		}//if
	}//while
}//BFSTraverse
/*---------ͼ�ı���--------------*/

Status PrintFoot(LinkQueue Q, int start) {
	//������·��
	int foot[MAX_VERTEX_NUM];///��󶥵���
	int i;
	QueuePtr p;//����һ������
	p = Q.rear;//pָ���β�ڵ�
	for (i = 0; i < MAX_VERTEX_NUM; i++) {
		foot[i] = -1;
	}//���еĳ�ʼ��
	foot[0] = p->data;
	p = p->priou;
	for (i = 1; p->data != start; i++) {
		foot[i] = p->data;
		p = p->priou;
	}
	foot[i] = p->data;
	for (; i >= 0; i--) {
		//������� 
		if (foot[i] >= 0) {
			printf("%d ", foot[i] + 1);
		}
	}
}

int main()
{
	Graph G;
	CreateGraph(&G);//����һ��ͼͼ�����ҳ�ʼ����1
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (j != i) {
				printf("%d<->%d:", i + 1, j + 1);
				BFSTraverse(G, i, j);//��ȱ���
				printf("\n");
			}//if
		}//for j
	}//for i
	return 0;
}