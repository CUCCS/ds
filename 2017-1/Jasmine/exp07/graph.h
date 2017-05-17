#ifndef H_GRAPH  
#define H_GRAPH  

#define INFINITY   99999
#define MAX_VERTEX_NUM 20
int visited[MAX_VERTEX_NUM];
typedef struct ArcCell            //弧的定义
{
	int adj;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct                    //图的定义
{
	AdjMatrix arcs;
	int vexnum, arcnum;
}Graph;

#endif 
