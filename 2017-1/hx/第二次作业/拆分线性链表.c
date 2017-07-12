#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LNode{
    int data;
    struct LNode  *next;
}LNode,*LinkList;

void CreateList (LinkList *L,int n)
{
    LinkList p = (LinkList) malloc(sizeof(LNode));
    LinkList temp = p;
    srand((unsigned)time( NULL ) );
    for(;n!=0;--n){
        p->next = (LinkList)malloc(sizeof(LNode));
        p->next->data = rand()%1024;
        p=p->next;
    }
    p->next = NULL;
    *L = temp->next;
    free(temp);
}

void Traverse1 (LinkList L)
{
    LNode *p = L;
    while(p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
void Traverse2 (LinkList L)
{
    LNode *p = L->next;
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p != L->next);
    printf("\n");
}
void SplitList(LinkList L,LinkList*pL1,LinkList*pL2)
{
    *pL1=(LNode*)malloc(sizeof(LNode));
    (*pL1)->data = 0;
    (*pL1)->next = NULL;
    *pL2=(LNode*)malloc(sizeof(LNode));
    (*pL2)->data = 0;
    (*pL2)->next = NULL;
    LinkList p,rear1 = *pL1,rear2=*pL2;
    int count=0;
    for(p = L;p != NULL;p = p->next)
    {
        ++count;
        if(count%2)
        {
            (*pL1)->data++;
            rear1->next = p;
            rear1 = p;
        }
        else
        {
            (*pL2)->data++;
            rear2->next = p;
            rear2 = p;
        }
    }
    rear1->next = (*pL1)->next;
    rear2->next = (*pL2)->next;
}
int main()
{
    LinkList L,L1 = NULL,L2 = NULL;
    int n;
    
    srand((unsigned)time( NULL ) );
    n = rand()%9+2;
    printf(" 分解前的线性链表数据长度: %d\n",n);
    /*scanf("%d",&n);*/
    CreateList(&L,n);
    printf("分解前的线性链表数据:\n");
    Traverse1(L);
    
    SplitList(L,&L1,&L2);
    printf("\n分解后的单循环链表L1数据:\n");
    Traverse2(L1);
    printf("\n分解后的单循环链表L2数据:\n");
    Traverse2(L2);
    return 0;
}
