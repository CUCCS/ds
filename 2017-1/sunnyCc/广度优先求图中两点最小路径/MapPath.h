// ������������ͼ������洢��ʾ����������������
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
	int vexs[9];//vex��������ʾͼ�оŸ�����Ƿ񱻷��ʣ������������Ԫ�ر���ֵΪ0
	Array a;//����ʹ���ڽӾ�������ʾ����ض�ͼ�����Դ���һ������Array����ʾ�����֮����ͨ��ϵ
	int vexnum, arcnum;//vexnum��arcnum�ֱ��ʾͼ�Ľ��ͻ���
}Graph;

/*���������������л�������������������*/
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

/*������������ͼ�Ĳ���������������*/
Status CreatGraph(Graph *, Array);
int FirstAdjVex(Graph, QElemType);
LinkQueue BFSTraverse(Graph G, int a, int b);//������ȱ���
void Print(LinkQueue, int a, int b);//������һ�����н������