#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct List//创建链表结构体
{
    int data;
    struct List *next;
} List, *Listlink;

Listlink creatList(int length, int number) //生成链表
{
    Listlink current, previous, head;
    int i = 0;
    head = NULL;
    previous = NULL;
    current = NULL;
    srand(time(NULL));
    for (i = 0; i < length; i++)//通过循环控制链表的创建
    {
        current = (Listlink) malloc(sizeof(List));
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

Listlink mergeLinklist(Listlink la, Listlink lb)//链表的合并
{

    Listlink cHead;
    cHead = NULL;
    Listlink cCurrent;
    cCurrent = NULL;
    if (la->data < lb->data) {
        cHead = la;
        la = la->next;
    }
    else {
        cHead = lb;
        lb = lb->next;
    }
    cCurrent = cHead;
    while ((la != NULL) && (lb != NULL)) {
        if (la->data < lb->data) {
            cCurrent->next = la;
            la = la->next;
        }
        else {
            cCurrent->next = lb;
            lb = lb->next;
        }
        cCurrent = cCurrent->next;
    }
    if (la != NULL) {
        cCurrent->next = la;
    }
    if (lb != NULL) {
        cCurrent->next = lb;
    }
    return cHead;
}

void printList(const Listlink head)//打印链表
{
    const List *phead;
    phead = head;

    while (phead != NULL) {
        printf("%d ", phead->data);
        //cout << phead->data<<" ";
        phead = phead->next;
    }
}

int main() {
    Listlink La, Lb, Lc;
    int length;
    int number = 1;
    srand(time(NULL));
    length = rand() % 20;
    number = number + rand() % 13;
    La = creatList(length, number);
    length = rand() % 16;
    number = number + rand() % 10;
    Lb = creatList(length, number);
    printf("La:");
    printList(La);
    printf("\n");
    printf("Lb:");
    printList(Lb);
    printf("\n");
    Lc = mergeLinklist(La, Lb);
    printf("After the merge:");
    printList(Lc);
    printf("\n");
    return 0;
}