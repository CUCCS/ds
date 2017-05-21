#include<stdio.h>
#include<stdlib.h>

#define MAX_VEX 20
#define Queue_Size 100
int visited[MAX_VEX];//访问标志数组visited
typedef int ElemType;
typedef int VerType;
typedef enum {
    OK,
    ERROR,
    OVERFLOW
} Status;

typedef struct q_node {//队列中的每个节点
    ElemType data;
    struct q_node *previous;
    struct q_node *next;
} Qnode, *Pq_node;

typedef struct link_queue {//队列
    Pq_node front;
    Pq_node rear;
} LinkQueue;

typedef struct ArcCell {//定义弧
    ElemType eadj;//用"1"表示相邻,"0"表示不相邻
} AdjMatrix[MAX_VEX][MAX_VEX];

typedef struct graph {//定义图
    AdjMatrix arcs;
    int arcs_num;//弧数
    int vers_num;//顶点数目
} Graph;

/*对于队列基本操作实现*/
Status InitQueue(LinkQueue *q);//初始化队列
Status EnQueue(LinkQueue *q, ElemType e);//入队列
Status DeQueue(LinkQueue *q, ElemType *e);//出队列
bool EmptyQueue(LinkQueue q);//判断队列是否为空
/*对于队列基本操作实现*/

/*对于图的操作*/
Status Add(Graph *g, int i, int j);//为邻接矩阵赋值
Status CreatGraph(Graph *g);//构建一个图
VerType ToFirstAdjVex(Graph g, int num);//返回第一个邻接顶点
VerType ToNextAdjVex(Graph g, int i, int j);//返回下一个邻接顶点

void BFSTraverse(Graph g, int a, int b);//按广度优先非递归遍历图g
Status PrintFoot(LinkQueue q, VerType start);//输出两点间的最短路径
/*对于图的操作*/


Status InitQueue(LinkQueue *q) {//初始化队列
    q->front = (Pq_node) malloc(Queue_Size * sizeof(Qnode));
    q->rear = (Pq_node) malloc(Queue_Size * sizeof(Qnode));
    q->front = q->rear;
    if (!(q->front)) {
        return ERROR;
    }
    q->front->next = q->rear->next = NULL;//初始化队列得头和尾
    return OK;
}

Status EnQueue(LinkQueue *q, ElemType e) {//入队列
    Pq_node ptr;
    ptr = (Pq_node) malloc(sizeof(Qnode));
    if (!ptr) {
        return ERROR;
    }
    ptr->data = e;
    ptr->next = NULL;
    ptr->previous = q->front;
    q->rear->next = ptr;
    q->rear = ptr;
    return OK;
}

Status DeQueue(LinkQueue *q, ElemType *e) {//出队列
    if (EmptyQueue(*q)) {
        return ERROR;
    }
    q->front = q->front->next;//队列非空才可以进行出队列操作
    *e = q->front->data;
    return OK;
}

bool EmptyQueue(LinkQueue q) {//判断队列是否为空
    if (q.front == q.rear) {
        return true;
    }
    
    return false;
    
}

Status Add(Graph *g, int i, int j) {//为邻接矩阵赋值
    if (i >= MAX_VEX || j >= MAX_VEX) {
        return ERROR;
    }
    g->arcs[i][j].eadj = 1;
    g->arcs[j][i].eadj = 1;
    
    return OK;
}

Status CreatGraph(Graph *g) {//构建一个图
    g->vers_num = 9;//初始化图的弧数
    g->arcs_num = 12;//初始化图的边数
    int i = 0;
    int j = 0;
    for (i = 0; i < g->vers_num; i++) {
        for (j = 0; j < g->vers_num; j++) {
            g->arcs[i][j].eadj = 0;//初始化邻接矩阵,"0"表示不相邻
        }
    }
    Add(g, 0, 1);
    Add(g, 0, 2);
    Add(g, 0, 3);
    Add(g, 0, 6);
    Add(g, 1, 2);
    Add(g, 3, 4);
    Add(g, 3, 5);
    Add(g, 4, 5);
    Add(g, 5, 7);
    Add(g, 6, 7);
    Add(g, 6, 8);
    Add(g, 7, 8);//依次为图的相邻顶点赋值,初始化一个图
    return OK;
    
}

VerType ToFirstAdjVex(Graph g, int num) {//返回第一个邻接顶点
    int i;
    for (i = 0; i < g.vers_num; i++) {
        if (g.arcs[num][i].eadj == 1) {
            return i;
        }
    }
    return -1;
}

VerType ToNextAdjVex(Graph g, int i, int j) {//返回下一个邻接顶点
    int k;
    for (k = j + 1; k < g.vers_num; k++) {
        if (g.arcs[i][k].eadj == 1) {
            return k;
        }
    }
    return -1;
}

void BFSTraverse(Graph g, int a, int b) {//按广度优先非递归遍历图g
    
    int i = 0, j, k;
    int e;
    LinkQueue q;
    bool flag;
    for (i = 0; i < g.vers_num; ++i) {
        visited[i] = 0;
        
    }
    InitQueue(&q);//置空的辅助队列q
    EnQueue(&q, a);//起点元素a进入队列
    visited[a] = 1;
    flag = false;
    while (!EmptyQueue(q)) {
        DeQueue(&q, &e);//队头元素出队并置为e
        
        for (j = ToFirstAdjVex(g, e); j >= 0; j = ToNextAdjVex(g, e, j)) {
            if (j == b) {
                EnQueue(&q, j);
                PrintFoot(q, a);
                flag = true;
                break;
            }
            if (!visited[j]) {//j为e尚未访问的邻接顶点
                EnQueue(&q, j);
                visited[j] = true;
            }
            
        }
        if (flag) {
            break;
        }
        
    }
    
}

Status PrintFoot(LinkQueue q, VerType start) {//输出两点间的最短路径
    int track[MAX_VEX];//该数组用来存储路径
    Pq_node ptr;
    int i = 0, j;
    
    ptr = q.rear;
    for (i = 0; i < MAX_VEX; i++) {
        track[i] = -1;
    }
    track[0] = ptr->data;
    ptr = ptr->previous;
    for (i = 1; ptr->data != start; i++) {
        track[i] = ptr->data;
        ptr = ptr->previous;
    }
    track[i] = ptr->data;
    for (j = i; j >= 0; j--)//倒序输出路径
    {
        if (track[j] >= 0) {
            printf("%d ", track[j] + 1);
        }
        
    }
}

int main() {
    Graph graph;
    CreatGraph(&graph);
    int i = 0, j = 0;
    printf("图中任意两点间的最短距离为:\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (j != i) {
                printf("%d<->%d:", i + 1, j + 1);
                BFSTraverse(graph, i, j);
                printf("\n");
            }
        }
    }
    return 0;
}
