#include <stdio.h>
#include <stdlib.h>
#include "Queen.h"

#define MAX 12

typedef struct Graph{
	bool** matrix;
	int size;
}Graph;
Graph CreatGraph(int size);//����ͼ
Status InitTestGraph(Graph* G);//��ʼ��ͼ
Status TraverseGraph(Graph a);//����ͼ
Status BFSTraverse(Graph* g, int start ,int end);//�����������
int FirstAdjVex(Graph p, int i);//��ʼ��
int NextVex(Graph g,int i,int j);//��һ����
Status TraversePath(LinkQueue Q, int start);//��ӡ·��