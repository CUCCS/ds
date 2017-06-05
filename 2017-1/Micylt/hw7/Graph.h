#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int QElemType;
#define MAX 20 //最大顶点个数


//定义队列的结构以及相关函数
typedef enum 

{
	FALSE,
	TRUE,
}BOOL;

typedef enum 
{
	OK,
	OVERFLOW,
	ERROR,
} Status;

typedef struct QNode 
{
	QElemType data;
	struct QNode *next;
	struct QNode *prious;
}QNode, *QueuePtr;

typedef struct LinkQueue 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/*关于队列的相关操作*/
Status InitQueue(LinkQueue q);//初始化队列
Status EnQueue(LinkQueue *q, QElemType e);//加入一个结点
BOOL QueueEmpty(LinkQueue q);//检查队列是否为空
Status DeQueue(LinkQueue *q, QElemType *e);//删除一个结点
Status TraverseQueue(LinkQueue q);//遍历队列

/*-------------------------------------------------------------------------------------------------------------------------*/

//定义图的结构以及相关的操作函数

typedef struct Graph 
{
	BOOL** matrix;
	int size;
}Graph;

Graph CreatGraph(int size);//创建图
Status InitTestGraph(Graph* G);//初始化图
Status TraverseGraph(Graph a);//遍历图
Status BFSTraverse(Graph* g, int start, int end);//广度优先搜索
int FirstAdjVex(Graph p, int i);//初始点
int NextVex(Graph g, int i, int j);//下一个点
Status TraversePath(LinkQueue Q, int start);//打印路径