//�ο�jackcily����ҵ
#include <stdio.h>
#include <malloc.h>

#define Max 100  //�����������
#define Maxnum 10 //��֪ͼ����

//ͼ���ڽӾ���洢
typedef struct Node
{
	int num;//�洢����
	struct Node *next;
}Node,*vertexnode;
typedef struct 
{
	vertexnode a[Max];
}Graph;
//���ö������ڴ洢ͨ��·���������Ϣ
struct queue
{
	int vertex;//����
	int c_num;//����
}queue[Max];
int front, rear;//����ȫ�ֱ������������������Ķ���
void print(int front);//��ӡ��������
void CreateGraph(Graph **g, int array[][Max], int k);//��ʼ���ڽӾ���
void shortest_path(Graph *g, int i, int j, int *visit);//�����·��