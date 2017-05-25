//�������ȱ�����ʾ������ͼ���������̾��루���ڽӾ���
#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100//���洢
#define MAX_VERTEX 20//ͼ������

typedef struct node//����ͼ
{
	int data;//����洢����
	struct node *next;
}node, *vexnode;

typedef struct
{
	vexnode ad[MAXSIZE];//��̬��������洢��Ϣ
}Graph;//ͼ�Ĺ���

//���帨���������������洢·����Ϣ
struct queue
{
	int vertex;//����
	int pre_num;//�ڼ���
}queue[MAXSIZE];

int front, rear;

void print(int front)//���ڴ�ӡ��������
{
	while (front != 0)
	{
		int b = front;
		front = queue[front].pre_num;
		queue[b].pre_num = -1;//���ʹ�����Ϊ-1
	}
	front = 0;//front��0
	while (front<MAXSIZE)
	{
		if (queue[front].pre_num == -1)//���·��
		{
			printf("%d ", queue[front].vertex + 1);
		}
		front++;
	}
}

//����ͼ
void CreateGraph(Graph **g, int array[][MAXSIZE])//ͷ�巨��ʼ���ڽӾ���
{
	(*g) = (Graph *)malloc(sizeof(Graph));
	for (int i = 0; i<MAX_VERTEX; i++)
	{
		(*g)->ad[i] = NULL;//�ֱ��ʼ���ṹ��ָ��
	}
	int c = 0;
	node *p;
	int j;
	for (int i = 0; i<MAX_VERTEX; i++)
	{//����
		for (j = 0; j<MAX_VERTEX; j++)
		{//�ֶ�
			if (array[i][j] != 0)//�����ͨ·�����ڴ沢�洢
			{
				p = (node *)malloc(sizeof(node));//�����ڴ�
				p->data = j;
				p->next = (*g)->ad[i];
				(*g)->ad[i] = p;//ͷ�巨�����ڽӾ���
			}
		}
	}
}

//������ȱ����������·��
void shortest_path(Graph *g, int v, int u, int *visited)
{
	node *p;
	int m;
	int find = 0;//findΪflag������Ƿ��ҵ�
	rear++;
	for (int a = 0; a < MAXSIZE; a++)//��ʼ������
	{
		queue[a].vertex = 0;
		queue[a].pre_num = 0;
	}
	queue[rear].vertex = v;//���
	queue[rear].pre_num = -1;//��Ǹõ�
	visited[v] = 1;//�Ѹõ���Ϊ�Ѿ����ʹ�
	while (front != rear && !find)
	{
		front++;
		m = queue[front].vertex;//���������Ӷ�����������
		if (m == u)//����ҵ����յ�
		{
			find = 1;//find��ʶ���ҵ�
			print(front);
			return;//����
		}
		p = g->ad[m];//�������������
		while (p != NULL)
		{//������ȱ���
			if (visited[p->data] == 0)//���û�з��ʹ�
			{
				visited[p->data] = 1;//��ʶ�ѷ���
				rear++;
				queue[rear].vertex = p->data;
				queue[rear].pre_num = front;
			}
			p = p->next;//������һ��
		}
	}
}
int main()
{
	int graph_array[][MAXSIZE] = {

	{0,1,1,1,0,0,1,0,0},
	{1,0,1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0,0},
	{1,0,0,0,1,1,0,0,0},
	{0,0,0,1,0,1,0,0,0},
	{0,0,0,1,1,0,0,1,0},
	{1,0,0,0,0,0,0,1,1},
	{0,0,0,0,0,1,1,0,1},
	{0,0,0,0,0,0,1,1,0}
		
	};
	
	Graph *g;
	CreateGraph(&g, graph_array);
	for (int i = 0; i < 9; i++)
	{
		
		for (int j = i+1; j < 9; j++)
		{
				front = -1;//��ʼ��front 
				rear = -1;//��ʼ��rear 
				int visited[MAXSIZE] = { 0 };//��ʼ�� visit
				printf("%d<->%d�� ", i + 1, j + 1);//��� 
				shortest_path(g, i, j, visited);//�����·�� 
				printf("\n");
			
		}
		printf("\n");
	}
	for (int i = 0; i < MAX_VERTEX; i++)
	{	//�ͷ��ڴ�
		node *p;
		node *q;
		p = g->ad[i];
		while (p != NULL)//��p��Ϊ��ʱ 
		{
			q = p;//��q=p 
			p = p->next;//pָ����һ������ 
			free(q);//�ͷ�q���ڴ� 
		}
	}
	return 0;
}