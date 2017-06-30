#include "Graph.h"

int main() 
{
	Graph a = CreatGraph(9);
	int x;
	int y;

	InitTestGraph(&a);
	printf("该图的邻接矩阵如下：\n");
	TraverseGraph(a);
	printf("\n");
	printf("开始遍历每个点到另外一个点的最短路径：\n");
	for (x = 1; x <= 9; x++) 
	{
		for (y = 1; y <= 9; y++) 
		{
			if (x != y) 
			{
				printf("<%d -->%d> ", x, y);
				BFSTraverse(&a, x - 1, y - 1);
				printf("\n");
			}
		}
	}
	printf("遍历结束\n");
	return 0;
}