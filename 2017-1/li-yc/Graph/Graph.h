#include <stdio.h>
#include <stdlib.h>
#include "Queen.h"

#define MAX 12

typedef struct Graph{
	bool** matrix;
	int size;
}Graph;
Graph CreatGraph(int size);//创建图
Status InitTestGraph(Graph* G);//初始化图
Status TraverseGraph(Graph a);//遍历图
Status BFSTraverse(Graph* g, int start ,int end);//广度优先搜索
int FirstAdjVex(Graph p, int i);//初始点
int NextVex(Graph g,int i,int j);//下一个点
Status TraversePath(LinkQueue Q, int start);//打印路径