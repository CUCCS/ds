#include <stdio.h>
#include "Graph.h"

int main() 
{
	Graph G;

	CreateGraph(&G);
	
	Connect(&G, 0, 1);
	Connect(&G, 0, 2);
	Connect(&G, 0, 3);
	Connect(&G, 0, 6);
	Connect(&G, 1, 2);
	Connect(&G, 3, 4);
	Connect(&G, 3, 5);
	Connect(&G, 4, 5);
	Connect(&G, 5, 7);
	Connect(&G, 6, 7);
	Connect(&G, 6, 8);
	Connect(&G, 7, 8);

	Print(G);

	return 0;
}