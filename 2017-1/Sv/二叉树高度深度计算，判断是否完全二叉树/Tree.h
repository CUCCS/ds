#include<stdio.h>
#include<stdlib.h>
#define  TElemType char
typedef enum _Status{
    FALSE,
    OK,
    OVERFLOW,
    TRUE,
    ERROR,
}Status;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode  *lchild, *rchild; 
} BiTNode, *BiTree;

typedef BiTNode QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *Next;
}QNode, *QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType *e);
BiTNode* CreateBiTree(BiTNode *T,char *);
void Preorder(BiTNode *T);
int Depth(BiTree T);
int LevelOrderTraverseTree(BiTNode *T);
Status CheckComplete(BiTNode *T);
