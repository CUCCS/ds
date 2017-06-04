#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define MAX_VERTEX_NUM 100
#define INFINITY INT_MAX    //��ʾ�������㲻������ֵΪ����
#define Visit(x) {visited[x]=true;}


bool visited[MAX_VERTEX_NUM];

typedef int VRType;

typedef struct ArcCell   // ���Ķ���
{ 
	VRType  adj;     // VRType�Ƕ����ϵ���͡�
					 // ����Ȩͼ����1��0��ʾ���ڷ�
} AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct   // ͼ�Ķ���
{ 
	AdjMatrix  arcs;                 // ������Ϣ                     
	int   vexnum, arcnum;       // ������������                
} Graph;

Status CreateGraph(Graph *G);  //����һ������ͼ

Status Connect(Graph*G, int x, int y);  //Ϊ�ڽӾ���ֵ,��������֮������ӹ�ϵ

void BFSTraverse(Graph G, int a, int b);  //������ȱ���ͼ

ElemType FirstAdjVex(Graph G, int i);  //���ض���i�ĵ�һ���ڽӶ���

ElemType NextAdjVex(Graph G, int i, int j);  //���ض���i����һ���ڽӶ���

Status Show(LinkQueue Q, int start);  //����������������·��

Status Print();  //��ӡ�����

