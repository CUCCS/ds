#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct Link_list {
    int data;
    struct Link_list *next;
} Linklist, *LNode;

LNode CreatLinklist(int length, int number);//创建一个线性链表
void PrintLinklist(const LNode list);//打印线性链表
void PrintLoopLinklist(const LNode list);//打印循环单链表
void disingrateLinklist(const LNode list, LNode la, LNode lb);//将一个线性表分解为两个循环单链表

LNode CreatLinklist(int length, int number)//创建一个线性链表
{
    LNode current, previous, head, list;
    int i = 0;
    head = NULL;
    list = NULL;
    list = head;
    previous = NULL;
    current = NULL;
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        current = (LNode) malloc(sizeof(Link_list));
        if (head == 0) {
            head = current;
        }
        if (previous != NULL) {
            previous->next = current;
        }
        number = number + rand() % 4;
        current->data = number;
        current->next = NULL;
        previous = current;
    }
    return head;
}

void PrintLinklist(const LNode list)//打印线性链表
{
    LNode p;
    p = list;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void PrintLoopLinklist(const LNode list) //打印循环单链表
{
    LNode start;
    start = list->next;
    while (start != list) {
        printf("%d ", start->data);
        start = start->next;
    }
}

void disingrateLinklist(const LNode list, LNode la, LNode lb)//将一个线性表分解为两个循环单链表
{
    LNode pla, acurrent, ahead, plb, bcurrent, bhead;
    int count = 1;
    int alen = 0, blen = 0;
    LNode p;
    p = list;
    acurrent = la;
    ahead = la;
    bcurrent = lb;
    bhead = lb;
    while (p != NULL) {
        if (count % 2 != 0) {
            pla = (LNode) malloc(sizeof(Linklist));
            pla->data = p->data;

            pla->next = acurrent;
            ahead->next = pla;
            acurrent = pla;
            alen++;


        }
        else {
            plb = (LNode) malloc(sizeof(Link_list));
            plb->data = p->data;

            plb->next = bcurrent;
            bhead->next = plb;
            bcurrent = plb;
            blen++;

        }
        p = p->next;
        count++;
    }
    ahead->data = alen;
    bhead->data = blen;
    printf("\nLa is:\n");
    PrintLoopLinklist(la);
    printf("\nThe length of la is:%d\n", ahead->data);

    printf("\nLb is:\n");
    PrintLoopLinklist(lb);
    printf("\nThe length of lb is:%d\n", bhead->data);

}

int main() {
    LNode List, La, Lb;
    La = (LNode) malloc(sizeof(Link_list));
    La->next = La;
    Lb = (LNode) malloc(sizeof(Link_list));
    Lb->next = Lb;

    int number;
    srand(time(NULL));
    number = number % 5 + 3;
    int length = length % 5 + 14;
    List = CreatLinklist(length, number);
    printf("The original list is:\n");
    PrintLinklist(List);
    printf("\nThe length of original list is :%d", length);
    printf("\nAfter ...\n");

    disingrateLinklist(List, La, Lb);
    return 0;


}
