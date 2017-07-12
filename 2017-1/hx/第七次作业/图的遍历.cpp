#include<stdio.h>
#include<stdlib.h>
#define MAX_VEX 20
#define Queue_Size 100
int visited[MAX_VEX];
typedef int ElemType;
typedef int VerType;
typedef enum{
    OK,
    ERROR,
    OVERFLOW
}Status;

typedef struct q_node{
    ElemType data;
    struct q_node *previous;
    struct q_node *next;
}Qnode,*Pq_node;

typedef struct link_queue{
    Pq_node front;
    Pq_node rear;
}LinkQueue;

typedef struct ArcCell{
    ElemType eadj;
}AdjMatrix[MAX_VEX][MAX_VEX];

typedef struct graph{
    AdjMatrix arcs;
    int arcs_num;
    int vers_num;
}Graph;


Status InitQueue(LinkQueue *q);
Status EnQueue(LinkQueue*q, ElemType e);
Status DeQueue(LinkQueue*q,ElemType *e);
bool EmptyQueue(LinkQueue q);


Status Add(Graph*g,int i,int j);
Status CreatGraph(Graph*g);
VerType  ToFirstAdjVex(Graph g,int num);
VerType ToNextAdjVex(Graph g,int i,int j);
void BFSTraverse(Graph g,int a,int b);
Status PrintFoot(LinkQueue q,VerType start);



Status InitQueue(LinkQueue *q){
    q->front=(Pq_node)malloc(Queue_Size*sizeof(Qnode));
    q->rear=(Pq_node)malloc(Queue_Size*sizeof(Qnode));
    q->front=q->rear;
    if(!(q->front)){
        return ERROR;
    }
    q->front->next=q->rear->next=NULL;
    return OK;
}

Status EnQueue(LinkQueue*q, ElemType e) {
    Pq_node ptr;
    ptr=(Pq_node)malloc(sizeof(Qnode));
    if(!ptr)
    {
        return ERROR;
    }
    ptr->data=e;
    ptr->next=NULL;
    ptr->previous=q->front;
    q->rear->next=ptr;
    q->rear=ptr;
    return OK;
}

Status DeQueue(LinkQueue *q,ElemType *e){
    if(EmptyQueue(*q)){
        return ERROR;
    }
    q->front=q->front->next;
    *e=q->front->data;
    return OK;
}

bool EmptyQueue(LinkQueue q){
    if(q.front==q.rear){
        return true;
    }
    
    return false;
    
}
Status Add(Graph*g,int i,int j) {
    if(i>=MAX_VEX||j>=MAX_VEX)
    {
        return ERROR;
    }
    g->arcs[i][j].eadj=1;
    g->arcs[j][i].eadj=1;
    
    return OK;
}
Status CreatGraph(Graph*g) {
    g->vers_num=9;
    g->arcs_num=12;
    int i=0;
    int j=0;
    for(i=0;i<g->vers_num;i++)
    {
        for(j=0;j<g->vers_num;j++)
        {
            g->arcs[i][j].eadj=0;
        }
    }
    Add(g, 0, 1); Add(g, 0, 2); Add(g, 0, 3); Add(g, 0, 6);
    Add(g, 1, 2); Add(g, 3, 4); Add(g, 3, 5); Add(g, 4, 5);
    Add(g, 5, 7); Add(g, 6, 7); Add(g, 6, 8); Add(g, 7, 8);
    return OK;
    
}

VerType  ToFirstAdjVex(Graph g,int num) {
    int i;
    for(i=0;i<g.vers_num;i++)
    {
        if(g.arcs[num][i].eadj==1){
            return i;
        }
    }
    return -1;
}

VerType ToNextAdjVex(Graph g,int i,int j){
    int k;
    for(k=j+1;k<g.vers_num;k++)
    {
        if(g.arcs[i][k].eadj==1){
            return k;
        }
    }
    return -1;
}

void BFSTraverse(Graph g,int a,int b) {
    int i=0,j,k;
    int e;
    LinkQueue q;
    bool flag;
    for(i=0;i<g.vers_num;++i){
        visited[i]=0;
        
    }
    InitQueue(&q);
    EnQueue(&q,a);
    visited[a]=1;
    flag=false;
    while(!EmptyQueue(q)){
        DeQueue(&q,&e);
        
        for(j=ToFirstAdjVex(g,e);j>=0;j=ToNextAdjVex(g,e,j))
        {
            if(j==b){
                EnQueue(&q,j);
                PrintFoot(q,a);
                flag=true;
                break;
            }
            if(!visited[j]){
                EnQueue(&q,j);
                visited[j]=true;
            }
            
        }
        if(flag){
            break;
        }
        
    }
    
}
Status PrintFoot(LinkQueue q,VerType start) {
    int track[MAX_VEX];
    Pq_node ptr;
    int i=0,j;
    
    ptr=q.rear;
    for(i=0;i<MAX_VEX;i++){
        track[i]=-1;
    }
    track[0]=ptr->data;
    ptr=ptr->previous;
    for(i=1;ptr->data!=start;i++){
        track[i]=ptr->data;
        ptr=ptr->previous;
    }
    track[i]=ptr->data;
    for( j=i;j>=0;j--)
    {if(track[j]>=0)
    {
        printf("%d ",track[j]+1);
    }
        
    }
    return OK;
}
int main()
{
    Graph graph;
    CreatGraph(&graph);
    int i=0,j=0;
    printf("到其他结点的最短路径为:\n");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
        {
            if(j!=i)
            {
                printf("%d<->%d:",i+1,j+1);
                BFSTraverse(graph,i,j);
                printf("\n");
            }
        }
    }
    return 0;
}