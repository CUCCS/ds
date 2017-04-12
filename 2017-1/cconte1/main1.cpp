#include <iostream>
using namespace std;
typedef struct List//创建链表结构体
{
    int data;
    struct List *next;
} List,*Listlink;
Listlink creatList() //生成链表
{
    Listlink current,previous,head;
    int length,i=0;
    head=NULL;
    previous=NULL;
    current=NULL;
    cin>>length;//输入链表的长度
    for(i=0;i<length;i++)//通过循环控制链表的创建
    {
        current=(Listlink)malloc(sizeof(List));
        if(head==0)
        {
            head=current;
        }
        if(previous!=NULL)
        {
            previous->next=current;
        }
        cin>>current->data;
        current->next=NULL;
        previous=current;
    }
    return head;
}
Listlink mergeLinklist(Listlink la, Listlink lb)//链表的合并
{

    Listlink cHead;
    cHead=NULL;
    Listlink cCurrent;
    cCurrent=NULL;
    if(la->data < lb->data)
    {
        cHead=la;
        la=la->next;
    }
    else
    {
        cHead=lb;
        lb=lb->next;
    }
    cCurrent=cHead;
    while((la!=NULL) && (lb!=NULL))
    {
        if(la->data < lb->data)
        {
            cCurrent->next=la;
            la=la->next;
        }
        else
        {
            cCurrent->next=lb;
            lb=lb->next;
        }
        cCurrent=cCurrent->next;
    }
    if(la!=NULL)
    {
        cCurrent->next=la;
    }
    if(lb!=NULL)
    {
        cCurrent->next=lb;
    }
    return cHead;
}

void printList(const Listlink head)//打印链表
{
   const List* phead ;
    phead=head;

    while ( phead!= NULL)
    {
        cout << phead->data<<" ";
        phead = phead->next;
    }
}
int main()
{
    Listlink La, Lb, Lc;
    La = creatList();
    Lb = creatList();
    Lc = mergeLinklist(La, Lb);
    printList(Lc);
    return 0;
}







