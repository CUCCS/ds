#include"Tree.h"

BiTNode* CreateBiTree(BiTNode *T,char *p){
    static char *ch;
    ch=p;
    //scanf_s("%c",&ch);
    //getchar();
    if(*ch == '0') {
        T = NULL;
    }
    else {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        if (!T){
            printf("OVERFLOW");
            exit(1);
        }
        T->data = *ch;    // 生成根结点
        T->lchild= CreateBiTree(T->lchild,++ch);   // 构造左子树
        T->rchild= CreateBiTree(T->rchild,++ch);   //` 构造右子树
    }
    return T;
}
void Preorder(BiTNode *T) 
{
	if (T) {
		Preorder(T->lchild); // 遍历左子树
		Preorder(T->rchild); // 遍历右子树
		printf("%c ", T->data);
	}
}
int Depth(BiTNode *T){ // 返回二叉树的深度
    int depthval;
    if(!T) {
        depthval = 0;
    } else {
        int depthLeft = Depth(T->lchild);
       int  depthRight= Depth(T->rchild);
        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depthval;
}
Status InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)exit(0);
    Q->front->Next = NULL;
    return OK;
}
Status QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)return TRUE;
    else return FALSE;
}
Status EnQueue(LinkQueue *Q, QElemType e) {
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)exit(OVERFLOW);
    p->data = e;
    p->Next = NULL;
    Q->rear->Next = p;
    Q->rear = p;
    return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e) {
    if (Q->front == Q->rear)return ERROR;
    QueuePtr p;
    p = Q->front->Next;
    *e = p->data;
    Q->front->Next = p->Next;
    if (Q->rear == p)Q->rear = Q->front;
    free(p);
    return OK;
}
int LevelOrderTraverseTree(BiTNode *T){
    LinkQueue Q;
    BiTNode *p=(BiTNode*)malloc(sizeof(BiTNode));
    InitQueue(&Q); //建立工作队列
    if(T==NULL){
        return 0;
    }
    int width=1;//所求宽度最大值（返回值）
    int LastWidth=1;//上一层宽度（这一次要循环遍历的次数）
    int ThisWidth=0;//当前遍历层数的宽度
    EnQueue(&Q,*T);
    while(QueueEmpty(Q)==FALSE) {
        while(LastWidth!=0){
        DeQueue(&Q, p);
        LastWidth--;
        //visit(p);
        if(p->lchild) {
            EnQueue(&Q, *p->lchild);
            ThisWidth++;
        }
        if(p->rchild) {
            EnQueue(&Q, *p->rchild);
            ThisWidth++;
        }
        }
        width=(ThisWidth>width)?ThisWidth:width;
        LastWidth=ThisWidth;
        ThisWidth=0;
    }
    return width;
}
Status CheckComplete(BiTNode *T){
   
	int temp = 1; 
	int flag=0;
    int depth=Depth(T);
    printf("深度：%d\n",depth);
    LinkQueue Q;
    BiTNode *p=(BiTNode*)malloc(sizeof(BiTNode));
    InitQueue(&Q); //建立工作队列
    EnQueue(&Q,*T);
    int LastWidth=1;//上一层宽度（这一次要循环遍历的次数）
    int ThisWidth=0;//当前遍历层数的宽度
   
    while(QueueEmpty(Q)==FALSE) {
        static int d=2;
        flag=2;
        while(LastWidth!=0){
           // flag=0;
        DeQueue(&Q, p);
        //visit(p);
            LastWidth--;
        if(p->lchild) {
            EnQueue(&Q, *p->lchild);
            ThisWidth++;
        }
        if(p->rchild) {
            EnQueue(&Q, *p->rchild);
            ThisWidth++;
        }
		{
			if (p->lchild == NULL&&p->rchild != NULL) {
				return FALSE;//只有右孩子没有左孩子，则是非完全二叉树
			}
			else if (p->lchild != NULL&&p->rchild != NULL) {
				flag = 2;//左右孩子均存在
			}
			else if (p->rchild == NULL&&flag == 2) {
				flag = 1;//立个flag，如果接下来都是空，则完全二叉树
			}
			else if (p->rchild == NULL&&p->lchild == NULL&&flag == 1) {
				flag = 1;
			}
		}
        if((p->rchild!=NULL||p->lchild!=NULL)&&flag==1){
            flag=0;//立下flag后，之后不为空，则非完全二叉树
        }
        if(flag!=0&&LastWidth==0&&d==depth){
                return OK;//
        }
    }
        if(flag==0){
            return FALSE;
        }
        LastWidth=ThisWidth;
        temp=LastWidth;
        ThisWidth=0;
        d++;
       // flag=0;
    }
    return FALSE;
}