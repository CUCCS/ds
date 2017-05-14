//
//  main.c
//  分解链表
//
//  Created by Huhongbo on 2017/4/10.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//

//说明：
//时间复杂度：
//Sequence函数在将list线性链表分解成两个循环链表时，只遍历一次线性表。其时间复杂度约为O(n)(n为list链表的长度)，此时，时间复杂度最小。
//空间复杂度：
//在创建两个循环链表(list1,list2)时，只分别重新动态分配了一个头结点。创建两个循环链表的过程，list1,list2初头结点外其他结点，没有重新分配空间，空间复杂度最小。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

typedef enum
{
    OK,
    ERROR,
    OVERFLOW
}Status;

//输出单链表；
Status output(LinkList L);

//输出循环单链表的一个周期；
Status output1(LinkList L);

//建立一个测试线性链表（第一个链结点为指针list的链表）
void CreateList_L(LinkList L, int n);

//将线性单链表分解到奇偶序列循环链表；
void ParitySequence(LinkList list, LinkList list1, LinkList list2);

Status output(LinkList L)
{
    LinkList p = L;
    if (L->next == NULL)
    {
        return ERROR;
    }
    LinkList Line;
    Line = L;
    while (Line->next != NULL)
    {
        printf("%d", Line->data);
        printf("\n");
        if (Line->next != NULL)
        {
            Line = Line->next;
        }
    }
    printf("%d", Line->data);
    return OK;
}

Status output1(LinkList L)
{
    LinkList p = L;
    if (L->next == NULL)
    {
        return ERROR;
    }
    LinkList Line;
    Line = L;
    while (Line->next !=p)
    {
        printf("%d", Line->data);
        printf("\n");
        if (Line->next != NULL)
        {
            Line = Line->next;
        }
    }
    printf("%d", Line->data);
    return OK;
}
//建立一个测试线性链表（第一个链结点为指针list的链表）
void CreateList_L(LinkList L, int n)
{
    LinkList L1 = L;
    L1->data = (int)rand() % 1024;
    LinkList p;
    int i;
    for (i = 0; i < n-1; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));  //生成新结点；
        p->data = (int)rand() % 1024;
        L1->next= p;
        L1 = L1->next;
        p->next=NULL;
    }
}


void Sequence(LinkList list,LinkList list1,LinkList list2)
{
    
    
    LNode*p1 = list1;
    LNode*p2 = list2;
    LNode*p = list;
    list1->data = 0;
    list2->data = 0;
    while (p!=NULL)
    {
        p1->next = p;
        p1 = p1->next;
        list1->data++;
        p = p->next;
        if (p!= NULL)
        {
            p2->next = p;
            p2 = p2->next;
            list2->data++;
            p = p->next;
        }
    }
    p1->next = list1;
    p2->next = list2;
}
int main()
{
    srand(time(0));
    int n;
    LinkList list = (LinkList)malloc(sizeof(LNode));
    LinkList list1 = (LinkList)malloc(sizeof(LNode));//奇序号链表头结点；
    LinkList list2 = (LinkList)malloc(sizeof(LNode));//偶序号链表头结点；
    n = rand() % 9 + 3;//确保链表list大小大于等于2；
    printf("随机生成线性链表:\n");
    CreateList_L(list, n);
    output(list);
    Sequence(list, list1, list2);
    printf("\n奇序列的循环链表：\n");
    output1(list1);
    printf("\n偶序列的循环链表：\n");
    output1(list2);
    
}
