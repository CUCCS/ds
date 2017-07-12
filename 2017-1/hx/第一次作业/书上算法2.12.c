#include<stdio.h>
#include"Header.h"
#include<time.h>
//建立线性表并将其置空
void CreateList(LinkList *L,int n)
{
    LinkList p = NULL;
    int i ;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    srand((unsigned)time( NULL ) );
    for(i=0;i<n;i++){
        p = (LinkList)malloc(sizeof(LNode));
        //scanf("%d",&p->data);//
        p->data = rand()%1024;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}//createlist
void SortList(LinkList L,int n)
{
    int i=0;
    int j=0;
    LinkList head;
    LinkList p1;
    LinkList p2;
    
    for(i=0;i<n;i++)
    {
        head = L->next;
        for( j=0;j<n-1;j++)
        {
            p1=head;
            p2=head->next;
            if( p1->data > p2->data){
                Elemtype temp = p1->data;
                p1->data = p2 -> data;
                p2->data = temp;
            }
            head = head->next;
        }
    }
}

void Traverse(LinkList L)
{
    LNode *p = L->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

void MergeList_L(LinkList La,LinkList Lb,LinkList  *Lc)
{
    LinkList pa,pb,pc;
    pa = La->next;
    pb = Lb->next;
    *Lc = pc = La;
    while(pa&&pb){
        if(pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else{
            pc->next = pb;
            pc = pb;
            pb =pb ->next;
        }
    }
    pc->next = pa? pa:pb;
    free(Lb);
}

void ShowList(LinkList *L1,LinkList *L2)
{
    int i,j;
    LinkList Lc;
    *L1 =(LinkList) malloc(sizeof(LNode));
    *L2 =(LinkList) malloc(sizeof(LNode));
    
    printf("L1的长度为:");
    scanf("%d",&i);
    
    CreateList(L1,i);
    printf("获取L1中的数据:\n");
    Traverse(*L1);
    printf("\n");
    
    SortList(*L1,i);
    printf("将L1中的数据由小到大排列:\n");
    Traverse(*L1);
    printf("\n");
    
    printf("\nL2的长度为:");
    scanf("%d",&j);
    
    CreateList(L2,j);
    printf("\n获取L2中的数据:");
    Traverse(*L2);
    printf("\n");
    
    SortList(*L2,j);
    printf("将L2中的数据由小到大排列:\n");
    Traverse(*L2);
    printf("\n");
    
    printf("将所有数据由小到大排列:\n");
    MergeList_L(*L1,*L2,&Lc);
    Traverse(Lc);
}



