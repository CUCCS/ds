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
	};//用二维数组存储用例邻接矩阵的信息
	Graph *g;//定义图g 
	CreateGraph(&g, graph_array);//初始化临接矩阵
	int j;
	for (int i = 0; i < 9; i++)
	{//分行 
		printf("\n");//分行 
		for (j = 0; j < 9; j++)
		{//分列即分别遍历 
			if (i == j)
			{//i=j 表明是自己到自己，为0，不做任何行为 
			}
			else if(i != j)//不是自己到自己 
			{
				front = -1;//初始化front 
			    rear = -1;//初始化rear 
				int visited[MAXSIZE] = { 0 };//初始化 visit
				printf("%d<->%d ", i + 1, j + 1);//输出 
				shortest_path(g, i, j, visited);//求最短路径 
				printf("\n");//换行 
			}//end if
		}//end for
	}//end for
	for (int i = 0; i <  MAX_VERTEX_NUM; i++)
	{	//释放堆上的内存
		node *p;//定义图元素 
		node *q;//定义图元素 
		p = g->ad[i];//p存g的数据 
		while (p != NULL)//当p不为空时 
		{
			q = p;//令q=p 
			p = p->next;//p指向下一个数据 
			free(q);//释放q的内存 
		}//end while
	}//end for
	return 0;//返回 
}
