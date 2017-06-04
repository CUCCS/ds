#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100//���洢
#define MAX_VERTEX_NUM 20//ͼ����
typedef struct node//����ͼԪ��
{
	int number;//�洢����
	struct node *next;//ָ��
}node, *vexnode;
typedef struct
{
	vexnode ad[MAXSIZE];//��̬��������洢��Ϣ
}Graph;//ͼ�Ĺ���
struct queue//���ö��У����ڴ洢��ͨ·���������Ϣ
{
	int vertex;//����
	int pre_num;//�ڼ���
}queue[MAXSIZE];
int front, rear;
void print(int front)//���ڴ�ӡ��������
{
	while (front != 0)
	{
		int b = front;//��֤����������壬����һ������b
		front = queue[front].pre_num;//ѭ��Ѱ����һ����
		queue[b].pre_num = -1;//���ʹ�����Ϊ-1
	}
	front = 0;//��front��Ϊ0
	while (front<MAXSIZE)//��֤���������
	{
		if (queue[front].pre_num == -1)//�����·�������
		{
			printf("%d ", queue[front].vertex + 1);//���·��
		}
		front++;//���½���
	}
}//print
void CreateGraph(Graph **g, int array[][MAXSIZE])//ͷ�巨��ʼ���ڽӾ���
{
	(*g) = (Graph *)malloc(sizeof(Graph));//�����ڴ�
	for (int i = 0; i<MAX_VERTEX_NUM; i++)
	{
		(*g)->ad[i] = NULL;//�ֱ��ʼ���ṹ��ָ��
	}
	int c = 0;
	node *p;
	int j;
	for (int i = 0; i<MAX_VERTEX_NUM; i++)
	{//����
		for (j = 0; j<MAX_VERTEX_NUM; j++)
		{//�ֶ�
			if (array[i][j] != 0)//�����ͨ·�����ڴ沢�洢
			{
				p = (node *)malloc(sizeof(node));//�����ڴ�
				p->number = j;
				p->next = (*g)->ad[i];
				(*g)->ad[i] = p;//ͷ�巨�����ڽӾ���
			}
		}
	}
}//CreateGraph
void shortest_path(Graph *g, int v, int u, int *visited)//�����·��
{
	node *p;
	int m;
	int find = 0;//findΪ��ʶ
	rear++;//rear�Լ�
	for (int a = 0; a < MAXSIZE; a++)//��ʼ������
	{
		queue[a].vertex = 0;//����
		queue[a].pre_num = 0;//�ڼ���
	}
	queue[rear].vertex = v;//���
	queue[rear].pre_num = -1;//��Ǹõ�
	visited[v] = 1;//�Ѹõ���Ϊ�Ѿ����ʹ�
	while (front != rear && !find)//�ײ���β
	{
		front++;//front�Լ�
		m = queue[front].vertex;//���������Ӷ�����������
		if (m == u)//����ҵ����յ�
		{
			find = 1;//find��Ϊ1
			print(front);//���front
			return;//����
		}
		p = g->ad[m];//�������������
		while (p != NULL)
		{//������ȱ���
			if (visited[p->number] == 0)//���û�з��ʹ�
			{
				visited[p->number] = 1;//��Ϊ1
				rear++;//rear�Լ�
				queue[rear].vertex = p->number;//����
				queue[rear].pre_num = front;//��
			}
			p = p->next;//ָ����һ������������
		}
	}
}//shortest_path