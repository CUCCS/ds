// ——————图的数组存储表示————————
#include <stdio.h>
#include <stdlib.h>

#define MAX 9
typedef int VRType;
typedef int QElemType;

typedef enum {
	OK,
	FALSE,
	TRUE,
}Status;

typedef int Array[MAX][MAX];
typedef struct {
	int vexs[9];//vex数组来表示图中九个结点是否被访问，访问则该数组元素被赋值为0
	Array a;//由于使用邻接矩阵来表示这个特定图，所以创建一个数组Array来表示各结点之间连通关系
	int vexnum, arcnum;//vexnum和arcnum分别表示图的结点和弧数
}Graph;

/*——————队列基本操作——————*/
typedef struct QNode {
	QElemType data;
	struct QNode *Next, *Priou;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
void InitQueue(LinkQueue *Q);
void EnQueue(LinkQueue *Q, QElemType e);
void DeQueue(LinkQueue *Q, QElemType *e);
Status QueueEmpty(LinkQueue Q);
Status DestroyQueue(LinkQueue *Q);

/*——————图的操作——————*/
Status CreatGraph(Graph *, Array);
int FirstAdjVex(Graph, QElemType);
LinkQueue BFSTraverse(Graph G, int a, int b);//广度优先遍历
void Print(LinkQueue, int a, int b);//构造了一个队列进行输出