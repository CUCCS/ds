#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int QElemType;
#define MAX 20 //��󶥵����


//������еĽṹ�Լ���غ���
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

/*���ڶ��е���ز���*/
Status InitQueue(LinkQueue q);//��ʼ������
Status EnQueue(LinkQueue *q, QElemType e);//����һ�����
BOOL QueueEmpty(LinkQueue q);//�������Ƿ�Ϊ��
Status DeQueue(LinkQueue *q, QElemType *e);//ɾ��һ�����
Status TraverseQueue(LinkQueue q);//��������

/*-------------------------------------------------------------------------------------------------------------------------*/

//����ͼ�Ľṹ�Լ���صĲ�������

typedef struct Graph 
{
	BOOL** matrix;
	int size;
}Graph;

Graph CreatGraph(int size);//����ͼ
Status InitTestGraph(Graph* G);//��ʼ��ͼ
Status TraverseGraph(Graph a);//����ͼ
Status BFSTraverse(Graph* g, int start, int end);//�����������
int FirstAdjVex(Graph p, int i);//��ʼ��
int NextVex(Graph g, int i, int j);//��һ����
Status TraversePath(LinkQueue Q, int start);//��ӡ·��