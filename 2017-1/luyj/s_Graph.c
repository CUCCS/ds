#include "Graph.h"

int main()
{
	int i;
	int j;

	MGraph Graph;
	CreateUDN(&Graph);
	for (i = 1; i <= Graph.vexnum; i++)
	{
		for (j = 1; j <= Graph.vexnum; j++)
		{
			LinkQueue Q;
			InitQueue(&Q);
			printf("%d<->%d:", i, j);
			BFSTraverse(&Graph, &Q, i, j);
			print(&Q, i);
			DestroyQueue(&Q);
		}
	}

}