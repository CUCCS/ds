#ifndef H_GRAPH  
#define H_GRAPH  

#define INFINITY   99999
#define MAX_VERTEX_NUM 20
int visited[MAX_VERTEX_NUM];
typedef struct ArcCell            //���Ķ���
{
	int adj;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct                    //ͼ�Ķ���
{
	AdjMatrix arcs;
	int vexnum, arcnum;
}Graph;

#endif 
