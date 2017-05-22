#include "MapPath.h"
//——————队列基本操作————————————
void InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->front->Next = Q->rear->Next = NULL;
	Q->front->Priou = NULL;
}
void EnQueue(LinkQueue *Q, QElemType e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->Next = NULL;
	p->Priou = Q->front;
	Q->rear->Next = p;
	Q->rear = p;
}
void DeQueue(LinkQueue* Q, QElemType* e) {
	Q->front = Q->front->Next;
	*e = Q->front->data;
}
Status QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)return TRUE;
	else return FALSE;
}
Status DestroyQueue(LinkQueue *Q) {
	while (Q->front) {
		Q->rear = Q->front->Next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
//——————————————————
Status CreatGraph(Graph *G, Array A) {
	//创建课件上的图
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			G->a[i][j] = A[i][j];
		}
	}

	G->vexnum = 9;
	G->arcnum = 12;

	for (int i = 0; i < 9; i++) {
		G->vexs[i] = 0;//全部设置为访问
	}
	return OK;
}

int FirstFind(Graph G, QElemType e) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.a[e][i] == 1)//如果e结点和i结点之间连通
		{
			return i;//返回和e连通的这个结点的数值
		}
	}
	return -1;
}
int NextFind(Graph G, QElemType e, int w) {
	for (int i = w + 1; i < G.vexnum; i++)//从第w+1个结点开始找
	{
		if (G.a[e][i] == 1)
		{
			return i;
		}
	}
	return -1;
}

LinkQueue BFSTraverse(Graph G, int a, int b)
{
	LinkQueue Q;
	InitQueue(&Q); // 置空的辅助队列Q
	int v, w;
	for (int i = 0; i < G.vexnum; i++) {
		G.vexs[i] = 0;//全部设置为访问
	}
	QElemType e = a - 1;
	for (v = e; v < G.vexnum; v++) {
		int flag = 0;
		if (G.vexs[v] == 0)// v 尚未访问
		{

			G.vexs[v] = 1;
			EnQueue(&Q, v);
			while (QueueEmpty(Q) == FALSE)
			{
				DeQueue(&Q, &e);
				for (w = FirstFind(G, e); w != -1; w = NextFind(G, e, w))//对于结点e,一直找它的连通结点，直到再也找不到为止
				{
					if (G.vexs[w] == 0) {
						G.vexs[w] = 1;
						EnQueue(&Q, w); // 访问的顶点w入队列
					}

					if (w == b - 1)
					{
						flag = 1;
						break;//按顺序遍历所有连通节点完毕
					}
					if (flag == 1) { break; }
				}
				if (flag == 1) { break; }
			}
		}
		if (flag == 1) { break; }
	}

	return Q;


}

void Print(LinkQueue Q, int a, int b)
{
	int temp[10];
	int count = 0;
	QueuePtr p = Q.rear;
	for (int i = 0; i < 10; i++) {
		temp[i] = 0;
	}
	while (p->Priou != NULL) {
		temp[count++] = p->data;
		p = p->Priou;
	}
	printf("%d->%d:", a, b);
	for (int i = count - 1; i >= 0; i--) {
		printf("%d ", temp[i] + 1);
	}
	printf("\n");
	QueuePtr q = Q.front->Next;//将q置于Q之后
	while (q->Priou != NULL) {
		q = q->Priou;
	}
	q = q->Next;
	Q.front = q;
	DestroyQueue(&Q);

}