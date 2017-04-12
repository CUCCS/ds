//
//  main.c
//  list
//
//  Created by Huhongbo on 2017/4/9.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//


/*时间复杂度：O(n)(n为链表长度) 因为SeperateList函数分离链表时只遍历了一次线性表，此时时间复杂度最小。
 空间复杂度：在list分离为两个循环链表list1和list2时，只分别重新动态分配了一个头结点。list1,list2除头结点外的其他结点并没有重新分配空间，此时空间复杂度最小*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}LNode,*LinkList;

//输出链表
void OutPutList(LinkList head)
{
    LNode *temp;
    int count=head->data;
    temp=head->next;
    printf("该链表中的数据有;\n");
    while(count)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        count--;
    }
    printf("\n");
}

//创建链表
LinkList CreateList()
{
    LinkList list;
    LNode *tail,*temp;
    int number;
    list=(LNode *)malloc(sizeof(LNode));
    list->data=0;
    list->next=NULL;
    tail=list;
    printf("依次输入结点序号，以0为结束标志:\n");
    scanf("%d",&number);
    while(number)
    {
        temp=(LNode *)malloc(sizeof(LNode));
        temp->data=number;
        if (list->next==NULL)
        {
            temp->next=list->next;
            list->next=temp;
        }
        else
        {
            temp->next=tail->next;
            tail->next=temp;
        }
        tail=temp;
        list->data++;
        scanf("%d",&number);
    }
    OutPutList(list);
    return list;
}

//分离链表为奇数链表和偶数链表
void SeperateList(LinkList list,LinkList list1,LinkList list2)
{
    list1->data=0;
    list1->next=NULL;
    list2->data=0;
    list2->next=NULL;
    LNode *rep,*temp,*tail1,*tail2;
    rep=temp=list->next;
    tail1=list1;
    tail2=list2;
    while (temp)
    {
        if (temp->data%2)
        {
            rep=temp->next;
            if (list1->next==NULL)
            {
                temp->next=list1->next;
                list1->next=temp;
            }
            else
            {
                temp->next=tail1->next;
                tail1->next=temp;
            }
            tail1=temp;
            list1->data++;
        }
        else
        {
            rep=temp->next;
            if (list2->next==NULL)
            {
                temp->next=list2->next;
                list2->next=temp;
            }
            else
            {
                temp->next=tail2->next;
                tail2->next=temp;
            }
            tail2=temp;
            list2->data++;
        }
        temp=rep;
    }
    tail1->next=list1;
    tail2->next=list2;
    free(list);
}

int main()
{
    LinkList list,list1,list2;
    list=CreateList();
    list1=(LNode *)malloc(sizeof(LNode));
    list2=(LNode *)malloc(sizeof(LNode));
    SeperateList(list,list1,list2);
    printf("链表1:\n元素个数为%d\n",list1->data);
    OutPutList(list1);
    printf("链表2:\n元素个数为%d\n",list2->data);
    OutPutList(list2);
    return 0;
}
