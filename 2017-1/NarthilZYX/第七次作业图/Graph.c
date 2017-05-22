#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int FirstAdjVex(Graph G, int i) {
	int k;
	for (k = 0; k < G.vexnum; k++) {
		if (G.arcs[i][k].adj == 1) {
			return k;
		}
	}
	return -1;
}//返回第一个邻接顶点，没有的话返回-1
int NextAdjVex(Graph G, int i, int j) {
	int k;
	for (k = j + 1; k < G.vexnum; k++) {
		if (G.arcs[i][k].adj == 1) {
			return k;
		}
	}
	return -1;
}//返回下一个邻接顶点，没有的话返回-1
Status CreateGraph(Graph *G) {
	int i, j;
	G->vexnum = 9;   //顶点数
	G->arcnum = 12;  //边数
	for (i = 0; i < G->vexnum; i++) {
		for (j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = INFINITY;  //初始化邻接矩阵,INFINITY表示不相邻，即无穷
		}
	}
	//初始化图,相邻顶点赋值
	Add(G, 0, 1); Add(G, 0, 2); Add(G, 0, 3); Add(G, 0, 6);
	Add(G, 1, 2); Add(G, 3, 4); Add(G, 3, 5); Add(G, 4, 5);
	Add(G, 5, 7); Add(G, 6, 7); Add(G, 6, 8); Add(G, 7, 8);
	
	return OK;
}//构建已知图
Status Add(Graph*G, int x, int y) {
	//构造邻接矩阵，相邻则赋值为1
	if (x >= MAX_VERTEX_NUM || y >= MAX_VERTEX_NUM) {
		return ERROR;
	}
	G->arcs[x][y].adj = G->arcs[y][x].adj = 1;
	return OK;
}//为邻接矩阵赋值
void BFSTraverse(Graph G, int a, int b) {
	int u, v, w;
	bool flag;
	LinkQueue Q;  //辅助队列
	for (v = 0; v < G.vexnum; ++v) {
		visited[v] = False;  //初始化访问标志
	}
	InitQueue(&Q); // 置空的辅助队列Q
	EnQueue(&Q, a); //起点入列
	visited[a] = True;
	flag = false;
	while (!QueueEmpty(Q)) {
		DeQueue(&Q, &u);
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
			//依次将相邻顶点入列
			if (w == b) {
				EnQueue(&Q, w);
				PrintFoot(Q, a);  //输出路径
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
}//广度优先遍历
Status PrintFoot(LinkQueue Q, int start) {
	int foot[MAX_VERTEX_NUM];
	int i;
	QueuePtr p;
	p = Q.rear;
	for (i = 0; i < MAX_VERTEX_NUM; i++) {
		foot[i] = -1;
	}
	foot[0] = p->data;//数据进入数组
	p = p->priou;//沿priou指针往前使前一个数据进入数组
	for (i = 1; p->data!= start; i++) {
		foot[i] = p->data;//依次往前
		p = p->priou;
	}
	foot[i] = p->data;
	for (; i >= 0; i--) {
		//倒序输出
		if (foot[i] >= 0) {
			printf("%d ", foot[i] + 1);
			}
	}
	return OK;
}//输出路径

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