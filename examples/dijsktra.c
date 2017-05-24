 /*******************************************************************************
  文件名: 
  项目:   
  模块:   
  作者:   huangwei
  版本:   0.1
  创建于:  
  描述:

  修改历史:
  日期:     修改人:    修改描述:

 *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "myds.h"
#include "dijkstra.h"
#include "graph.h"

int minDistance(int dist[], bool sptSet[], int vexnum) {
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < vexnum; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v]; 
            min_index = v;
        }
    }
 
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}

void printSolution(int dist[], int vexnum, int parent[], int src) {
    printf("Vertex\t  Distance\tPath");
    for (int i = 0; i < vexnum; i++) {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}

void dijkstra(Graph g, int src) {
    int count, u, v;
    int vexnum = g.vexnum;
    int dist[vexnum];  // 从顶点src到其他所有顶点的最短距离数组
 
    // sptSet[i]从顶点src到指定顶点i的最短路径是否包含顶点i
    bool sptSet[vexnum];
 
    // 保存最短路径树
    int parent[vexnum];
    int **graph = g.matrix;
 
    for (int i = 0; i < vexnum; i++) {
        parent[i] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
 
    dist[src] = 0;
 
    // 从指定顶点src出发的所有最短路径
    for (count = 0; count < vexnum - 1; count++) {
        u = minDistance(dist, sptSet, vexnum);
 
        sptSet[u] = true;
 
        for (v = 0; v < vexnum; v++) {
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }  
        }
    }
 
    printSolution(dist, vexnum, parent, src);
}


