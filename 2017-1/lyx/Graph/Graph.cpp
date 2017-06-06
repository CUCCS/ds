#include "Graph.h"
int main()
{
	int graph_array[][MAXSIZE] = {
		{ 1,1,1 ,1,0,0, 1,0,0 },
		{ 1,1,1 ,0,0,0, 0,0,0 },
		{ 1,1,1, 0,0,0, 0,0,0 },
		{ 1,0,0, 1,1,1, 0,0,0 },
		{ 0,0,0, 1,1,1, 0,0,0 },
		{ 0,0,0, 1,1,1, 0,1,0 },
		{ 1,0,0, 0,0,0, 1,1,1 },
		{ 0,0,0 ,0,0,1, 1,1,1 },
		{ 0,0,0 ,0,0,0, 1,1,1 }
	};//�ö�ά����洢�����ڽӾ������Ϣ
	Graph *g;//����ͼg 
	CreateGraph(&g, graph_array);//��ʼ���ٽӾ���
	int j;
	for (int i = 0; i < 9; i++)
	{//���� 
		printf("\n");//���� 
		for (j = 0; j < 9; j++)
		{//���м��ֱ���� 
			if (i == j)
			{//i=j �������Լ����Լ���Ϊ0�������κ���Ϊ 
			}
			else if(i != j)//�����Լ����Լ� 
			{
				front = -1;//��ʼ��front 
			    rear = -1;//��ʼ��rear 
				int visited[MAXSIZE] = { 0 };//��ʼ�� visit
				printf("%d<->%d ", i + 1, j + 1);//��� 
				shortest_path(g, i, j, visited);//�����·�� 
				printf("\n");//���� 
			}//end if
		}//end for
	}//end for
	for (int i = 0; i <  MAX_VERTEX_NUM; i++)
	{	//�ͷŶ��ϵ��ڴ�
		node *p;//����ͼԪ�� 
		node *q;//����ͼԪ�� 
		p = g->ad[i];//p��g������ 
		while (p != NULL)//��p��Ϊ��ʱ 
		{
			q = p;//��q=p 
			p = p->next;//pָ����һ������ 
			free(q);//�ͷ�q���ڴ� 
		}//end while
	}//end for
	return 0;//���� 
}
