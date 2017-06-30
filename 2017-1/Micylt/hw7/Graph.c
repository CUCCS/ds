//相关函数的实现
#include"Graph.h"
Status InitQueue(LinkQueue q) {
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front) {
		exit(OVERFLOW);
	}
	q.front->next = q.rear->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue *q, QElemType e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		return OVERFLOW;
	}
	p->data = e;
	p->next = NULL;
	p->prious = q->front;
	q->rear->next = p;
	q->rear = p;
	return OK;
}

BOOL QueueEmpty(LinkQueue q) {
	if (q.front == q.rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

Status DeQueue(LinkQueue *q, QElemType *e) {
	if (QueueEmpty(*q)) {
		return ERROR;
	}
	q->front = q->front->next;
	*e = q->front->data;
	return OK;
}

Status TraverseQueue(LinkQueue q) {
	QueuePtr p;
	printf("开始遍历:\n");
	if (QueueEmpty(q)) {
		printf("此时队列里不存在元素\n");
		return OK;
	}
	p = q.front;
	while (p != q.rear) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}



Graph CreatGraph(int size) {
	Graph temp;
	int i;
	int j;
	temp.size = size;
	temp.matrix = (BOOL*)malloc(size * sizeof(BOOL*));
	for (i = 0; i < size; i++) 
	{
		temp.matrix[i] = (BOOL*)malloc(size * sizeof(BOOL));
		for (j = 0; j < size; j++) 
		{
			temp.matrix[i][j] = 0;
		}
	}
	return temp;
}

Status InitTestGraph(Graph* G) //初始化图
{
	G->matrix[0][1] = 1;
	G->matrix[1][0] = 1;
	G->matrix[0][2] = 1;
	G->matrix[2][0] = 1;
	G->matrix[0][3] = 1;
	G->matrix[3][0] = 1;
	G->matrix[0][6] = 1;
	G->matrix[6][0] = 1;
	G->matrix[1][2] = 1;
	G->matrix[2][1] = 1;
	G->matrix[3][4] = 1;
	G->matrix[4][3] = 1;
	G->matrix[3][5] = 1;
	G->matrix[5][3] = 1;
	G->matrix[4][5] = 1;
	G->matrix[5][4] = 1;
	G->matrix[5][7] = 1;
	G->matrix[7][5] = 1;
	G->matrix[6][7] = 1;
	G->matrix[7][6] = 1;
	G->matrix[6][8] = 1;
	G->matrix[8][6] = 1;
	G->matrix[7][8] = 1;
	G->matrix[8][7] = 1;
	return OK;
}

Status TraverseGraph(Graph a) {
	int size = a.size;
	int i;
	int j;
	for (i = 0; i <= size; i++) {
		printf("%2d", i);
	}
	printf("\n");
	for (j = 0; j < size; j++) {
		printf("%2d", j + 1);
		for (i = 0; i < size; i++) {
			printf("%2d", a.matrix[j][i]);
		}
		printf("\n");
	}
	return OK;
}

int FirstAdjVex(Graph p, int i) {
	int a;
	for (a = 0; a < p.size; a++) {
		if (p.matrix[i][a] == TRUE) {
			return a;
		}
	}
	return -1;
}

int NextVex(Graph g, int i, int j) {
	int a;
	for (a = j + 1; a < g.size; a++) {
		if (g.matrix[i][a] == TRUE) {
			return a;
		}
	}
	return -1;
}

Status TraversePath(LinkQueue Q, int start) {
	int a[MAX] = { -1 };
	QueuePtr p;
	int i = 1;

	p = Q.rear;
	a[0] = p->data + 1;
	p = p->prious;

	while (p->data != start) {
		a[i] = p->data + 1;
		p = p->prious;
		i++;
	}
	a[i] = start + 1;
	for (; i >= 0; i--) {
		if (a[i] >= 0) {
			printf("%d ", a[i]);
		}
	}
	return OK;
}

Status BFSTraverse(Graph *g, int start, int end) {
	LinkQueue a;
	QElemType e;
	BOOL* visited = (BOOL*)malloc(g->size * sizeof(BOOL));
	int i;
	int w;
	int flag = 1;

	a.front = a.rear = (QueuePtr)malloc(sizeof(QNode));
	InitQueue(a);

	for (i = 0; i < g->size; i++) {
		visited[i] = FALSE;
	}
	visited[start] =TRUE;
	EnQueue(&a, start);

	while (!QueueEmpty(a)) {
		DeQueue(&a, &e);
		for (w = FirstAdjVex(*g, e); w != -1; w = NextVex(*g, e, w)) {
			if (w == end) {
				EnQueue(&a, w);
				flag = 0;
				break;
			}
			if (!visited[w]) {
				EnQueue(&a, w);
				visited[w] = TRUE;
			}
		}
		if (flag == 0) {
			TraversePath(a, start);
			printf("\n");
			break;
		}
	}
	return OK;
}

