//
//  main.c
//  suanfa2.12
//
//  Created by Huhongbo on 2017/3/22.
//  Copyright © 2017年 Huhongbo. All rights reserved.
//


#include<stdio.h>
#include<stdlib.h>

struct Linklist{
    int data;
    struct Linklist *next;
};

void input(struct Linklist *head,int num);//输入链表l1,l2

void sort(struct Linklist *l1,struct Linklist *l2);//合并两个链表l1,l2

void output(struct Linklist *head);//输出合并后的链表

int main()
{
    int n;
    struct Linklist *h1,*h2;  //两个链表的头指针
    h1=(struct Linklist*)malloc(sizeof(struct Linklist));
    h2=(struct Linklist*)malloc(sizeof(struct Linklist));
    h1->next=NULL;
    h2->next=NULL;
    
    //输入两个链表l1,l2
    printf("请输入第一个链表长度：\n");
    scanf("%d",&n);
    input(h1,n);
    printf("请输入第二个链表长度：\n");
    scanf("%d",&n);
    input(h2,n);
    
    //链表的合并
    sort(h1,h2);
    
    //链表的输出
    output(h1);
}

void input(struct Linklist *head,int num)
{
    struct Linklist *p;
    struct Linklist *q;
    q=head;
    printf("请输入链表内容：\n");
    for(int i=0;i<num;i++)
    {
        p=(struct Linklist *)malloc(sizeof(struct Linklist));
        scanf("%d",&p->data);
        q->next=p;
        p->next=NULL;
        q=p;
    }
}

void sort(struct Linklist *l1,struct Linklist *l2)
{
    struct Linklist *p1,*p2,*p;
    p1=l1;
    p2=l2->next;
    while(p1->next&&p2)
    {
        if(p1->next->data>p2->data)
        {
            p=p2->next;
            p2->next=p1->next;
            p1->next=p2;
            p2=p;
        }
        else
            p1=p1->next;
    }
    if(p2)
        p1->next=p2;
}

void output(struct Linklist *head)
{
    while(head->next)
    {
        printf(" %d ",head->next->data);
        head=head->next;
    }
}

























