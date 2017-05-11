#include "Graph.h"
void _connect(Graph* graph, int a, int b) {
	graph->matrix[a - 1][b - 1] = 1;
	graph->matrix[b - 1][a - 1] = 1;
}
bool _connected(Graph* graph, int a, int b) {
	return graph->matrix[a - 1][b - 1];
}
void _show(Graph* graph) {
	int x, y, size = graph->size;
	/*打印第一行*/
	printf("   ");
	for (x = 0; x < size; ++x) { printf("%2d ", x + 1); }
	printf("\n");
	/*打印剩下size行*/
	for (y = 0; y < size; ++y) {
		printf("%2d ", y + 1);
		for (x = 0; x < size; ++x) { printf(" %d ", graph->matrix[x][y]); }
		printf("\n");
	}
}
bool __allVisited(Graph* graph, bool* visited) {
	int size = graph->size;
	for (int i = 0; i < size; ++i) {
		if (!visited[i])
			return false;
	}
	return true;
}
void __backwardTraverse(Node* p) {
	if (p->prior) {
		__backwardTraverse(p->prior);
	}
	printf("%d ", p->data);
}
void _directory(Graph* graph, int start, int end) {
	/*队列与辅助数组*/
	Queue q = newQueue();
	bool* visited = (bool*)malloc(graph->size * sizeof(bool));

	int size = graph->size;
	int i;

	for (i = 0; i < size; ++i) { visited[i] = 0; }
	Visit(start);
	EnQueue(&q, start);
	DeQueue(&q);
	//TraverseQueue(q);
	while (!__allVisited(graph, visited)) {
		for (i = 1; i <= size; ++i) {
			if (graph->connected(graph, start, i) && !isVisited(i)) {
				Visit(i);
				EnQueue(&q, i);
				if (i == end) { break; }
			}
		}
		if (i == end) { break; }
		start = q.front->data;
		DeQueue(&q);
		//TraverseQueue(q);
	}
	__backwardTraverse(q.rear);
}
Graph newGraph(int size) {
	Graph temp;
	int i, j;
	temp.size = size;
	temp.matrix = (bool**)malloc(size * sizeof(bool*));
	for (i = 0; i < size; ++i) {
		temp.matrix[i] = (bool*)malloc(size * sizeof(bool));
		for (j = 0; j < size; ++j) {
			temp.matrix[i][j] = 0;
		}
	}

	temp.connect = _connect;
	temp.connected = _connected;
	temp.show = _show;
	temp.directory = _directory;
	return temp;
}