#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <limits.h>

#include "graph.h"

int minDistance(int dist[], bool sptSet[], int vexnum);
void printPath(int parent[], int j);
void printSolution(int dist[], int vexnum, int parent[], int src);
void dijkstra(Graph g, int src);

#endif

