#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
 
Status InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));
	if (!(Q->front)) {
		return ERROR;
	}
	Q->front->next = Q->rear->next = NULL;
	return OK;
}//��ʼ������
Status EnQueue(LinkQueue *Q, ElemType e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		return ERROR;
	}
	p->data = e;
	p->next = NULL;
	p->priou = Q->front;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}//����
Status DeQueue(LinkQueue *Q, ElemType *e) {
	if (QueueEmpty(*Q)) {
		return ERROR;
	}
	Q->front = Q->front->next;
	*e = Q->front->data;
	return OK;
}//����
bool QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	return false;
}; //�ж��Ƿ�Ϊ�ն���

int FirstAdjVex(Graph G, int i) {
	int k;
	for (k = 0; k < G.vexnum; k++) {
		if (G.arcs[i][k].adj == 1) {
			return k;
		}
	}
	return -1;
}//���ص�һ���ڽӶ��㣬û�еĻ�����-1
int NextAdjVex(Graph G, int i, int j) {
	int k;
	for (k = j + 1; k < G.vexnum; k++) {
		if (G.arcs[i][k].adj == 1) {
			return k;
		}
	}
	return -1;
}//������һ���ڽӶ��㣬û�еĻ�����-1
Status CreateGraph(Graph *G) {
	int i, j, k;
	G->vexnum = 9;   //������
	G->arcnum = 12;  //����

	for (i = 0; i < G->vexnum; i++) {
		for (j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = INFINITY;  //��ʼ���ڽӾ���,INFINITY��ʾ������
		}
	}
	//��ʼ��ͼ,���ڶ��㸳ֵ
	Add(G, 0, 1); Add(G, 0, 2); Add(G, 0, 3); Add(G, 0, 6);
	Add(G, 1, 2); Add(G, 3, 4); Add(G, 3, 5); Add(G, 4, 5);
	Add(G, 5, 7); Add(G, 6, 7); Add(G, 6, 8); Add(G, 7, 8);

	return OK;
}//������֪ͼ
Status Add(Graph*G, int x, int y) {
	//�����ڽӾ���������ֵΪ1
	if (x >= MAX_VERTEX_NUM || y >= MAX_VERTEX_NUM) {
		return ERROR;
	}
	G->arcs[x][y].adj = G->arcs[y][x].adj = 1;
	return OK;
}//Ϊ�ڽӾ���ֵ
void BFSTraverse(Graph G, int a, int b) {
	int u, v, w;
	bool flag;
	LinkQueue Q;  //��������
	for (v = 0; v < G.vexnum; ++v) {
		visited[v] = FALSE;  //��ʼ�����ʱ�־
	}
	InitQueue(&Q); // �ÿյĸ�������Q
	EnQueue(&Q, a); //�������
	visited[a] = TRUE;
	flag = false;
	while (!QueueEmpty(Q)) {
		DeQueue(&Q, &u);
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
			//���ν����ڶ�������
			if (w == b) {
				EnQueue(&Q, w);
				PrintFoot(Q, a);  //���·��
				flag = true;
				break;
			}
			if (!visited[w]) {
				EnQueue(&Q, w);
				visited[w] = true;
			}
		}
		if (flag) {
			break;
		}
	}
}//������ȱ���
Status PrintFoot(LinkQueue Q, int start) {
	int foot[MAX_VERTEX_NUM];
	int i;
	QueuePtr p;
	p = Q.rear;
	for (i = 0; i < MAX_VERTEX_NUM; i++) {
		foot[i] = -1;
	}
	foot[0] = p->data;
	p = p->priou;
	for (i = 1; p->data!= start; i++) {
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
}//���·��

int main()
{
	Graph G;
	int i, j;

	CreateGraph(&G);

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (j != i) {
				printf("%d<->%d:", i + 1, j + 1);
				BFSTraverse(G, i, j);
				printf("\n");
			}
		}
	}

	return 0;
}