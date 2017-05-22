#include <stdio.h>
#include "Graph.h"
#define SIZE 9

int main(void) {
	/*测试用例*/
	Graph g = newGraph(SIZE);
	g.connect(&g, 1, 2);
	g.connect(&g, 1, 3);
	g.connect(&g, 1, 4);
	g.connect(&g, 1, 7);
	g.connect(&g, 2, 3);
	g.connect(&g, 4, 5);
	g.connect(&g, 4, 6);
	g.connect(&g, 5, 6);
	g.connect(&g, 6, 8);
	g.connect(&g, 7, 8);
	g.connect(&g, 7, 9);
	g.connect(&g, 8, 9);
	
	/*寻找各点到其他各点的最短路径*/
	for (int start = 1; start <= SIZE; ++start) {
		for (int end = 1; end <= SIZE; ++end) {
			if (start == end) { continue; }
			printf("%d -> %d : ",start,end);
			g.directory(&g, start, end);
			printf("\n");
		}
	}
	return 0;
}