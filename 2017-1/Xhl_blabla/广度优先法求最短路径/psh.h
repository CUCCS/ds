#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100//���洢
#define MAXNUM 10//��֪ͼ����
typedef struct node
{
	int number;//�洢����
	struct node *next;//ָ��
}node, *vertexnode;//����ͼԪ��
typedef struct
{
	vertexnode ad[MAXSIZE];//��̬��������洢��Ϣ
}Graph;//ͼ�Ĺ���
struct queue//���ö��У����ڴ洢��ͨ·���������Ϣ
{
	int vertex;//����
	int pre_num;//�ڼ���
}queue[MAXSIZE];
int  front, rear;
void  print(int front);//���ڴ�ӡ��������
void CreateGraph(Graph **g, int array[][MAXSIZE], int k);//ͷ�巨��ʼ���ڽӾ���
void shortest_path(Graph *g, int v, int u, int *visited);//�����·��