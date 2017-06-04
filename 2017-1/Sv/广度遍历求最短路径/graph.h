// 图的数组存储表示————————
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 9
typedef int VRType;
typedef int QElemType;

typedef enum {
    FALSE,
    OK,
    OVERFLOW,
    TRUE,
    ERROR,
}Status;

typedef VRType AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
    int vexs[9];
    AdjMatrix arcs;
    int vexnum,arcnum;//图的顶点和弧数
}MGraph;

//队列基本操作——————
typedef struct QNode {
    QElemType data;
    struct QNode *Next,*Priou;
}QNode, *QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
void InitQueue(LinkQueue *Q);
void EnQueue(LinkQueue *Q, QElemType e);
void DeQueue(LinkQueue *Q, QElemType *e) ;
Status QueueEmpty(LinkQueue Q);
Status DestroyQueue(LinkQueue *Q);
//图的操作——————
void CreatGraph(MGraph *,AdjMatrix );
int FirstAdjVex(MGraph,QElemType);
void BFSTraverse(MGraph G,int a,int b);
