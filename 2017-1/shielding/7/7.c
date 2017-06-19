#include "7.h"

int main()
{
	int i;
	int j;

	MGraph graph;
	CreateUDN(&graph);
	for (i = 1; i <= graph.vexnum; i++)
	{
		for (j = 1; j <= graph.vexnum; j++)
		{
			LinkQueue Q;
			InitQueue(&Q);
			printf("%d<->%d:", i, j);
			BFSTraverse(&graph, &Q, i, j);
			print(&Q, i);
			DestroyQueue(&Q);
		}
	}

}