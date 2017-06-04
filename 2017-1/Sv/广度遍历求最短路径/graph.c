#include "graph.h"


//队列基本操作————————————
void InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    Q->front->Next = Q->rear->Next= NULL;
    Q->front->Priou=NULL;
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
Status DestroyQueue(LinkQueue *Q){
    while (Q->front) {
        Q->rear = Q->front->Next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}
//——————————————————
void CreatGraph(MGraph *G,AdjMatrix A){
    //针对本题创建图

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            G->arcs[i][j]=A[i][j];
        }
    }
    G->vexnum=9;
    G->arcnum=12;
    for(int i=0;i<9;i++){
        G->vexs[i]=0;//全部设置为为访问
    }
}
int FirstAdjVex(MGraph G,QElemType e){
    for(int i=0;i<G.vexnum;i++){
        if(G.arcs[e][i]==1)return i;
    }
    return -1;
}
int NextAdjVex(MGraph G,QElemType e,int w){
    for(int i=w+1;i<G.vexnum;i++){
        if(G.arcs[e][i]==1) return i;
    }
    return -1;
}

void BFSTraverse(MGraph G,int a,int b){
    LinkQueue Q;
    InitQueue(&Q); // 置空的辅助队列Q
    int v,w;
    for(int i=0;i<G.vexnum;i++){
        G.vexs[i]=0;
        
    }
    QElemType e=a-1;
    for(v = e; v < G.vexnum; ++v) {
        int flag=0;
        if(G.vexs[v]==0) { // v 尚未访问
            G.vexs[v] = 1;
            EnQueue(&Q, v); // v入队列
            while(QueueEmpty(Q)==FALSE) {
                DeQueue(&Q, &e); // 队头元素出队并置为u
                for(w = FirstAdjVex(G, e); w != -1; w = NextAdjVex(G,e,w)) {
                    if (G.vexs[w]==0) {
                        G.vexs[w] = 1;
                        EnQueue(&Q, w); // 访问的顶点w入队列
                        }
                    if(w==b-1){
                        flag=1;
                        break;
                    }
                    if(flag==1)break;
                }
                if(flag==1)break;
            }
        }
        if(flag==1)break;
    }
//    QueuePtr p=Q.front->Next;
//    while(p->Priou!=NULL){
//        p=p->Priou;
//    }
//    p=p->Next;
//    Q.front=p;//便于销毁队列；
    int temp[10];
    int count=0;
    QueuePtr p=Q.rear;
    for(int i=0;i<10;i++){
        temp[i]=0;
    }
    while (p->Priou!=NULL) {
        temp[count++]=p->data;
        p=p->Priou;
    }
    printf("%d->%d:",a,b);
    for(int i=count-1;i>=0;i--){
        printf("%d ",temp[i]+1);
    }
    printf("\n");
        QueuePtr q=Q.front->Next;
        while(q->Priou!=NULL){
            q=q->Priou;
        }
        q=q->Next;
        Q.front=q;//便于销毁队列；
    DestroyQueue(&Q);
    }

